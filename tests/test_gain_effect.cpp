/**
 * @file test_gain_effect.cpp
 * @brief Unit tests for GainEffect
 */

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <cstring>
#include <string>

#include "gain_effect.h"

using Catch::Matchers::WithinAbs;
using Catch::Matchers::WithinRel;

// ============================================================================
// Construction Tests
// ============================================================================

TEST_CASE("GainEffect construction", "[gain_effect][construction]") {
    SECTION("Default gain is 1.0") {
        GainEffect gain;
        REQUIRE_THAT(gain.get_gain(), WithinAbs(1.0f, 0.001f));
    }
    
    SECTION("Custom initial gain") {
        GainEffect gain(0.5f);
        REQUIRE_THAT(gain.get_gain(), WithinAbs(0.5f, 0.001f));
    }
    
    SECTION("Clamps gain above max") {
        GainEffect gain(2.0f);
        REQUIRE_THAT(gain.get_gain(), WithinAbs(1.0f, 0.001f));
    }
    
    SECTION("Clamps gain below min") {
        GainEffect gain(-0.5f);
        REQUIRE_THAT(gain.get_gain(), WithinAbs(0.0f, 0.001f));
    }
}


// ============================================================================
// Gain Setting Tests
// ============================================================================

TEST_CASE("GainEffect gain setting", "[gain_effect][gain]") {
    GainEffect gain;
    
    SECTION("Set valid gain") {
        gain.set_gain(0.75f);
        REQUIRE_THAT(gain.get_gain(), WithinAbs(0.75f, 0.001f));
    }
    
    SECTION("Clamps high values") {
        gain.set_gain(5.0f);
        REQUIRE_THAT(gain.get_gain(), WithinAbs(1.0f, 0.001f));
    }
    
    SECTION("Clamps negative values") {
        gain.set_gain(-1.0f);
        REQUIRE_THAT(gain.get_gain(), WithinAbs(0.0f, 0.001f));
    }
}

// ============================================================================
// dB Conversion Tests
// ============================================================================

TEST_CASE("GainEffect dB conversion", "[gain_effect][db]") {
    GainEffect gain;
    
    SECTION("Unity gain = 0 dB") {
        gain.set_gain(1.0f);
        REQUIRE_THAT(gain.get_gain_db(), WithinAbs(0.0f, 0.1f));
    }
    
    SECTION("Half amplitude = -6 dB") {
        gain.set_gain(0.5f);
        REQUIRE_THAT(gain.get_gain_db(), WithinAbs(-6.02f, 0.1f));
    }
    
    SECTION("Quarter amplitude = -12 dB") {
        gain.set_gain(0.25f);
        REQUIRE_THAT(gain.get_gain_db(), WithinAbs(-12.04f, 0.1f));
    }
    
    SECTION("Zero gain returns very low dB") {
        gain.set_gain(0.0f);
        REQUIRE(gain.get_gain_db() <= -100.0f);
    }
    
    SECTION("Set gain from dB") {
        gain.set_gain_db(-6.0f);
        REQUIRE_THAT(gain.get_gain(), WithinRel(0.5f, 0.01f));
    }
}


// ============================================================================
// Parameter Interface Tests
// ============================================================================

TEST_CASE("GainEffect parameter interface", "[gain_effect][parameters]") {
    GainEffect gain(0.5f);
    
    SECTION("Has parameter") {
        REQUIRE(gain.has_parameter() == true);
    }
    
    SECTION("Get parameter percent") {
        REQUIRE(gain.get_parameter_percent() == 50);
        
        gain.set_gain(0.75f);
        REQUIRE(gain.get_parameter_percent() == 75);
        
        gain.set_gain(1.0f);
        REQUIRE(gain.get_parameter_percent() == 100);
    }
    
    SECTION("Adjust parameter up") {
        gain.adjust_parameter(1);  // +5%
        REQUIRE(gain.get_parameter_percent() == 55);
        
        gain.adjust_parameter(2);  // +10%
        REQUIRE(gain.get_parameter_percent() == 65);
    }
    
    SECTION("Adjust parameter down") {
        gain.adjust_parameter(-1);  // -5%
        REQUIRE(gain.get_parameter_percent() == 45);
        
        gain.adjust_parameter(-3);  // -15%
        REQUIRE(gain.get_parameter_percent() == 30);
    }
    
    SECTION("Parameter clamps at max") {
        gain.set_gain(0.95f);
        gain.adjust_parameter(5);  // Try +25%
        REQUIRE(gain.get_parameter_percent() == 100);
    }
    
    SECTION("Parameter clamps at min") {
        gain.set_gain(0.05f);
        gain.adjust_parameter(-5);  // Try -25%
        REQUIRE(gain.get_parameter_percent() == 0);
    }
    
    SECTION("Parameter string formatting") {
        char buffer[32];
        
        gain.set_gain(0.5f);
        gain.get_parameter_string(buffer, sizeof(buffer));
        REQUIRE(std::string(buffer) == " 50%");
        
        gain.set_gain(1.0f);
        gain.get_parameter_string(buffer, sizeof(buffer));
        REQUIRE(std::string(buffer) == "100%");
    }
}


// ============================================================================
// Audio Processing Tests
// ============================================================================

TEST_CASE("GainEffect audio processing", "[gain_effect][processing]") {
    SECTION("Unity gain is passthrough") {
        GainEffect gain(1.0f);
        
        int16_t samples[4] = {1000, 2000, 3000, 4000};
        int16_t original[4];
        std::memcpy(original, samples, sizeof(samples));
        
        gain.process(samples, 4);
        
        // Unity gain should not modify samples
        REQUIRE(samples[0] == original[0]);
        REQUIRE(samples[1] == original[1]);
        REQUIRE(samples[2] == original[2]);
        REQUIRE(samples[3] == original[3]);
    }
    
    SECTION("Half gain reduces amplitude") {
        GainEffect gain(0.5f);
        
        int16_t samples[4] = {10000, 20000, -10000, -20000};
        gain.process(samples, 4);
        
        // Q15 scaling: result = (sample * gain_q15) >> 15
        // With gain=0.5, gain_q15 = 16383
        // 10000 * 16383 / 32768 ≈ 5000
        REQUIRE(samples[0] > 4000);
        REQUIRE(samples[0] < 6000);
    }
    
    SECTION("Zero gain silences audio") {
        GainEffect gain(0.0f);
        
        int16_t samples[4] = {10000, 20000, 30000, 32767};
        gain.process(samples, 4);
        
        REQUIRE(samples[0] == 0);
        REQUIRE(samples[1] == 0);
        REQUIRE(samples[2] == 0);
        REQUIRE(samples[3] == 0);
    }
    
    SECTION("Disabled effect is passthrough") {
        GainEffect gain(0.5f);
        gain.set_enabled(false);
        
        int16_t samples[4] = {1000, 2000, 3000, 4000};
        int16_t original[4];
        std::memcpy(original, samples, sizeof(samples));
        
        gain.process(samples, 4);
        
        REQUIRE(samples[0] == original[0]);
        REQUIRE(samples[1] == original[1]);
    }
}

// ============================================================================
// Reset Tests
// ============================================================================

TEST_CASE("GainEffect reset", "[gain_effect][reset]") {
    GainEffect gain(0.75f);
    
    // Reset is a no-op for stateless effect
    gain.reset();
    
    // Gain should be unchanged
    REQUIRE_THAT(gain.get_gain(), WithinAbs(0.75f, 0.001f));
}

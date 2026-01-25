/**
 * @file test_audio_effect.cpp
 * @brief Unit tests for AudioEffect base class
 */

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <string>

#include "audio_effect.h"

using Catch::Matchers::WithinAbs;
using Catch::Matchers::WithinRel;

// ============================================================================
// Concrete Test Effect
// ============================================================================

class TestableEffect : public AudioEffect {
public:
    TestableEffect(std::string_view name = "Testable") 
        : AudioEffect(name)
        , process_count(0) {}
    
    void process(int16_t* samples, uint32_t num_samples) override {
        process_count++;
        // Simple passthrough
        (void)samples;
        (void)num_samples;
    }
    
    void reset() override {
        process_count = 0;
    }
    
    int process_count;
};

class ParameterizedEffect : public AudioEffect {
public:
    ParameterizedEffect() 
        : AudioEffect("Parameterized")
        , value_(50) {}
    
    void process(int16_t* samples, uint32_t num_samples) override {
        (void)samples;
        (void)num_samples;
    }
    
    bool has_parameter() const override { return true; }
    
    int get_parameter_percent() const override { return value_; }
    
    void get_parameter_string(char* buffer, uint32_t buffer_size) const override {
        if (buffer && buffer_size >= 8) {
            snprintf(buffer, buffer_size, "%d%%", value_);
        }
    }
    
    void adjust_parameter(int delta) override {
        value_ += delta * 5;
        if (value_ < 0) value_ = 0;
        if (value_ > 100) value_ = 100;
    }
    
private:
    int value_;
};

// ============================================================================
// Basic Properties Tests
// ============================================================================

TEST_CASE("AudioEffect basic properties", "[audio_effect][properties]") {
    TestableEffect effect("TestEffect");
    
    SECTION("Name is set correctly") {
        REQUIRE(effect.get_name() == "TestEffect");
    }
    
    SECTION("Enabled by default") {
        REQUIRE(effect.is_enabled() == true);
    }
    
    SECTION("Can be disabled") {
        effect.set_enabled(false);
        REQUIRE(effect.is_enabled() == false);
    }
    
    SECTION("Can be re-enabled") {
        effect.set_enabled(false);
        effect.set_enabled(true);
        REQUIRE(effect.is_enabled() == true);
    }
}

// ============================================================================
// CPU Profiling Tests
// ============================================================================

TEST_CASE("AudioEffect CPU profiling", "[audio_effect][profiling]") {
    TestableEffect effect;
    
    SECTION("Initial utilization is zero") {
        REQUIRE_THAT(effect.get_cpu_utilization(), WithinAbs(0.0f, 0.001f));
    }
    
    SECTION("Accumulates cycles") {
        effect.add_cycles(1000);
        effect.add_cycles(2000);
        effect.add_cycles(3000);
        
        // 6000 cycles total over 100ms at 480MHz
        // Available cycles = 480,000,000 * 0.1 = 48,000,000
        // Utilization = 6000 / 48,000,000 * 100 = 0.0125%
        effect.finalize_utilization(480000000, 100);
        
        REQUIRE_THAT(effect.get_cpu_utilization(), WithinAbs(0.0125f, 0.001f));
    }
    
    SECTION("Finalize resets accumulators") {
        effect.add_cycles(10000);
        effect.finalize_utilization(480000000, 100);
        
        float first_util = effect.get_cpu_utilization();
        REQUIRE(first_util > 0.0f);
        
        // Finalize again without adding cycles
        effect.finalize_utilization(480000000, 100);
        
        REQUIRE_THAT(effect.get_cpu_utilization(), WithinAbs(0.0f, 0.001f));
    }
    
    SECTION("Handles zero measurement period") {
        effect.add_cycles(1000);
        effect.finalize_utilization(480000000, 0);
        
        REQUIRE_THAT(effect.get_cpu_utilization(), WithinAbs(0.0f, 0.001f));
    }
    
    SECTION("Handles no calls") {
        // Don't add any cycles
        effect.finalize_utilization(480000000, 100);
        
        REQUIRE_THAT(effect.get_cpu_utilization(), WithinAbs(0.0f, 0.001f));
    }
    
    SECTION("Realistic DSP load calculation") {
        // Simulate 1ms of processing at 48kHz (48 samples)
        // If effect takes 100,000 cycles per call
        // And we call it 100 times in 100ms
        for (int i = 0; i < 100; i++) {
            effect.add_cycles(100000);
        }
        
        // 10,000,000 cycles over 100ms at 480MHz
        // Available = 48,000,000 cycles
        // Utilization = 10,000,000 / 48,000,000 * 100 = 20.83%
        effect.finalize_utilization(480000000, 100);
        
        REQUIRE_THAT(effect.get_cpu_utilization(), WithinRel(20.83f, 0.01f));
    }
}

// ============================================================================
// Parameter Interface Tests
// ============================================================================

TEST_CASE("AudioEffect parameter interface", "[audio_effect][parameters]") {
    SECTION("Base class has no parameter") {
        TestableEffect effect;
        REQUIRE(effect.has_parameter() == false);
        REQUIRE(effect.get_parameter_percent() == 0);
    }
    
    SECTION("Parameterized effect has parameter") {
        ParameterizedEffect effect;
        REQUIRE(effect.has_parameter() == true);
        REQUIRE(effect.get_parameter_percent() == 50);
    }
    
    SECTION("Parameter adjustment") {
        ParameterizedEffect effect;
        
        effect.adjust_parameter(1);  // +5
        REQUIRE(effect.get_parameter_percent() == 55);
        
        effect.adjust_parameter(-2);  // -10
        REQUIRE(effect.get_parameter_percent() == 45);
    }
    
    SECTION("Parameter clamping") {
        ParameterizedEffect effect;
        
        // Try to go above 100
        effect.adjust_parameter(20);  // +100
        REQUIRE(effect.get_parameter_percent() == 100);
        
        // Try to go below 0
        effect.adjust_parameter(-30);  // -150
        REQUIRE(effect.get_parameter_percent() == 0);
    }
    
    SECTION("Parameter string formatting") {
        ParameterizedEffect effect;
        char buffer[32];
        
        effect.get_parameter_string(buffer, sizeof(buffer));
        REQUIRE(std::string(buffer) == "50%");
        
        effect.adjust_parameter(2);  // 60%
        effect.get_parameter_string(buffer, sizeof(buffer));
        REQUIRE(std::string(buffer) == "60%");
    }
    
    SECTION("Base class parameter string is empty") {
        TestableEffect effect;
        char buffer[32] = "initial";
        
        effect.get_parameter_string(buffer, sizeof(buffer));
        REQUIRE(std::string(buffer) == "");
    }
    
    SECTION("Null buffer is safe") {
        ParameterizedEffect effect;
        effect.get_parameter_string(nullptr, 0);
        // Should not crash
    }
}

// ============================================================================
// Reset Tests
// ============================================================================

TEST_CASE("AudioEffect reset", "[audio_effect][reset]") {
    TestableEffect effect;
    
    // Process a few times
    int16_t samples[4] = {0};
    effect.process(samples, 4);
    effect.process(samples, 4);
    effect.process(samples, 4);
    
    REQUIRE(effect.process_count == 3);
    
    effect.reset();
    
    REQUIRE(effect.process_count == 0);
}

// ============================================================================
// Move Semantics Tests
// ============================================================================

TEST_CASE("AudioEffect move semantics", "[audio_effect][move]") {
    SECTION("Move construction") {
        TestableEffect original("Original");
        original.set_enabled(false);
        
        TestableEffect moved(std::move(original));
        
        REQUIRE(moved.get_name() == "Original");
        REQUIRE(moved.is_enabled() == false);
    }
    
    SECTION("Move assignment") {
        TestableEffect original("Original");
        TestableEffect target("Target");
        
        target = std::move(original);
        
        REQUIRE(target.get_name() == "Original");
    }
}

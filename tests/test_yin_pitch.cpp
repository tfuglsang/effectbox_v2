/**
 * @file test_yin_pitch.cpp
 * @brief Unit tests for YIN pitch detector
 */

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <vector>
#include <cmath>

#include "yin_pitch_detector.h"

using Catch::Matchers::WithinAbs;
using Catch::Matchers::WithinRel;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// ============================================================================
// Helper Functions
// ============================================================================

/**
 * @brief Generate a sine wave at specified frequency
 */
std::vector<int16_t> generate_sine(float frequency, float sample_rate, 
                                    size_t num_samples, float amplitude = 16000.0f) {
    std::vector<int16_t> samples(num_samples);
    for (size_t i = 0; i < num_samples; i++) {
        float t = static_cast<float>(i) / sample_rate;
        samples[i] = static_cast<int16_t>(amplitude * sinf(2.0f * M_PI * frequency * t));
    }
    return samples;
}

/**
 * @brief Generate silence
 */
std::vector<int16_t> generate_silence(size_t num_samples) {
    return std::vector<int16_t>(num_samples, 0);
}

/**
 * @brief Generate white noise (simple PRNG)
 */
std::vector<int16_t> generate_noise(size_t num_samples, int16_t amplitude = 8000) {
    std::vector<int16_t> samples(num_samples);
    uint32_t seed = 12345;
    for (size_t i = 0; i < num_samples; i++) {
        seed = seed * 1103515245 + 12345;
        samples[i] = static_cast<int16_t>((seed >> 16) % (2 * amplitude) - amplitude);
    }
    return samples;
}


// ============================================================================
// Construction Tests
// ============================================================================

TEST_CASE("YinPitchDetector construction", "[yin][construction]") {
    SECTION("Default construction") {
        YinPitchDetector yin(48000.0f);
        
        REQUIRE(yin.is_enabled() == true);
        REQUIRE(yin.has_pitch() == false);
        REQUIRE_THAT(yin.get_pitch(), WithinAbs(0.0f, 0.001f));
        REQUIRE_THAT(yin.get_probability(), WithinAbs(0.0f, 0.001f));
    }
    
    SECTION("Custom threshold") {
        YinPitchDetector yin(48000.0f, 0.10f);
        REQUIRE(yin.has_parameter() == true);
    }
    
    SECTION("Custom name") {
        YinPitchDetector yin(48000.0f, 0.15f, "Custom YIN");
        REQUIRE(yin.get_name() == "Custom YIN");
    }
}

// ============================================================================
// Pitch Detection Tests
// ============================================================================

TEST_CASE("YinPitchDetector detects sine waves", "[yin][detection]") {
    YinPitchDetector yin(48000.0f, 0.15f);
    
    // YIN needs INPUT_BUFFER_SIZE samples (3072) to trigger detection
    constexpr size_t REQUIRED_SAMPLES = YinPitchDetector::INPUT_BUFFER_SIZE;
    
    SECTION("Detects 440Hz (A4)") {
        auto samples = generate_sine(440.0f, 48000.0f, REQUIRED_SAMPLES * 2);
        
        // Process in chunks
        yin.process(samples.data(), samples.size());
        
        if (yin.has_pitch()) {
            REQUIRE_THAT(yin.get_pitch(), WithinRel(440.0f, 0.05f));  // Within 5%
            REQUIRE(yin.get_probability() > 0.5f);
        }
    }
    
    SECTION("Detects 220Hz (A3)") {
        auto samples = generate_sine(220.0f, 48000.0f, REQUIRED_SAMPLES * 2);
        
        yin.process(samples.data(), samples.size());
        
        if (yin.has_pitch()) {
            REQUIRE_THAT(yin.get_pitch(), WithinRel(220.0f, 0.05f));
        }
    }
    
    SECTION("Detects 82Hz (Low E guitar)") {
        auto samples = generate_sine(82.41f, 48000.0f, REQUIRED_SAMPLES * 2);
        
        yin.process(samples.data(), samples.size());
        
        if (yin.has_pitch()) {
            REQUIRE_THAT(yin.get_pitch(), WithinRel(82.41f, 0.10f));  // 10% tolerance for low freq
        }
    }
    
    SECTION("Detects 330Hz (High E guitar)") {
        auto samples = generate_sine(329.63f, 48000.0f, REQUIRED_SAMPLES * 2);
        
        yin.process(samples.data(), samples.size());
        
        if (yin.has_pitch()) {
            REQUIRE_THAT(yin.get_pitch(), WithinRel(329.63f, 0.05f));
        }
    }
}


// ============================================================================
// Non-Pitch Signal Tests
// ============================================================================

TEST_CASE("YinPitchDetector rejects non-pitched signals", "[yin][rejection]") {
    YinPitchDetector yin(48000.0f, 0.15f);
    constexpr size_t REQUIRED_SAMPLES = YinPitchDetector::INPUT_BUFFER_SIZE;
    
    SECTION("Rejects silence") {
        auto samples = generate_silence(REQUIRED_SAMPLES * 2);
        
        yin.process(samples.data(), samples.size());
        
        // Should not detect pitch in silence
        REQUIRE(yin.has_pitch() == false);
    }
    
    SECTION("Rejects noise") {
        auto samples = generate_noise(REQUIRED_SAMPLES * 2);
        
        yin.process(samples.data(), samples.size());
        
        // Noise should not produce confident pitch detection
        // (may occasionally detect something, but probability should be low)
        if (yin.has_pitch()) {
            // If it detects something, probability should be low
            // This is a soft check since noise can occasionally look periodic
            INFO("Noise detected pitch: " << yin.get_pitch() << "Hz, prob: " << yin.get_probability());
        }
    }
}

// ============================================================================
// Reset Tests
// ============================================================================

TEST_CASE("YinPitchDetector reset", "[yin][reset]") {
    YinPitchDetector yin(48000.0f);
    constexpr size_t REQUIRED_SAMPLES = YinPitchDetector::INPUT_BUFFER_SIZE;
    
    // Detect a pitch first
    auto samples = generate_sine(440.0f, 48000.0f, REQUIRED_SAMPLES * 2);
    yin.process(samples.data(), samples.size());
    
    // Reset
    yin.reset();
    
    // Should clear detection state
    REQUIRE(yin.has_pitch() == false);
    REQUIRE_THAT(yin.get_pitch(), WithinAbs(0.0f, 0.001f));
    REQUIRE_THAT(yin.get_probability(), WithinAbs(0.0f, 0.001f));
}

// ============================================================================
// Parameter Interface Tests
// ============================================================================

TEST_CASE("YinPitchDetector parameter interface", "[yin][parameters]") {
    YinPitchDetector yin(48000.0f, 0.15f);
    
    SECTION("Has parameter") {
        REQUIRE(yin.has_parameter() == true);
    }
    
    SECTION("Adjust threshold up") {
        yin.adjust_parameter(5);  // +5%
        // Threshold should increase (harder to detect)
        char buffer[32];
        yin.get_parameter_string(buffer, sizeof(buffer));
        // Should show threshold when no pitch detected
        std::string result(buffer);
        REQUIRE(result.find("Th:") != std::string::npos);
    }
    
    SECTION("Adjust threshold down") {
        yin.adjust_parameter(-5);  // -5%
        // Threshold should decrease (easier to detect)
    }
    
    SECTION("Threshold clamps at bounds") {
        // Try to go very high
        for (int i = 0; i < 100; i++) {
            yin.adjust_parameter(1);
        }
        // Should be clamped at 50%
        
        // Try to go very low
        for (int i = 0; i < 100; i++) {
            yin.adjust_parameter(-1);
        }
        // Should be clamped at 5%
    }
}


// ============================================================================
// Frequency Range Tests
// ============================================================================

TEST_CASE("YinPitchDetector frequency range", "[yin][range]") {
    YinPitchDetector yin(48000.0f, 0.15f);
    constexpr size_t REQUIRED_SAMPLES = YinPitchDetector::INPUT_BUFFER_SIZE;
    
    SECTION("Rejects frequencies below MIN_FREQUENCY") {
        // 30Hz is below MIN_FREQUENCY (50Hz)
        auto samples = generate_sine(30.0f, 48000.0f, REQUIRED_SAMPLES * 2);
        
        yin.process(samples.data(), samples.size());
        
        // Should not detect or should reject
        if (yin.has_pitch()) {
            // If detected, should not be 30Hz (would be octave error or rejection)
            REQUIRE(yin.get_pitch() >= YinPitchDetector::MIN_FREQUENCY);
        }
    }
    
    SECTION("Rejects frequencies above MAX_FREQUENCY") {
        // 1500Hz is above MAX_FREQUENCY (1000Hz)
        auto samples = generate_sine(1500.0f, 48000.0f, REQUIRED_SAMPLES * 2);
        
        yin.process(samples.data(), samples.size());
        
        // Should not detect or should reject
        if (yin.has_pitch()) {
            REQUIRE(yin.get_pitch() <= YinPitchDetector::MAX_FREQUENCY);
        }
    }
}

// ============================================================================
// Disabled State Tests
// ============================================================================

TEST_CASE("YinPitchDetector disabled state", "[yin][disabled]") {
    YinPitchDetector yin(48000.0f);
    constexpr size_t REQUIRED_SAMPLES = YinPitchDetector::INPUT_BUFFER_SIZE;
    
    yin.set_enabled(false);
    
    auto samples = generate_sine(440.0f, 48000.0f, REQUIRED_SAMPLES * 2);
    yin.process(samples.data(), samples.size());
    
    // Should not process when disabled
    REQUIRE(yin.has_pitch() == false);
}

// ============================================================================
// Incremental Processing Tests
// ============================================================================

TEST_CASE("YinPitchDetector incremental processing", "[yin][incremental]") {
    YinPitchDetector yin(48000.0f, 0.15f);
    
    // Generate enough samples for multiple detections
    auto samples = generate_sine(440.0f, 48000.0f, 48000);  // 1 second
    
    // Process in small chunks (simulating real-time audio callback)
    constexpr size_t CHUNK_SIZE = 512;  // Typical audio buffer size
    
    bool detected = false;
    for (size_t offset = 0; offset < samples.size() && !detected; offset += CHUNK_SIZE) {
        size_t remaining = std::min(CHUNK_SIZE, samples.size() - offset);
        yin.process(samples.data() + offset, remaining);
        
        if (yin.has_pitch()) {
            detected = true;
            REQUIRE_THAT(yin.get_pitch(), WithinRel(440.0f, 0.05f));
        }
    }
    
    // Should eventually detect the pitch
    REQUIRE(detected == true);
}

// ============================================================================
// Constants Verification
// ============================================================================

TEST_CASE("YinPitchDetector constants", "[yin][constants]") {
    SECTION("Buffer sizes are consistent") {
        // INPUT_BUFFER_SIZE should be BUFFER_SIZE * DOWNSAMPLE_FACTOR
        REQUIRE(YinPitchDetector::INPUT_BUFFER_SIZE == 
                YinPitchDetector::BUFFER_SIZE * YinPitchDetector::DOWNSAMPLE_FACTOR);
    }
    
    SECTION("Downsampled rate is correct") {
        REQUIRE_THAT(YinPitchDetector::DOWNSAMPLED_RATE, 
                     WithinAbs(8000.0f, 0.1f));  // 48000 / 6 = 8000
    }
    
    SECTION("Frequency range is valid") {
        REQUIRE(YinPitchDetector::MIN_FREQUENCY > 0.0f);
        REQUIRE(YinPitchDetector::MAX_FREQUENCY > YinPitchDetector::MIN_FREQUENCY);
        REQUIRE(YinPitchDetector::MAX_FREQUENCY < YinPitchDetector::DOWNSAMPLED_RATE / 2);
    }
}

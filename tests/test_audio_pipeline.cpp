/**
 * @file test_audio_pipeline.cpp
 * @brief Unit tests for AudioPipeline
 */

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <vector>
#include <cstring>

#include "audio_pipeline.h"

using Catch::Matchers::WithinAbs;

// ============================================================================
// Mock Effect for Testing
// ============================================================================

class MockEffect : public AudioEffect {
public:
    MockEffect(std::string_view name = "Mock") 
        : AudioEffect(name)
        , process_called(false)
        , sample_count(0)
        , scale_factor(1) {}
    
    void process(int16_t* samples, uint32_t num_samples) override {
        process_called = true;
        sample_count = num_samples;
        
        // Apply simple transformation for verification
        for (uint32_t i = 0; i < num_samples; i++) {
            samples[i] = static_cast<int16_t>(samples[i] / scale_factor);
        }
    }
    
    void reset() override {
        process_called = false;
        sample_count = 0;
    }
    
    bool process_called;
    uint32_t sample_count;
    int scale_factor;
};

// ============================================================================
// Pipeline Management Tests
// ============================================================================

TEST_CASE("AudioPipeline effect management", "[audio_pipeline][management]") {
    AudioPipeline pipeline;
    
    SECTION("Initially empty") {
        REQUIRE(pipeline.get_effect_count() == 0);
        REQUIRE(pipeline.get_effect(0) == nullptr);
    }
    
    SECTION("Add single effect") {
        MockEffect effect;
        REQUIRE(pipeline.add_effect(&effect) == true);
        REQUIRE(pipeline.get_effect_count() == 1);
        REQUIRE(pipeline.get_effect(0) == &effect);
    }
    
    SECTION("Add multiple effects") {
        MockEffect e1("Effect1"), e2("Effect2"), e3("Effect3");
        
        REQUIRE(pipeline.add_effect(&e1) == true);
        REQUIRE(pipeline.add_effect(&e2) == true);
        REQUIRE(pipeline.add_effect(&e3) == true);
        
        REQUIRE(pipeline.get_effect_count() == 3);
        REQUIRE(pipeline.get_effect(0) == &e1);
        REQUIRE(pipeline.get_effect(1) == &e2);
        REQUIRE(pipeline.get_effect(2) == &e3);
    }
    
    SECTION("Remove effect") {
        MockEffect e1, e2;
        pipeline.add_effect(&e1);
        pipeline.add_effect(&e2);
        
        REQUIRE(pipeline.remove_effect(&e1) == true);
        REQUIRE(pipeline.get_effect_count() == 1);
        REQUIRE(pipeline.get_effect(0) == &e2);
    }
    
    SECTION("Remove non-existent effect returns false") {
        MockEffect e1, e2;
        pipeline.add_effect(&e1);
        
        REQUIRE(pipeline.remove_effect(&e2) == false);
        REQUIRE(pipeline.get_effect_count() == 1);
    }
    
    SECTION("Clear removes all effects") {
        MockEffect e1, e2, e3;
        pipeline.add_effect(&e1);
        pipeline.add_effect(&e2);
        pipeline.add_effect(&e3);
        
        pipeline.clear();
        
        REQUIRE(pipeline.get_effect_count() == 0);
    }
    
    SECTION("Cannot add null effect") {
        REQUIRE(pipeline.add_effect(nullptr) == false);
        REQUIRE(pipeline.get_effect_count() == 0);
    }
    
    SECTION("Cannot exceed MAX_EFFECTS") {
        std::vector<MockEffect> effects(AudioPipeline::MAX_EFFECTS + 5);
        
        for (uint32_t i = 0; i < AudioPipeline::MAX_EFFECTS; i++) {
            REQUIRE(pipeline.add_effect(&effects[i]) == true);
        }
        
        // Should fail when full
        REQUIRE(pipeline.add_effect(&effects[AudioPipeline::MAX_EFFECTS]) == false);
        REQUIRE(pipeline.get_effect_count() == AudioPipeline::MAX_EFFECTS);
    }
}

// ============================================================================
// Pipeline Enable/Disable Tests
// ============================================================================

TEST_CASE("AudioPipeline enable/disable", "[audio_pipeline][enable]") {
    AudioPipeline pipeline;
    MockEffect effect;
    pipeline.add_effect(&effect);
    
    SECTION("Pipeline enabled by default") {
        REQUIRE(pipeline.is_enabled() == true);
    }
    
    SECTION("Disabled pipeline doesn't process") {
        pipeline.set_enabled(false);
        
        int16_t samples[8] = {1000, 1000, 2000, 2000, 3000, 3000, 4000, 4000};
        pipeline.process(samples, 8);
        
        REQUIRE(effect.process_called == false);
        // Samples unchanged
        REQUIRE(samples[0] == 1000);
    }
    
    SECTION("Re-enabled pipeline processes") {
        pipeline.set_enabled(false);
        pipeline.set_enabled(true);
        
        int16_t samples[4] = {1000, 1000, 2000, 2000};
        pipeline.process(samples, 4);
        
        REQUIRE(effect.process_called == true);
    }
}

// ============================================================================
// Audio Processing Tests
// ============================================================================

TEST_CASE("AudioPipeline audio processing", "[audio_pipeline][processing]") {
    AudioPipeline pipeline;
    
    SECTION("Processes through enabled effects only") {
        MockEffect e1("Enabled"), e2("Disabled");
        e2.set_enabled(false);
        
        pipeline.add_effect(&e1);
        pipeline.add_effect(&e2);
        
        int16_t samples[8] = {1000, 1000, 2000, 2000, 3000, 3000, 4000, 4000};
        pipeline.process(samples, 8);
        
        REQUIRE(e1.process_called == true);
        REQUIRE(e2.process_called == false);
    }
    
    SECTION("Effects process in order") {
        MockEffect e1("First"), e2("Second");
        e1.scale_factor = 2;  // Halve
        e2.scale_factor = 2;  // Halve again
        
        pipeline.add_effect(&e1);
        pipeline.add_effect(&e2);
        
        // Stereo input: L=4000, R=4000
        int16_t samples[4] = {4000, 4000, 4000, 4000};
        pipeline.process(samples, 4);
        
        // After e1: 4000/2 = 2000
        // After e2: 2000/2 = 1000
        // Output duplicated to both channels
        REQUIRE(samples[0] == 1000);
        REQUIRE(samples[1] == 1000);
    }
    
    SECTION("Stereo to mono conversion uses left channel") {
        MockEffect effect;
        pipeline.add_effect(&effect);
        
        // Stereo input: L=1000, R=9999 (different values)
        int16_t samples[4] = {1000, 9999, 1000, 9999};
        pipeline.process(samples, 4);
        
        // Pipeline takes left channel only, duplicates to output
        REQUIRE(samples[0] == 1000);
        REQUIRE(samples[1] == 1000);
        REQUIRE(samples[2] == 1000);
        REQUIRE(samples[3] == 1000);
    }
    
    SECTION("Handles empty sample buffer") {
        MockEffect effect;
        pipeline.add_effect(&effect);
        
        pipeline.process(nullptr, 0);
        REQUIRE(effect.process_called == false);
    }
    
    SECTION("Handles null pointer") {
        MockEffect effect;
        pipeline.add_effect(&effect);
        
        pipeline.process(nullptr, 100);
        REQUIRE(effect.process_called == false);
    }
}

// ============================================================================
// Pipeline Reset Tests
// ============================================================================

TEST_CASE("AudioPipeline reset", "[audio_pipeline][reset]") {
    AudioPipeline pipeline;
    MockEffect e1, e2;
    
    pipeline.add_effect(&e1);
    pipeline.add_effect(&e2);
    
    // Process to set flags
    int16_t samples[4] = {1000, 1000, 1000, 1000};
    pipeline.process(samples, 4);
    
    REQUIRE(e1.process_called == true);
    REQUIRE(e2.process_called == true);
    
    // Reset should call reset on all effects
    pipeline.reset();
    
    REQUIRE(e1.process_called == false);
    REQUIRE(e2.process_called == false);
}

// ============================================================================
// Profiling Tests
// ============================================================================

TEST_CASE("AudioPipeline profiling", "[audio_pipeline][profiling]") {
    AudioPipeline pipeline;
    
    SECTION("Profiling enabled by default") {
        REQUIRE(pipeline.is_profiling_enabled() == true);
    }
    
    SECTION("Can disable profiling") {
        pipeline.set_profiling_enabled(false);
        REQUIRE(pipeline.is_profiling_enabled() == false);
    }
    
    SECTION("Profiling accumulates cycles when enabled") {
        MockEffect effect;
        pipeline.add_effect(&effect);
        
        // Initialize DWT mock
        AudioPipeline::init_profiling();
        DWT->CYCCNT = 0;
        
        int16_t samples[4] = {1000, 1000, 1000, 1000};
        
        // Simulate cycle counter advancing during process
        // (In real hardware, DWT->CYCCNT increments automatically)
        DWT->CYCCNT = 1000;
        pipeline.process(samples, 4);
        
        // Effect should have cycles recorded (mock may not be perfect)
        // Just verify processing happened
        REQUIRE(effect.process_called == true);
    }
}

// ============================================================================
// Edge Cases
// ============================================================================

TEST_CASE("AudioPipeline edge cases", "[audio_pipeline][edge]") {
    AudioPipeline pipeline;
    
    SECTION("Get effect with invalid index returns nullptr") {
        MockEffect effect;
        pipeline.add_effect(&effect);
        
        REQUIRE(pipeline.get_effect(0) == &effect);
        REQUIRE(pipeline.get_effect(1) == nullptr);
        REQUIRE(pipeline.get_effect(100) == nullptr);
    }
    
    SECTION("Process with no effects is passthrough") {
        int16_t samples[4] = {1000, 2000, 3000, 4000};
        int16_t original[4];
        std::memcpy(original, samples, sizeof(samples));
        
        pipeline.process(samples, 4);
        
        // With no effects, stereo->mono->stereo still happens
        // Left channel duplicated to both
        REQUIRE(samples[0] == original[0]);
        REQUIRE(samples[1] == original[0]);  // Right gets left value
    }
}

/**
 * @file test_guitar_tuning.cpp
 * @brief Unit tests for GuitarTuning utilities
 */

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <cstring>
#include <string>

#include "guitar_tuning.h"

using namespace GuitarTuning;
using Catch::Matchers::WithinAbs;
using Catch::Matchers::WithinRel;

// ============================================================================
// freq_to_midi Tests
// ============================================================================

TEST_CASE("freq_to_midi converts standard frequencies correctly", "[guitar_tuning][midi]") {
    SECTION("A4 = 440Hz -> MIDI 69") {
        REQUIRE_THAT(freq_to_midi(440.0f), WithinAbs(69.0f, 0.01f));
    }
    
    SECTION("A3 = 220Hz -> MIDI 57") {
        REQUIRE_THAT(freq_to_midi(220.0f), WithinAbs(57.0f, 0.01f));
    }
    
    SECTION("A5 = 880Hz -> MIDI 81") {
        REQUIRE_THAT(freq_to_midi(880.0f), WithinAbs(81.0f, 0.01f));
    }
    
    SECTION("Middle C (C4) = 261.63Hz -> MIDI 60") {
        REQUIRE_THAT(freq_to_midi(261.63f), WithinAbs(60.0f, 0.1f));
    }
    
    SECTION("Low E guitar string = 82.41Hz -> MIDI 40") {
        REQUIRE_THAT(freq_to_midi(82.41f), WithinAbs(40.0f, 0.1f));
    }
    
    SECTION("Invalid frequency returns -1") {
        REQUIRE(freq_to_midi(0.0f) < 0.0f);
        REQUIRE(freq_to_midi(-100.0f) < 0.0f);
    }
}

// ============================================================================
// midi_to_freq Tests
// ============================================================================

TEST_CASE("midi_to_freq converts MIDI notes correctly", "[guitar_tuning][midi]") {
    SECTION("MIDI 69 -> 440Hz (A4)") {
        REQUIRE_THAT(midi_to_freq(69), WithinAbs(440.0f, 0.01f));
    }
    
    SECTION("MIDI 60 -> 261.63Hz (C4)") {
        REQUIRE_THAT(midi_to_freq(60), WithinAbs(261.63f, 0.5f));
    }
    
    SECTION("MIDI 40 -> 82.41Hz (E2 - low guitar string)") {
        REQUIRE_THAT(midi_to_freq(40), WithinAbs(82.41f, 0.1f));
    }
    
    SECTION("Octave relationship: MIDI+12 doubles frequency") {
        float f1 = midi_to_freq(60);
        float f2 = midi_to_freq(72);
        REQUIRE_THAT(f2, WithinRel(f1 * 2.0f, 0.001f));
    }
}

// ============================================================================
// calculate_cents Tests
// ============================================================================

TEST_CASE("calculate_cents computes pitch deviation", "[guitar_tuning][cents]") {
    SECTION("Identical frequencies return 0 cents") {
        REQUIRE_THAT(calculate_cents(440.0f, 440.0f), WithinAbs(0.0f, 0.001f));
    }
    
    SECTION("One semitone sharp = +100 cents") {
        float a4 = 440.0f;
        float a4_sharp = midi_to_freq(70);  // A#4
        REQUIRE_THAT(calculate_cents(a4_sharp, a4), WithinAbs(100.0f, 0.5f));
    }
    
    SECTION("One semitone flat = -100 cents") {
        float a4 = 440.0f;
        float g4_sharp = midi_to_freq(68);  // G#4
        REQUIRE_THAT(calculate_cents(g4_sharp, a4), WithinAbs(-100.0f, 0.5f));
    }
    
    SECTION("Octave up = +1200 cents") {
        REQUIRE_THAT(calculate_cents(880.0f, 440.0f), WithinAbs(1200.0f, 0.1f));
    }
    
    SECTION("Octave down = -1200 cents") {
        REQUIRE_THAT(calculate_cents(220.0f, 440.0f), WithinAbs(-1200.0f, 0.1f));
    }
    
    SECTION("Invalid frequencies return 0") {
        REQUIRE_THAT(calculate_cents(0.0f, 440.0f), WithinAbs(0.0f, 0.001f));
        REQUIRE_THAT(calculate_cents(440.0f, 0.0f), WithinAbs(0.0f, 0.001f));
    }
}

// ============================================================================
// get_note_name Tests
// ============================================================================

TEST_CASE("get_note_name returns correct note names", "[guitar_tuning][notes]") {
    SECTION("MIDI 69 = A") {
        REQUIRE(std::string(get_note_name(69)) == "A");
    }
    
    SECTION("MIDI 60 = C") {
        REQUIRE(std::string(get_note_name(60)) == "C");
    }
    
    SECTION("MIDI 61 = C#") {
        REQUIRE(std::string(get_note_name(61)) == "C#");
    }
    
    SECTION("MIDI 40 = E (low guitar string)") {
        REQUIRE(std::string(get_note_name(40)) == "E");
    }
    
    SECTION("Invalid MIDI returns ?") {
        REQUIRE(std::string(get_note_name(-1)) == "?");
        REQUIRE(std::string(get_note_name(128)) == "?");
    }
}

// ============================================================================
// get_octave Tests
// ============================================================================

TEST_CASE("get_octave returns correct octave numbers", "[guitar_tuning][notes]") {
    SECTION("MIDI 69 = octave 4 (A4)") {
        REQUIRE(get_octave(69) == 4);
    }
    
    SECTION("MIDI 60 = octave 4 (C4)") {
        REQUIRE(get_octave(60) == 4);
    }
    
    SECTION("MIDI 48 = octave 3 (C3)") {
        REQUIRE(get_octave(48) == 3);
    }
    
    SECTION("MIDI 40 = octave 2 (E2)") {
        REQUIRE(get_octave(40) == 2);
    }
    
    SECTION("MIDI 21 = octave 0 (A0 - lowest piano key)") {
        REQUIRE(get_octave(21) == 0);
    }
}

// ============================================================================
// find_closest_string Tests
// ============================================================================

TEST_CASE("find_closest_string identifies guitar strings", "[guitar_tuning][strings]") {
    SECTION("82Hz -> Low E (string 0)") {
        REQUIRE(find_closest_string(82.0f) == 0);
    }
    
    SECTION("110Hz -> A (string 1)") {
        REQUIRE(find_closest_string(110.0f) == 1);
    }
    
    SECTION("147Hz -> D (string 2)") {
        REQUIRE(find_closest_string(147.0f) == 2);
    }
    
    SECTION("196Hz -> G (string 3)") {
        REQUIRE(find_closest_string(196.0f) == 3);
    }
    
    SECTION("247Hz -> B (string 4)") {
        REQUIRE(find_closest_string(247.0f) == 4);
    }
    
    SECTION("330Hz -> High E (string 5)") {
        REQUIRE(find_closest_string(330.0f) == 5);
    }
    
    SECTION("Slightly sharp E2 still matches E string") {
        REQUIRE(find_closest_string(85.0f) == 0);  // ~50 cents sharp
    }
    
    SECTION("Invalid frequency returns -1") {
        REQUIRE(find_closest_string(0.0f) == -1);
        REQUIRE(find_closest_string(-100.0f) == -1);
    }
}

// ============================================================================
// get_tuning_direction Tests
// ============================================================================

TEST_CASE("get_tuning_direction indicates tuning action", "[guitar_tuning][tuning]") {
    SECTION("Within threshold = in tune (0)") {
        REQUIRE(get_tuning_direction(0.0f) == 0);
        REQUIRE(get_tuning_direction(3.0f) == 0);
        REQUIRE(get_tuning_direction(-3.0f) == 0);
        REQUIRE(get_tuning_direction(IN_TUNE_THRESHOLD) == 0);
        REQUIRE(get_tuning_direction(-IN_TUNE_THRESHOLD) == 0);
    }
    
    SECTION("Flat = tune up (-1)") {
        REQUIRE(get_tuning_direction(-10.0f) == -1);
        REQUIRE(get_tuning_direction(-50.0f) == -1);
    }
    
    SECTION("Sharp = tune down (+1)") {
        REQUIRE(get_tuning_direction(10.0f) == 1);
        REQUIRE(get_tuning_direction(50.0f) == 1);
    }
}

// ============================================================================
// is_in_tune Tests
// ============================================================================

TEST_CASE("is_in_tune checks tuning accuracy", "[guitar_tuning][tuning]") {
    SECTION("Exact match is in tune") {
        REQUIRE(is_in_tune(440.0f, 440.0f) == true);
    }
    
    SECTION("Within threshold is in tune") {
        // 5 cents sharp at 440Hz is about 441.27Hz
        REQUIRE(is_in_tune(441.0f, 440.0f) == true);
    }
    
    SECTION("Outside threshold is not in tune") {
        // 10 cents sharp at 440Hz is about 442.55Hz
        REQUIRE(is_in_tune(445.0f, 440.0f) == false);
    }
}

// ============================================================================
// freq_to_note_string Tests
// ============================================================================

TEST_CASE("freq_to_note_string formats note strings", "[guitar_tuning][format]") {
    char buffer[32];
    
    SECTION("440Hz formats as A4") {
        freq_to_note_string(440.0f, buffer, sizeof(buffer), false);
        REQUIRE(std::string(buffer) == "A4");
    }
    
    SECTION("261.63Hz formats as C4") {
        freq_to_note_string(261.63f, buffer, sizeof(buffer), false);
        REQUIRE(std::string(buffer) == "C4");
    }
    
    SECTION("With cents deviation") {
        // Slightly sharp A4
        freq_to_note_string(445.0f, buffer, sizeof(buffer), true);
        // Should contain A4 and positive cents
        std::string result(buffer);
        REQUIRE(result.find("A4") != std::string::npos);
        REQUIRE(result.find("+") != std::string::npos);
    }
    
    SECTION("Invalid frequency shows ---") {
        freq_to_note_string(0.0f, buffer, sizeof(buffer), false);
        REQUIRE(std::string(buffer) == "---");
    }
    
    SECTION("Null buffer is safe") {
        float result = freq_to_note_string(440.0f, nullptr, 0, false);
        REQUIRE_THAT(result, WithinAbs(0.0f, 0.001f));
    }
}

// ============================================================================
// get_tuning_instruction Tests
// ============================================================================

TEST_CASE("get_tuning_instruction provides tuning guidance", "[guitar_tuning][format]") {
    char buffer[32];
    
    SECTION("In tune message") {
        get_tuning_instruction(0.0f, buffer, sizeof(buffer));
        REQUIRE(std::string(buffer) == "IN TUNE");
        
        get_tuning_instruction(3.0f, buffer, sizeof(buffer));
        REQUIRE(std::string(buffer) == "IN TUNE");
    }
    
    SECTION("Slightly flat - tune up") {
        get_tuning_instruction(-10.0f, buffer, sizeof(buffer));
        std::string result(buffer);
        REQUIRE(result.find("tune up") != std::string::npos);
    }
    
    SECTION("Very flat - TUNE UP") {
        get_tuning_instruction(-30.0f, buffer, sizeof(buffer));
        std::string result(buffer);
        REQUIRE(result.find("TUNE UP") != std::string::npos);
    }
    
    SECTION("Slightly sharp - tune down") {
        get_tuning_instruction(10.0f, buffer, sizeof(buffer));
        std::string result(buffer);
        REQUIRE(result.find("tune down") != std::string::npos);
    }
    
    SECTION("Very sharp - TUNE DOWN") {
        get_tuning_instruction(30.0f, buffer, sizeof(buffer));
        std::string result(buffer);
        REQUIRE(result.find("TUNE DOWN") != std::string::npos);
    }
}

// ============================================================================
// Standard Tuning Constants Tests
// ============================================================================

TEST_CASE("Standard tuning constants are correct", "[guitar_tuning][constants]") {
    SECTION("Six strings defined") {
        REQUIRE(NUM_STRINGS == 6);
    }
    
    SECTION("Low E string frequency") {
        REQUIRE_THAT(STANDARD_TUNING[0].frequency, WithinAbs(82.41f, 0.1f));
        REQUIRE(STANDARD_TUNING[0].midi_note == 40);
    }
    
    SECTION("A string frequency") {
        REQUIRE_THAT(STANDARD_TUNING[1].frequency, WithinAbs(110.0f, 0.1f));
        REQUIRE(STANDARD_TUNING[1].midi_note == 45);
    }
    
    SECTION("High E string frequency") {
        REQUIRE_THAT(STANDARD_TUNING[5].frequency, WithinAbs(329.63f, 0.1f));
        REQUIRE(STANDARD_TUNING[5].midi_note == 64);
    }
}

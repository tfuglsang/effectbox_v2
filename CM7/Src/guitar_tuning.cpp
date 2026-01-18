/**
 * @file guitar_tuning.cpp
 * @brief Guitar tuning utilities implementation
 * @author Thomas Fuglsang <tfuglsang@gmail.com>
 */

#include "guitar_tuning.h"
#include <cstdio>
#include <cstring>

namespace GuitarTuning {

float freq_to_note_string(float freq, char* buffer, uint32_t size, bool include_cents) {
    if (buffer == nullptr || size == 0) return 0.0f;
    
    if (freq <= 0.0f) {
        snprintf(buffer, size, "---");
        return 0.0f;
    }
    
    // Calculate MIDI note and cents
    float midi_note_f = freq_to_midi(freq);
    int midi_note = static_cast<int>(midi_note_f + 0.5f);  // Round to nearest
    
    if (midi_note < 0 || midi_note > 127) {
        snprintf(buffer, size, "---");
        return 0.0f;
    }
    
    // Get note name and octave
    const char* note_name = get_note_name(midi_note);
    int octave = get_octave(midi_note);
    
    // Calculate cents deviation from perfect pitch
    float perfect_freq = midi_to_freq(midi_note);
    float cents = calculate_cents(freq, perfect_freq);
    int cents_int = static_cast<int>(cents);
    
    // Format output
    if (include_cents && cents_int != 0) {
        snprintf(buffer, size, "%s%d %+dc", note_name, octave, cents_int);
    } else {
        snprintf(buffer, size, "%s%d", note_name, octave);
    }
    
    return cents;
}

void get_tuning_instruction(float cents, char* buffer, uint32_t size) {
    if (buffer == nullptr || size == 0) return;
    
    int direction = get_tuning_direction(cents);
    float abs_cents = (cents < 0.0f) ? -cents : cents;
    
    if (direction == 0) {
        snprintf(buffer, size, "IN TUNE");
    } else if (direction < 0) {
        // Flat - need to tune up
        if (abs_cents > CLOSE_THRESHOLD) {
            snprintf(buffer, size, "TUNE UP <<<");
        } else {
            snprintf(buffer, size, "tune up <");
        }
    } else {
        // Sharp - need to tune down
        if (abs_cents > CLOSE_THRESHOLD) {
            snprintf(buffer, size, ">>> TUNE DOWN");
        } else {
            snprintf(buffer, size, "> tune down");
        }
    }
}

} // namespace GuitarTuning

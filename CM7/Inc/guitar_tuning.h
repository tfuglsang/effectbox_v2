/**
 * @file guitar_tuning.h
 * @brief Guitar tuning constants and pitch calculation utilities
 * @author Thomas Fuglsang <tfuglsang@gmail.com>
 * 
 * Provides standard guitar tuning frequencies, note names,
 * and functions for pitch detection and tuner displays.
 */

#ifndef GUITAR_TUNING_H
#define GUITAR_TUNING_H

#include <cstdint>
#include <cmath>

namespace GuitarTuning {

// ============================================================================
// Constants
// ============================================================================

/** Note names for chromatic scale (C = 0, C# = 1, ... B = 11) */
constexpr const char* NOTE_NAMES[] = {
    "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"
};
constexpr int NUM_NOTES = 12;

/** Reference pitch: A4 = 440 Hz (MIDI note 69) */
constexpr float A4_FREQUENCY = 440.0f;
constexpr int A4_MIDI_NOTE = 69;

/** Guitar string info */
struct StringInfo {
    const char* name;       // e.g., "E2"
    float frequency;        // Hz
    int midi_note;          // MIDI note number
};

/** Standard tuning (E A D G B E) from low to high */
constexpr StringInfo STANDARD_TUNING[] = {
    {"E2",  82.41f,  40},   // Low E
    {"A2", 110.00f,  45},   // A
    {"D3", 146.83f,  50},   // D
    {"G3", 196.00f,  55},   // G
    {"B3", 246.94f,  59},   // B
    {"E4", 329.63f,  64}    // High E
};
constexpr int NUM_STRINGS = sizeof(STANDARD_TUNING) / sizeof(STANDARD_TUNING[0]);

/** Tuning thresholds (in cents) */
constexpr float IN_TUNE_THRESHOLD = 5.0f;       // Considered "in tune"
constexpr float CLOSE_THRESHOLD = 15.0f;        // Considered "close"
constexpr float MAX_STRING_DEVIATION = 100.0f;  // Max cents to associate with a string

// ============================================================================
// Inline Functions
// ============================================================================

/**
 * @brief Calculate MIDI note number from frequency
 * @param freq Frequency in Hz
 * @return MIDI note number (floating point for cents calculation)
 */
inline float freq_to_midi(float freq) {
    if (freq <= 0.0f) return -1.0f;
    return 12.0f * log2f(freq / A4_FREQUENCY) + static_cast<float>(A4_MIDI_NOTE);
}

/**
 * @brief Calculate frequency from MIDI note number
 * @param midi_note MIDI note number
 * @return Frequency in Hz
 */
inline float midi_to_freq(int midi_note) {
    return A4_FREQUENCY * powf(2.0f, (midi_note - A4_MIDI_NOTE) / 12.0f);
}

/**
 * @brief Calculate cents deviation between two frequencies
 * @param measured Measured frequency
 * @param target Target frequency
 * @return Cents deviation (positive = sharp, negative = flat)
 */
inline float calculate_cents(float measured, float target) {
    if (measured <= 0.0f || target <= 0.0f) return 0.0f;
    return 1200.0f * log2f(measured / target);
}

/**
 * @brief Get note name from MIDI note number
 * @param midi_note MIDI note number (0-127)
 * @return Pointer to note name string
 */
inline const char* get_note_name(int midi_note) {
    if (midi_note < 0 || midi_note > 127) return "?";
    return NOTE_NAMES[midi_note % NUM_NOTES];
}

/**
 * @brief Get octave from MIDI note number
 * @param midi_note MIDI note number
 * @return Octave number (-1 to 9)
 */
inline int get_octave(int midi_note) {
    return (midi_note / NUM_NOTES) - 1;
}

/**
 * @brief Find the closest guitar string to a frequency
 * @param freq Frequency in Hz
 * @return Index into STANDARD_TUNING array, or -1 if too far from any string
 */
inline int find_closest_string(float freq) {
    if (freq <= 0.0f) return -1;
    
    int closest = -1;
    float min_cents_diff = MAX_STRING_DEVIATION;
    
    for (int i = 0; i < NUM_STRINGS; i++) {
        float cents = calculate_cents(freq, STANDARD_TUNING[i].frequency);
        float abs_cents = (cents < 0.0f) ? -cents : cents;
        
        if (abs_cents < min_cents_diff) {
            min_cents_diff = abs_cents;
            closest = i;
        }
    }
    
    return closest;
}

/**
 * @brief Determine tuning direction from cents deviation
 * @param cents Cents deviation from target
 * @return -1 = flat (tune up), 0 = in tune, 1 = sharp (tune down)
 */
inline int get_tuning_direction(float cents) {
    if (cents < -IN_TUNE_THRESHOLD) return -1;  // Flat - tune up
    if (cents > IN_TUNE_THRESHOLD) return 1;    // Sharp - tune down
    return 0;                                     // In tune
}

/**
 * @brief Check if a frequency is considered "in tune" with a target
 * @param measured Measured frequency
 * @param target Target frequency
 * @return true if within IN_TUNE_THRESHOLD cents
 */
inline bool is_in_tune(float measured, float target) {
    float cents = calculate_cents(measured, target);
    float abs_cents = (cents < 0.0f) ? -cents : cents;
    return abs_cents <= IN_TUNE_THRESHOLD;
}

// ============================================================================
// Non-inline Functions (defined in guitar_tuning.cpp)
// ============================================================================

/**
 * @brief Convert frequency to note string with octave and cents
 * 
 * Formats: "A4", "C#3 +12c", "E2 -8c"
 * 
 * @param freq Frequency in Hz
 * @param buffer Output buffer
 * @param size Buffer size
 * @param include_cents Whether to include cents deviation
 * @return Cents deviation from perfect pitch
 */
float freq_to_note_string(float freq, char* buffer, uint32_t size, bool include_cents = false);

/**
 * @brief Get a description of how to tune (e.g., "Tune UP", "Tune DOWN", "IN TUNE")
 * 
 * @param cents Cents deviation
 * @param buffer Output buffer
 * @param size Buffer size
 */
void get_tuning_instruction(float cents, char* buffer, uint32_t size);

} // namespace GuitarTuning

#endif // GUITAR_TUNING_H

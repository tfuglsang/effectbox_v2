# EffectBox v2 Unit Tests

Host-side unit tests for the EffectBox audio DSP code. These tests run on your development machine (not the STM32 target) using mock implementations of CMSIS-DSP and HAL functions.

## Prerequisites

- CMake 3.20+
- C++17 compiler (clang, gcc, or MSVC)
- Internet connection (for Catch2 download on first build)

## Building and Running Tests

```bash
# From the tests directory
cd tests
cmake -B build -S .
cmake --build build

# Run all tests
./build/effectbox_tests

# Run with verbose output
./build/effectbox_tests -s

# Run specific test suite
./build/effectbox_tests "[guitar_tuning]"
./build/effectbox_tests "[audio_pipeline]"
./build/effectbox_tests "[gain_effect]"
./build/effectbox_tests "[yin]"
./build/effectbox_tests "[audio_effect]"

# List all tests
./build/effectbox_tests --list-tests
```

## Test Coverage

| Component | File | Coverage |
|-----------|------|----------|
| GuitarTuning | `test_guitar_tuning.cpp` | MIDI conversion, cents calculation, note formatting, string detection |
| AudioPipeline | `test_audio_pipeline.cpp` | Effect management, stereo/mono conversion, enable/disable |
| AudioEffect | `test_audio_effect.cpp` | Base class, CPU profiling, parameter interface |
| GainEffect | `test_gain_effect.cpp` | Gain setting, dB conversion, parameter adjustment |
| YinPitchDetector | `test_yin_pitch.cpp` | Pitch detection, frequency range, incremental processing |

## Mock Infrastructure

The `mocks/` directory contains stub implementations:

- `arm_math.h` - CMSIS-DSP types and basic functions
- `stm32h7xx.h` - HAL types and DWT cycle counter

These mocks provide enough functionality to compile and test the DSP algorithms without actual hardware.

## Adding New Tests

1. Create `test_<component>.cpp` in this directory
2. Add the file to `CMakeLists.txt`
3. Use Catch2 macros: `TEST_CASE`, `SECTION`, `REQUIRE`, etc.
4. Tag tests with component name: `"[component_name]"`

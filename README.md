# EffectBox v2 - STM32H747I Guitar Effects & Tuner

A real-time audio effects processor and guitar tuner running on the STM32H747I-DISCO board.

## Features

### Audio Effects Mode
- **Distortion** - Soft-clipping overdrive with adjustable drive
- **Chorus** - Modulated delay for rich, shimmering sound
- **Flanger** - Classic jet-plane swooshing effect
- **Tremolo** - Amplitude modulation with adjustable rate
- **Delay/Echo** - Single-tap delay with feedback (50-250ms)
- **Reverb** - Schroeder reverb with parallel comb filters

All effects process mono audio internally with stereo I/O conversion handled by the audio pipeline.

### Pitch Detection Mode (Guitar Tuner)
- YIN algorithm for accurate pitch detection
- Optimized with 6x downsampling (48kHz → 8kHz)
- Standard guitar tuning reference (E A D G B E)
- Visual tuning indicator with cents deviation display
- Real-time confidence meter

## Hardware

- **Board**: STM32H747I-DISCO (Discovery Kit)
- **MCU**: STM32H747XI dual-core (Cortex-M7 @ 400MHz + Cortex-M4)
- **Audio Codec**: WM8994 (48kHz, 16-bit)
- **Display**: 4" 800x480 LCD with capacitive touch
- **Input**: Joystick for navigation and parameter adjustment

## Project Structure

```
CM7/
├── Inc/                    # Header files
│   ├── app_common.h        # Shared constants and declarations
│   ├── audio_effect.h      # Base class for all effects
│   ├── audio_pipeline.h    # Effect chain with stereo/mono conversion
│   ├── guitar_effects.h    # Distortion, Delay, Chorus, Flanger, Tremolo, Reverb
│   ├── yin_pitch_detector.h # YIN pitch detection algorithm
│   ├── guitar_tuning.h     # Tuning constants and utilities
│   ├── lcd_utils.h         # Flicker-free LCD drawing
│   └── ...
├── Src/                    # Source files
│   ├── main.cpp            # Application entry point
│   ├── audio_effects_mode.cpp  # Effects menu and setup
│   ├── pitch_detection_mode.cpp # Guitar tuner UI
│   ├── stm32_init.cpp      # Hardware initialization
│   └── ...
CM4/                        # Cortex-M4 core (minimal)
Drivers/                    # HAL, BSP, CMSIS-DSP
```

## Building

### Prerequisites
- CMake 3.20+
- ARM GCC Toolchain (arm-none-eabi-gcc)
- STM32CubeMX (for regenerating HAL code if needed)

### Build Commands

```bash
# Configure
cmake -B build/Debug -G Ninja

# Build
cmake --build build/Debug

# Flash (using STM32CubeProgrammer)
STM32_Programmer_CLI -c port=SWD -w build/Debug/CM7/effectbox_v2_CM7.elf -rst
```

## Usage

1. Power on the board
2. Select mode using the joystick:
   - **Audio Effects**: Process audio through effect chain
   - **Pitch Detection**: Guitar tuner mode

### Audio Effects Mode Controls
- **UP/DOWN**: Navigate effect list
- **SEL**: Toggle effect ON/OFF
- **LEFT/RIGHT**: Adjust effect parameter

### Pitch Detection Mode
- Play a guitar string
- Watch the tuning indicator and cents display
- Arrows show tuning direction (flat/sharp)

## Technical Details

- **Sample Rate**: 48kHz
- **Buffer Size**: 512 samples per channel (double-buffered)
- **Audio Flow**: Stereo In → Mono → Effects → Stereo Out
- **CPU Profiling**: DWT cycle counter for per-effect utilization
- **Memory Usage**: ~66KB RAM, ~131KB Flash (CM7)

## Author

Thomas Fuglsang <tfuglsang@gmail.com>

## License

MIT License - See LICENSE file for details.

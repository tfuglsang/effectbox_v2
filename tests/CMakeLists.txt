cmake_minimum_required(VERSION 3.20)
project(effectbox_tests CXX)

# Build for host, not target
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch Catch2
include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(Catch2)

# Mock CMSIS-DSP types and STM32 HAL (minimal stubs for host testing)
add_library(platform_mocks INTERFACE)
target_include_directories(platform_mocks INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/mocks)

# Test executable
add_executable(effectbox_tests
    test_main.cpp
    test_guitar_tuning.cpp
    test_audio_pipeline.cpp
    test_audio_effect.cpp
    test_gain_effect.cpp
    test_yin_pitch.cpp
    ../CM7/Src/guitar_tuning.cpp
)

# IMPORTANT: mocks directory must come FIRST to shadow real headers
# (e.g., app_common.h mock shadows the real one that pulls in STM32 HAL)
target_include_directories(effectbox_tests PRIVATE 
    mocks
    ../CM7/Inc
)

# Force-include the mock app_common.h before any other includes
# This ensures the include guard is defined before the real header is seen
target_compile_options(effectbox_tests PRIVATE
    -include ${CMAKE_CURRENT_SOURCE_DIR}/mocks/app_common.h
)

target_link_libraries(effectbox_tests PRIVATE 
    Catch2::Catch2WithMain 
    platform_mocks
)

# Enable testing
include(CTest)
include(Catch)
catch_discover_tests(effectbox_tests)

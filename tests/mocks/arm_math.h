/**
 * @file arm_math.h
 * @brief Mock CMSIS-DSP types and functions for host-side testing
 * 
 * Provides minimal stubs to allow compiling and testing DSP code
 * on the development host without actual CMSIS-DSP library.
 */

#ifndef ARM_MATH_MOCK_H
#define ARM_MATH_MOCK_H

#include <cstdint>
#include <cmath>
#include <cstring>
#include <algorithm>

// CMSIS-DSP type definitions
typedef float float32_t;
typedef double float64_t;
typedef int32_t q31_t;
typedef int16_t q15_t;
typedef int8_t q7_t;

// ARM status type
typedef enum {
    ARM_MATH_SUCCESS = 0,
    ARM_MATH_ARGUMENT_ERROR = -1,
    ARM_MATH_LENGTH_ERROR = -2,
    ARM_MATH_SIZE_MISMATCH = -3,
    ARM_MATH_NANINF = -4,
    ARM_MATH_SINGULAR = -5,
    ARM_MATH_TEST_FAILURE = -6
} arm_status;

// Constants
#ifndef PI
#define PI 3.14159265358979f
#endif

// ============================================================================
// FFT Structures (stubs)
// ============================================================================

typedef struct {
    uint16_t fftLen;
    const float32_t* pTwiddle;
    const uint16_t* pBitRevTable;
    uint16_t bitRevLength;
} arm_cfft_instance_f32;

typedef struct {
    arm_cfft_instance_f32 Sint;
    uint16_t fftLenRFFT;
    const float32_t* pTwiddleRFFT;
} arm_rfft_fast_instance_f32;

// ============================================================================
// Filter Structures
// ============================================================================

typedef struct {
    uint8_t numStages;
    float32_t* pState;
    const float32_t* pCoeffs;
} arm_biquad_casd_df1_inst_f32;

typedef struct {
    int8_t numStages;
    q31_t* pState;
    const q31_t* pCoeffs;
    int8_t postShift;
} arm_biquad_casd_df1_inst_q31;

typedef struct {
    uint16_t numTaps;
    float32_t* pState;
    const float32_t* pCoeffs;
} arm_fir_instance_f32;

// ============================================================================
// Basic Math Functions
// ============================================================================

/**
 * @brief Q15 vector scaling
 */
inline void arm_scale_q15(const q15_t* pSrc, q15_t scaleFract, int8_t shift,
                          q15_t* pDst, uint32_t blockSize) {
    (void)shift;  // Simplified: ignore shift for testing
    for (uint32_t i = 0; i < blockSize; i++) {
        int32_t result = (static_cast<int32_t>(pSrc[i]) * scaleFract) >> 15;
        // Saturate to Q15 range
        if (result > 32767) result = 32767;
        if (result < -32768) result = -32768;
        pDst[i] = static_cast<q15_t>(result);
    }
}

/**
 * @brief Float32 dot product
 */
inline void arm_dot_prod_f32(const float32_t* pSrcA, const float32_t* pSrcB,
                              uint32_t blockSize, float32_t* result) {
    float32_t sum = 0.0f;
    for (uint32_t i = 0; i < blockSize; i++) {
        sum += pSrcA[i] * pSrcB[i];
    }
    *result = sum;
}

/**
 * @brief Float32 sine (using standard library)
 */
inline float32_t arm_sin_f32(float32_t x) {
    return sinf(x);
}

/**
 * @brief Float32 cosine (using standard library)
 */
inline float32_t arm_cos_f32(float32_t x) {
    return cosf(x);
}

// ============================================================================
// FFT Functions (stubs)
// ============================================================================

inline arm_status arm_rfft_fast_init_f32(arm_rfft_fast_instance_f32* S, uint16_t fftLen) {
    S->fftLenRFFT = fftLen;
    return ARM_MATH_SUCCESS;
}

inline void arm_rfft_fast_f32(const arm_rfft_fast_instance_f32* S,
                               float32_t* p, float32_t* pOut, uint8_t ifftFlag) {
    (void)S;
    (void)ifftFlag;
    // Stub: just copy input to output for testing
    std::memcpy(pOut, p, S->fftLenRFFT * sizeof(float32_t));
}

inline void arm_cmplx_mag_f32(const float32_t* pSrc, float32_t* pDst, uint32_t numSamples) {
    for (uint32_t i = 0; i < numSamples; i++) {
        float32_t real = pSrc[2 * i];
        float32_t imag = pSrc[2 * i + 1];
        pDst[i] = sqrtf(real * real + imag * imag);
    }
}

// ============================================================================
// Filter Functions
// ============================================================================

inline void arm_biquad_cascade_df1_init_f32(arm_biquad_casd_df1_inst_f32* S,
                                            uint8_t numStages,
                                            const float32_t* pCoeffs,
                                            float32_t* pState) {
    S->numStages = numStages;
    S->pCoeffs = pCoeffs;
    S->pState = pState;
    // Clear state
    std::memset(pState, 0, 4 * numStages * sizeof(float32_t));
}

inline void arm_biquad_cascade_df1_f32(const arm_biquad_casd_df1_inst_f32* S,
                                        const float32_t* pSrc,
                                        float32_t* pDst,
                                        uint32_t blockSize) {
    // Simplified biquad implementation for testing
    const float32_t* coeffs = S->pCoeffs;
    float32_t* state = S->pState;
    
    float32_t b0 = coeffs[0];
    float32_t b1 = coeffs[1];
    float32_t b2 = coeffs[2];
    float32_t a1 = coeffs[3];  // Already negated in CMSIS format
    float32_t a2 = coeffs[4];
    
    float32_t x1 = state[0];
    float32_t x2 = state[1];
    float32_t y1 = state[2];
    float32_t y2 = state[3];
    
    for (uint32_t i = 0; i < blockSize; i++) {
        float32_t x0 = pSrc[i];
        float32_t y0 = b0 * x0 + b1 * x1 + b2 * x2 + a1 * y1 + a2 * y2;
        
        x2 = x1;
        x1 = x0;
        y2 = y1;
        y1 = y0;
        
        pDst[i] = y0;
    }
    
    state[0] = x1;
    state[1] = x2;
    state[2] = y1;
    state[3] = y2;
}

inline void arm_biquad_cascade_df1_init_q31(arm_biquad_casd_df1_inst_q31* S,
                                            uint8_t numStages,
                                            const q31_t* pCoeffs,
                                            q31_t* pState,
                                            int8_t postShift) {
    S->numStages = numStages;
    S->pCoeffs = pCoeffs;
    S->pState = pState;
    S->postShift = postShift;
    std::memset(pState, 0, 4 * numStages * sizeof(q31_t));
}

inline void arm_biquad_cascade_df1_q31(const arm_biquad_casd_df1_inst_q31* S,
                                        const q31_t* pSrc,
                                        q31_t* pDst,
                                        uint32_t blockSize) {
    // Simplified Q31 biquad for testing - just pass through
    for (uint32_t i = 0; i < blockSize; i++) {
        pDst[i] = pSrc[i];
    }
}

inline void arm_fir_init_f32(arm_fir_instance_f32* S,
                              uint16_t numTaps,
                              const float32_t* pCoeffs,
                              float32_t* pState,
                              uint32_t blockSize) {
    (void)blockSize;
    S->numTaps = numTaps;
    S->pCoeffs = pCoeffs;
    S->pState = pState;
}

inline void arm_fir_f32(const arm_fir_instance_f32* S,
                         const float32_t* pSrc,
                         float32_t* pDst,
                         uint32_t blockSize) {
    // Simplified: just copy for testing
    std::memcpy(pDst, pSrc, blockSize * sizeof(float32_t));
}

#endif // ARM_MATH_MOCK_H

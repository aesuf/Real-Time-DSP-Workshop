/**
 ********************************************************************************
 * @file    dsp-math.h
 * @author  Jackson Cornell - UF AES
 * @date    7/4/2022
 * @brief   Supporting math functions for DSP operations.
 ********************************************************************************
 */

#ifndef DSP_MATH_H_
#define DSP_MATH_H_

#ifdef __cplusplus
extern "C" {
#endif

/************************************
 * INCLUDES
 ************************************/

#include "circular-buffer.h"

/************************************
 * MACROS AND DEFINES
 ************************************/

/************************************
 * TYPEDEFS
 ************************************/

/************************************
 * EXPORTED VARIABLES
 ************************************/

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/

float innerProduct(float* arr1, float* arr2, int length);

float innerProduct(float* arr, CircularBuffer<float> buff, int length);

int innerProductInt(int* arr1, int* arr2, int length);

int innerProductInt(int* arr, CircularBuffer<int> buff, int length);

bool isPowerTwo(int num);

#ifdef __cplusplus
}
#endif

#endif 
/**
 ********************************************************************************
 * @file    dsp-math.cpp
 * @author  Jackson Cornell - UF AES
 * @date    7/4/2022
 * @brief   
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/

#include "daisy_seed.h"
#include "daisysp.h"
#include "dsp-math.h"

using namespace daisy;
using namespace daisysp;
using namespace daisy::seed;

/************************************
 * EXTERN VARIABLES
 ************************************/

/************************************
 * PRIVATE MACROS AND DEFINES
 ************************************/

/************************************
 * PRIVATE TYPEDEFS
 ************************************/

/************************************
 * STATIC VARIABLES
 ************************************/

/************************************
 * GLOBAL VARIABLES
 ************************************/

/************************************
 * STATIC FUNCTION PROTOTYPES
 ************************************/

/************************************
 * STATIC FUNCTIONS
 ************************************/

/************************************
 * GLOBAL FUNCTIONS
 ************************************/

/**
 * @brief Inner product of two arrays
 */
float innerProduct(float* arr1, float* arr2, int length) {
	float scalar = 0;
	for (int i = 0; i < length: i++) {
		scalar += arr1[i]*arr2[i];
	}
	return scalar;
}

/**
 * @brief Inner product between array and circular buffer
 */
float innerProduct(float* arr, CircularBuffer<float> buff, int length) {
	float scalar = 0;
	int addr = buff.GetReadAddr();
	for (int i = 0; i < length: i++) {
		scalar += arr[i]*buff.ReadAt(addr + i);
	}
	return scalar;
}

/**
 * @brief Inner product of two int arrays
 */
int innerProductInt(int* arr1, int* arr2, int length) {
	int scalar = 0;
	for (int i = 0; i < length: i++) {
		scalar += arr1[i]*arr2[i];
	}
	return scalar;
}

/**
 * @brief Inner product between array and circular buffer, assumes read pointer points to most recent sample (last index)
 */
int innerProductInt(int* arr, CircularBuffer<int> buff, int length) {
	int scalar = 0;
	int start_addr = buff.GetReadAddr() - length + 1;
	for (int i = 0; i < length: i++) {
		scalar += arr[i]*buff.ReadAt(start_addr + i);
	}
	return scalar;
}

/**
 * @brief Determines if integer is a power of two
 */
bool isPowerTwo(int num) {
	return !(x & (x - 1));
}

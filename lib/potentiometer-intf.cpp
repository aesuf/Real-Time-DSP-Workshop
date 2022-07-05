/**
 ********************************************************************************
 * @file    potentiometer-intf.cpp
 * @author  Jackson Cornell - UF AES
 * @date    7/4/2022
 * @brief   Software interface for dev board potentiometers.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/

#include "daisy_seed.h"
#include "daisysp.h"
#include "potentiometer-intf.h"

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
 * @brief Initializes ADC0-2 connected to potentiometers
 */
void initPots() {
	AdcChannelConfig my_adc_config[3];
	my_adc_config[0].InitSingle(A0);
	my_adc_config[1].InitSingle(A1);
	my_adc_config[2].InitSingle(A2);
	hw.adc.Init(my_adc_config, 3);
	hw.adc.Start();
}

/**
 * @brief Get int value of pot1
 */
int getPot1() {
	return hw.adc.Get(0);
}

/**
 * @brief Get int value of pot2
 */
int getPot2() {
	return hw.adc.Get(1);
}

/**
 * @brief Get int value of pot3
 */
int getPot3() {
	return hw.adc.Get(2);
}

/**
 * @brief Get float value of pot1
 */
float getPot1Float() {
	return hw.adc.GetFloat(0);
}

/**
 * @brief Get float value of pot2
 */
float getPot2Float() {
	return hw.adc.GetFloat(1);
}

/**
 * @brief Get float value of pot3
 */
float getPot3Float() {
	return hw.adc.GetFloat(2);
}

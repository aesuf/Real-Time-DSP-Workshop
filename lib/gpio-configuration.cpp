/**
 ********************************************************************************
 * @file    gpio-configuration.cpp
 * @author  Jackson Cornell - UFAES
 * @date    7/4/2022
 * @brief   
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/

#include "daisy_seed.h"
#include "daisysp.h"
#include "gpio-configuration.h"

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
 * @brief Initializes system with Daisy Seed hardware object
 */
void initSys() {
	hw.Init();
}
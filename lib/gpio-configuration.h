/**
 ********************************************************************************
 * @file    gpio-configuration.h
 * @author  Jackson Cornell - UF AES
 * @date    7/4/2022
 * @brief   Define daisy seed pin functions and assignments.
 ********************************************************************************
 */

#ifndef GPIO_CONFIGURATION_H_
#define GPIO_CONFIGURATION_H_

#ifdef __cplusplus
extern "C" {
#endif

/************************************
 * INCLUDES
 ************************************/

#include "daisy_seed.h"

/************************************
 * MACROS AND DEFINES
 ************************************/

/************************************
 * TYPEDEFS
 ************************************/

/************************************
 * EXPORTED VARIABLES
 ************************************/

DaisySeed hw;

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/

void initSys();


#ifdef __cplusplus
}
#endif

#endif 
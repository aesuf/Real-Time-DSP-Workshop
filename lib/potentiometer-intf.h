/**
 ********************************************************************************
 * @file    potentiometer-intf.h
 * @author  Jackson Cornell - UF AES
 * @date    7/4/2022
 * @brief   Software interface for dev board potentiometers.
 ********************************************************************************
 */

#ifndef POTENTIOMETER_INTF_H_
#define POTENTIOMETER_INTF_H_

#ifdef __cplusplus
extern "C" {
#endif

/************************************
 * INCLUDES
 ************************************/

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

void initPots();

int getPot1();

int getPot2();

int getPot3();

float getPot1Float();

float getPot2Float();

float getPot3Float();

#ifdef __cplusplus
}
#endif

#endif 
/**
 ******************************************************************************
 * @file    Light_Swich.h
 * @author  MOHAMMED KHALED
 * @brief   Header file of Light Switch ECUAL module.
 ******************************************************************************
 * @attention
 * All rights reserved.
 ******************************************************************************
 */

#ifndef __ECUAL_LIGHT_SWITCH_H__
#define __ECUAL_LIGHT_SWITCH_H__

/*- INCLUDES -----------------------------------------------*/

#include <stdint.h>

/* Exported types ------------------------------------------------------------*/

/**
 * @brief  Door State structures definition
 */
typedef enum
{

    SWITCH_OFF_STATE = 1, /*  LIGHT SWITCH IS NOT PRESSED    */
    SWITCH_ON_STATE = 0   /* LIGHT SWITCH IS PRESSED         */

} SWITCH_StateTypeDef;

/*- PRIMITIVE TYPES ----------------------------------------*/

/**
 * @defgroup defines for the number of times to filter the reading values
 */
#define FilterNumType uint32_t
#define SamplePeriod uint32_t

#define FILTER_1_TIME ((FilterNumType)0X00000001)
#define FILTER_2_TIME ((FilterNumType)0X00000002)
#define FILTER_3_TIME ((FilterNumType)0X00000003)
#define FILTER_4_TIME ((FilterNumType)0X00000004)
#define FILTER_5_TIME ((FilterNumType)0X00000005)

/*- ENUMS --------------------------------------------------*/

/*- STRUCTS AND UNIONS -------------------------------------*/

/*- FUNCTION-LIKE MACROS -----------------------------------*/

/*- FUNCTION DECLARATIONS ----------------------------------*/

/***************** Initialization function ***********************/

void LightSwitch_init(void);

/*************** control operation functions *********************/

SWITCH_StateTypeDef LightSW_getState(FilterNumType samples, SamplePeriod period);

void LightSW_SetON_Callback(void (*SW_ON_CallBack)(void));
void LightSW_SetOFF_Callback(void (*SW_OFF_CallBack)(void));

#endif /*ECUAL_LIGHT_SWITCH_.H*/



/**
 ******************************************************************************
 * @file    Sppeed_Sensor.h
 * @author  MOHAMMED KHALED
 * @brief   Header file of Spped sensor ECUAL module.
 ******************************************************************************
 * @attention
 * All rights reserved.
 ******************************************************************************
 */

#ifndef __ECUAL_SPEED_SENSOR_H__
#define __ECUAL_SPEED_SENSOR_H__

/*- INCLUDES -----------------------------------------------*/

#include <stdint.h>

/* Exported types ------------------------------------------------------------*/

/**
 * @brief  Movement State structures definition
 */
typedef enum
{
    Moving_State = 0,  /* Car is moving  */
    Stopping_State = 1 /*  Car is stopped*/

} Movement_StateTypeDef;

/*- PRIMITIVE TYPES ----------------------------------------*/

#define SpeedMeasure uint32_t

/*- ENUMS --------------------------------------------------*/

/*- STRUCTS AND UNIONS -------------------------------------*/

/*- FUNCTION-LIKE MACROS -----------------------------------*/

/*- FUNCTION DECLARATIONS ----------------------------------*/

/***************** Initialization function ***********************/

void SpeedSens_init(void);

/*************** control operation functions *********************/

SpeedMeasure SpeedSens_getMeasure(void);
Movement_StateTypeDef SpeedSens_getMovState(void);

#endif /*ECUAL_SPEED_SENSOR_.H*/

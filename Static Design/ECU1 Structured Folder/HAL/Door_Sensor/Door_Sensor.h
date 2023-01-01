

/**
 ******************************************************************************
 * @file    Door_Sensor.h
 * @author  MOHAMMED KHALED
 * @brief   Header file of Door Sensor ECUAL module.
 ******************************************************************************
 * @attention
 * All rights reserved.
 ******************************************************************************
 */

#ifndef __ECUAL_DOOR_SENSOR_H__
#define __ECUAL_DOOR_SENSOR_H__

/*- INCLUDES -----------------------------------------------*/

#include <stdint.h>

/* Exported types ------------------------------------------------------------*/

/**
 * @brief  Door State structures definition
 */
typedef enum
{
    Door_Opened = 0, /* At least on the car's doors is opened   */
    Doors_Closed = 1 /*  All the doors are closed               */

} Door_StateTypeDef;

/*- PRIMITIVE TYPES ----------------------------------------*/

#define SpeedMeasure uint32_t

/*- ENUMS --------------------------------------------------*/

/*- STRUCTS AND UNIONS -------------------------------------*/

/*- FUNCTION-LIKE MACROS -----------------------------------*/

/*- FUNCTION DECLARATIONS ----------------------------------*/

/***************** Initialization function ***********************/

void DoorSens_init(void);

/*************** control operation functions *********************/

Door_StateTypeDef DoorSens_getState(void);

void DoorSens_SetOpenCallback(void (*openState_CallBack)(void));
void DoorSens_SetCloseCallback(void (*closeState_CallBack)(void));

#endif /*ECUAL_DOOR_SENSOR_.H*/

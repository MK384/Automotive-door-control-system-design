

/**
 ******************************************************************************
 * @file    ALARM_Control.h
 * @author  MOHAMMED KHALED
 * @brief   Header file of ALARM Control ECUAL module.
 ******************************************************************************
 * @attention
 * All rights reserved.
 ******************************************************************************
 */

#ifndef __ECUAL_ALARM_CONTROL_H__
#define __ECUAL_ALARM_CONTROL_H__

/*- INCLUDES -----------------------------------------------*/

#include <stdint.h>

/* Exported types ------------------------------------------------------------*/

/**
 * @brief  Alarm Control status definition
 */
typedef enum
{
    STATUS_OK = 0,    /* Contol operation has successfully done   */
    STATUS_NOT_OK = 1 /* Contol operation  has failed             */

} Alarm_StatusTypeDef;

/*- PRIMITIVE TYPES ----------------------------------------*/

/*- ENUMS --------------------------------------------------*/

/*- STRUCTS AND UNIONS -------------------------------------*/

/*- FUNCTION-LIKE MACROS -----------------------------------*/

/*- FUNCTION DECLARATIONS ----------------------------------*/

/***************** Initialization function ***********************/

void AlarmCtrl_init(void);

/*************** control operation functions *********************/

Alarm_StatusTypeDef AlarmCtrl_Set_ON(void);
Alarm_StatusTypeDef AlramCtrl_Set_OFF(void);

#endif /*ECUAL_LIGHT_CONTROL_.H*/



/**
 ******************************************************************************
 * @file    Light_Control.h
 * @author  MOHAMMED KHALED
 * @brief   Header file of Light Control ECUAL module.
 ******************************************************************************
 * @attention
 * All rights reserved.
 ******************************************************************************
 */

#ifndef __ECUAL_LIGHT_CONTROL_H__
#define __ECUAL_LIGHT_CONTROL_H__

/*- INCLUDES -----------------------------------------------*/

#include <stdint.h>

/* Exported types ------------------------------------------------------------*/

/**
 * @brief  Light Control structures definition
 */
typedef enum
{
    Left_Light_Select = 0,  /* Left Light driver is selected to control    */
    Right_Light_Select = 1, /* Right Light driver is selected to control   */
    Both_Light_Select = 2   /* Both Light driver is selected to control    */

} Light_SelectType;

/**
 * @brief  Light Control status definition
 */
typedef enum
{
    STATUS_OK = 0,    /* Contol operation has successfully done   */
    STATUS_NOT_OK = 1 /* Contol operation  has failed             */

} CTRL_StatusTypeDef;

/*- PRIMITIVE TYPES ----------------------------------------*/

/*- ENUMS --------------------------------------------------*/

/*- STRUCTS AND UNIONS -------------------------------------*/

/*- FUNCTION-LIKE MACROS -----------------------------------*/

/*- FUNCTION DECLARATIONS ----------------------------------*/

/***************** Initialization function ***********************/

void LightCtrl_init(void);

/*************** control operation functions *********************/

CTRL_StatusTypeDef LightCtrl_Set_ON(Light_SelectType lightSel);
CTRL_StatusTypeDef LightCtrl_Set_OFF(Light_SelectType lightSel);

#endif /*ECUAL_LIGHT_CONTROL_.H*/

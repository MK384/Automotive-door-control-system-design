/**
 ******************************************************************************
 * @file    IC_Driver.h
 * @author  MOHAMMED KHALED
 * @brief   Header file of General Purpose Timer MCAL driver.
 ******************************************************************************
 * @attention
 * All rights reserved.
 ******************************************************************************
 */

#ifndef __MCAL_IC_H__
#define __MCAL_IC_H__

/*- INCLUDES -----------------------------------------------*/

#include <stdint.h>

/*- CONSTANTS ----------------------------------------------*/

/** @defgroup Input_Capture_Polarity Input Capture Polarity
 * @{
 */
#define ICPolarity_TypeDef uint32_t

/*!< Capture triggered by rising edge on timer input                  */
#define ICPOLARITY_RISING ((ICPolarity_TypeDef)0x00000001)

/*!< Capture triggered by falling edge on timer input                 */
#define ICPOLARITY_FALLING ((ICPolarity_TypeDef)0x00000002)

/*!< Capture triggered by both rising and falling edges on timer input*/
#define ICPOLARITY_BOTHEDGE ((ICPolarity_TypeDef)0x00000003)
/**
 * @}
 */

/** @defgroup TIM_Input_Capture_Selection TIM Input Capture Selection
 * @{
 */
#define TIM_SEL_TypeDef uint32_t
/*!< TIM1 Input 1, 2, 3 or 4 is selected to be connected to IC1, IC2, IC3 or IC4, respectively */
#define TIM1_ICSELECTION ((TIM_SEL_TypeDef)0x00000001)

/*!< TIM2 Input 1, 2, 3 or 4 is selected to be connected to IC2, IC1, IC4 or IC3, respectively */
#define TIM2_ICSELECTION ((TIM_SEL_TypeDef)0x00000002)

/*!< TIM3 Input 1, 2, 3 or 4 is selected to be connected to IC2, IC1, IC4 or IC3, respectively */
#define TIM2_ICSELECTION ((TIM_SEL_TypeDef)0x00000003)
/**
 * @}
 */

/** @defgroup IC_Channel _Selection
 * @{
 */
#define IC_Channel_TypeDef uint32_t

#define IC_CHANNEL_1 ((IC_Channel_TypeDef)0x00000001) /*!< IC Channel 1 is selected */
#define IC_CHANNEL_2 ((IC_Channel_TypeDef)0x00000002) /*!< IC Channel 2 is selected */
#define IC_CHANNEL_3 ((IC_Channel_TypeDef)0x00000004) /*!< IC Channel 3 is selected */
#define IC_CHANNEL_4 ((IC_Channel_TypeDef)0x00000008) /*!< IC Channel 4 is selected */
/**
 * @}
 */

/*- PRIMITIVE TYPES ----------------------------------------*/

typedef enum
{

    IC_Status_OK,
    IC_Status_NOT_OK

} IC_StatusTypeDef;

/*- ENUMS --------------------------------------------------*/
/**
 * @brief  TIM Input Capture Configuration Structure definition
 */
typedef struct
{
    IC_Channel_TypeDef ICChannel; /*!< Specifies the channel of the input Capture.
                            This parameter can be a value of @ref IC_Channel _Selection */

    ICPolarity_TypeDef ICPolarity; /*!< Specifies the active edge of the input signal.
                              This parameter can be a value of @ref Input_Capture_Polarity */

    TIM_SEL_TypeDef ICSelection; /*!< Specifies the input.
                               This parameter can be a value of @ref Input_Capture_Selection */

    uint32_t ICPrescaler; /*!< Specifies the Input Capture Prescaler.
                               This parameter can be a value of @ref Input_Capture_Prescaler */

} IC_InitTypeDef;

/*- FUNCTION-LIKE MACROS -----------------------------------*/
/*- FUNCTION DECLARATIONS ----------------------------------*/

/***************** Initialization functions ***********************/

IC_StatusTypeDef IC_Init(IC_InitTypeDef *prsInit);
IC_StatusTypeDef IC_DeInit(IC_Channel_TypeDef ICChannel);

/*************** Timer Control functions *********************/
/* Blocking mode: Polling */
HAL_StatusTypeDef HAL_TIM_IC_Start(IC_Channel_TypeDef Channel);
HAL_StatusTypeDef HAL_TIM_IC_Stop(IC_Channel_TypeDef Channel);
/* Non-Blocking mode: Interrupt */
HAL_StatusTypeDef HAL_TIM_IC_Start_IT(IC_Channel_TypeDef Channel);
HAL_StatusTypeDef HAL_TIM_IC_Stop_IT(IC_Channel_TypeDef Channel);

IC_StatusTypeDef HAL_TIM_IC_GetState(IC_Channel_TypeDef Channel);

void IC_CallbackSet(IC_Channel_TypeDef Channel, void (*IC_Callback)(void));

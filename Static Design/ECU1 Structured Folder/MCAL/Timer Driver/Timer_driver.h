/**
 ******************************************************************************
 * @file    Timer_Driver.h
 * @author  MOHAMMED KHALED
 * @brief   Header file of General Purpose Timer MCAL driver.
 ******************************************************************************
 * @attention
 * All rights reserved.
 ******************************************************************************
 */

#ifndef __MCAL_GPT_H__
#define __MCAL_GPT_H__

/*- INCLUDES -----------------------------------------------*/

#include <stdint.h>

/*- CONSTANTS ----------------------------------------------*/

/** @defgroup TIMER_ChannelType define
 * @brief TIMERs Channels define (the user uses this defines as insatnces for the config type )
 * @{
 */
#defien TIM_TypeDef uint32_t

#define TIM0 ((uint32_t)0X0000001)
#define TIM1 ((uint32_t)0X0000010)
#define TIM2 ((uint32_t)0X0000100)
#define TIM3 ((uint32_t)0X0001000)
#define TIM4 ((uint32_t)0X0010000)
#define TIM5 ((uint32_t)0X0100000)

/**
 * @}
 */

/*- PRIMITIVE TYPES ----------------------------------------*/
/*- ENUMS --------------------------------------------------*/

/**
 * @brief Timer Channel Running Mode
 * @{
 */
typedef enum
{
    GPT_MODE_CONT,
    GPT_MODE_ONESHOT,
    GPT_MODE_SPEC

} GPT_ModeType;
/**
 * @}
 */

/**
 * @brief Timer ChannelS configuration type -> used in the initialization API
 */

typedef struct
{

    TIM_TypeDef Channel; /*!< TIM Channels def can be used                         */

    uint32_t TickFrequency; /*!< TIMER Frequency                                   */

    uint32_t TickValueMax; /*!< MAX Ticks for Channel                              */

    GPT_ModeType ChannelMode; /*!<Running mode [Continues, One-Shot or specified]  */

    void (*PeriodElapsedCallback)(void); /*!< TIM Period Elapsed Callback          */

} GPT_ConfgTypeDef;
/**
 * @}
 */

/*- FUNCTION-LIKE MACROS -----------------------------------*/
/*- FUNCTION DECLARATIONS ----------------------------------*/

/***************** Initialization functions ***********************/

void GPT_Init(GPT_ConfgTypeDef *ConfigPtr);

/*************** Timer Control functions *********************/

void GPT_StartTimer(TIM_TypeDef Channel, uint32_t TicksValue);

void GPT_StopTimer(TIM_TypeDef Channel);

uint32_t GPT_GetTimeElapsed(TIM_TypeDef Channel);

uint32_t GPT_GetTimeRemaining(TIM_TypeDef Channel);

/*************** Timers Notification functions *********************/

void GPT_Notification_TIM0(void);
void GPT_Notification_TIM1(void);
void GPT_Notification_TIM2(void);
void GPT_Notification_TIM3(void);
void GPT_Notification_TIM4(void);
void GPT_Notification_TIM5(void);

void GPT_Notification_WTIM0(void);
void GPT_Notification_WTIM1(void);
void GPT_Notification_WTIM2(void);
void GPT_Notification_WTIM3(void);
void GPT_Notification_WTIM4(void);
void GPT_Notification_WTIM5(void);

/**
 * @}
 */

#endif /*MCAL_GPT.h*/

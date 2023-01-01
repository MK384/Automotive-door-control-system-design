/**
 ******************************************************************************
 * @file    DIO_Driver.h
 * @author  MOHAMMED KHALED
 * @brief   Header file of GPIO MCAL module.
 ******************************************************************************
 * @attention
 * All rights reserved.
 ******************************************************************************
 */

#ifndef __MCAL_GPIO_H__
#define __MCAL_GPIO_H__

/*- INCLUDES -----------------------------------------------*/

#include <stdint.h>

/*- CONSTANTS ----------------------------------------------*/
/** @defgroup GPIO_pins_define GPIO pins define
 * @{
 */
#define PIN_TypeDef uint16_t

#define GPIO_PIN_0 ((uint16_t)0x0001) /* Pin 0 selected    */
#define GPIO_PIN_1 ((uint16_t)0x0002) /* Pin 1 selected    */
#define GPIO_PIN_2 ((uint16_t)0x0004) /* Pin 2 selected    */
#define GPIO_PIN_3 ((uint16_t)0x0008) /* Pin 3 selected    */
#define GPIO_PIN_4 ((uint16_t)0x0010) /* Pin 4 selected    */
#define GPIO_PIN_5 ((uint16_t)0x0020) /* Pin 5 selected    */
#define GPIO_PIN_6 ((uint16_t)0x0040) /* Pin 6 selected    */
#define GPIO_PIN_7 ((uint16_t)0x0080) /* Pin 7 selected    */
/**
 * @}
 */

/** @defgroup GPIO_pins_define GPIO Ports define
 * @{
 */
#define PORT_TypeDef uint16_t

#define GPIO_PORTA ((PORT_TypeDef)0x0001) /* PORT A selected    */
#define GPIO_PORTB ((PORT_TypeDef)0x0002) /* PORT B selected    */
#define GPIO_PORTC ((PORT_TypeDef)0x0004) /* PORT C selected    */
#define GPIO_PORTD ((PORT_TypeDef)0x0008) /* PORT D selected    */
#define GPIO_PORTE ((PORT_TypeDef)0x0010) /* PORT E selected    */
#define GPIO_PORTF ((PORT_TypeDef)0x0020) /* PORT F selected    */

/**
 * @}
 */

/** @defgroup GPIO_Private_Constants GPIO Private Constants
 * @{
 */

#define GPIO_MODE_Pos 0U
#define GPIO_MODE (0x3UL << GPIO_MODE_Pos)
#define MODE_INPUT (0x0UL << GPIO_MODE_Pos)
#define MODE_OUTPUT (0x1UL << GPIO_MODE_Pos)
#define MODE_AF (0x2UL << GPIO_MODE_Pos)
#define MODE_ANALOG (0x3UL << GPIO_MODE_Pos)

#define OUTPUT_TYPE_Pos 4U
#define OUTPUT_TYPE (0x1UL << OUTPUT_TYPE_Pos)
#define OUTPUT_PP (0x0UL << OUTPUT_TYPE_Pos)
#define OUTPUT_OD (0x1UL << OUTPUT_TYPE_Pos)

#define EXTI_MODE_Pos 16U
#define EXTI_MODE (0x3UL << EXTI_MODE_Pos)
#define EXTI_IT (0x1UL << EXTI_MODE_Pos)

#define TRIGGER_MODE_Pos 20U
#define TRIGGER_MODE (0x7UL << TRIGGER_MODE_Pos)
#define TRIGGER_RISING (0x1UL << TRIGGER_MODE_Pos)
#define TRIGGER_FALLING (0x2UL << TRIGGER_MODE_Pos)

/**
 * @}
 */

/*- PRIMITIVE TYPES ----------------------------------------*/

/** @defgroup GPIO_TYPES for using in initialization
 * @{
 */
#define MODE_TypeDef uint32_t
#define PULL_TypeDef uint32_t
#define ALTER_TypeDef uint32_t
/**
 * @}
 */

/*- ENUMS --------------------------------------------------*/

/* @brief  GPIO Bit SET and Bit RESET enumeration
 */
typedef enum
{
    PIN_RESET = 0,
    PIN_SET

} GPIO_PinState;

/*- STRUCTS AND UNIONS -------------------------------------*/
/**
 * @brief GPIO Init structure definition
 */
typedef struct
{
    PORT_TypeDef Port; /*!< Specifies the GPIO Port to be configured.
                           This parameter can be any refrence of GPIOA_Type */

    PIN_TypeDef Pin; /*!< Specifies the GPIO pins to be configured.
                    This parameter can be any value of @ref GPIO_pins_define */

    MODE_TypeDef Mode; /*!< Specifies the operating mode for the selected pins.
                     This parameter can be a value of @ref GPIO_mode_define */

    PULL_TypeDef Pull; /*!< Specifies the Pull-up or Pull-Down activation for the selected pins.
                     This parameter can be a value of @ref GPIO_pull_define */

    ALTER_TypeDef Alternate; /*!< Peripheral to be connected to the selected pins.
                           This parameter can be a value of @ref GPIO_Alternate_function_selection */
} GPIO_InitTypeDef;

/** @defgroup GPIO_mode_define GPIO mode define
  * @brief GPIO Configuration Mode

  *           - : EXTI trigger detection on 3 bits
  *           - : Output type (Push Pull or Open Drain) on 1 bit
  *           - : GPIO mode (Input, Output, Alternate or Analog) on 2 bits
  * @{
  */
#define GPIO_MODE_INPUT MODE_INPUT                    /*!< Input Floating Mode                   */
#define GPIO_MODE_OUTPUT_PP (MODE_OUTPUT | OUTPUT_PP) /*!< Output Push Pull Mode                 */
#define GPIO_MODE_OUTPUT_OD (MODE_OUTPUT | OUTPUT_OD) /*!< Output Open Drain Mode                */
#define GPIO_MODE_AF_PP (MODE_AF | OUTPUT_PP)         /*!< Alternate Function Push Pull Mode     */
#define GPIO_MODE_AF_OD (MODE_AF | OUTPUT_OD)         /*!< Alternate Function Open Drain Mode    */

#define GPIO_MODE_ANALOG MODE_ANALOG /*!< Analog Mode  */

#define GPIO_MODE_IT_RISING (MODE_INPUT | EXTI_IT | TRIGGER_RISING)                           /*!< External Interrupt Mode with Rising edge trigger detection          */
#define GPIO_MODE_IT_FALLING (MODE_INPUT | EXTI_IT | TRIGGER_FALLING)                         /*!< External Interrupt Mode with Falling edge trigger detection         */
#define GPIO_MODE_IT_RISING_FALLING (MODE_INPUT | EXTI_IT | TRIGGER_RISING | TRIGGER_FALLING) /*!< External Interrupt Mode with Rising/Falling edge trigger detection  */

/**
 * @}
 */

/** @defgroup GPIO_pull_define GPIO pull define
 * @brief GPIO Pull-Up or Pull-Down Activation
 * @{
 */
#define GPIO_NOPULL 0x00000000U   /*!< No Pull-up or Pull-down activation  */
#define GPIO_PULLUP 0x00000001U   /*!< Pull-up activation                  */
#define GPIO_PULLDOWN 0x00000002U /*!< Pull-down activation                */
/**
 * @}
 */
/*- FUNCTION-LIKE MACROS -----------------------------------*/

#define _GPIO_EXTI_CLEAR_IT(GPIO_PORT, GPIO_PIN) (GPIO_PORT->ICR |= GPIO_PIN)
#define _GPIO_EXTI_GET_IT(GPIO_PORT, GPIO_PIN) (GPIO_PORT->RIS & GPIO_PIN)

/*- FUNCTION DECLARATIONS ----------------------------------*/

/***************** Initialization function ***********************/
void GPIO_Init(GPIO_InitTypeDef *pstr_Init);

/*************** IO operation functions *********************/
GPIO_PinState GPIO_ReadPin(PORT_TypeDef *GPIOx, PIN_TypeDef GPIO_Pin);
void GPIO_WritePin(PORT_TypeDef GPIOx, PIN_TypeDef GPIO_Pin, GPIO_PinState PinState);
void GPIO_TogglePin(PORT_TypeDef GPIOx, PIN_TypeDef GPIO_Pin);

void GPIO_EXTI_CallbackSet(PORT_TypeDef GPIOx, , PIN_TypeDef GPIO_Pin, void (*EXTI_Callback)(void));

/**
 * @}
 */

#endif /*MCAL_GPIO.h*/

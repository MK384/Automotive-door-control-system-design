

/**
 ******************************************************************************
 * @file    CAN_Driver.h
 * @author  MOHAMMED KHALED
 * @brief   Header file of GPIO MCAL module.
 ******************************************************************************
 * @attention
 * All rights reserved.
 ******************************************************************************
 */

#ifndef __MCAL_CAN_H__
#define __MCAL_CAN_H__

/*- INCLUDES -----------------------------------------------*/

#include <stdint.h>

/* Exported types ------------------------------------------------------------*/
/** @defgroup CAN_Exported_Types CAN Exported Types
 * @{
 */
/**
 * @brief  CAN State structures definition
 */
typedef enum
{
    CAN_STATE_RESET = 0x00U,         /*!< CAN not yet initialized or disabled */
    CAN_STATE_READY = 0x01U,         /*!< CAN initialized and ready for use   */
    CAN_STATE_LISTENING = 0x02U,     /*!< CAN receive process is ongoing      */
    CAN_STATE_SLEEP_PENDING = 0x03U, /*!< CAN sleep request is pending        */
    CAN_STATE_SLEEP_ACTIVE = 0x04U,  /*!< CAN sleep mode is active            */
    CAN_STATE_ERROR = 0x05U          /*!< CAN error state                     */

} CAN_StateTypeDef;

/** @defgroup CAN_operating_mode CAN Operating Mode
 * @{
 */
#define CAN_MODE_NORMAL (0x00000000U)              /*!< Normal mode   */
#define CAN_MODE_LOOPBACK ((uint32_t)CAN_BTR_LBKM) /*!< Loopback mode */
#define CAN_MODE_SILENT ((uint32_t)CAN_BTR_SILM)   /*!< Silent mode   */
/**
 * @}
 */

/**
 * @brief  CAN Tx message header structure definition
 */
typedef struct
{
    uint32_t StdId; /*!< Specifies the standard identifier. */

    uint32_t IDE; /*!< Specifies the type of identifier for the message that will be transmitted. */

    uint32_t RTR; /*!< Specifies the type of frame for the message that will be transmitted.*/

    uint32_t DLC; /*!< Specifies the length of the frame that will be transmitted. */

} CAN_TxHeaderTypeDef;

/**
 * @brief  CAN init structure definition
 */
typedef struct
{
    uint32_t Prescaler; /*!< Specifies the length of a time quantum.*/

    uint32_t Mode; /*!< Specifies the CAN operating mode.
                        This parameter can be a value of @ref CAN_operating_mode */

    uint32_t TimeSeg; /*!< Specifies the number of time quanta in Bit Segment.*/

    FunctionalState TimeTriggeredMode; /*!< Enable or disable the time triggered communication mode.
                                            This parameter can be set to ENABLE or DISABLE. */

    FunctionalState AutoRetransmission; /*!< Enable or disable the non-automatic retransmission mode.
                                             This parameter can be set to ENABLE or DISABLE. */

    FunctionalState TransmitFifoPriority; /*!< Enable or disable the transmit FIFO priority.
                                               This parameter can be set to ENABLE or DISABLE. */
} CAN_InitTypeDef;

/*- PRIMITIVE TYPES ----------------------------------------*/

/*- ENUMS --------------------------------------------------*/

/*- STRUCTS AND UNIONS -------------------------------------*/

/*- FUNCTION-LIKE MACROS -----------------------------------*/

/*- FUNCTION DECLARATIONS ----------------------------------*/

/***************** Initialization function ***********************/

CAN_StatusTypeDef HAL_CAN_Init(CAN_InitTypeDef *hcan);
CAN_StatusTypeDef HAL_CAN_DeInit(CAN_InitTypeDef *hcan);

/*************** control operation functions *********************/

CAN_StatusTypeDef CAN_Start(CAN_InitTypeDef *hcan);
CAN_StatusTypeDef CAN_Stop(CAN_InitTypeDef *hcan);
CAN_StatusTypeDef CAN_RequestSleep(CAN_InitTypeDef *hcan);
CAN_StatusTypeDef CAN_WakeUp(CAN_InitTypeDef *hcan);

CAN_StatusTypeDef CAN_AddTxMessage(CAN_InitTypeDef *hcan, CAN_TxHeaderTypeDef *pHeader,
                                   uint8_t aData[], uint32_t *pTxMailbox);
CAN_StatusTypeDef CAN_AbortTxRequest(CAN_InitTypeDef *hcan, uint32_t TxMailboxes);

/* Interrupts management ******************************************************/
CAN_StatusTypeDef HAL_CAN_ActivateNotification(CAN_InitTypeDef *hcan, uint32_t ActiveITs);
CAN_StatusTypeDef HAL_CAN_DeactivateNotification(CAN_InitTypeDef *hcan, uint32_t InactiveITs);

/************** Callbacks functions **************************************/

void HAL_CAN_TxMailbox0CompleteCallback(CAN_InitTypeDef *hcan);
void HAL_CAN_TxMailbox1CompleteCallback(CAN_InitTypeDef *hcan);
void HAL_CAN_TxMailbox2CompleteCallback(CAN_InitTypeDef *hcan);
void HAL_CAN_TxMailbox0AbortCallback(CAN_InitTypeDef *hcan);
void HAL_CAN_TxMailbox1AbortCallback(CAN_InitTypeDef *hcan);
void HAL_CAN_TxMailbox2AbortCallback(CAN_InitTypeDef *hcan);
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_InitTypeDef *hcan);
void HAL_CAN_RxFifo0FullCallback(CAN_InitTypeDef *hcan);
void HAL_CAN_RxFifo1MsgPendingCallback(CAN_InitTypeDef *hcan);
void HAL_CAN_RxFifo1FullCallback(CAN_InitTypeDef *hcan);
void HAL_CAN_SleepCallback(CAN_InitTypeDef *hcan);
void HAL_CAN_WakeUpFromRxMsgCallback(CAN_InitTypeDef *hcan);
void HAL_CAN_ErrorCallback(CAN_InitTypeDef *hcan);

/**
 * @}
 */

#endif /*MCAL_CAN.h*/

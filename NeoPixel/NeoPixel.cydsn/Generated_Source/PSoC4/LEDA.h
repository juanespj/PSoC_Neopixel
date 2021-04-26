/*******************************************************************************
* File Name: LEDA.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_LEDA_H) /* Pins LEDA_H */
#define CY_PINS_LEDA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "LEDA_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} LEDA_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   LEDA_Read(void);
void    LEDA_Write(uint8 value);
uint8   LEDA_ReadDataReg(void);
#if defined(LEDA__PC) || (CY_PSOC4_4200L) 
    void    LEDA_SetDriveMode(uint8 mode);
#endif
void    LEDA_SetInterruptMode(uint16 position, uint16 mode);
uint8   LEDA_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void LEDA_Sleep(void); 
void LEDA_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(LEDA__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define LEDA_DRIVE_MODE_BITS        (3)
    #define LEDA_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - LEDA_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the LEDA_SetDriveMode() function.
         *  @{
         */
        #define LEDA_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define LEDA_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define LEDA_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define LEDA_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define LEDA_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define LEDA_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define LEDA_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define LEDA_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define LEDA_MASK               LEDA__MASK
#define LEDA_SHIFT              LEDA__SHIFT
#define LEDA_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LEDA_SetInterruptMode() function.
     *  @{
     */
        #define LEDA_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define LEDA_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define LEDA_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define LEDA_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(LEDA__SIO)
    #define LEDA_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(LEDA__PC) && (CY_PSOC4_4200L)
    #define LEDA_USBIO_ENABLE               ((uint32)0x80000000u)
    #define LEDA_USBIO_DISABLE              ((uint32)(~LEDA_USBIO_ENABLE))
    #define LEDA_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define LEDA_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define LEDA_USBIO_ENTER_SLEEP          ((uint32)((1u << LEDA_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << LEDA_USBIO_SUSPEND_DEL_SHIFT)))
    #define LEDA_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << LEDA_USBIO_SUSPEND_SHIFT)))
    #define LEDA_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << LEDA_USBIO_SUSPEND_DEL_SHIFT)))
    #define LEDA_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(LEDA__PC)
    /* Port Configuration */
    #define LEDA_PC                 (* (reg32 *) LEDA__PC)
#endif
/* Pin State */
#define LEDA_PS                     (* (reg32 *) LEDA__PS)
/* Data Register */
#define LEDA_DR                     (* (reg32 *) LEDA__DR)
/* Input Buffer Disable Override */
#define LEDA_INP_DIS                (* (reg32 *) LEDA__PC2)

/* Interrupt configuration Registers */
#define LEDA_INTCFG                 (* (reg32 *) LEDA__INTCFG)
#define LEDA_INTSTAT                (* (reg32 *) LEDA__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define LEDA_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(LEDA__SIO)
    #define LEDA_SIO_REG            (* (reg32 *) LEDA__SIO)
#endif /* (LEDA__SIO_CFG) */

/* USBIO registers */
#if !defined(LEDA__PC) && (CY_PSOC4_4200L)
    #define LEDA_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define LEDA_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define LEDA_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define LEDA_DRIVE_MODE_SHIFT       (0x00u)
#define LEDA_DRIVE_MODE_MASK        (0x07u << LEDA_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins LEDA_H */


/* [] END OF FILE */

/*******************************************************************************
* File Name: LEDG.h  
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

#if !defined(CY_PINS_LEDG_H) /* Pins LEDG_H */
#define CY_PINS_LEDG_H

#include "cytypes.h"
#include "cyfitter.h"
#include "LEDG_aliases.h"


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
} LEDG_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   LEDG_Read(void);
void    LEDG_Write(uint8 value);
uint8   LEDG_ReadDataReg(void);
#if defined(LEDG__PC) || (CY_PSOC4_4200L) 
    void    LEDG_SetDriveMode(uint8 mode);
#endif
void    LEDG_SetInterruptMode(uint16 position, uint16 mode);
uint8   LEDG_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void LEDG_Sleep(void); 
void LEDG_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(LEDG__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define LEDG_DRIVE_MODE_BITS        (3)
    #define LEDG_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - LEDG_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the LEDG_SetDriveMode() function.
         *  @{
         */
        #define LEDG_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define LEDG_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define LEDG_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define LEDG_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define LEDG_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define LEDG_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define LEDG_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define LEDG_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define LEDG_MASK               LEDG__MASK
#define LEDG_SHIFT              LEDG__SHIFT
#define LEDG_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LEDG_SetInterruptMode() function.
     *  @{
     */
        #define LEDG_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define LEDG_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define LEDG_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define LEDG_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(LEDG__SIO)
    #define LEDG_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(LEDG__PC) && (CY_PSOC4_4200L)
    #define LEDG_USBIO_ENABLE               ((uint32)0x80000000u)
    #define LEDG_USBIO_DISABLE              ((uint32)(~LEDG_USBIO_ENABLE))
    #define LEDG_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define LEDG_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define LEDG_USBIO_ENTER_SLEEP          ((uint32)((1u << LEDG_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << LEDG_USBIO_SUSPEND_DEL_SHIFT)))
    #define LEDG_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << LEDG_USBIO_SUSPEND_SHIFT)))
    #define LEDG_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << LEDG_USBIO_SUSPEND_DEL_SHIFT)))
    #define LEDG_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(LEDG__PC)
    /* Port Configuration */
    #define LEDG_PC                 (* (reg32 *) LEDG__PC)
#endif
/* Pin State */
#define LEDG_PS                     (* (reg32 *) LEDG__PS)
/* Data Register */
#define LEDG_DR                     (* (reg32 *) LEDG__DR)
/* Input Buffer Disable Override */
#define LEDG_INP_DIS                (* (reg32 *) LEDG__PC2)

/* Interrupt configuration Registers */
#define LEDG_INTCFG                 (* (reg32 *) LEDG__INTCFG)
#define LEDG_INTSTAT                (* (reg32 *) LEDG__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define LEDG_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(LEDG__SIO)
    #define LEDG_SIO_REG            (* (reg32 *) LEDG__SIO)
#endif /* (LEDG__SIO_CFG) */

/* USBIO registers */
#if !defined(LEDG__PC) && (CY_PSOC4_4200L)
    #define LEDG_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define LEDG_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define LEDG_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define LEDG_DRIVE_MODE_SHIFT       (0x00u)
#define LEDG_DRIVE_MODE_MASK        (0x07u << LEDG_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins LEDG_H */


/* [] END OF FILE */

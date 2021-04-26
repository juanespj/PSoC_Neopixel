/*******************************************************************************
* File Name: NeoPixel_pixl.h  
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

#if !defined(CY_PINS_NeoPixel_pixl_H) /* Pins NeoPixel_pixl_H */
#define CY_PINS_NeoPixel_pixl_H

#include "cytypes.h"
#include "cyfitter.h"
#include "NeoPixel_pixl_aliases.h"


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
} NeoPixel_pixl_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   NeoPixel_pixl_Read(void);
void    NeoPixel_pixl_Write(uint8 value);
uint8   NeoPixel_pixl_ReadDataReg(void);
#if defined(NeoPixel_pixl__PC) || (CY_PSOC4_4200L) 
    void    NeoPixel_pixl_SetDriveMode(uint8 mode);
#endif
void    NeoPixel_pixl_SetInterruptMode(uint16 position, uint16 mode);
uint8   NeoPixel_pixl_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void NeoPixel_pixl_Sleep(void); 
void NeoPixel_pixl_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(NeoPixel_pixl__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define NeoPixel_pixl_DRIVE_MODE_BITS        (3)
    #define NeoPixel_pixl_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - NeoPixel_pixl_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the NeoPixel_pixl_SetDriveMode() function.
         *  @{
         */
        #define NeoPixel_pixl_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define NeoPixel_pixl_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define NeoPixel_pixl_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define NeoPixel_pixl_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define NeoPixel_pixl_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define NeoPixel_pixl_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define NeoPixel_pixl_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define NeoPixel_pixl_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define NeoPixel_pixl_MASK               NeoPixel_pixl__MASK
#define NeoPixel_pixl_SHIFT              NeoPixel_pixl__SHIFT
#define NeoPixel_pixl_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in NeoPixel_pixl_SetInterruptMode() function.
     *  @{
     */
        #define NeoPixel_pixl_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define NeoPixel_pixl_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define NeoPixel_pixl_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define NeoPixel_pixl_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(NeoPixel_pixl__SIO)
    #define NeoPixel_pixl_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(NeoPixel_pixl__PC) && (CY_PSOC4_4200L)
    #define NeoPixel_pixl_USBIO_ENABLE               ((uint32)0x80000000u)
    #define NeoPixel_pixl_USBIO_DISABLE              ((uint32)(~NeoPixel_pixl_USBIO_ENABLE))
    #define NeoPixel_pixl_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define NeoPixel_pixl_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define NeoPixel_pixl_USBIO_ENTER_SLEEP          ((uint32)((1u << NeoPixel_pixl_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << NeoPixel_pixl_USBIO_SUSPEND_DEL_SHIFT)))
    #define NeoPixel_pixl_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << NeoPixel_pixl_USBIO_SUSPEND_SHIFT)))
    #define NeoPixel_pixl_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << NeoPixel_pixl_USBIO_SUSPEND_DEL_SHIFT)))
    #define NeoPixel_pixl_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(NeoPixel_pixl__PC)
    /* Port Configuration */
    #define NeoPixel_pixl_PC                 (* (reg32 *) NeoPixel_pixl__PC)
#endif
/* Pin State */
#define NeoPixel_pixl_PS                     (* (reg32 *) NeoPixel_pixl__PS)
/* Data Register */
#define NeoPixel_pixl_DR                     (* (reg32 *) NeoPixel_pixl__DR)
/* Input Buffer Disable Override */
#define NeoPixel_pixl_INP_DIS                (* (reg32 *) NeoPixel_pixl__PC2)

/* Interrupt configuration Registers */
#define NeoPixel_pixl_INTCFG                 (* (reg32 *) NeoPixel_pixl__INTCFG)
#define NeoPixel_pixl_INTSTAT                (* (reg32 *) NeoPixel_pixl__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define NeoPixel_pixl_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(NeoPixel_pixl__SIO)
    #define NeoPixel_pixl_SIO_REG            (* (reg32 *) NeoPixel_pixl__SIO)
#endif /* (NeoPixel_pixl__SIO_CFG) */

/* USBIO registers */
#if !defined(NeoPixel_pixl__PC) && (CY_PSOC4_4200L)
    #define NeoPixel_pixl_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define NeoPixel_pixl_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define NeoPixel_pixl_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define NeoPixel_pixl_DRIVE_MODE_SHIFT       (0x00u)
#define NeoPixel_pixl_DRIVE_MODE_MASK        (0x07u << NeoPixel_pixl_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins NeoPixel_pixl_H */


/* [] END OF FILE */

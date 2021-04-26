/*******************************************************************************
* File Name: LEDG.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "LEDG.h"

static LEDG_BACKUP_STRUCT  LEDG_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: LEDG_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet LEDG_SUT.c usage_LEDG_Sleep_Wakeup
*******************************************************************************/
void LEDG_Sleep(void)
{
    #if defined(LEDG__PC)
        LEDG_backup.pcState = LEDG_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            LEDG_backup.usbState = LEDG_CR1_REG;
            LEDG_USB_POWER_REG |= LEDG_USBIO_ENTER_SLEEP;
            LEDG_CR1_REG &= LEDG_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(LEDG__SIO)
        LEDG_backup.sioState = LEDG_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        LEDG_SIO_REG &= (uint32)(~LEDG_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: LEDG_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to LEDG_Sleep() for an example usage.
*******************************************************************************/
void LEDG_Wakeup(void)
{
    #if defined(LEDG__PC)
        LEDG_PC = LEDG_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            LEDG_USB_POWER_REG &= LEDG_USBIO_EXIT_SLEEP_PH1;
            LEDG_CR1_REG = LEDG_backup.usbState;
            LEDG_USB_POWER_REG &= LEDG_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(LEDG__SIO)
        LEDG_SIO_REG = LEDG_backup.sioState;
    #endif
}


/* [] END OF FILE */

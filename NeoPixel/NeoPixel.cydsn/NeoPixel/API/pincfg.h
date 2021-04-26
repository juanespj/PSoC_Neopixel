/*******************************************************************************
* File Name: `$INSTANCE_NAME`_PVT.h
* Version `$CY_MAJOR_VERSION`.`$CY_MINOR_VERSION`
*
* Description:
*  This file provides constants and parameter values for the Software Transmit
*  UART Component.
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#ifndef `$INSTANCE_NAME`_PINCFG_H
#define `$INSTANCE_NAME`_PINCFG_H

#include "`$INSTANCE_NAME`_sled.h"


#if(`$INSTANCE_NAME`_PIN_STATIC_MODE == 1u)
    #define `$INSTANCE_NAME`_PIN_NUMBER                 (`$INSTANCE_NAME`_pixl__0__SHIFT)
    #define `$INSTANCE_NAME`_PIN_PORT_NUMBER            (`$INSTANCE_NAME`_pixl__0__PORT)
    #if (CY_PSOC4)
        #define `$INSTANCE_NAME`_PIN_DR                 (`$INSTANCE_NAME`_pixl__DR)
    #else
        #define `$INSTANCE_NAME`_PIN_DR                 (`$INSTANCE_NAME`_pixl__0__PC)
    #endif /* (CY_PSOC4) */
    
#else
    #if (!CY_PSOC4)
        #define `$INSTANCE_NAME`_PORT_CNF_BASE          (CYREG_PRT0_PC0)
    #else
        #if (CY_PSOC4A)
            #define `$INSTANCE_NAME`_PORT_CNF_BASE          ((uint32)CYDEV_PRT0_BASE)
            #define `$INSTANCE_NAME`_PORT_CNF_SIZE          ((uint32)CYDEV_PRT0_SIZE)
            #define `$INSTANCE_NAME`_PORT_CNF_MODE_OFFSET   ((uint32)(CYREG_PRT0_PC - CYDEV_PRT0_BASE))
            #define `$INSTANCE_NAME`_PORT_CNF_DR_OFFSET     ((uint32)(CYDEV_PRT0_BASE - CYREG_PRT0_DR))     
        #else
            #define `$INSTANCE_NAME`_PORT_CNF_BASE          ((uint32)CYDEV_GPIO_PRT0_BASE)
            #define `$INSTANCE_NAME`_PORT_CNF_SIZE          ((uint32)CYDEV_GPIO_PRT0_SIZE)
            #define `$INSTANCE_NAME`_PORT_CNF_MODE_OFFSET   ((uint32)(CYREG_GPIO_PRT0_PC - CYDEV_GPIO_PRT0_BASE))
            #define `$INSTANCE_NAME`_PORT_CNF_DR_OFFSET     ((uint32)(CYDEV_GPIO_PRT0_BASE - CYREG_GPIO_PRT0_DR))
        #endif /* (CY_PSOC4A) */
    #endif /* (!CY_PSOC4) */
#endif /* (`$INSTANCE_NAME`_PIN_STATIC_MODE == 1u) */

/* Nibble Offset and Mask */
#define `$INSTANCE_NAME`_BYTE_UPPER_NIBBLE_SHIFT        (0x04u)
#define `$INSTANCE_NAME`_U16_UPPER_BYTE_SHIFT           (0x08u)
#define `$INSTANCE_NAME`_BYTE_LOWER_NIBBLE_MASK         (0x0Fu)
#define `$INSTANCE_NAME`_U16_LOWER_BYTE_MASK            (0xFFu)

#if (!CY_PSOC4)
    #define `$INSTANCE_NAME`_MAX_PORT_NUMBER            (15u)
#else
    #if (CY_PSOC4_4100 || CY_PSOC4_4200)
        #define `$INSTANCE_NAME`_MAX_PORT_NUMBER            (4u)
    #else
        #define `$INSTANCE_NAME`_MAX_PORT_NUMBER            ((`=GetFeatureParameter("m0s8ioss", "GPIO.GPIO_PORT_NR")`u) - 1u)
    #endif  /* (CY_PSOC4_4100 || CY_PSOC4_4200) */
#endif /* (!CY_PSOC4) */

#define `$INSTANCE_NAME`_MAX_PIN_NUMBER                 (7u)
#endif /* CY_SW_TX_UART_`$INSTANCE_NAME`_PVT_H */


/* [] END OF FILE */

/*******************************************************************************
* File Name: NeoPixel_PVT.h
* Version 0.0
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

#ifndef NeoPixel_PINCFG_H
#define NeoPixel_PINCFG_H

#include "NeoPixel_sled.h"


#if(NeoPixel_PIN_STATIC_MODE == 1u)
    #define NeoPixel_PIN_NUMBER                 (NeoPixel_pixl__0__SHIFT)
    #define NeoPixel_PIN_PORT_NUMBER            (NeoPixel_pixl__0__PORT)
    #if (CY_PSOC4)
        #define NeoPixel_PIN_DR                 (NeoPixel_pixl__DR)
    #else
        #define NeoPixel_PIN_DR                 (NeoPixel_pixl__0__PC)
    #endif /* (CY_PSOC4) */
    
#else
    #if (!CY_PSOC4)
        #define NeoPixel_PORT_CNF_BASE          (CYREG_PRT0_PC0)
    #else
        #if (CY_PSOC4A)
            #define NeoPixel_PORT_CNF_BASE          ((uint32)CYDEV_PRT0_BASE)
            #define NeoPixel_PORT_CNF_SIZE          ((uint32)CYDEV_PRT0_SIZE)
            #define NeoPixel_PORT_CNF_MODE_OFFSET   ((uint32)(CYREG_PRT0_PC - CYDEV_PRT0_BASE))
            #define NeoPixel_PORT_CNF_DR_OFFSET     ((uint32)(CYDEV_PRT0_BASE - CYREG_PRT0_DR))     
        #else
            #define NeoPixel_PORT_CNF_BASE          ((uint32)CYDEV_GPIO_PRT0_BASE)
            #define NeoPixel_PORT_CNF_SIZE          ((uint32)CYDEV_GPIO_PRT0_SIZE)
            #define NeoPixel_PORT_CNF_MODE_OFFSET   ((uint32)(CYREG_GPIO_PRT0_PC - CYDEV_GPIO_PRT0_BASE))
            #define NeoPixel_PORT_CNF_DR_OFFSET     ((uint32)(CYDEV_GPIO_PRT0_BASE - CYREG_GPIO_PRT0_DR))
        #endif /* (CY_PSOC4A) */
    #endif /* (!CY_PSOC4) */
#endif /* (NeoPixel_PIN_STATIC_MODE == 1u) */

/* Nibble Offset and Mask */
#define NeoPixel_BYTE_UPPER_NIBBLE_SHIFT        (0x04u)
#define NeoPixel_U16_UPPER_BYTE_SHIFT           (0x08u)
#define NeoPixel_BYTE_LOWER_NIBBLE_MASK         (0x0Fu)
#define NeoPixel_U16_LOWER_BYTE_MASK            (0xFFu)

#if (!CY_PSOC4)
    #define NeoPixel_MAX_PORT_NUMBER            (15u)
#else
    #if (CY_PSOC4_4100 || CY_PSOC4_4200)
        #define NeoPixel_MAX_PORT_NUMBER            (4u)
    #else
        #define NeoPixel_MAX_PORT_NUMBER            ((-1u) - 1u)
    #endif  /* (CY_PSOC4_4100 || CY_PSOC4_4200) */
#endif /* (!CY_PSOC4) */

#define NeoPixel_MAX_PIN_NUMBER                 (7u)
#endif /* CY_SW_TX_UART_NeoPixel_PVT_H */


/* [] END OF FILE */

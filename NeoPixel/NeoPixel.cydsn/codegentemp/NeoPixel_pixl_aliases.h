/*******************************************************************************
* File Name: NeoPixel_pixl.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_NeoPixel_pixl_ALIASES_H) /* Pins NeoPixel_pixl_ALIASES_H */
#define CY_PINS_NeoPixel_pixl_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define NeoPixel_pixl_0			(NeoPixel_pixl__0__PC)
#define NeoPixel_pixl_0_PS		(NeoPixel_pixl__0__PS)
#define NeoPixel_pixl_0_PC		(NeoPixel_pixl__0__PC)
#define NeoPixel_pixl_0_DR		(NeoPixel_pixl__0__DR)
#define NeoPixel_pixl_0_SHIFT	(NeoPixel_pixl__0__SHIFT)
#define NeoPixel_pixl_0_INTR	((uint16)((uint16)0x0003u << (NeoPixel_pixl__0__SHIFT*2u)))

#define NeoPixel_pixl_INTR_ALL	 ((uint16)(NeoPixel_pixl_0_INTR))


#endif /* End Pins NeoPixel_pixl_ALIASES_H */


/* [] END OF FILE */

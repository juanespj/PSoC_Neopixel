/*******************************************************************************
* File Name: BTN.h  
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

#if !defined(CY_PINS_BTN_ALIASES_H) /* Pins BTN_ALIASES_H */
#define CY_PINS_BTN_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define BTN_0			(BTN__0__PC)
#define BTN_0_PS		(BTN__0__PS)
#define BTN_0_PC		(BTN__0__PC)
#define BTN_0_DR		(BTN__0__DR)
#define BTN_0_SHIFT	(BTN__0__SHIFT)
#define BTN_0_INTR	((uint16)((uint16)0x0003u << (BTN__0__SHIFT*2u)))

#define BTN_INTR_ALL	 ((uint16)(BTN_0_INTR))


#endif /* End Pins BTN_ALIASES_H */


/* [] END OF FILE */

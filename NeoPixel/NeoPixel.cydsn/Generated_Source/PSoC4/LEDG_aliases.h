/*******************************************************************************
* File Name: LEDG.h  
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

#if !defined(CY_PINS_LEDG_ALIASES_H) /* Pins LEDG_ALIASES_H */
#define CY_PINS_LEDG_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define LEDG_0			(LEDG__0__PC)
#define LEDG_0_PS		(LEDG__0__PS)
#define LEDG_0_PC		(LEDG__0__PC)
#define LEDG_0_DR		(LEDG__0__DR)
#define LEDG_0_SHIFT	(LEDG__0__SHIFT)
#define LEDG_0_INTR	((uint16)((uint16)0x0003u << (LEDG__0__SHIFT*2u)))

#define LEDG_INTR_ALL	 ((uint16)(LEDG_0_INTR))


#endif /* End Pins LEDG_ALIASES_H */


/* [] END OF FILE */

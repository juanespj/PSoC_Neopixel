/*******************************************************************************
* File Name: LEDA.h  
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

#if !defined(CY_PINS_LEDA_ALIASES_H) /* Pins LEDA_ALIASES_H */
#define CY_PINS_LEDA_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define LEDA_0			(LEDA__0__PC)
#define LEDA_0_PS		(LEDA__0__PS)
#define LEDA_0_PC		(LEDA__0__PC)
#define LEDA_0_DR		(LEDA__0__DR)
#define LEDA_0_SHIFT	(LEDA__0__SHIFT)
#define LEDA_0_INTR	((uint16)((uint16)0x0003u << (LEDA__0__SHIFT*2u)))

#define LEDA_INTR_ALL	 ((uint16)(LEDA_0_INTR))


#endif /* End Pins LEDA_ALIASES_H */


/* [] END OF FILE */

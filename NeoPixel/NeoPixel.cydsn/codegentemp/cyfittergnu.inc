/*******************************************************************************
* File Name: cyfittergnu.inc
* 
* PSoC Creator  4.4
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2020 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

.ifndef INCLUDED_CYFITTERGNU_INC
.set INCLUDED_CYFITTERGNU_INC, 1
.include "cydevicegnu_trm.inc"

/* BTN */
.set BTN__0__DM__MASK, 0xE00000
.set BTN__0__DM__SHIFT, 21
.set BTN__0__DR, CYREG_PRT0_DR
.set BTN__0__HSIOM, CYREG_HSIOM_PORT_SEL0
.set BTN__0__HSIOM_MASK, 0xF0000000
.set BTN__0__HSIOM_SHIFT, 28
.set BTN__0__INTCFG, CYREG_PRT0_INTCFG
.set BTN__0__INTSTAT, CYREG_PRT0_INTSTAT
.set BTN__0__MASK, 0x80
.set BTN__0__PA__CFG0, CYREG_UDB_PA0_CFG0
.set BTN__0__PA__CFG1, CYREG_UDB_PA0_CFG1
.set BTN__0__PA__CFG10, CYREG_UDB_PA0_CFG10
.set BTN__0__PA__CFG11, CYREG_UDB_PA0_CFG11
.set BTN__0__PA__CFG12, CYREG_UDB_PA0_CFG12
.set BTN__0__PA__CFG13, CYREG_UDB_PA0_CFG13
.set BTN__0__PA__CFG14, CYREG_UDB_PA0_CFG14
.set BTN__0__PA__CFG2, CYREG_UDB_PA0_CFG2
.set BTN__0__PA__CFG3, CYREG_UDB_PA0_CFG3
.set BTN__0__PA__CFG4, CYREG_UDB_PA0_CFG4
.set BTN__0__PA__CFG5, CYREG_UDB_PA0_CFG5
.set BTN__0__PA__CFG6, CYREG_UDB_PA0_CFG6
.set BTN__0__PA__CFG7, CYREG_UDB_PA0_CFG7
.set BTN__0__PA__CFG8, CYREG_UDB_PA0_CFG8
.set BTN__0__PA__CFG9, CYREG_UDB_PA0_CFG9
.set BTN__0__PC, CYREG_PRT0_PC
.set BTN__0__PC2, CYREG_PRT0_PC2
.set BTN__0__PORT, 0
.set BTN__0__PS, CYREG_PRT0_PS
.set BTN__0__SHIFT, 7
.set BTN__DR, CYREG_PRT0_DR
.set BTN__INTCFG, CYREG_PRT0_INTCFG
.set BTN__INTSTAT, CYREG_PRT0_INTSTAT
.set BTN__MASK, 0x80
.set BTN__PA__CFG0, CYREG_UDB_PA0_CFG0
.set BTN__PA__CFG1, CYREG_UDB_PA0_CFG1
.set BTN__PA__CFG10, CYREG_UDB_PA0_CFG10
.set BTN__PA__CFG11, CYREG_UDB_PA0_CFG11
.set BTN__PA__CFG12, CYREG_UDB_PA0_CFG12
.set BTN__PA__CFG13, CYREG_UDB_PA0_CFG13
.set BTN__PA__CFG14, CYREG_UDB_PA0_CFG14
.set BTN__PA__CFG2, CYREG_UDB_PA0_CFG2
.set BTN__PA__CFG3, CYREG_UDB_PA0_CFG3
.set BTN__PA__CFG4, CYREG_UDB_PA0_CFG4
.set BTN__PA__CFG5, CYREG_UDB_PA0_CFG5
.set BTN__PA__CFG6, CYREG_UDB_PA0_CFG6
.set BTN__PA__CFG7, CYREG_UDB_PA0_CFG7
.set BTN__PA__CFG8, CYREG_UDB_PA0_CFG8
.set BTN__PA__CFG9, CYREG_UDB_PA0_CFG9
.set BTN__PC, CYREG_PRT0_PC
.set BTN__PC2, CYREG_PRT0_PC2
.set BTN__PORT, 0
.set BTN__PS, CYREG_PRT0_PS
.set BTN__SHIFT, 7

/* LEDA */
.set LEDA__0__DM__MASK, 0x1C0000
.set LEDA__0__DM__SHIFT, 18
.set LEDA__0__DR, CYREG_PRT1_DR
.set LEDA__0__HSIOM, CYREG_HSIOM_PORT_SEL1
.set LEDA__0__HSIOM_MASK, 0x0F000000
.set LEDA__0__HSIOM_SHIFT, 24
.set LEDA__0__INTCFG, CYREG_PRT1_INTCFG
.set LEDA__0__INTSTAT, CYREG_PRT1_INTSTAT
.set LEDA__0__MASK, 0x40
.set LEDA__0__PA__CFG0, CYREG_UDB_PA1_CFG0
.set LEDA__0__PA__CFG1, CYREG_UDB_PA1_CFG1
.set LEDA__0__PA__CFG10, CYREG_UDB_PA1_CFG10
.set LEDA__0__PA__CFG11, CYREG_UDB_PA1_CFG11
.set LEDA__0__PA__CFG12, CYREG_UDB_PA1_CFG12
.set LEDA__0__PA__CFG13, CYREG_UDB_PA1_CFG13
.set LEDA__0__PA__CFG14, CYREG_UDB_PA1_CFG14
.set LEDA__0__PA__CFG2, CYREG_UDB_PA1_CFG2
.set LEDA__0__PA__CFG3, CYREG_UDB_PA1_CFG3
.set LEDA__0__PA__CFG4, CYREG_UDB_PA1_CFG4
.set LEDA__0__PA__CFG5, CYREG_UDB_PA1_CFG5
.set LEDA__0__PA__CFG6, CYREG_UDB_PA1_CFG6
.set LEDA__0__PA__CFG7, CYREG_UDB_PA1_CFG7
.set LEDA__0__PA__CFG8, CYREG_UDB_PA1_CFG8
.set LEDA__0__PA__CFG9, CYREG_UDB_PA1_CFG9
.set LEDA__0__PC, CYREG_PRT1_PC
.set LEDA__0__PC2, CYREG_PRT1_PC2
.set LEDA__0__PORT, 1
.set LEDA__0__PS, CYREG_PRT1_PS
.set LEDA__0__SHIFT, 6
.set LEDA__DR, CYREG_PRT1_DR
.set LEDA__INTCFG, CYREG_PRT1_INTCFG
.set LEDA__INTSTAT, CYREG_PRT1_INTSTAT
.set LEDA__MASK, 0x40
.set LEDA__PA__CFG0, CYREG_UDB_PA1_CFG0
.set LEDA__PA__CFG1, CYREG_UDB_PA1_CFG1
.set LEDA__PA__CFG10, CYREG_UDB_PA1_CFG10
.set LEDA__PA__CFG11, CYREG_UDB_PA1_CFG11
.set LEDA__PA__CFG12, CYREG_UDB_PA1_CFG12
.set LEDA__PA__CFG13, CYREG_UDB_PA1_CFG13
.set LEDA__PA__CFG14, CYREG_UDB_PA1_CFG14
.set LEDA__PA__CFG2, CYREG_UDB_PA1_CFG2
.set LEDA__PA__CFG3, CYREG_UDB_PA1_CFG3
.set LEDA__PA__CFG4, CYREG_UDB_PA1_CFG4
.set LEDA__PA__CFG5, CYREG_UDB_PA1_CFG5
.set LEDA__PA__CFG6, CYREG_UDB_PA1_CFG6
.set LEDA__PA__CFG7, CYREG_UDB_PA1_CFG7
.set LEDA__PA__CFG8, CYREG_UDB_PA1_CFG8
.set LEDA__PA__CFG9, CYREG_UDB_PA1_CFG9
.set LEDA__PC, CYREG_PRT1_PC
.set LEDA__PC2, CYREG_PRT1_PC2
.set LEDA__PORT, 1
.set LEDA__PS, CYREG_PRT1_PS
.set LEDA__SHIFT, 6

/* NeoPixel_pixl */
.set NeoPixel_pixl__0__DM__MASK, 0x7000
.set NeoPixel_pixl__0__DM__SHIFT, 12
.set NeoPixel_pixl__0__DR, CYREG_PRT3_DR
.set NeoPixel_pixl__0__HSIOM, CYREG_HSIOM_PORT_SEL3
.set NeoPixel_pixl__0__HSIOM_MASK, 0x000F0000
.set NeoPixel_pixl__0__HSIOM_SHIFT, 16
.set NeoPixel_pixl__0__INTCFG, CYREG_PRT3_INTCFG
.set NeoPixel_pixl__0__INTSTAT, CYREG_PRT3_INTSTAT
.set NeoPixel_pixl__0__MASK, 0x10
.set NeoPixel_pixl__0__PA__CFG0, CYREG_UDB_PA3_CFG0
.set NeoPixel_pixl__0__PA__CFG1, CYREG_UDB_PA3_CFG1
.set NeoPixel_pixl__0__PA__CFG10, CYREG_UDB_PA3_CFG10
.set NeoPixel_pixl__0__PA__CFG11, CYREG_UDB_PA3_CFG11
.set NeoPixel_pixl__0__PA__CFG12, CYREG_UDB_PA3_CFG12
.set NeoPixel_pixl__0__PA__CFG13, CYREG_UDB_PA3_CFG13
.set NeoPixel_pixl__0__PA__CFG14, CYREG_UDB_PA3_CFG14
.set NeoPixel_pixl__0__PA__CFG2, CYREG_UDB_PA3_CFG2
.set NeoPixel_pixl__0__PA__CFG3, CYREG_UDB_PA3_CFG3
.set NeoPixel_pixl__0__PA__CFG4, CYREG_UDB_PA3_CFG4
.set NeoPixel_pixl__0__PA__CFG5, CYREG_UDB_PA3_CFG5
.set NeoPixel_pixl__0__PA__CFG6, CYREG_UDB_PA3_CFG6
.set NeoPixel_pixl__0__PA__CFG7, CYREG_UDB_PA3_CFG7
.set NeoPixel_pixl__0__PA__CFG8, CYREG_UDB_PA3_CFG8
.set NeoPixel_pixl__0__PA__CFG9, CYREG_UDB_PA3_CFG9
.set NeoPixel_pixl__0__PC, CYREG_PRT3_PC
.set NeoPixel_pixl__0__PC2, CYREG_PRT3_PC2
.set NeoPixel_pixl__0__PORT, 3
.set NeoPixel_pixl__0__PS, CYREG_PRT3_PS
.set NeoPixel_pixl__0__SHIFT, 4
.set NeoPixel_pixl__DR, CYREG_PRT3_DR
.set NeoPixel_pixl__INTCFG, CYREG_PRT3_INTCFG
.set NeoPixel_pixl__INTSTAT, CYREG_PRT3_INTSTAT
.set NeoPixel_pixl__MASK, 0x10
.set NeoPixel_pixl__PA__CFG0, CYREG_UDB_PA3_CFG0
.set NeoPixel_pixl__PA__CFG1, CYREG_UDB_PA3_CFG1
.set NeoPixel_pixl__PA__CFG10, CYREG_UDB_PA3_CFG10
.set NeoPixel_pixl__PA__CFG11, CYREG_UDB_PA3_CFG11
.set NeoPixel_pixl__PA__CFG12, CYREG_UDB_PA3_CFG12
.set NeoPixel_pixl__PA__CFG13, CYREG_UDB_PA3_CFG13
.set NeoPixel_pixl__PA__CFG14, CYREG_UDB_PA3_CFG14
.set NeoPixel_pixl__PA__CFG2, CYREG_UDB_PA3_CFG2
.set NeoPixel_pixl__PA__CFG3, CYREG_UDB_PA3_CFG3
.set NeoPixel_pixl__PA__CFG4, CYREG_UDB_PA3_CFG4
.set NeoPixel_pixl__PA__CFG5, CYREG_UDB_PA3_CFG5
.set NeoPixel_pixl__PA__CFG6, CYREG_UDB_PA3_CFG6
.set NeoPixel_pixl__PA__CFG7, CYREG_UDB_PA3_CFG7
.set NeoPixel_pixl__PA__CFG8, CYREG_UDB_PA3_CFG8
.set NeoPixel_pixl__PA__CFG9, CYREG_UDB_PA3_CFG9
.set NeoPixel_pixl__PC, CYREG_PRT3_PC
.set NeoPixel_pixl__PC2, CYREG_PRT3_PC2
.set NeoPixel_pixl__PORT, 3
.set NeoPixel_pixl__PS, CYREG_PRT3_PS
.set NeoPixel_pixl__SHIFT, 4

/* Miscellaneous */
.set CYDEV_BCLK__HFCLK__HZ, 24000000
.set CYDEV_BCLK__HFCLK__KHZ, 24000
.set CYDEV_BCLK__HFCLK__MHZ, 24
.set CYDEV_BCLK__SYSCLK__HZ, 24000000
.set CYDEV_BCLK__SYSCLK__KHZ, 24000
.set CYDEV_BCLK__SYSCLK__MHZ, 24
.set CYDEV_CHIP_DIE_LEOPARD, 1
.set CYDEV_CHIP_DIE_PSOC4A, 26
.set CYDEV_CHIP_DIE_PSOC5LP, 2
.set CYDEV_CHIP_DIE_PSOC5TM, 3
.set CYDEV_CHIP_DIE_TMA4, 4
.set CYDEV_CHIP_DIE_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_FM0P, 5
.set CYDEV_CHIP_FAMILY_FM3, 6
.set CYDEV_CHIP_FAMILY_FM4, 7
.set CYDEV_CHIP_FAMILY_PSOC3, 1
.set CYDEV_CHIP_FAMILY_PSOC4, 2
.set CYDEV_CHIP_FAMILY_PSOC5, 3
.set CYDEV_CHIP_FAMILY_PSOC6, 4
.set CYDEV_CHIP_FAMILY_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_USED, CYDEV_CHIP_FAMILY_PSOC4
.set CYDEV_CHIP_JTAG_ID, 0x04C81193
.set CYDEV_CHIP_MEMBER_3A, 1
.set CYDEV_CHIP_MEMBER_4A, 26
.set CYDEV_CHIP_MEMBER_4AA, 25
.set CYDEV_CHIP_MEMBER_4AB, 30
.set CYDEV_CHIP_MEMBER_4AC, 14
.set CYDEV_CHIP_MEMBER_4AD, 15
.set CYDEV_CHIP_MEMBER_4AE, 16
.set CYDEV_CHIP_MEMBER_4D, 20
.set CYDEV_CHIP_MEMBER_4E, 6
.set CYDEV_CHIP_MEMBER_4F, 27
.set CYDEV_CHIP_MEMBER_4G, 4
.set CYDEV_CHIP_MEMBER_4H, 24
.set CYDEV_CHIP_MEMBER_4I, 32
.set CYDEV_CHIP_MEMBER_4J, 21
.set CYDEV_CHIP_MEMBER_4K, 22
.set CYDEV_CHIP_MEMBER_4L, 31
.set CYDEV_CHIP_MEMBER_4M, 29
.set CYDEV_CHIP_MEMBER_4N, 11
.set CYDEV_CHIP_MEMBER_4O, 8
.set CYDEV_CHIP_MEMBER_4P, 28
.set CYDEV_CHIP_MEMBER_4Q, 17
.set CYDEV_CHIP_MEMBER_4R, 9
.set CYDEV_CHIP_MEMBER_4S, 12
.set CYDEV_CHIP_MEMBER_4T, 10
.set CYDEV_CHIP_MEMBER_4U, 5
.set CYDEV_CHIP_MEMBER_4V, 23
.set CYDEV_CHIP_MEMBER_4W, 13
.set CYDEV_CHIP_MEMBER_4X, 7
.set CYDEV_CHIP_MEMBER_4Y, 18
.set CYDEV_CHIP_MEMBER_4Z, 19
.set CYDEV_CHIP_MEMBER_5A, 3
.set CYDEV_CHIP_MEMBER_5B, 2
.set CYDEV_CHIP_MEMBER_6A, 33
.set CYDEV_CHIP_MEMBER_FM3, 37
.set CYDEV_CHIP_MEMBER_FM4, 38
.set CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1, 34
.set CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2, 35
.set CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3, 36
.set CYDEV_CHIP_MEMBER_UNKNOWN, 0
.set CYDEV_CHIP_MEMBER_USED, CYDEV_CHIP_MEMBER_4A
.set CYDEV_CHIP_DIE_EXPECT, CYDEV_CHIP_MEMBER_USED
.set CYDEV_CHIP_DIE_ACTUAL, CYDEV_CHIP_DIE_EXPECT
.set CYDEV_CHIP_REV_LEOPARD_ES1, 0
.set CYDEV_CHIP_REV_LEOPARD_ES2, 1
.set CYDEV_CHIP_REV_LEOPARD_ES3, 3
.set CYDEV_CHIP_REV_LEOPARD_PRODUCTION, 3
.set CYDEV_CHIP_REV_PSOC4A_ES0, 17
.set CYDEV_CHIP_REV_PSOC4A_PRODUCTION, 17
.set CYDEV_CHIP_REV_PSOC5LP_ES0, 0
.set CYDEV_CHIP_REV_PSOC5LP_PRODUCTION, 0
.set CYDEV_CHIP_REV_PSOC5TM_ES0, 0
.set CYDEV_CHIP_REV_PSOC5TM_ES1, 1
.set CYDEV_CHIP_REV_PSOC5TM_PRODUCTION, 1
.set CYDEV_CHIP_REV_TMA4_ES, 17
.set CYDEV_CHIP_REV_TMA4_ES2, 33
.set CYDEV_CHIP_REV_TMA4_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_3A_ES1, 0
.set CYDEV_CHIP_REVISION_3A_ES2, 1
.set CYDEV_CHIP_REVISION_3A_ES3, 3
.set CYDEV_CHIP_REVISION_3A_PRODUCTION, 3
.set CYDEV_CHIP_REVISION_4A_ES0, 17
.set CYDEV_CHIP_REVISION_4A_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_4AA_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4AB_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4AC_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4AD_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4AE_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4D_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD, 0
.set CYDEV_CHIP_REVISION_4E_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION_256K, 0
.set CYDEV_CHIP_REVISION_4G_ES, 17
.set CYDEV_CHIP_REVISION_4G_ES2, 33
.set CYDEV_CHIP_REVISION_4G_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_4H_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4I_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4J_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4K_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4L_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4M_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4N_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4O_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4P_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4Q_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4R_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4S_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4T_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4U_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4V_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4W_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4X_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4Y_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4Z_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_5A_ES0, 0
.set CYDEV_CHIP_REVISION_5A_ES1, 1
.set CYDEV_CHIP_REVISION_5A_PRODUCTION, 1
.set CYDEV_CHIP_REVISION_5B_ES0, 0
.set CYDEV_CHIP_REVISION_5B_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_6A_ES, 17
.set CYDEV_CHIP_REVISION_6A_NO_UDB, 33
.set CYDEV_CHIP_REVISION_6A_PRODUCTION, 33
.set CYDEV_CHIP_REVISION_FM3_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_FM4_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_USED, CYDEV_CHIP_REVISION_4A_PRODUCTION
.set CYDEV_CHIP_REV_EXPECT, CYDEV_CHIP_REVISION_USED
.set CYDEV_CONFIG_READ_ACCELERATOR, 1
.set CYDEV_CONFIG_UNUSED_IO_AllowButWarn, 0
.set CYDEV_CONFIG_UNUSED_IO_AllowWithInfo, 1
.set CYDEV_CONFIG_UNUSED_IO_Disallowed, 2
.set CYDEV_CONFIG_UNUSED_IO, CYDEV_CONFIG_UNUSED_IO_Disallowed
.set CYDEV_CONFIGURATION_COMPRESSED, 1
.set CYDEV_CONFIGURATION_MODE_COMPRESSED, 0
.set CYDEV_CONFIGURATION_MODE, CYDEV_CONFIGURATION_MODE_COMPRESSED
.set CYDEV_CONFIGURATION_MODE_DMA, 2
.set CYDEV_CONFIGURATION_MODE_UNCOMPRESSED, 1
.set CYDEV_DEBUG_PROTECT_KILL, 4
.set CYDEV_DEBUG_PROTECT_OPEN, 1
.set CYDEV_DEBUG_PROTECT, CYDEV_DEBUG_PROTECT_OPEN
.set CYDEV_DEBUG_PROTECT_PROTECTED, 2
.set CYDEV_DEBUGGING_DPS_Disable, 3
.set CYDEV_DEBUGGING_DPS_SWD, 2
.set CYDEV_DEBUGGING_DPS, CYDEV_DEBUGGING_DPS_SWD
.set CYDEV_DEBUGGING_ENABLE, 1
.set CYDEV_DFT_SELECT_CLK0, 1
.set CYDEV_DFT_SELECT_CLK1, 2
.set CYDEV_HEAP_SIZE, 0x80
.set CYDEV_IMO_TRIMMED_BY_USB, 0
.set CYDEV_IMO_TRIMMED_BY_WCO, 0
.set CYDEV_IS_EXPORTING_CODE, 0
.set CYDEV_IS_IMPORTING_CODE, 0
.set CYDEV_PROJ_TYPE, 0
.set CYDEV_PROJ_TYPE_BOOTLOADER, 1
.set CYDEV_PROJ_TYPE_LAUNCHER, 5
.set CYDEV_PROJ_TYPE_LOADABLE, 2
.set CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER, 4
.set CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER, 3
.set CYDEV_PROJ_TYPE_STANDARD, 0
.set CYDEV_STACK_SIZE, 0x0400
.set CYDEV_USE_BUNDLED_CMSIS, 1
.set CYDEV_VARIABLE_VDDA, 1
.set CYDEV_VDDA_MV, 3300
.set CYDEV_VDDD_MV, 3300
.set CYDEV_WDT_GENERATE_ISR, 1
.set CYIPBLOCK_M0S8_CTBM_VERSION, 0
.set CYIPBLOCK_m0s8cpuss_VERSION, 0
.set CYIPBLOCK_m0s8csd_VERSION, 0
.set CYIPBLOCK_m0s8gpio2_VERSION, 0
.set CYIPBLOCK_m0s8hsiom4a_VERSION, 0
.set CYIPBLOCK_m0s8lcd_VERSION, 0
.set CYIPBLOCK_m0s8lpcomp_VERSION, 0
.set CYIPBLOCK_m0s8pclk_VERSION, 0
.set CYIPBLOCK_m0s8sar_VERSION, 0
.set CYIPBLOCK_m0s8scb_VERSION, 0
.set CYIPBLOCK_m0s8srssv2_VERSION, 1
.set CYIPBLOCK_m0s8tcpwm_VERSION, 0
.set CYIPBLOCK_m0s8udbif_VERSION, 0
.set CYIPBLOCK_S8_GPIO_VERSION, 2
.set CYDEV_BOOTLOADER_ENABLE, 0
.endif

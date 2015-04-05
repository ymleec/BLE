/******************************************************************************
* Project Name		: ADD YOUR PROJECT NAME HERE
* File Name			: Init.c
* Version 			: 1.0
* Device Used		: CY8C4247LQI-BL483
* Software Used		: ADD PSOC CREATOR VERSION USED FOR YOUR PROJECT
* Compiler    		: ARM GCC 4.8.4
* Related Hardware	: CY8CKIT-042-BLE Bluetooth Low Energy Pioneer Kit 
* Owner				: ADD YOUR EMAIL ID HERE
*
********************************************************************************
* Copyright (2015), Cypress Semiconductor Corporation. All Rights Reserved.
********************************************************************************
* This software is owned by Cypress Semiconductor Corporation (Cypress)
* and is protected by and subject to worldwide patent protection (United
* States and foreign), United States copyright laws and international treaty
* provisions. Cypress hereby grants to licensee a personal, non-exclusive,
* non-transferable license to copy, use, modify, create derivative works of,
* and compile the Cypress Source Code and derivative works for the sole
* purpose of creating custom software in support of licensee product to be
* used only in conjunction with a Cypress integrated circuit as specified in
* the applicable agreement. Any reproduction, modification, translation,
* compilation, or representation of this software except as specified above 
* is prohibited without the express written permission of Cypress.
*
* Disclaimer: CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH 
* REGARD TO THIS MATERIAL, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* Cypress reserves the right to make changes without further notice to the 
* materials described herein. Cypress does not assume any liability arising out 
* of the application or use of any product or circuit described herein. Cypress 
* does not authorize its products for use as critical components in life-support 
* systems where a malfunction or failure may reasonably be expected to result in 
* significant injury to the user. The inclusion of Cypress' product in a life-
* support systems application implies that the manufacturer assumes all risk of 
* such use and in doing so indemnifies Cypress against all charges. 
*
* Use of this Software may be limited by and subject to the applicable Cypress
* software license agreement. 
*******************************************************************************/

/********************************************************************************
*	Description - This file contains system initialization routine
********************************************************************************/

#include <BLE Interface.h>
#include <Configuration.h>
#include <LowPower.h>
#include <Project.h>

/*******************************************************************************
* Function Name: InitializeSystem
********************************************************************************
*
* Summary:
*  Systm initialization function.
*
* Parameters:  
*  None
*
* Return: 
*  None
*
*******************************************************************************/
void InitializeSystem(void)
{
    CyGlobalIntEnable;      /* Enable Global Interrupts*/
    
    /* Internal low power oscillator is no longer required after Watch Crystal oscillator is started */
    CySysClkIloStop();
    
    /* Set the divider for ECO, ECO will be used as source when IMO is switched off to save power */
    CySysClkWriteEcoDiv(CY_SYS_CLK_ECO_DIV8);
    
    BLE_Engine_Start();     /* start the BLE interface */
    
    /* Wait for BLE Component to Initialize */
    while (CyBle_GetState() == CYBLE_STATE_INITIALIZING)
    {
        CyBle_ProcessEvents(); 
    }
    
#if (CONSOLE_LOG_ENABLE)
    Console_Start();  /* Console log interface */
    Console_UartPutString("System initialization complete\r\n"); 
#endif /* End of #if (CONSOLE_LOG_ENABLE) */
    
    /* ADD YOUR CODE TO INITIALIZE OTHER COMPONENTS IN YOUR DESIGN */
}

/* [] END OF FILE */

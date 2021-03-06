/******************************************************************************
* Project Name		: ADD YOUR PROJECT NAME HERE
* File Name			: BLE Interface.c
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
* Description -  This file contains routines that handle all the BLE interface  
* connection establishment procedures and event handlers.
********************************************************************************/

#include <BLE Interface.h>
#include <Configuration.h>
#include <project.h>
#include <stdio.h>

/***************************************
*    Function declarations
***************************************/
void BLE_StackEventHandler(uint32 event, void* eventParam);
void BLE_SERVICE_NAME_CallBack(uint32 event, void* eventParam); /* PLACEHOLDER BLE SERVICE EVENT HANDLER ROUTINE */

/***************************************
*    Global variables
***************************************/

/*******************************************************************************
* Function Name: BLE_Engine_Start
********************************************************************************
*
* Summary:
*  Application level API for starting the BLE interface. The API internally calls
*  other BLE interface init APIs to setup the system.
*
* Parameters:  
*  None
*
* Return: 
*  None
*
*******************************************************************************/
CYBLE_API_RESULT_T BLE_Engine_Start(void)
{
    CYBLE_API_RESULT_T apiResult;
    
    apiResult = CyBle_Start(BLE_StackEventHandler);
    
    if(apiResult != CYBLE_ERROR_OK)
    {
        CYASSERT(0);    
    }
    
    /* ADD YOUR CODE TO REGISTER OTHER BLE SERVICE SPECIFIC EVENT HANDLERS */
   
    return apiResult;
}

/*******************************************************************************
* Function Name: BLE_Run
********************************************************************************
*
* Summary:
*  BLE interface processing engine. This API should be continuously called by 
*  the application in its main loop.
*
* Parameters:  
*  None
*
* Return: 
*  None
*
*******************************************************************************/
void BLE_Run(void)
{
    CyBle_ProcessEvents();
    
    /* ADD YOUR CODE TO PERFORM OTHER BLE OPERATIONS IN MAIN LOOP. 
     * STORING BONDING INFORMATION TO FLASH IS ONE EXAMPLE */
}

/*******************************************************************************
* Function Name: BLE_StackEventHandler
********************************************************************************
*
* Summary:
*   BLE stack generic event handler routine for handling connection, discovery, 
*   security etc. events.
*
* Parameters:  
*  event - event that triggered this callback
*  eventParam - parameters for the event.
*
* Return: 
*  None
*******************************************************************************/
void BLE_StackEventHandler(uint32 event, void* eventParam)
{
    CYBLE_API_RESULT_T apiResult;
    
    (void) eventParam;
    
    switch(event)
    {
        case CYBLE_EVT_GAP_DEVICE_DISCONNECTED:
            
        break;
        
        case CYBLE_EVT_STACK_ON:
            /* Put the device into discoverable mode so that remote can search it. */
            apiResult = CyBle_GappStartAdvertisement(CYBLE_ADVERTISING_FAST);
            
            if(apiResult != CYBLE_ERROR_OK)
            {
                CYASSERT(0);    
            }
        break;
            
        /* ADD YOUR CODE TO HANDLE OTHER GENERIC BLE STACK EVENTS */
            
        /* All the BLE stack events can be found in BLE_Stack.h (see CYBLE_EVENT_T enum) and  BLE_eventHandler.h (see
         * CYBLE_EVT_T enum ) */
                
        default:
        
        break;
    }
}

/*******************************************************************************
* Function Name: BLE_SERVICE_NAME_CallBack
********************************************************************************
*
* Summary:
*   This is an event callback function to receive events from the BLE service.
*
* Parameters:
*  event - the event code
*  *eventParam - the event parameters
*
*******************************************************************************/
void BLE_SERVICE_NAME_CallBack(uint32 event, void* eventParam)
{
    (void) eventParam;
    
    switch(event)
    {
        
    }
}

/* [] END OF FILE */

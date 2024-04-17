/*
*   main.cpp
*   
*   Created on: 16-April-2024
*   Author: Khan
*/
//============================ File Header =====================================
//
//   C/C++ Language Header file
//
//==============================================================================
//                               MODULE INFORMATION
//==============================================================================
//
//  $Source:  $
//
//  $Date: 2022/06/05 05:17:07GMT $
//
//  $Revision: 1.0 $
//
//==============================================================================
//                         FILE DESCRIPTION
//==============================================================================
//
//!  \file
//!  This module acts as the main handler of the system. All the system state
//   machines and actions are carried out in this main loop file.
//
//==============================================================================
//                        INCLUDE FILES
//==============================================================================
#include <Arduino.h>
#include "controls.h"
#include "sensor.h"
#include "timer.h"


//==============================================================================
//                       GLOBAL DATA
//==============================================================================
float Temperature = 34.6;
int Humidity = 44;

// Setting default access point credentials
const char* ssid = "TW-27";
const char* password = "9876543210twff";


//==============================================================================
//                       LOCAL FUNCTIONS & CODE
//==============================================================================
//----------------------------------------------------------------------------
//
// void setup() 
//
//! This function acts as a setup function which brings up the necessary 
//  board functions and initializes the states
//
//! return void
//----------------------------------------------------------------------------
void setup() 
{
    Serial.begin(115200);
    Serial.println("Initializing Sensor, Control, Wifi and LED Pins");

    vSetI2CPins();
    vCheckSht31Conn();
}

//----------------------------------------------------------------------------
//
// void loop() 
//
//! This function is the main loop function which will keep on running 
//  and perform certain tasks
//
//! return void
//----------------------------------------------------------------------------
void loop() 
{

}
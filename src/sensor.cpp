/*
*   sensor.cpp
*   
*   Created on: 16-April-2024
*   Author: Hassam
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
//  $Date: 2024/04/16 18:38:51GMT $
//
//  $Revision: 1.0 $
//
//==============================================================================
//                         FILE DESCRIPTION
//==============================================================================
//
//!  \file
//!  This module implements the necessary definitions required for the
//   temperature and humidity sensor measurements
//
//==============================================================================
//                        INCLUDE FILES
//==============================================================================
#include "sensor.h"

//==============================================================================
//                          GLOBAL DATA
//==============================================================================


//==============================================================================
//                       ENUMS & DATA STRUCTURES
//==============================================================================
Adafruit_SHT31 tempHumidSens = Adafruit_SHT31();

//==============================================================================
//                       EXTERNAL DATA
//==============================================================================
bool bTempHumidFound = false;
uint16_t udHumidityReading = 0;
uint16_t udTempReading = 0;
TwoWire I2C_0 = TwoWire();

//==============================================================================
//                       FUNCTIONS & CODE
//==============================================================================
//----------------------------------------------------------------------------
//
// void vSetI2CPins(void)
//
//! This function initializes the I2C pins for the temperature sensor
//
//! return void
//----------------------------------------------------------------------------
void vSetI2CPins(void)
{
    // Initialize the pins of I2C which has temperature and humidity sensor
    I2C_0.begin(TEMP_SENSE_SDA , TEMP_SENSE_SCL , I2C_Frequency);
}

//----------------------------------------------------------------------------
//
// void vScanI2cDevices(void)
//
//! This function initializes the I2C pins for the temperature sensor
//
//! return void
//----------------------------------------------------------------------------
void vScanI2cDevices(void)
{
    byte error, address;
    int nDevices;
    Serial.println("Scanning...");
    nDevices = 0;
    for(address = 1; address < 127; address++ )
    {
      // The i2c_scanner uses the return value of
      // the Write.endTransmisstion to see if
      // a device did acknowledge to the address.
      I2C_0.beginTransmission(address);
      error = I2C_0.endTransmission();
      if (error == 0)
      {
        Serial.print("I2C device found at address 0x");
        if (address<16)
          Serial.print("0");
        Serial.print(address,HEX);
        Serial.println("  !");
        nDevices++;
      }
      else if (error==4)
      {
        Serial.print("Unknown error at address 0x");
        if (address<16)
          Serial.print("0");
        Serial.println(address,HEX);
      }    
    }
    if (nDevices == 0)
      Serial.println("No I2C devices found\n");
    else
      Serial.println("done\n");
    delay(5000);           // wait 5 seconds for next scan
}

//----------------------------------------------------------------------------
//
// bool bCheckSht31Conn(void)
//
//! This function checks for the temperature and humidity sensor connection
//  on the I2C bus 
//
//! return bool
//----------------------------------------------------------------------------
void vCheckSht31Conn(void)
{
    if (!tempHumidSens.begin(0x44))
    {
        Serial.println("Could not find SHT31 IC");
        delay(10);
        bTempHumidFound = false;
    }
    else
    {
        Serial.println("Temperature Humidity Sensor Detected");
        bTempHumidFound = true;
    }
}

//----------------------------------------------------------------------------
//
// void vSenseTempHumidity(void)
//
//! This function reads the temperature and humidity values from the sensor
//
//! return void
//----------------------------------------------------------------------------
void vSenseTempHumidity(void)
{
    // First checking that temperature sensor is connected on I2C
    if (bTempHumidFound == true)
    {
        udHumidityReading = tempHumidSens.readHumidity();
        udTempReading = tempHumidSens.readTemperature();
        Serial.print("Temperature *C = "); Serial.println(udTempReading);
        Serial.print("Humidity % = "); Serial.println(udHumidityReading);

    }
    else
    {
      udTempReading = 255;
      udHumidityReading = 255;
    }
}

//==============================================================================
//                        End Of File
//==============================================================================

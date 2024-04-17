/*
*   timer.cpp
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
//  $Date: 2024/04/16 18:26:07GMT $
//
//  $Revision: 1.0 $
//
//==============================================================================
//                         FILE DESCRIPTION
//==============================================================================
//
//!  \file
//!  This module implements the requried timer functions for calculating tick
//   count and tick difference
//
//==============================================================================
//                        INCLUDE FILES
//==============================================================================
#include "timer.h"


//==============================================================================
//                       LOCAL FUNCTIONS & CODE
//==============================================================================
//----------------------------------------------------------------------------
//
// uint32_t ulTimerRead1ms(void)
//
//! This function reads the current milliseconds tick
//
//! return void
//----------------------------------------------------------------------------
uint32_t ulTimerRead1ms(void)
{
    uint32_t ulTick = 0;
    ulTick = millis();
    return (ulTick);
}

//----------------------------------------------------------------------------
//
// uint32_t ulTimerRead1ms(uint32_t ulRefTick)
//
//! This function gets the difference between the current and previous
//  milliseconds tick using the reference time tick
//
//! return void
//----------------------------------------------------------------------------
uint32_t ulTimerDiff1ms(uint32_t ulRefTick)
{
    uint32_t ulDiff = 0;
    uint32_t ulCurrTick = 0;

    ulCurrTick = millis();
    if (ulCurrTick >= ulRefTick)
    {
        ulDiff = ulCurrTick - ulRefTick;
    }
    else /* Handles wrap-around */
    {
        ulDiff = (0xFFFFFFFF - ulRefTick) + ulCurrTick + 1;
    }

    return (ulDiff);
}

//==============================================================================
//                        End Of File
//==============================================================================
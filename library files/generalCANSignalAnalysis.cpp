//
//  generalCANSignalAnalysis.cpp
//  To be used with CANserver created by Josh Wardell
//
//  Created by Chris Allemang on Jun 11 2020.
//

#include "Arduino.h"
#include "generalCANSignalAnalysis.h"

generalCANSignalAnalysis::generalCANSignalAnalysis() //constructor
{
}

int generalCANSignalAnalysis::getSignal(uint64_t CANMessage, int signalStartBit, int signalLength, float signalFactor, int signalOffset)
{
  _CANMessage = CANMessage;
  _signalStartBit = signalStartBit + 1; //change start bit index to starting at 1
  _signalLength = signalLength;
  _signalFactor = signalFactor;
  _signalOffset = signalOffset;
  _signalMessage = ((1 << _signalLength) - 1) & (_CANMessage >> (_signalStartBit - 1)); //mask unwanted bits and shfit
  _signalMessage = float(unsigned(_signalMessage)) * _signalFactor + _signalOffset; //apply factor and offset
  return (_signalMessage); //return analyzed signal
}

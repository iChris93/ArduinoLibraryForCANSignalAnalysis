//
//  generalCANSignalAnalysis.h
//  To be used with CANserver created by Josh Wardell
//
//  Created by Chris Allemang on Jun 11 2020.
//

#ifndef generalCANSignalAnalysis_h
#define generalCANSignalAnalysis_h

#include "Arduino.h"

class generalCANSignalAnalysis
{
  public:
    generalCANSignalAnalysis(); //constructor
    //function to analyze CAN signal, inputs: 64 bit CANMessage, start bit location (indexed starting at 0), singal bit lenght, signal factor, singal offset
    int getSignal(uint64_t CANMessage, int signalStartBit, int signalLength, float signalFactor, int signalOffset); 
  private: //private variables corresponding to the above public variables
    uint64_t _CANMessage;
    int _signalMessage;
    int _signalStartBit;
    int _signalLength;
    float _signalFactor;
    int _signalOffset;
};


#endif /* generalCANSignalAnalysis_h */

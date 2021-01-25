//
//  generalCANSignalAnalysis.h
//  To be used with CANserver created by Josh Wardell
//
//  Created by Chris Allemang on July 4 2020.
//

#ifndef generalCANSignalAnalysis_h
#define generalCANSignalAnalysis_h

#include "Arduino.h"

class generalCANSignalAnalysis
{
  public:
    generalCANSignalAnalysis(); //constructor
    //function to analyze CAN signal, inputs: 64 bit CANMessage, start bit location (indexed starting at 0), singal bit lenght, signal factor, singal offset
    float getSignal(uint64_t CANMessage, uint8_t signalStartBit, uint8_t signalLength, int signalFactor, int32_t signalOffset, bool ISsigned, bool byteOrder);
    float getSignal(uint64_t CANMessage, uint8_t signalStartBit, uint8_t signalLength, double signalFactor, int32_t signalOffset, bool ISsigned, bool byteOrder);
  
  private: //private variables corresponding to the above public variables
    uint64_t _CANMessage;
    float _signalMessage;
    uint8_t _signalStartBit;
    uint8_t _signalLength;
    int _signalFactorInt;
    double _signalFactorDouble;
    int32_t _signalOffset;
    bool _ISsigned;
    bool _byteOrder;
};


#endif /* generalCANSignalAnalysis_h */

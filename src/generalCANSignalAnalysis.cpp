//
//  generalCANSignalAnalysis.cpp
//  To be used with CANserver created by Josh Wardell
//
//  Created by Chris Allemang on July 4 2020.
//  Modified by E.Burkowski
//

#include "Arduino.h"
#include "generalCANSignalAnalysis.h"


generalCANSignalAnalysis::generalCANSignalAnalysis() //constructor
{
}

uint64_t generalCANSignalAnalysis::bigLittleSwap(uint64_t value)
{
    value = ((value << 8)  & 0xFF00FF00FF00FF00ull) | ((value >> 8)  & 0x00FF00FF00FF00FFull);
    value = ((value << 16) & 0xFFFF0000FFFF0000ull) | ((value >> 16) & 0x0000FFFF0000FFFFull);
    return (value << 32) | (value >> 32);
}

float generalCANSignalAnalysis::getSignal(uint64_t CANMessage, int signalStartBit, int signalLength, int signalFactor, int signalOffset, bool ISsigned, bool byteOrder)
{
    _CANMessage = CANMessage;
    _signalStartBit = signalStartBit;
    _signalLength = signalLength;
    _signalFactorInt = signalFactor;
    _signalOffset = signalOffset;
    _ISsigned = ISsigned;
    _byteOrder = byteOrder;
    if (_byteOrder == BIG_ENDIAN) _CANMessage = bigLittleSwap(_CANMessage);
    _signalMessage = 0xFFFFFFFFul >> (32 - _signalLength) & (_CANMessage >> _signalStartBit); //mask unwanted bits and shift
    if (_ISsigned == true){
        if(_signalMessage > pow(2, _signalLength-1))
        {
            _signalMessage = 0 - (pow(2, _signalLength) - _signalMessage);
        }
        _signalMessage = signed(_signalMessage) * _signalFactorDouble + _signalOffset; //apply factor and offset
    }
    else
    {
        _signalMessage = unsigned(_signalMessage) * _signalFactorInt + _signalOffset; //apply factor and offset
    }
    return (_signalMessage); //return analyzed signal
}

float generalCANSignalAnalysis::getSignal(uint64_t CANMessage, int signalStartBit, int signalLength, double signalFactor, int signalOffset, bool ISsigned, bool byteOrder)
{
    _CANMessage = CANMessage;
    _signalStartBit = signalStartBit;
    _signalLength = signalLength;
    _signalFactorDouble = signalFactor;
    _signalOffset = signalOffset;
    _ISsigned = ISsigned;
    _byteOrder = byteOrder;
    if (_byteOrder == BIG_ENDIAN) _CANMessage = bigLittleSwap(_CANMessage);
    _signalMessage = 0xFFFFFFFFul >> (32 - _signalLength) & (_CANMessage >> _signalStartBit); //mask unwanted bits and shift
    if (_ISsigned == true){
        if(_signalMessage > pow(2, _signalLength-1))
        {
            _signalMessage = 0 - (pow(2, _signalLength) - _signalMessage);
        }
        _signalMessage = float(signed(_signalMessage)) * _signalFactorDouble + _signalOffset; //apply factor and offset
    }
    else
    {
        _signalMessage = float(unsigned(_signalMessage)) * _signalFactorDouble + _signalOffset;
    }
    return (_signalMessage); //return analyzed signal
}

# ArduinoLibaryForCANSignalAnalysis
General Arduino Library to extract CAN signals from messages.

Function:

`int getSignal(uint64_t CANMessage, int signalStartBit, int signalLength, float signalFactor, int signalOffset);`

with inputs from left to right:

64-bit CAN message, signal starting bit location (indexed starting at 0), signal bit length, signal factor/scale/multiplier, signal offset

returns analyzed integer signal

# ArduinoLibraryForCANSignalAnalysis
General Arduino Library to extract CAN signals from messages.

Function:

`int getSignal(uint64_t CANMessage, int signalStartBit, int signalLength, int or dobule signalFactor, int signalOffset, bool ISsigned, bool byteOrder);`

with inputs from left to right:

64-bit CAN message, signal starting bit location (indexed starting at 0), signal bit length, signal factor/scale/multiplier, signal offset, 1 = signed and 0 = unsigned, 1 = little endian and 0 = big endian

returns analyzed integer signal

NOTE: Code cannot currently handle big endian

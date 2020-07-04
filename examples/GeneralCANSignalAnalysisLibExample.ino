
#include "generalCANSignalAnalysis.h" //Include library for analyzing CAN Signals
generalCANSignalAnalysis analyzeMessage; //initialize library
uint64_t test = 0b0000000000000000000000000000000000110000010000000001000000111110100000001010010000010000; //test message having 42000 starting at bit 0, 16000 starting at bit 16, 16400 starting at bit 32, and 48 starting at bit 48
void setup() {
  // put your setup code here, to run once:
Serial.begin(57600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //get.Signal inputs from left to right: CANMessage, starting bit (indexed started at 0), singal length in bits, signal scale, signal offset
int batteryVoltage=analyzeMessage.getSignal(test, 0, 16, 0.01, 0, false, 1); //analyze "test" CAN message starting at bit 0 with a bit lenght of 16, a scale of 0.01, and an offest of 0
Serial.println();
Serial.print("Battery Votlage: ");
Serial.print(batteryVoltage);
Serial.print(" V");
int batteryCurrent=analyzeMessage.getSignal(test, 16, 16, -0.01, 0, false, 1);
Serial.println();
Serial.print("Battery Current: ");
Serial.print(batteryCurrent);
Serial.print(" A");
int rawBatteryCurrent=analyzeMessage.getSignal(test, 32, 16, -0.05, 500, false, 1);
Serial.println();
Serial.print("Raw Battery Current: ");
Serial.print(rawBatteryCurrent);
Serial.print(" A");
int chargeHoursRemaining=analyzeMessage.getSignal(test, 48, 12, 1, 0, false, 1);
Serial.println();
Serial.print("Charge Time Remaining: ");
Serial.print(chargeHoursRemaining);
Serial.print(" min");
delay(1500);
Serial.println();

}

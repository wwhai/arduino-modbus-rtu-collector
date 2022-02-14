#include <ArduinoRS485.h>
#include <ArduinoModbus.h>

void setup()
{
  Serial.begin(115200);
  ModbusRTUClient.begin(115200);
}
float compute(int v)
{
  return v * 5.0 / 1023.0;
}

void loop()
{
  ModbusRTUClient.holdingRegisterWrite(1, 0x00, analogRead(A0));
  ModbusRTUClient.holdingRegisterWrite(1, 0x01, analogRead(A1));
  ModbusRTUClient.holdingRegisterWrite(1, 0x02, analogRead(A2));
  ModbusRTUClient.holdingRegisterWrite(1, 0x03, analogRead(A3));
  ModbusRTUClient.holdingRegisterWrite(1, 0x04, analogRead(A4));
  delay(1000);
}
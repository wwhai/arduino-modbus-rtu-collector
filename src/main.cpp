#include <ArduinoRS485.h>
#include <ArduinoModbus.h>

void setup()
{
  Serial.begin(115200);
  ModbusRTUClient.begin(115200);
}

void loop()
{

  ModbusRTUClient.coilWrite(1, 0x00, 0x00);
  ModbusRTUClient.coilWrite(1, 0x01, 0x01);
  ModbusRTUClient.coilWrite(1, 0x02, 0x00);
  ModbusRTUClient.coilWrite(1, 0x03, 0x01);
  delay(1000);
}
#include <ArduinoRS485.h>
#include <ArduinoModbus.h>
int R = 2;
int G = 4;
int B = 7;
void initIO()
{
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  digitalWrite(R, LOW);
  digitalWrite(G, LOW);
  digitalWrite(B, LOW);
}
float compute(int v)
{
  return v * (5.0 / 1023.0);
}
void setup()
{
  Serial.begin(115200);
  ModbusRTUServer.begin(1, 115200);
  ModbusRTUServer.configureCoils(0, 3);
  initIO();
}

//
// 设置灯色
//
void setRBG(int io, int addr)
{
  if (ModbusRTUServer.coilRead(addr))
  {
    digitalWrite(io, LOW);
  }
  else
  {
    digitalWrite(io, HIGH);
  }
}

void loop()
{
  setRBG(R, 0);
  setRBG(G, 1);
  setRBG(B, 2);

  ModbusRTUServer.poll();
}
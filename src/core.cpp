#include <Arduino.h>
#include "COSensor.h"

#define BUF_SIZE (1024)
char *data = (char *)malloc(BUF_SIZE);

void hexPrintDebug(char *buf, size_t len)
{
  for (int i = 0; i < len; i++)
  {
    if (buf[i] >> 4 == 0)
    {
      Serial.print('0');
    }
    Serial.print(buf[i], HEX);
    Serial.print(' ');
  }
  Serial.println();
}

COSensor coSensor;

void setup()
{
  Serial.begin(115200);
  coSensor.init(17, 16, 9600, 2);
  delay(1000);
  coSensor.switchToQAMode(); //Command to swith sensor to QA mode
  delay(500);
}

void loop()
{
  float conc = coSensor.getConcentration();
  Serial.println(conc, 1);
  delay(1000);
}
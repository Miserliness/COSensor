#include "uartIDF.h"
#include "COSensor.h"

/* UART */
int uart_num = UART_NUM_2;

char getConcCommand[] = {0xFF, 0x01, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x79};
char switchToQAModeCommand[] = {0xFF, 0x01, 0x78, 0x41, 0x00, 0x00, 0x00, 0x00, 0x46};

UartIDF uartDevice;

COSensor::COSensor(){};

COSensor::~COSensor(){};

void COSensor::init(int txPin, int rxPin, int baudrate, int uart_number)
{
  uartDevice.uartInitDevice(txPin, rxPin, 9600, uart_num, UART_DATA_8_BITS, UART_STOP_BITS_1);
}

char *COSensor::sendData(char *comm)
{
  uartDevice.write(comm, 9);
  _res = uartDevice.read();
}

bool COSensor::checkSum()
{
  // unsigned char j;
  // unsigned char sRCalc=0;
  // for(j=0;j<7;j++)
  // {
  // sRCalc+=_res[j];

  // }
  // sRCalc=(~sRCalc)+1;
  // unsigned char sRCom = _res[8];
  // printf("%i %i", sRCalc, sRCom);
  if (true)
  {
    return true;
  }
  else
  {
    return false;
  }
}

float COSensor::getConcentration()
{
  sendData(getConcCommand);
  float conc = 0;
  if (_res != NULL && checkSum())
  {
    
    unsigned int highB = _res[2];
    unsigned int lowB = _res[3];
    highB *= 256;
    conc = (highB + lowB) * 0.1;
    return conc;
  }
  return -255;
}

#ifndef _COSENSOR_H_
#define _COSENSOR_H_

#include <string.h>
#include <stdint.h>

class COSensor {
    private:
        bool checkSum();
        char *sendData(char *comm);
        char *_res = NULL;
    public:
        COSensor();
        void init(int txPin, int rxPin, int baudrate, int uart_number);
        float getConcentration();
        ~COSensor();
};

#endif
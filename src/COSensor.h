#ifndef _COSENSOR_H_
#define _COSENSOR_H_

#include <string.h>
#include <stdint.h>
#include <esp_timer.h>

class COSensor {
    private:
        bool checkSum();
        void sendData(char *comm);
        char *_res = NULL;
    public:
        COSensor();
        void init(int txPin, int rxPin, int baudrate, int uart_number, int timeout);
        float getConcentration();
        void switchToQAMode();
        ~COSensor();
};

#endif
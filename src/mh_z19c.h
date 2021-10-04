#ifndef _MH_Z19C
#define _MH_Z19C

#include <Arduino.h>

class mh_z19c {
public:
    mh_z19c(uint8_t channel);
    int readPPM();
    void selfCalibrationOn();
    void selfCalibrationOff();    

private:
    uint8_t calcCheckSum(uint8_t *packet);

    uint8_t read_co2[8] = {0xff, 0x01, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00};
    uint8_t self_cal_on[8] = {0xff, 0x01, 0x79, 0xA0, 0x00, 0x00, 0x00, 0x00};
    uint8_t self_cal_off[8] = {0xff, 0x01, 0x79, 0x00, 0x00, 0x00, 0x00, 0x00};

    HardwareSerial serial;
};


#endif
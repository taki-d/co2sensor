#include "mh_z19c.h"

mh_z19c::mh_z19c(uint8_t channel) :
    serial(channel)
{
    serial.begin(9600);
}

int mh_z19c::readPPM(){
    serial.write(read_co2, 8);
    serial.write(calcCheckSum(read_co2));
    serial.flush();
    while (serial.available() != 0);

    uint8_t buf[9]; 
    serial.readBytes(buf, 9);
    int ppm = buf[3] | (buf[2] << 8);

    return ppm;
}

void mh_z19c::selfCalibrationOn(){
    serial.write(self_cal_on, 8);
    serial.write(calcCheckSum(self_cal_on));
    serial.flush();
}

void mh_z19c::selfCalibrationOff(){
    serial.write(self_cal_off, 8);
    serial.write(calcCheckSum(self_cal_off));
    serial.flush();
}

uint8_t mh_z19c::calcCheckSum(uint8_t *packet) {
    uint8_t checksum = 0;
  
    for (uint8_t i = 1; i < 8; i++){
        checksum += packet[i];
    }
    return 0xff - checksum + 0x01;
}
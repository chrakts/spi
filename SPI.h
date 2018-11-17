#ifndef SPI_H
#define SPI_H

#include "spiHardware.h"

class SPI
{
    public:
        SPI(uint8_t num);
        ~SPI();
        void begin();
        uint8_t transfer(uint8_t dt);

    protected:

    private:
};

#endif // SPI_H

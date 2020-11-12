#ifndef SPIDEVICE_H
#define SPIDEVICE_H

#include <avr/io.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <errno.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "spi_driver.h"

class spiDevice
{
  public:
    spiDevice(SPI_t *module,PORT_t *spiPort,PORT_t *csPort,uint8_t csPin,bool lsbFirst,SPI_MODE_t mode,SPI_INTLVL_t intLevel,bool clk2x,SPI_PRESCALER_t clockDivision);
    virtual ~spiDevice();

    uint8_t getConfig() { return _config; }
    void setConfig(uint8_t val) { _config = val; }
    SPI_Master_t * getSpi() { return &_spi; }
    void select();
    void unselect();
    uint8_t transceiveByte(uint8_t TXdata);
    void transceiveBytes(uint8_t transceiveLength, uint8_t *transmitBytes, uint8_t *receiveBytes);

  protected:

  private:
    uint8_t _config;
    SPI_Master_t _spi;
    PORT_t *_csPort;
    uint8_t _csPin;
};

#endif // SPIDEVICE_H

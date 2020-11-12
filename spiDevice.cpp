#include "spiDevice.h"
#include "ledHardware.h"

spiDevice::spiDevice(SPI_t *module,PORT_t *spiPort,PORT_t *csPort,uint8_t csPin,bool lsbFirst,SPI_MODE_t mode,SPI_INTLVL_t intLevel,bool clk2x,SPI_PRESCALER_t clockDivision)
{
  //ctor
  _csPort     = csPort;
  _csPin      = csPin;
  _config = SPI_MasterInit(&_spi,module,spiPort,lsbFirst,mode,intLevel,clk2x,clockDivision);
}

spiDevice::~spiDevice()
{
  //dtor
}

void spiDevice::select()
{
  _csPort->OUTCLR = _csPin;
}

void spiDevice::unselect()
{
  _csPort->OUTSET = _csPin;
}

uint8_t spiDevice::transceiveByte(uint8_t TXdata)
{
  _spi.module->CTRL = _config;
  return(SPI_MasterTransceiveByte(&_spi,TXdata));
}

void spiDevice::transceiveBytes(uint8_t transceiveLength, uint8_t *transmitBytes, uint8_t *receiveBytes)
{
uint8_t rec,trans,i;

  select();
  _spi.module->CTRL = _config;
  trans = 0;
  for(i=0;i<transceiveLength;i++)
  {
    if(transmitBytes!=NULL)
      trans = transmitBytes[i];
    rec = SPI_MasterTransceiveByte(&_spi,trans);
    if(receiveBytes!=NULL)
      receiveBytes[i] = rec;
  }
  unselect();
}

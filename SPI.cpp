#include "SPI.h"
#include "Operators.h"
#include <stdlib.h>
#include <stdint.h>
#include <util/delay.h>
#include <avr/sleep.h>


SPI::SPI(uint8_t num)
{
  SPI_PORT.DIRSET = SPI_MOSI | SPI_SCK;
  SPI_PORT.DIRCLR = SPI_MISO;
  SPI_CS_PORT.DIRSET = SPI_CS;
  SPI_CS_PORT.OUTSET = SPI_CS;
  SPI_DEV.CTRL = SPI_ENABLE_bm | SPI_MODE_0_gc | SPI_MASTER_bm | SPI_PRESCALER_DIV128_gc;
 }

SPI::~SPI()
{
    //dtor
}

void SPI::begin()
{
}

uint8_t SPI::transfer(uint8_t dt)
{
  SPI_DEV.DATA = dt;
	do
	{
	} while ( !(SPI_DEV.STATUS & SPI_IF_bm) );
	_delay_us(5);
	return(SPI_DEV.DATA);

}

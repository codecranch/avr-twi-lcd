#include "twi.h"
#include "main.h"

void TWI_Init(void) {
	/* SCL CLOCK 
	* CPU 16Mhz CLK 100khz
	*/
	TWBR = 0x48;
}

void TWI_Start(void) {
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
}

void TWI_Transmit(unsigned char data) {
	TWDR = data;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
}

void TWI_TransmitByAddr(unsigned char data, unsigned char addr) {
	TWI_Start();
	TWI_Transmit(addr);
	TWI_Transmit(data);
	TWI_Stop();
}

void TWI_Stop(void) {
	TWCR = (1<<TWINT) | (1<<TWSTO) | (1<<TWEN);
}
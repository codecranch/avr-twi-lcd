#include "lcd.h"
#include "main.h"
#include "twi.h"

unsigned char portlcd = 0;

void LCD_Init(void) {
	sendHalfByte(0b00000011);
	_delay_ms(5);
	sendHalfByte(0b00000011);
	_delay_us(100);
	sendHalfByte(0b00000011);
	_delay_ms(1);
	sendHalfByte(0b00000010);
	_delay_ms(1);
	sendByte(0b00101000, 0); // Data 4bit, Line 2, Font 5x8
	_delay_ms(1);
	sendByte(0b00001110, 0); //Display ON, Cursor ON, Blink OFF
	_delay_ms(1);

	TWI_TransmitByAddr(portlcd |= 0x08, 0x4E); //BackLight ON
	
	TWI_TransmitByAddr(portlcd &= ~0x02, 0x4E); //LCD Write ON
}

void LCD_BackLight(unsigned char mode) {
	switch(mode) {
		case 0: 
			TWI_TransmitByAddr(portlcd &= ~0x08, 0x4E); //BackLight OFF
			break;
		case 1: 
			TWI_TransmitByAddr(portlcd |= 0x08, 0x4E); //BackLight ON
			break;
	}
}

void sendHalfByte(unsigned char c) {
	c <<= 4;
	
	TWI_TransmitByAddr(portlcd |= 0x04, 0x4E); // Enable E
	_delay_us(50);

	TWI_TransmitByAddr(portlcd | c, 0x4E);

	TWI_TransmitByAddr(portlcd &= ~0x04, 0x4E); // Disable E
	_delay_us(50);

}

void sendByte(unsigned char c, unsigned char mode) {
	if(mode == 0) TWI_TransmitByAddr(portlcd &= ~0x01, 0x4E);
	else TWI_TransmitByAddr(portlcd |= 0x01, 0x4E);
	unsigned char hc = 0;
	hc = c >> 4;
	sendHalfByte(hc);
	sendHalfByte(c);
}

void LCD_sendString(char s[]) {
	char n;
	for(n=0; s[n]!='\0'; n++)
		sendByte(s[n], 1);
}

void LCD_setPosition(unsigned char x, unsigned char y) {
	switch(y) {
		case 0: 
			sendByte(x | 0x80, 0);
			break;
		case 1: 
			sendByte((0x40+ x) | 0x80, 0);
			break;
		case 2: 
			sendByte((0x10+ x) | 0x80, 0);
			break;
		case 3: 
			sendByte((0x50+ x) | 0x80, 0);
			break;
	}
}

void LCD_clear(void) {
	sendByte(0x01, 0);
	_delay_ms(5);
}
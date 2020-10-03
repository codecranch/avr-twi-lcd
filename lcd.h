#ifndef LCD_H_
#define LCD_H_

void LCD_Init(void);
void sendHalfByte(unsigned char);
void sendByte(unsigned char, unsigned char);
void LCD_setPosition(unsigned char, unsigned char);
void LCD_sendString(char[]);
void LCD_clear(void);
void LCD_BackLight(unsigned char);

#endif /* LCD_H_ */
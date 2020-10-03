#### Example Project

**CORE:** ATMEGA16 (16Mhz)

**TWI(I2C) adapter:** based on PCF8574T

**Default PCF8574T address:**

**0x27** - 7bit address
**0x4E**- address & command write

**Support LCD Displays:**

1. LCD 1602A based on HD44780
2. LCD WH1604A (Winstar)

| LCD Pin   | LCD Name  | PCF8574  |
| ------------ | ------------ | ------------ |
|1|VSS(Ground)|x
|2|VDD(+5V)|x
|3|V0(Contrast voltage)|x
|4|RS(Register select)|P0
|5|RW(Read/Write)|P1
|6|E(Enable)|P2
|7|DB0|x
|8|DB1|x
|9|DB2|x
|10|DB3|x
|11|DB4|P4
|12|DB5|P5
|13|DB6|P6
|14|DB7|P7
|15|A(BackLight +5V)|x
|16|K(BackLight Ground)|P3

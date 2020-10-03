#ifndef TWI_H_
#define TWI_H_

void TWI_Start(void);
void TWI_Init(void);
void TWI_Stop(void);
void TWI_Transmit(unsigned char);
void TWI_TransmitByAddr(unsigned char, unsigned char);

#endif /* TWI_H_ */
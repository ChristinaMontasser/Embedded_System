/*
 * SPI_interface.h
 *
 *  Created on: May 21, 2021
 *      Author: Compu Store
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_init(void);
u8 SPI_read();
void SPI_write(u8 data);
void assignPtrCallBack(void (*PtrPassed)(void));
#define Enable 6
#define LSB 5
#define selectMS 4
#define clockPolarity 3
#define clockPhase 2
#define EnableInterrupt 7
#endif /* SPI_INTERFACE_H_ */

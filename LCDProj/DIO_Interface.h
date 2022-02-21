/*
 * DIO_Interface.h
 *
 *  Created on: Mar 29, 2021
 *      Author: Compu Store
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

void DIO_vdSetPortDirection(u8 PortID, u8 PortDirection);
void DIO_vdSetPortValue(u8 PortID , u8 PortValue );
void DIO_vdSetPintDirection(u8 PortID, u8 PinID, u8 PinDirection);
void DIO_vdSetPinValue(u8 PortID , u8 PinID ,u8 PinValue);
u8 DIO_u8GetPinValue(u8 PortID, u8 PinID);
void DIO_vdTogPortValue(u8 PortID);
void DIO_vdTogPinValue(u8 PortID, u8 PinID);

//Ports' IDs
#define PortA 0
#define PortB 1
#define PortC 2
#define PortD 3

#define PORT_INPUT   0
#define PORT_OUTPUT 255


#define PORT_LOW  0

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

//To set pin direction
#define PIN_INPUT   0
#define PIN_OUTPUT  1

//To set pin value
#define PIN_High 1
#define PIN_LOW  0

#endif /* DIO_INTERFACE_H_ */

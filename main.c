/*
 * USART_C.c
 *
 * Created: 09.04.2022 16:09:33
 * Author : ZM
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#define F_CPU 8000000

char WORD[] = {'T', 'e', 's', 't'};
unsigned int count;

ISR(USART_UDRE_vect) {
	if(count <= 4) { UDR = WORD[count]; count++; }
	else { UCSRB = (0 << TXEN) | (0 << UDRIE);	count = 0; }
}


int main(void) {
	UCSRB = (1 << TXEN) | (1 << UDRIE);
	UCSRC = (1 << UCSZ1) | (1 << UCSZ0) | (1 << URSEL);
	UBRRL = 0x33;
	sei();
    while (1);
	return 0;
}


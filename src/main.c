/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
 /**
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include <asf.h>
#include <avr.h>

int main (void)
{
	// Insert system clock initialization code here (sysclk_init()).

	board_init();

	// Insert application code here, after the board has been initialized.
	
	/* Pin 0 of port B will be an output (where LED is) */
	/* Pin 0 of port A will be an input (where button is) */
	SET_BIT(DDRB, 0); 
	CLR_BIT(DDRA, 0); 
	
	while (1)
	{
		/* If input from button is high (being pressed) turn on LED */
		if (GET_BIT(PINA, 0)) {
			SET_BIT(PORTB, 0); /* Set Bit where LED is connected to high */
			for (int i = 0; i < 10000; i++) {} /* Primitive wait function (remove when crystal is added) */
				
			/* wait_avr(500); use this line when crystal is installed correctly */
			
			CLR_BIT(PORTB, 0); /* Turn off light after waiting */
		}
	}
	
	return 0;
}

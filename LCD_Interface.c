/* -------------------Project Name--------------------					
		LCD (16 x 2) Interface with 8051
						    and display character								
	Here we will use P89V51RD2 microcontroller 				
 ----------------------------------------------------	*/
 
/* ------------------- Pin Configuration --------------		
						
					RS       RW    E          D0  ----   D7
				       P2.0     P2.1  P2.2	 P1.0 ----  P1.7  
 ----------------------------------------------------	*/
 
 
 
#include <reg52.h>		/* Register Header files for registers address */

/* sbit_ is command like  #define */

sbit RS = P2^0;			/* here port 2.0 is renamed as RS (register_select)   */

sbit RW = P2^1;			/* Port 2.1 is renamed as a RW (read / write) */

sbit E = P2^2;		       /* Port 2.2 is renamed as a E (Enable) */



void send_command(unsigned int command_value);			/* Prototyping of sending command value function */

void send_data(unsigned int command_data);			/* Prototyping of sending data function */
	
void ms_delay(unsigned int time);				/* Prototyping of delay function */


void main ()	/* Main Start */
{
	
	/* LCD Initialization */
	
	/* 2 lines and 5 x 7 dots in per character */
	
	send_command(0x38);					/* Initialize lcd of 2 lines and 5x7 dots use command (0x38) */
	
	send_command(0x0E);					/* When display is on cursor will blink  */	
	
	send_command(0x01);         /* This will clear the data which was previously wrote to the disply registers */
	
	
	while (1)
	{
		send_command(0x80);						/* shift curser on 1st line */

		send_data('L');
		send_data('C');
		send_data('D');
		
			send_command(0xC0);					/* shit cursor on 2nd line */
		
		send_data('I');
		send_data('N');
		send_data('T');
		send_data('E');
		send_data('R');
		send_data('F');
		send_data('A');
		send_data('C');
		send_data('E');
		
	}
	
	
	
	
}/* main ends here */



void send_command(unsigned int command_value) /* this function send command value p1 to command register_ */
{
	P1 = command_value;			/* command value send to port P1 */
	RW = 0;									/* for accpet data, logic low enble the write data_ pin */
	RS = 0;								/* for selecting instruction command code register in LCD use RS = low */
	E = 1;								/* To latch data present in port 1 to LCD enable pin set to high */
	ms_delay(10);					/* add some delay of 10ms */
	E = 0;								/* then enable pin set to low for completion of latching data */
}


void send_data(unsigned int data_value)
{
	P1 = data_value;			/* Send data for display on lcd to Port 1 */
	RW = 0;								/* read / write pin enable using logic low for writing a data_ */
	RS = 1;								/* selecting data register using logic high */
	E = 1;								/* To latch data present in port 1 to LCD enable pin set to high */
	ms_delay(10);					/* add some delay of 10ms */
	E = 0;								/* then enable pin set to low for completion of latching data */

}


void ms_delay (unsigned int time)
{
	unsigned int i, j;
	
	/* if we pass time argument equal to 1000 then (time * 1 ms) equal to 1 sec of 
		 dealy will generate */
	

	for (i = 0; i < time; i++)
	{
		for (j = 0; j < 113; j++)					/* This will generate delay of 1 m.s. */
		{
		}
	}
	
}

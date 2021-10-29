#include "msp430G2553.h"

void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;
    P1DIR |= BIT6; // P1.6 to output
    TA0CTL = TASSEL_2 +ID_3+MC_1+TACLR; //sets period

    TA0CCR0 = 31249; // Set maximum count value (PWM Period
    TACCR1 = TA0CCR0*.2; //duty cycle

    TA0CCTL0 |= CCIE;
    TA0CCTL1 |= CCIE;

    TA0CCTL0 &=~CCIFG;
    TA0CCTL1 &=~CCIFG;

    _enable_interrupts(); // Enter LPM0
 }
#pragma vector = TIMER0_A0_VECTOR       //define the interrupt service vector
__interrupt void TA0_ISR (void)    // interrupt service routine
{
   P1OUT |=BIT6;
   TA0CCTL0 &=~CCIFG;
}

#pragma vector = TIMER0_A1_VECTOR       //define the interrupt service vector
__interrupt void TA1_ISR (void)    // interrupt service routine
{
   P1OUT &=~BIT6;
   TA0CCTL1 &=~CCIFG;

}




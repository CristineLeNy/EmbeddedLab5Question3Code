# EmbeddedLab5Question3Code

Code for Question 2 of the fifth lab within Rowan University Embedded Class (2021).  

For the lab, we had to change the brightness of the LED using a hardware PWM. The frequency for this project is 4Hz. The period that was used is 250ms and the duty cycle is at 20%.  

For this question, I used a hardware PWM. I used the TASSEL_2 clock since it had 1 megahertz frequency. I also used the divider ID_3 since it would shrink the value needed for TA0CCRO. I decided to use the MOD_1 so that it would be in up mode. This allows for me to change the brighness of the LED progressivly. The TA0CCRO value was 31249 and TA0CCR1 value is 6249.8.

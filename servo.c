#include <servo.h>


void main()
{
   setup_adc_ports(AN0_TO_AN3|VREF_VREF);
   setup_timer_3(T3_DISABLED | T3_DIV_BY_1);
setup_adc(ADC_CLOCK_DIV_2);
  


   while(TRUE)
   {
   float sen0=0;
   
    set_adc_channel(0); 
   sen0=read_adc();    

   if(sen0>0){
         output_high(PIN_B0);      //desactivación del servo
         delay_ms(0.3);
         output_low(PIN_B0);
delay_ms(8.9);
   }
   else{
 output_high(PIN_B0);      //desactivación del servo
         delay_ms(0.5);
         output_low(PIN_B0);
         delay_ms(10);
   }
   }
}

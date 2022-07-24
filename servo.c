#include <18F4550.h>
#device adc=8


//#use delay(clock=20M, xtal)
#use delay(clock=4M, xtal)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8,UART)


void main(void){
   while(true){
   
   if((input(PIN_E0))){

        
        output_high(PIN_B0);
         delay_ms(0.3);
         output_low(PIN_B0);
         delay_ms(8.9);
         output_high(PIN_B0);
         delay_ms(0.3);
         output_low(PIN_B0);
         delay_ms(8.9);

   }else{
   
         
         
         
          output_high(PIN_B0);
         delay_us(2000);
         output_low(PIN_B0);
         delay_us(18000);
   }
   }
}














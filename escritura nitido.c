#include <18F4550.h>
#device adc=8



//#use delay(clock=20M, xtal)
#use delay(clock=4M, xtal)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8,UART)





void main() { 
                            //Declaracion de la Variable “C” de tipo char

while(TRUE) {
   
     
              
   delay_ms(500);
   printf("1");

delay_ms(500);
   printf("2");
delay_ms(500);

 printf("3");
delay_ms(500);
   }


  
}

 
         
   

 

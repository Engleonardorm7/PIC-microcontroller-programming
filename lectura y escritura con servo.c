#include <18F4550.h>
#device adc=8



//#use delay(clock=20M, xtal)
#use delay(clock=4M, xtal)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8,UART)

char a;



#int_RDA                         //Interrupción por recepción de datos

void RDA_isr(){


a=getc();                            //Declaracion de la Variable “C” de tipo char
}
void main () {
while(TRUE) {
   
   enable_interrupts(INT_RDA);   //Habilitación interrupción por recepción RS232
   enable_interrupts(GLOBAL);
   
if(a=='1'){     
        delay_ms(100);
   printf("1");
   output_high(pin_b0);

}else{
  
   output_low(pin_b0);

}


if(a=='2'){  
delay_ms(100); 
 printf("2");
   output_high(pin_b1);
}else{
  
   output_low(pin_b1);

}

if(a=='3'){  
delay_ms(100); 
 printf("3");
output_high(pin_b2);
   }else{

   output_low(pin_b2);

}
}

  
}


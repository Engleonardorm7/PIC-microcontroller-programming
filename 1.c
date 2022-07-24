#include <18f4550.h>                    // declaro pic a usar
#fuses xt,nowdt,nomclr,nolvp,put  // declaro fuses
#use delay(clock=4M)                    // declaro cristal usar
#use rs232(uart1,baud=9600,xmit=PIN_c7,bits=8,parity=N)       // configuro el modulo USART asincrono como TX  
#use fast_io(b)                     
#use fast_io(a)
char data_envio=250;


void main()                             // inicio
{
   set_tris_b(255);                       // asigno puertob como salida
   set_tris_a(255);                     // asigno puertoa como entrada
   
while(true){                            // bucle while

   if( input(pin_a0)==0)                // supervisa que pulsador fue presionado
   { putc('1');                         // envia el caracter 1 por el usart
   while(input(pin_a0)==0);}            // buclea hasta cuando se deja de precionar 
                                        // el pulsador
   if(input(pin_a1)==0)
   {putc('2');
   while(input(pin_a1));}
   
   if(input(pin_a2)==0)
   {putc('3');
   while(input(pin_a2));}
     
     if(input(pin_a3)==0)
   {putc('4'); 
   while(input(pin_a3));}
   
   if(input(pin_b0)==0)
   {putc('5');
   while(input(pin_b0)==0);}  
     }
}                      

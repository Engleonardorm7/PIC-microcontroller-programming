//#include <reconocimiento.h>
#include <18F4550.h>
#include <string.h>
#use delay(clock=4000000)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=9,UART)

void main()
{
char datos[16];         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

gets(datos);

printf(datos);

  // print the string when a newline arrives:
  //if (datos[8]) {
  
    //    clear the string:

{
   
  //  stringComplete = false;
  }

}
//}
/*
  SerialEvent occurs whenever a new data comes in the
  hardware serial RX.  This routine is run between each
  time loop() runs, so using delay inside loop can delay
  response.  Multiple bytes of data may be available.
*/


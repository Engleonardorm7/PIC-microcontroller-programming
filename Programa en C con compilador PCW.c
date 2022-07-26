#include <18F4550.h>
#device adc=8

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES WDT128                   //Watch Dog Timer uses 1:128 Postscale
#FUSES INTRC                    //Internal RC Osc
#FUSES NOPROTECT                //Code not protected from reading
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOPUT                    //No Power Up Timer
#FUSES NOCPD                    //No EE protection
#FUSES STVREN                   //Stack full/underflow will cause reset
#FUSES NODEBUG                  //No Debug mode for ICD
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NOWRT                    //Program memory not write protected
#FUSES NOWRTD                   //Data EEPROM not write protected
#FUSES IESO                     //Internal External Switch Over mode enabled
#FUSES FCMEN                    //Fail-safe clock monitor enabled
#FUSES PBADEN                   //PORTB pins are configured as analog input channels on RESET
#FUSES NOWRTC                   //configuration not registers write protected
#FUSES NOWRTB                   //Boot block not write protected
#FUSES NOEBTR                   //Memory not protected from table reads
#FUSES NOEBTRB                  //Boot block not protected from table reads
#FUSES NOCPB                    //No Boot Block code protection
#FUSES MCLR                     //Master Clear pin enabled
#FUSES LPT1OSC                  //Timer1 configured for low-power operation
#FUSES NOXINST                  //Extended set extension and Indexed Addressing mode disabled (Legacy mode)
#FUSES PLL12                    //Divide By 12(48MHz oscillator input)
#FUSES CPUDIV4                  //System Clock by 4
#FUSES USBDIV                   //USB clock source comes from PLL divide by 2
#FUSES VREGEN                   //USB voltage regulator enabled
#FUSES ICPRT                    //ICPRT enabled

//#use delay(clock=20M, xtal)
#use delay(clock=4M, xtal)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8,UART)


#include <kbd.c>

#define use_portb_kbd TRUE

void main() { 
   kbd_init();                       //Funcion para inicializar el uso del teclado
   port_b_pullups(TRUE); 
   
char C;
char a;                                      //Declaracion de la Variable �C� de tipo char

while(TRUE) {
   
      C = kbd_getc(); 
              
    if ( !input (pin_b0)){
   printf("1");

   }
 if ( !input (pin_b1)){
   printf("2");

   }
 if ( !input (pin_d3)){
   printf("3");

   }
  if ( !input (pin_b3)){
   printf("4");

   }
 if ( !input (pin_b4)){
   printf("5");

   }
 if ( !input (pin_b5)){
   printf("6");

   }
  if ( !input (pin_b6)){
   printf("7");

   }
 if ( !input (pin_b7)){
   printf("8");

   }
 if ( !input (pin_d6)){
   printf("9");

   }
if ( !input (pin_d5)){
   printf("0");

   }

  
}

 
         
   }
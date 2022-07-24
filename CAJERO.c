#include <18f4550.h>
#FUSES XT                  // Crystal osc <= 4mhz for PCM/PCH , 3mhz to 10 mhz for PCD
#FUSES NOWDT               // No Watch Dog Timer
#FUSES NOPUT               // No Power Up Timer
#FUSES NOPROTECT           // Code not protected from reading
#FUSES NODEBUG             // No Debug mode for ICD
#FUSES NOBROWNOUT          // No brownout reset
#FUSES NOLVP               // No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NOCPD               // No EE protection
#FUSES NOWRT               // Program memory not write protected
#fuses HS,NOWDT,NOMCLR,NOPBADEN
#fuses HS,NOWDT,NOMCLR,NOPBADEN
#fuses HS,NOMCLR,NOWDT,NOPBADEN 
#use delay(clock=4Mhz)
#use fast_io(b)
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)

#define use_portb_kbd TRUE

#if defined(__PCH__)
#if defined use_portb_kbd
   #byte kbd = 0xF81            
#else
   #byte kbd = 0xF83              
#endif
#else
#if defined use_portb_kbd
   #byte kbd = 6                 
#else
   #byte kbd = 8                 
#endif
#endif

#if defined use_portb_kbd
   #define set_tris_kbd(x) set_tris_b(x)
#else
   #define set_tris_kbd(x) set_tris_d(x)
#endif

#define COL0 (1 << 0) // PIN_B0
#define COL1 (1 << 1) // PIN_B1
#define COL2 (1 << 2) // PIN_B2
#define COL3 (1 << 3) // PIN_B3

#define ROW0 (1 << 4) // PIN_B4
#define ROW1 (1 << 5) // PIN_B5
#define ROW2 (1 << 6) // PIN_B6
#define ROW3 (1 << 7) // PIN_B7


#define ALL_ROWS (ROW0|ROW1|ROW2|ROW3)


#define ALL_PINS (ALL_ROWS|COL0|COL1|COL2|COL3)

char const KEYS[4][4] = {{'1','2','3','A'},
                         {'4','5','6','B'},
                         {'7','8','9','C'},
                         {'*','0','#','D'}};


#define KBD_DEBOUNCE_FACTOR 33    
void kbd_init() {
}

char kbd_getc( ) {
   static byte kbd_call_count;
   static short int kbd_down;
   static char last_key;
   static byte col;

   byte kchar;
   byte row;

   kchar="";
   if(++kbd_call_count>KBD_DEBOUNCE_FACTOR) {
       switch (col) {
         case 0   : set_tris_kbd(ALL_PINS&~COL0);
                    kbd=~COL0&ALL_PINS;
                    break;
         case 1   : set_tris_kbd(ALL_PINS&~COL1);
                    kbd=~COL1&ALL_PINS;
                    break;
         case 2   : set_tris_kbd(ALL_PINS&~COL2);
                    kbd=~COL2&ALL_PINS;
                    break;
         case 3   : set_tris_kbd(ALL_PINS&~COL3);
                    kbd=~COL3&ALL_PINS;
                    break;
       }

       if(kbd_down) {
         if((kbd & (ALL_ROWS))==(ALL_ROWS)) {
           kbd_down=false;
           kchar=last_key;
           last_key="";
         }
       } else {
          if((kbd & (ALL_ROWS))!=(ALL_ROWS)) {
             if((kbd & ROW0)==0)
               row=0;
             else if((kbd & ROW1)==0)
               row=1;
             else if((kbd & ROW2)==0)
               row=2;
             else if((kbd & ROW3)==0)
               row=3;
             last_key =KEYS[row][col];
             kbd_down = true;
          } else {
             ++col;
             if(col==4)
               col=0;
          }
       }
      kbd_call_count=0;
   }
  set_tris_kbd(ALL_PINS);
  return(kchar);
}

void main(){
   char oprimir=0;
   port_b_pullups(TRUE);
   kbd_init();
  // printf();
   do {
      oprimir=kbd_getc();
      if(oprimir!=0){
         putc(oprimir);
         printf(oprimir);
         delay_ms(500);
      }
   } while (TRUE);
}

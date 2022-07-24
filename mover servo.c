#include <18f4550.h>
   // servo_pwm_232

// Ejemplo con un servo FUTABA S3003
// Alimentación y pulsos a 5V
// Cuadro de Tiempos :
// Periodo 20 ms (Frecuencia 50 Hz)
// Ancho Pulso minimo 0.5 ms
// Ancho pulso medio 1.5 ms
// Ancho pulso maximo 2.5 ms
// TMR0 a 1:16 -> 1 RTCC cada 4.096 ms
// -> 1 Tick cada 0.096 / 256 = 0.016 ms
// -> 20 ms = (4 x RTCC completas) + (1 * RTCC - 30 ticks)
// Ancho Pulso minimo 0.5 ms -> 31 ticks de TMR0
// Ancho pulso medio 1.5 ms -> 93 ticks de TMR0
// Ancho pulso maximo 2.5 ms -> 155 ticks de TMR0

#fuses XT,NOWDT,NOPROTECT,NOLVP,PUT,BROWNOUT
#use delay(clock=4000000)
#use standard_io(b)
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)

#define PIN_SERVO1 PIN_B0

const int AJUSTE_FINO_DE_RTCC = 30;
const int ticks_PULSO_MINIMO = 31;
const int ticks_PULSO_MEDIO = 93;
const int ticks_PULSO_MAXIMO = 155;

int1 flagRTCC = 0;
int contRTCC = 0;
int1 flagSERVO1 = 0;
int tSERVO1 = ticks_PULSO_MEDIO;
char Keypress =0x00;

void eco_servos(void);
void ajusta_servo(void);

#int_rda
void rda_isr() {
  Keypress=0x00;
  if(kbhit()){
    Keypress=getc();
  }
}

#int_RTCC
RTCC_isr(){
  ++contRTCC;
  if(contRTCC==4){
    set_TIMER0(AJUSTE_FINO_DE_RTCC);
  }
  if(contRTCC==5){
    flagRTCC=1;
    contRTCC=0x00;
  }
}

void main() {

int ValTIMER0;

  setup_counters(RTCC_INTERNAL,RTCC_DIV_16);
  enable_interrupts(int_rda);
  enable_interrupts(global);
  printf("\r\n\SERVO Commander\r\n\r\n" );
  eco_servos();
  set_TIMER0(0);
  enable_interrupts(INT_RTCC);
  do {
    // DISPARO DEL PULSO PWM
    if(flagRTCC==1){
      flagRTCC=0;
      output_high(PIN_SERVO1);
      flagSERVO1=1; 
    }
    // CONTROL DE ANCHO DEL PULSO PWM
    if(flagSERVO1==1){
      valTIMER0 = get_TIMER0();
      if(valTIMER0>tSERVO1){
        flagSERVO1=0;
        output_low(PIN_SERVO1);
      } 
    } 
    // CONTROL DESDE LA RS-232
    if(Keypress!=0x00){
      ajusta_servo(); 
      Keypress=0x00;
    }
  } while (TRUE);
}

void ajusta_servo(void){

  switch(Keypress){
    // Periodos Prefijados
    case '1': tSERVO1=ticks_PULSO_MINIMO;
              break;
    case '2': tSERVO1=ticks_PULSO_MEDIO;
              break;
    case '3': tSERVO1=ticks_PULSO_MAXIMO;
              break;
    // Inc Dec Periodo
    case '+': if(++tSERVO1>ticks_PULSO_MAXIMO){
                tSERVO1=ticks_PULSO_MAXIMO;
              }
              break;
    case '-': if(--tSERVO1<ticks_PULSO_MINIMO){
                tSERVO1=ticks_PULSO_MINIMO;
              }
              break;
    // Dame Periodo actual
    case 'r': eco_servos();
              break;
  }
}

void eco_servos(void){
  printf("S=%u\r\n",tSERVO1);
}




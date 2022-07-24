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

void main()
{

   setup_adc_ports(AN0_TO_AN3|VSS_VDD);
   setup_adc(ADC_CLOCK_DIV_2);
   setup_wdt(WDT_OFF);
   setup_timer_0(RTCC_INTERNAL);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_timer_3(T3_DISABLED|T3_DIV_BY_1);
   setup_ccp1(CCP_OFF);
   setup_comparator(NC_NC_NC_NC);

float sen0=0;
float sen1=0;
float sen2=0;
float sen3=0;
   //TODO: User Code


 set_adc_channel(0);
   sen0=read_adc();
   
   set_adc_channel(1);
    
   sen1=read_adc();
   
    set_adc_channel(2);
   sen2=read_adc();
   
   set_adc_channel(3);

   sen3=read_adc();


   
   enable_interrupts(INT_RDA);   //Habilitación interrupción por recepción RS232
   enable_interrupts(GLOBAL);
 
 while(true){
  set_adc_channel(3);
   sen3=read_adc();
 delay_ms(100);
   printf("%02.1f",sen3);
delay_ms(100);
 if((sen3>9)&&(sen3<13)){
 output_high(pin_e1);
    output_low(pin_e0);
 
 }
 
 else{
 output_low(pin_e1);
    output_low(pin_e0);
if(sen3<=7){
output_high(pin_d6);
output_low(pin_d7);
}else{
output_low(pin_d6);
output_low(pin_d7);
}
 }
}

  
}


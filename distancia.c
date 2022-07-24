#include <18F4550.h>
#device adc=8

//#use delay(clock=20M, xtal)
#use delay(clock=4M, xtal)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8,UART)

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


     //TODO: User Code
float sen0=0;
float sen1=0;
int sen2=0;
int sen3=0;




while (true){ 


 set_adc_channel(0);
   sen0=read_adc();
   
   set_adc_channel(1);
    
   sen1=read_adc();
   
    set_adc_channel(2);
   sen2=read_adc();
   
   set_adc_channel(3);

   sen3=read_adc();
   
   



   
   //sensor de linea
   if(sen0<=214){
   
   printf("Fresa detectada");//distancia entre el sensor y la fresa en la cuchara
   output_high(pin_b2);
   output_high(PIN_B0);
         delay_us(2000);
         output_low(PIN_B0);
         delay_us(18000);
           

   }

}  if(sen0>214){
  printf("no se ha detectado nada");
   output_low(pin_b2);
    output_high(PIN_B0);
         delay_ms(0.3);
         output_low(PIN_B0);
delay_ms(8.9);
         
         

   
   } 
}








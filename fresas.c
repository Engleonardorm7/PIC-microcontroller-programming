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
float sen1=0;
int sen2=0;
int sen3=0;
int sen4=0;
float x=0;

while (true){ 
if(((input(pin_c0))&&(input(pin_c1)))==1){

while (true){ 


 set_adc_channel(0);
   sen1=read_adc();
   
   set_adc_channel(1);
    
   sen2=read_adc();
   
    set_adc_channel(2);
   sen3=read_adc();
   
   set_adc_channel(3);

   sen4=read_adc();
   
   
x=((2)*sen1);


   
   //sensor de linea
   if(sen2==10){ 
   
    printf("Fresa detectada");//distancia entre el sensor y la fresa en la cuchara
   output_high(pin_b2);
   output_high(PIN_B0);
         delay_us(2000);
         output_low(PIN_B0);
         delay_us(18000);
         delay_ms(5000);
   }
   else{
   
    printf("No se ha detectado nada");
   output_low(pin_b2);
    output_high(PIN_B0);
         delay_ms(0.3);
         output_low(PIN_B0);
         delay_ms(8.9);
   }
   
   //sensor de luz inicial
if(sen3==255){
   output_high(pin_b3);
   delay_ms(3000);                //tiempo que la fresa corre por la banda
   }
   else{
   output_low(pin_b3);
   }
   
   
   output_high(pin_b1);        // la banda 2 se mueve continuamente
  
  
  //sensor de linea
  
     if(sen4==255){                  //distancia del sensor y la fresa con chocolate
   output_high(pin_b1);
   delay_ms(3000);                  //tiempo en llegar al sensor de temperatura
   }
   else{
      output_low(pin_b1);// la banda 2 se mueve continuamente
   }
   
   //sensor de temperatura

   
if(sen1==7){               //14 ºC - 15 ºC
   output_high(pin_b1);
      
 printf("%2.1f",x);
delay_ms(3000);
break;
   }
   else{
   output_low(pin_b1);
    printf("%2.1f",x);
delay_ms(1000);
break;
   }
}
}
else{
output_low(pin_b0);
output_low(pin_b1);
output_low(pin_b3);

delay_ms(30);
}
}
}





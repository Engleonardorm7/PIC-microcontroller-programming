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
while(TRUE) {

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
   
if((input(PIN_B3)==1)||(a=='1')){ 

   delay_ms(10);
        
        
        
         
         if((sen1<=148)||(sen0<=139)||(sen2<=40)){
         
         printf("Fresa detectada");
         }else{
         printf("N");
         }
        
    if(sen1<=148){
    //distancia entre el sensor de linea y la fresa 
    output_high(pin_e1);
    output_low(pin_e0);
    

    }

        
    if(sen0<=139){
    
    //distancia entre el sensor de distancia y la fresa en la cuchara
     
           output_low(pin_e1);
    output_low(pin_e0);
    
      
    output_high(PIN_B0);
         delay_us(2000);
         output_low(PIN_B0);
         delay_us(18000);
           

   }

else{
  
   
    output_high(PIN_B0);
         delay_ms(0.3);
         output_low(PIN_B0);
delay_ms(8.9);



}     

if(sen2<=40){


   //distancia entre el sensor de luz y la fresa 
    output_high(pin_d6);
    output_low(pin_d7);
}
else{
output_low(pin_d6);
output_low(pin_d7);
}
        
        if((input(PIN_D4)==1)){
        
  set_adc_channel(3);
   sen3=read_adc();
 delay_ms(10);
   printf("%02.1f",sen3);

if(sen3<=7){
output_high(pin_d6);
output_low(pin_d7);
}else{
output_low(pin_d6);
output_low(pin_d7);
}
}

  

   
   
   }else{

  delay_ms(10); 
 printf("paila ");
 output_low(pin_d6);
    output_low(pin_d7);
        output_low(pin_e1);
    output_low(pin_e0);

   
}


}

  
}


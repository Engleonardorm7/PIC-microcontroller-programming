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

  setup_adc_ports(AN0_TO_AN4|VSS_VDD);
   setup_adc(ADC_CLOCK_DIV_2);

   setup_spi(SPI_SS_DISABLED);
   setup_wdt(WDT_OFF);
   setup_timer_0(RTCC_INTERNAL);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_ccp1(CCP_OFF);
   setup_comparator(NC_NC_NC_NC);


float sen0=0;
float sen1=0;
int sen2=0;
int sen3=0;
float sen5=0;
   //TODO: User Code


 set_adc_channel(0);
   sen0=read_adc();
   
   set_adc_channel(1);
    
   sen1=read_adc();
   
    set_adc_channel(2);
   sen2=read_adc();
   
   set_adc_channel(5);

   sen5=read_adc();


   
   enable_interrupts(INT_RDA);   //Habilitación interrupción por recepción RS232
   enable_interrupts(GLOBAL);
 
 while(true){
  set_adc_channel(5);
   sen5=read_adc();
 delay_ms(100);
   printf("%02.1f",sen0);
delay_ms(100);

}

  
}

  

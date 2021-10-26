#INCLUDE <TV_PICKIT2_SHIFT_1.C>
#INCLUDE <TV_PICKIT2_SHIFT_LCD.C>

SIGNED INT16 T1,DUTY;
SIGNED INT8 BDN,CAPSO;
#INT_TIMER3
VOID INTERRUPT_TIMER3()
{
   SET_TIMER3(3036);
   BDN++;
   IF(BDN==10)
   {
      BDN=0;
      T1=GET_TIMER1();  SET_TIMER1(0); //DOC SAU 1 GIAY
      T1=T1/45;   T1=T1*60;   //T1=(T1*4)/3
      GIAI_MA_GAN_CHO_8LED_QUET_16_XOA(T1);
   }
}

VOID PHIM_UP()
{
   IF(!INPUT(UP)&&(DUTY<1000))
   {
      DELAY_QUET_8LED(100);
      IF(!INPUT(UP))
      {
      DUTY=DUTY+10;
      SET_PWM1_DUTY(DUTY);
      CAPSO++;
      XUAT_4LED_7DOAN_2SO(MA7DOAN[CAPSO/10],MA7DOAN[CAPSO%10]);
      DELAY_QUET_8LED(300);
      }
   }
}

VOID PHIM_DW()
{
   IF(!INPUT(DW)&&(DUTY>0))
   {
      DELAY_QUET_8LED(100);
      IF(!INPUT(DW))
      {
         DUTY=DUTY-10;
         SET_PWM1_DUTY(DUTY);
         CAPSO--;
         XUAT_4LED_7DOAN_2SO(MA7DOAN[CAPSO/10],MA7DOAN[CAPSO%10]);
         DELAY_QUET_8LED(300);
      }
   }
}

VOID MAIN()
{
   SET_UP_PORT_IC_CHOT();
   DC_ENABLE=1;
   OUTPUT_LOW(PIN_C1);
   XUAT_BUZZER_RELAY();
   
   SETUP_CCP1(CCP_PWM);
   SETUP_TIMER_2(T2_DIV_BY_16,249,1);
   DUTY=0;  CAPSO=0;
   XUAT_4LED_7DOAN_2SO(MA7DOAN[CAPSO/10],MA7DOAN[CAPSO%10]);
   SET_PWM1_DUTY(DUTY);
   
   ENABLE_INTERRUPTS(GLOBAL);
   ENABLE_INTERRUPTS(INT_TIMER3);
   SETUP_TIMER_3(T3_INTERNAL|T3_DIV_BY_8);
   SET_TIMER3(3036);
   
   SETUP_TIMER_1(T1_EXTERNAL_SYNC|T1_DIV_BY_1);
   SET_TIMER1(0);
   BDN=0;
   
   WHILE(TRUE)
   {
      PHIM_DW();
      PHIM_UP();
      HIEN_THI_8LED_7DOAN_QUET();
      IF(!INPUT(STOP))
      {
         DUTY=0;  CAPSO=0;
         SET_TIMER1(0);
         XUAT_4LED_7DOAN_2SO(MA7DOAN[CAPSO/10],MA7DOAN[CAPSO%10]);
         SET_PWM1_DUTY(DUTY);
      }
   }
}
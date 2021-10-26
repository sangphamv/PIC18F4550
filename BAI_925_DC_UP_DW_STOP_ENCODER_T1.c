#INCLUDE <TV_PICKIT2_SHIFT_1.C>

SIGNED INT8 CAPSO;
UNSIGNED INT16 T1,T1_TAM,DUTY;

VOID PHIM_UP()
{
   IF(!INPUT(UP)&&(DUTY<1000))
   {
      DELAY_QUET_8LED(100);
      IF(!INPUT(UP))
      {
      DUTY=DUTY+50;
      SET_PWM1_DUTY(DUTY);
      CAPSO++;
      XUAT_4LED_7DOAN_2SO(MA7DOAN[CAPSO/10],MA7DOAN[CAPSO%10]);
      DELAY_QUET_8LED(100);
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
         DUTY=DUTY-50;
         CAPSO--;
         XUAT_4LED_7DOAN_2SO(MA7DOAN[CAPSO/10],MA7DOAN[CAPSO%10]);
         SET_PWM1_DUTY(DUTY);
         DELAY_QUET_8LED(200);
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
   
   SETUP_TIMER_1(T1_EXTERNAL_SYNC|T1_DIV_BY_1);
   SET_TIMER1(0);
   T1=T1_TAM=0;
   GIAI_MA_GAN_CHO_8LED_QUET_16_XOA(T1);
   
   WHILE(TRUE)
   {
      PHIM_DW();
      PHIM_UP();
      T1=GET_TIMER1();
      IF(T1!=T1_TAM)
      {
         GIAI_MA_GAN_CHO_8LED_QUET_16_XOA(T1);
         T1_TAM=T1;
      }
      HIEN_THI_8LED_7DOAN_QUET();
      IF(!INPUT(STOP))
      {
         DUTY=0;  CAPSO=0;
         XUAT_4LED_7DOAN_2SO(MA7DOAN[CAPSO/10],MA7DOAN[CAPSO%10]);
         SET_PWM1_DUTY(DUTY);
      }
   }
}
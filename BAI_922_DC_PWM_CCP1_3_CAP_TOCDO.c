#INCLUDE <TV_PICKIT2_SHIFT_1.c>
SIGNED INT8 CAPSO;
UNSIGNED INT16 DUTY;

VOID KT_PHIM()
{
   IF(!INPUT(BT0)) 
      {
         DUTY=0;
         CAPSO=0;
      }
   IF(!INPUT(BT1))
      {
         DUTY=350;
         CAPSO=1;
      }
   IF(!INPUT(BT2))
      {
         DUTY=700;
         CAPSO=2;
      }
      
   IF(!INPUT(BT3)) 
      {
         DUTY=1000;
         CAPSO=3;
      }
}

VOID MAIN() 
{ 
 SET_UP_PORT_IC_CHOT(); 
 DC_ENABLE=1;
 OUTPUT_LOW(PIN_C1);
 XUAT_BUZZER_RELAY();
 SETUP_CCP1(CCP_PWM); 
 SETUP_TIMER_2(T2_DIV_BY_16, 249, 1); 
 DUTY=0;  CAPSO=0; 
 XUAT_4LED_7DOAN_1SO(MA7DOAN[CAPSO]);
 SET_PWM1_DUTY(DUTY);
    WHILE(TRUE)
    {
        KT_PHIM();
       XUAT_4LED_7DOAN_1SO(MA7DOAN[CAPSO]);
       SET_PWM1_DUTY(DUTY);
    }
}


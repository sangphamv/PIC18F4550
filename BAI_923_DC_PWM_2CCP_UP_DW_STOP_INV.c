#INCLUDE <TV_PICKIT2_SHIFT_1.C>
#INCLUDE <TV_PICKIT2_SHIFT_DC_MOTOR.C>

SIGNED INT8 PWM_CAPSO;
UNSIGNED INT16 Y=0;
VOID XUAT_LED_THUAN_NGHICH()
{
   IF(!DCMOTOR_TN)   XUAT_32LED_DON_2WORD(0,Y);
   ELSE              XUAT_32LED_DON_2WORD(Y,0);
}

VOID XOA_SO_CAP_TOC_DO()
{
   PWM_CAPSO=0;
   XUAT_4LED_7DOAN_GIAIMA_XOA_SO0(PWM_CAPSO);
}

VOID PHIM_INV_PWM()
{
   IF(!INPUT(INV))
   {
      DELAY_MS(20);
      {
         IF(!INPUT(INV))
         {
            DELAY_MS(10);
            DCMOTOR_TN=~DCMOTOR_TN;
            XUAT_LED_THUAN_NGHICH();
            XOA_SO_CAP_TOC_DO();
            DC_MOTOR_PWM_CCP1_CCP2_STOP();
            DO{}
            WHILE(!INPUT(INV));
         }
      }
   }
}

VOID PHIM_UP_PWM()
{
   IF(!INPUT(UP)&&(PWM_DUTY<1000))
   {
      DELAY_MS(20);
      IF(!INPUT(UP))
         {
            PWM_DUTY=PWM_DUTY+50;
            DC_MOTOR_PWW_SETUP_DUTY();
            PWM_CAPSO++;
            XUAT_4LED_7DOAN_GIAIMA_XOA_SO0(PWM_CAPSO);
            DELAY_MS(200);
         }
   }
}

VOID PHIM_DW_PWM()
{
   IF(!INPUT(DW)&&(PWM_DUTY>0))
   {
      DELAY_MS(20);
      IF(!INPUT(DW))
         {
            PWM_DUTY=PWM_DUTY-50;
            PWM_CAPSO--;
            XUAT_4LED_7DOAN_GIAIMA_XOA_SO0(PWM_CAPSO);
            DC_MOTOR_PWW_SETUP_DUTY();
            DELAY_MS(200);
         }
   }
}

VOID PHIM_STOP_PWM()
{
   IF(!INPUT(STOP))
   {
      DC_MOTOR_PWM_CCP1_CCP2_STOP();
      XOA_SO_CAP_TOC_DO();
   }
}

VOID MAIN()
{
   SET_UP_PORT_IC_CHOT();
   DC_MOTOR_ENABLE();
   SETUP_TIMER_2(T2_DIV_BY_16,249,1);
   
   DCMOTOR_TN=0;
   DCMOTOR_ONOFF=0;
   Y=0XFFFF;
   XUAT_LED_THUAN_NGHICH();
   PWM_DUTY=0;
   DC_MOTOR_KTAO_CCPX_KTAO();
   DC_MOTOR_PWW_SETUP_DUTY();
   
   PWM_CAPSO=0;
   XUAT_4LED_7DOAN_GIAIMA_XOA_SO0(PWM_CAPSO);
   WHILE(TRUE)
   {
      PHIM_DW_PWM();
      PHIM_UP_PWM();
      PHIM_INV_PWM();
      PHIM_STOP_PWM();
   }
}


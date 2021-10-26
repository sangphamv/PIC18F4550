#INCLUDE <TV_PICKIT2_SHIFT_1.C>
#INCLUDE <TV_PICKIT2_SHIFT_DC_MOTOR.C>

VOID MAIN()
{
   SET_UP_PORT_IC_CHOT();
   DC_MOTOR_ENABLE();
   DC_MOTOR_STOP();
   WHILE(TRUE)
   {
      WHILE(INPUT(ON));
      {
         DC_MOTOR_QUAY_THUAN();
         XUAT_32LED_DON_4BYTE(0,0,0,0XFF);
      }
      WHILE(INPUT(OFF));
      {
      DC_MOTOR_STOP();
      XUAT_32LED_DON_4BYTE(0,0,0,0);
      }
   }
}

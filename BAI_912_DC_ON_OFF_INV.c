#INCLUDE <TV_PICKIT2_SHIFT_1.C>
#INCLUDE <TV_PICKIT2_SHIFT_DC_MOTOR.C>
VOID PHIM_INV()
{
   IF(!INPUT(INV))
   {
      DELAY_MS(20);
      {
         IF(!INPUT(INV))
         {
            DC_MOTOR_STOP();
            DELAY_MS(1000);
            DCMOTOR_TN=~DCMOTOR_TN;
            DC_MOTOR_CONTROL();
            DO{}
            WHILE(!INPUT(INV));
         }
      }
   }
}

VOID MAIN()
{
   SET_UP_PORT_IC_CHOT();
   DC_MOTOR_ENABLE();
   DC_MOTOR_STOP();
   WHILE(TRUE)
   {
      WHILE(INPUT(ON)); //CHO NHAN STOP
      DCMOTOR_ONOFF=1;
      DC_MOTOR_CONTROL();
      DO
      {
         PHIM_INV();
      }
      WHILE(INPUT(OFF));
      DC_MOTOR_STOP();
   }
}

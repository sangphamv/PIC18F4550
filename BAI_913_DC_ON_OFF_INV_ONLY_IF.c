
#INCLUDE <TV_PICKIT2_SHIFT_1.c>
#INCLUDE <TV_PICKIT2_SHIFT_DC_MOTOR.c>

VOID PHIM_ON()
{
   IF ( ! INPUT (ON)) DCMOTOR_ONOFF = 1;
}

VOID PHIM_OFF()
{
   IF ( ! INPUT (OFF))
   {
      DCMOTOR_ONOFF = 0;
   }
}

VOID PHIM_INV()
{
   IF ( ! INPUT (INV) )
   {
      DELAY_MS (20) ;

      IF ( ! INPUT (INV) )
      {
         DC_MOTOR_STOP () ;
         DELAY_MS (1000) ;
         DCMOTOR_TN = ~DCMOTOR_TN;
         DC_MOTOR_CONTROL () ;
         WHILE ( ! INPUT (INV)) ;
      }
   }
}

VOID MAIN()
{
   SET_UP_PORT_IC_CHOT () ;
   DC_MOTOR_ENABLE () ;
   DC_MOTOR_STOP () ;

   WHILE (TRUE)
   {
      IF (DCMOTOR_ONOFF == 1)
      {
         IF (DCMOTOR_TN) DC_MOTOR_QUAY_THUAN ();
         ELSE   DC_MOTOR_QUAY_NGHICH ();
         IF (DCMOTOR_TN == 1) XUAT_32LED_DON_2WORD (0XFFFF, 0);
         ELSE XUAT_32LED_DON_2WORD (0, 0XFFFF);
         PHIM_OFF () ;
         PHIM_INV () ;
      }

      IF (DCMOTOR_ONOFF == 0)
      {
         PHIM_ON () ;
         DC_MOTOR_STOP () ;
         XUAT_32LED_DON_2WORD (0, 0) ;
      }
   }
}


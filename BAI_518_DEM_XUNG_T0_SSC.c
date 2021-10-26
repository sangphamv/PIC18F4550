
#INCLUDE <TV_PICKIT2_SHIFT_1.c>
UNSIGNED INT8 T0;

UNSIGNED INT1 TT;

VOID GIAI_MA_GAN_CHO_8LED_QUET()
{
   LED_7DQ[0] = MA7DOAN [T0 % 10];
   LED_7DQ[1] = MA7DOAN [T0 / 10];
}

VOID PHIM_START_STOP()
{
   IF ( ! INPUT (BT0) )
   {
      DELAY_MS (20);
      {
         IF ( ! INPUT (BT0) )
         {
            TT = ~TT;

            IF (TT == 1)
            {
               XUAT_32LED_DON_4BYTE (0XFF, 0XFF, 0XFF, 0XFF) ;
               SETUP_TIMER_0 (T0_EXT_L_TO_H|T0_DIV_1|T0_8_BIT);
            }

            ELSE
            {
               XUAT_32LED_DON_4BYTE (0X00, 0X00, 0X00, 0X00) ;
               SETUP_TIMER_0 (T0_OFF);
            }

            DO{}
            WHILE ( ! INPUT (BT0)) ;
         }
      }
   }
}

VOID PHIM_CLR()
{
   IF ( ! INPUT (BT1) )
   {
      DELAY_MS (20);
      {
         IF ( ! INPUT (BT1) )
         {
            SET_TIMER0 (0) ;
            DO{}
            WHILE ( ! INPUT (BT1)) ;
         }
      }
   }
}

VOID MAIN()
{
   SET_UP_PORT_IC_CHOT () ;
   SETUP_TIMER_0 (T0_OFF);
   SET_TIMER0 (90) ;
   TT = 0;

   WHILE (TRUE)
   {
      PHIM_START_STOP () ;
      PHIM_CLR () ;
      T0 = GET_TIMER0 () ;
      GIAI_MA_GAN_CHO_8LED_QUET () ;
      IF (T0 > 99) SET_TIMER0 (1);
      HIEN_THI_8LED_7DOAN_QUET ();
   }
}


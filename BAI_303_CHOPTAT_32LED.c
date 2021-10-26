
#INCLUDE <TV_PICKIT2_SHIFT_1.C>

UNSIGNED INT8 Y;

VOID MAIN()
{
   SET_UP_PORT_IC_CHOT () ;
   Y = 0;

   WHILE (TRUE)
   {
      XUAT_32LED_DON_4BYTE (Y, Y, Y, Y) ;
      DELAY_MS (200) ;
      Y = ~Y;
   }
}


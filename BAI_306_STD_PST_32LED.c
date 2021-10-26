
#INCLUDE <TV_PICKIT2_SHIFT_1.C>

UNSIGNED INT8 I;
UNSIGNED INT32 Y;

VOID MAIN ()
{
   SET_UP_PORT_IC_CHOT ();
   Y = 0;

   WHILE (TRUE)
   {
      FOR (I = 0; I < 16; I++)
      {
         XUAT_32LED_DON_2WORD (Y, Y) ;
         DELAY_MS (300);
         Y = (Y>>1)+0X8000;
      }

      FOR (I = 0; I < 16; I++)
      {
         XUAT_32LED_DON_2WORD (Y, Y) ;
         DELAY_MS (300);
         Y = (Y>>1);
      }
   }
}


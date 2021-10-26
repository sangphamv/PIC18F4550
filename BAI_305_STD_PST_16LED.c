
#INCLUDE <TV_PICKIT2_SHIFT_1.C>
UNSIGNED INT16 Y;

UNSIGNED INT8 I;

VOID MAIN ()
{
   SET_UP_PORT_IC_CHOT();
   Y=0;

   WHILE (TRUE)
   {
      FOR (I = 0; I < 16; I++)
      {
         XUAT_32LED_DON_2WORD (0, Y) ;
         DELAY_MS (300) ;
         Y = (Y<<1) + 1;
      }

      FOR (I = 0; I < 16; I++)
      {
         XUAT_32LED_DON_2WORD (0, Y) ;
         DELAY_MS (300) ;
         Y = (Y<<1);
      }
   }
}


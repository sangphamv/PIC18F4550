
#INCLUDE <TV_PICKIT2_SHIFT_1.C>

UNSIGNED INT8 Y, I;

VOID MAIN ()
{
   SET_UP_PORT_IC_CHOT ();
   Y = 0;

   WHILE (TRUE)
   {
      FOR (I = 0; I < 8; I++)
      {
         XUAT_32LED_DON_4BYTE (0, 0, 0, Y);
         DELAY_MS (200);
         Y = (Y<<1) + 1;
      }

      FOR (I = 0; I < 8; I++)
      {
         XUAT_32LED_DON_4BYTE (0, 0, 0, Y);
         DELAY_MS (200);
         Y = (Y<<1);
      }
   }
}


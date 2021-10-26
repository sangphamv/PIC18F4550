
#INCLUDE <TV_PICKIT2_SHIFT_1.C>

UNSIGNED INT8 I;
UNSIGNED INT32 Y;

VOID MAIN ()
{
   SET_UP_PORT_IC_CHOT ();
   Y = 0;

   WHILE (TRUE)
   {
      FOR (I = 0; I < 32; I++)
      {
         XUAT_32LED_DON_1DW(Y);
         DELAY_MS (30);
         Y = (Y<<1) + 1;
      }

      FOR (I = 0; I < 32; I++)
      {
         XUAT_32LED_DON_1DW (Y);
         DELAY_MS (30);
         Y = (Y<<1);
      }
      FOR (I = 0; I < 32; I++)
      {
         XUAT_32LED_DON_1DW(Y);
         DELAY_MS (30);
         Y = (Y>>1)+0X80000000;
      }

      FOR (I = 0; I < 32; I++)
      {
         XUAT_32LED_DON_1DW (Y);
         DELAY_MS (30);
         Y = (Y>>1);
      }
   }
}



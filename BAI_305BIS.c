
#INCLUDE <TV_PICKIT2_SHIFT_1.C>
UNSIGNED INT32 Y;

UNSIGNED INT32 I;

VOID MAIN ()
{
   SET_UP_PORT_IC_CHOT ();
   Y = 0;
   XUAT_32LED_DON_4BYTE (Y, Y, Y, Y);
   DELAY_MS (500);

   WHILE (TRUE)
   {
      FOR (I = 0; I < 32; I++)
      {
         XUAT_32LED_DON_4BYTE (Y>>24, Y>>16, Y>>8, Y);
         DELAY_MS (500);
         Y = (Y<<1|0X3800)&0X001FF800;
      }

      FOR (I = 0; I < 32; I++)
      {
         XUAT_32LED_DON_4BYTE (Y>>24, Y>>16, Y>>8, Y);
         DELAY_MS (500);
         Y = (Y>>1|0X3800)&0X001FF800;
      }
   }
}


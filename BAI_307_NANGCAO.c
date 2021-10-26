// 1 LAN 3 LED SANG , 10 LED SANG GIUA 32 LED
#INCLUDE <TV_PICKIT2_SHIFT_1.C>

UNSIGNED INT32 I;
UNSIGNED INT32 Y;

VOID MAIN ()
{
   SET_UP_PORT_IC_CHOT ();
   Y = 0;
   XUAT_32LED_DON_1DW(Y);  

   WHILE (TRUE)
   {
      FOR (I = 0; I < 32; I++)
      {
         XUAT_32LED_DON_1DW(Y);
         DELAY_MS (1000);
         Y = ((Y<<3)|0X00003800)&0X001FF800;
      }

      FOR (I = 0; I < 32; I++)
      {
         XUAT_32LED_DON_1DW (Y);
         DELAY_MS (1000);
         Y = ((Y>>3)|0X001E0000)&0X001FF800;
      }
   }
}



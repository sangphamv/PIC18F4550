
#INCLUDE <TV_PICKIT2_SHIFT_1.C>
UNSIGNED INT16 Y;

UNSIGNED INT32 LED;

VOID MAIN ()
{
   SET_UP_PORT_IC_CHOT();
   Y=0;
   LED=(LED<<1)|0X00000800;
   WHILE (TRUE)
   {
      FOR (LED = 0; LED < 32; LED++)
      {
         XUAT_32LED_DON_4BYTE(0,LED>>8,LED,0);
         DELAY_MS (300) ;
         Y = (Y<<1) + 1;
      }

      FOR (LED= 0; LED < 32;LED++)
      {
         XUAT_32LED_DON_4BYTE(0,LED>>8,LED,0);
         DELAY_MS (300) ;
         Y = (Y<<1);
      }
   }
}


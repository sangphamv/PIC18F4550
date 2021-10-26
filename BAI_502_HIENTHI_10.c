#INCLUDE <TV_PICKIT2_SHIFT_1.C>
UNSIGNED INT16 TG_DELAY;

VOID MAIN ()
{
   SET_UP_PORT_IC_CHOT();
   TG_DELAY=1;
   WHILE (TRUE)
      {
         XUAT_8LED_7DOAN_QUET_1(0XFD, 0XC0);    //0
         DELAY_MS(TG_DELAY);
         
         XUAT_8LED_7DOAN_QUET_1(0XFE, 0XF9);    //1
         DELAY_MS(TG_DELAY);                
      }
}

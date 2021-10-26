
#INCLUDE <TV_PICKIT2_SHIFT_1.C>

SIGNED INT8 GIAY;
UNSIGNED INT16 I;

VOID HIENTHI_DELAY()
{
   FOR (I = 0; I < 200; I++)
   {
      XUAT_8LED_7DOAN_QUET_2 (0, MA7DOAN [GIAY % 10]); DELAY_US (200) ;
      XUAT_8LED_7DOAN_QUET_TAT_LED () ;
      XUAT_8LED_7DOAN_QUET_2 (1, MA7DOAN [GIAY / 10]); DELAY_US (200) ;
      XUAT_8LED_7DOAN_QUET_TAT_LED () ;
   }
}

VOID MAIN()
{
   SET_UP_PORT_IC_CHOT () ;

   WHILE (TRUE)
   {
      FOR (GIAY = 0; GIAY < 60; GIAY++)
      {
         HIENTHI_DELAY ();
      }
   }
}


#INCLUDE <TV_PICKIT2_SHIFT_1.C>
SIGNED INT16 PHUT,GIAY;
VOID MAIN()
{
   SET_UP_PORT_IC_CHOT();
   GIAY=0;
   PHUT=0;
   WHILE(TRUE)
   {
      FOR(PHUT=0;PHUT<60;PHUT++)
      {
         FOR(GIAY=0;GIAY<60;GIAY++)
         {
            XUAT_4LED_7DOAN_4SO(MA7DOAN[PHUT/10],MA7DOAN[PHUT%10],MA7DOAN[GIAY/10],MA7DOAN[GIAY%10]);
            DELAY_MS(50);
         }
      }    
   }
}

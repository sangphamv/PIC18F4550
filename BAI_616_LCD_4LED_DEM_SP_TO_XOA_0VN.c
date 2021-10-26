// HIEN THI LCD SO NHO
#INCLUDE <TV_PICKIT2_SHIFT_1.C>
#INCLUDE <TV_PICKIT2_SHIFT_LCD.C>

UNSIGNED INT16 T0,T0_TAM,DV,CH,TR;

VOID GM_LCD()
{
   DV = T0 % 10 + 0X30;
   CH = T0 / 10 % 10 + 0X30;
   TR = T0 / 100 + 0X30;
   
   IF (TR == 0X30)
   {
      TR = 32; //0X20
      IF (CH == 0X30)
         CH = 0X20;
   }
}

VOID HT_LCD()
{
   LCD_GOTO_XY (0, 0) ;
   LCD_DATA (TR) ;
   LCD_DATA (CH) ;
   LCD_DATA (DV) ;
}

VOID MAIN()
{
   SET_UP_PORT_IC_CHOT () ;
   SETUP_LCD () ;
   LCD_GOTO_XY (0, 0) ;
   LCD_DATA ("DEM SAN PHAM:") ;
   
   SETUP_TIMER_0 (T0_EXT_L_TO_H|T0_DIV_1) ;
   SET_TIMER0 (0) ;
   T0_TAM = T0 = 0;
   
   WHILE (TRUE)
   {
      T0 = GET_TIMER0 () ;

      IF (T0 != T0_TAM)
      {
         T0_TAM = T0;
         GM_LCD () ;
         HT_LCD () ;
         XUAT_4LED_7DOAN_4SO (0, MA7DOAN[TR], MA7DOAN[CH], MA7DOAN[DV]) ;
      }

      IF (T0 >= 101) SET_TIMER0 (1);
   }
}


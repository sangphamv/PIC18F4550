
#INCLUDE <TV_PICKIT2_SHIFT_1.C>
#INCLUDE <TV_PICKIT2_SHIFT_LCD.C>

UNSIGNED INT16 T0;

VOID HIENTHI_LCD()
{
   LCD_GOTO_XY (0, 17) ;
   DELAY_US (20) ;
   LCD_DATA (T0 / 100 + 0X30) ;
   LCD_DATA (T0 / 10 % 10 + 0X30) ;
   LCD_DATA (T0 % 10 + 0X30) ;
}

VOID MAIN()
{
   SET_UP_PORT_IC_CHOT () ;
   SETUP_LCD () ;
   LCD_GOTO_XY (0, 0) ;
   LCD_DATA ("DEM SAN PHAM:") ;
   
   SETUP_TIMER_0 (T0_EXT_L_TO_H|T0_DIV_1) ;
   SET_TIMER0 (0) ;
   T0 = 0;
   
   WHILE (TRUE)
   {
      HIENTHI_LCD ();
      T0 = GET_TIMER0 ();
      IF (T0 >= 101) SET_TIMER0 (1);
   }
}


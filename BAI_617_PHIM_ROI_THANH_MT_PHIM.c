
#INCLUDE <TV_PICKIT2_SHIFT_1.c>
#INCLUDE <TV_PICKIT2_SHIFT_LCD.c>
#INCLUDE <TV_PICKIT2_SHIFT_KEY4X4_138.c>

UNSIGNED INT16 T0[2],DEM=0;
SIGNED INT8 MP;

VOID HIENTHI()
{
   LCD_GOTO_XY (0, 17) ;
   DELAY_US (20) ;
   LCD_DATA (T0[0] / 10 + 48) ;
   LCD_DATA (T0[1] % 10 + 48) ;
   LCD_GOTO_XY (1, 17) ;
   DELAY_US (20) ;
   LCD_DATA (DEM / 10 % 10 + 48) ;
   LCD_DATA (DEM % 10 + 48) ;
}

VOID MAIN()
{
   SET_UP_PORT_IC_CHOT () ;
   SETUP_LCD () ;
   SET_TRIS_B (0X3C);
   LCD_GOTO_XY (1, 0) ;
   LCD_DATA ("DEM SAN PHAM: ") ;
   LCD_GOTO_XY (0, 0) ;
   LCD_DATA ("GIA TRI CAI: ");
   setup_timer_0 (T0_EXT_L_TO_H|T0_DIV_1) ;
   SET_TIMER0 (0) ;
   DEM = 0;

   WHILE (TRUE)
   {
      MP = KEY_4X4_UP ();

      IF (MP != 0XFF)
      {
        IF(MP<10)
        {
            T0[1]=T0[0];
            T0[0]=MP;
        }
      }

      HIENTHI () ;
      XUAT_4LED_7DOAN_4SO (MA7DOAN[T0[1] / 10], MA7DOAN[T0[0] % 10], MA7DOAN[DEM / 10], MA7DOAN[DEM % 10]) ;
      DEM = GET_TIMER0 () ;
      IF (DEM == T0 + 1) SET_TIMER0 (0);
   }
}


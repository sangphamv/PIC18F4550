
#INCLUDE <TV_PICKIT2_SHIFT_1.c>
#INCLUDE <TV_PICKIT2_SHIFT_LCD.c>
#INCLUDE <TV_PICKIT2_SHIFT_KEY4X4_138.c>

UNSIGNED INT8 T0,KQ,GTC,MP;
UNSIGNED INT8 MA[2];

VOID HIENTHI_LCD()
{
   LCD_GOTO_XY (0, 18) ;
   DELAY_US (20) ;
   LCD_DATA (MA[1]) ;
   LCD_DATA (MA[0]) ;
   LCD_GOTO_XY (1, 18) ;
   DELAY_US (20) ;
   LCD_DATA (T0 / 10 + 0X30);
   LCD_DATA (T0 % 10 + 0X30);
}

VOID MAIN()
{
   SET_UP_PORT_IC_CHOT ();
   SETUP_LCD () ;
   LCD_GOTO_XY (0, 0) ;
   LCD_DATA ("GIA TRI CAI:") ;
   LCD_GOTO_XY (1, 0) ;
   LCD_DATA ("DEM SAN PHAM:") ;
   
   SETUP_TIMER_0 (T0_EXT_L_TO_H|T0_DIV_1);
   SET_TIMER0 (0) ;
   T0 = 0;
   MA[1] = 0X30;
   MA[0] = 0X30;

   WHILE (TRUE)
   {
      MP = KEY_4X4_DW () ;
      
      IF (MP != 0XFF)
      {
         IF (MP == 12)
         {
            LCD_GOTO_XY (0, 18) ;
            DELAY_US (20) ;
            LCD_DATA (0X30) ;
            LCD_DATA (0X31) ;
         }

         IF (MP < 10) KQ = MP + 0X30;
         MA[1] = MA[0];
         MA[0] = KQ;
         HIENTHI_LCD ();
      }

      
      
      GTC = (MA[1] - 0X30) * 10 + (MA[0] - 0X30) ; //GTC la gia tri cai
      T0 = GET_TIMER0 () ;
      IF (T0 > GTC) SET_TIMER0 (1);
      
      HIENTHI_LCD ();
      XUAT_4LED_7DOAN_4SO (MA7DOAN[MA[1] - 0X30], MA7DOAN[MA[0] - 0X30], MA7DOAN[T0 / 10], MA7DOAN[T0 % 10]) ;
   }
}


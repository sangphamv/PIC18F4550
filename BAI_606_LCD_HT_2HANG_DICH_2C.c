
#INCLUDE <TV_PICKIT2_SHIFT_1.C>
#INCLUDE <TV_PICKIT2_SHIFT_LCD.C>

UNSIGNED INT8 I;
VOID MAIN()
{
   SET_UP_PORT_IC_CHOT () ;
   SETUP_LCD () ;
   LCD_COMMAND (LCD_ADDR_LINE1) ;
   LCD_DATA ("KHOA DIEN - DIEN TU ");
   LCD_COMMAND (LCD_ADDR_LINE2) ;
   LCD_DATA ("BM DIENTUCONG NGHIEP") ;
   DELAY_MS (1000) ;

   WHILE (TRUE)
   {
      FOR(I=0;I<20;I++)
      {
      LCD_COMMAND (LCD_SHIFT_LEFT);
      DELAY_MS (1000) ;
      }
      FOR(I=0;I<20;I++)
      {
      LCD_COMMAND (LCD_SHIFT_RIGHT);
      DELAY_MS (1000);
      }
   }
}


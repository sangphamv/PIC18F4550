
#INCLUDE <TV_PICKIT2_SHIFT_1.c>
#INCLUDE <TV_PICKIT2_SHIFT_LCD.C>
#INCLUDE <TV_PICKIT2_SHIFT_GLCD128X64.c>
UNSIGNED INT8 T0;
SIGNED INT8 I;
UNSIGNED INT8 TRAM,CHUC,DONVI,TRAM1,CHUC1,DONVI1;
VOID LCD_HIENTHI_SO_Z_TOADO_XY(SIGNED INT8 LCD_SO,SIGNED INT8 X1, SIGNED Y1)
   {
   LCD_GOTO_XY (X1, Y1) ;
   FOR (I = 0; I < 6; I++)
   {
      IF (I == 3) LCD_GOTO_XY (X1 + 1, Y1);
      LCD_DATA (LCD_SO_X[LCD_SO][I]);
   }
   }

VOID LCD_HIENTHI_SOLON()
{
   TRAM1 = T0 /100;
   CHUC1 = T0 % 100 / 10;
   DONVI1 = T0 % 10;
         IF(TRAM1==0)
         {
            TRAM1=10;
            IF(CHUC1==0)
            {CHUC1=10;}
         }
   LCD_HIENTHI_SO_Z_TOADO_XY (TRAM1, 2, 0) ;
   LCD_HIENTHI_SO_Z_TOADO_XY (CHUC1, 2, 3) ;
   LCD_HIENTHI_SO_Z_TOADO_XY (DONVI1, 2, 6) ;
}
VOID GLCD_HIENTHI()
{
   TRAM1 = T0 / 100  + 0X30;
   CHUC1 = T0 / 10 % 10 + 0X30;
   DONVI1 = T0 % 10 + 0X30;
   IF(TRAM1==0X30)
      {
         TRAM1=0X20;
         IF(CHUC1==0X30)
         {
            CHUC1=0X20;
         }
      }
   GLCD_COMMAND (0X95);
   GLCD_DATA (TRAM1);
   GLCD_DATA (CHUC1);
   GLCD_DATA (DONVI1);
}

VOID LCD_HIENTHI()
{
   TRAM1 = T0 / 100  + 0X30;
   CHUC1 = T0 / 10 % 10 + 0X30;
   DONVI1 = T0 % 10 + 0X30;
   IF(TRAM1==0X30)
      {
         TRAM1=" ";
         IF(CHUC1==0X30)
         {
            CHUC1=" ";
         }
      }
   LCD_GOTO_XY (1, 13) ;
   DELAY_US (20);
   LCD_DATA (TRAM1);
   LCD_DATA (CHUC1);
   LCD_DATA (DONVI1);
}

VOID HIENTHI_4LED_7DOAN()
{
   TRAM = MA7DOAN[T0 / 100];
   CHUC = MA7DOAN[T0 / 10 % 10];
   DONVI = MA7DOAN[T0 % 10];
   IF(TRAM==0XC0)
      {
         TRAM=0XFF;
         IF(CHUC==0XC0)
         {
            CHUC=0XFF;
         }
      }
   XUAT_4LED_7DOAN_4SO (0XFF, TRAM, CHUC, DONVI) ;
}

VOID MAIN()
{
   SET_UP_PORT_IC_CHOT ();
   SETUP_GLCD (0X30);
   SETUP_LCD ();
   
   LCD_GOTO_XY (0, 0) ;
   LCD_DATA ("DEM SAN PHAM:");
   
   GLCD_COMMAND (0X80);
   GLCD_DATA (" DEM SAN PHAM: ");
   
   SETUP_TIMER_0 (T0_EXT_L_TO_H|T0_DIV_1|T0_8_BIT);
   SET_TIMER0 (0);
   LCD_COMMAND (0X40);
   FOR (I = 0; I < 64; I++) {LCD_DATA (LCD_MA_8DOAN[I]); }
   
   SETUP_TIMER_1 (T1_INTERNAL|T1_DIV_BY_8) ;
   SET_TIMER1 (3036) ;
   ENABLE_INTERRUPTS (GLOBAL) ;
   ENABLE_INTERRUPTS (INT_TIMER1) ;
   WHILE (TRUE)
   {
      T0 = GET_TIMER0 ();
      GLCD_HIENTHI ();
      LCD_HIENTHI_SOLON();
      LCD_HIENTHI () ;
      HIENTHI_4LED_7DOAN () ;
      IF (T0 >= 101) SET_TIMER0 (0) ;
   }
}


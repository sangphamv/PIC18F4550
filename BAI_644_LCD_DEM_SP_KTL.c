
#INCLUDE <TV_PICKIT2_SHIFT_1.c>
#INCLUDE <TV_PICKIT2_SHIFT_LCD.c>

SIGNED INT8 I;

UNSIGNED INT16 T0,NGAN,TRAM,CHUC,DONVI,NGAN1,TRAM1,CHUC1,DONVI1;

VOID LCD_HIENTHI_SO_Z_TOADO_XY(SIGNED INT8 LCD_SO,SIGNED INT8 X1, SIGNED Y1)
   {
   LCD_GOTO_XY (X1, Y1) ;
   FOR (I = 0; I < 6; I++)
   {
      IF (I == 3) LCD_GOTO_XY (X1 + 1, Y1);
      LCD_DATA (LCD_SO_X[LCD_SO][I]);
   }
   }

VOID HIEN_THI()
{
   NGAN = MA7DOAN[T0 / 1000];
   TRAM = MA7DOAN[T0 % 1000 / 100];
   CHUC = MA7DOAN[T0 % 100 / 10];
   DONVI = MA7DOAN[T0 % 10];

   IF (NGAN == 0XC0)
   {
      NGAN = 0XFF;

      IF (TRAM == 0XC0)
      {
         TRAM = 0XFF;

         IF (CHUC == 0XC0)
         { CHUC = 0XFF; }
      }
   }
   XUAT_4LED_7DOAN_4SO (NGAN, TRAM, CHUC, DONVI) ;
   
   NGAN1 = T0 / 1000;
   TRAM1 = T0 % 1000 / 100;
   CHUC1 = T0 % 100 / 10;
   DONVI1 = T0 % 10;
      IF(NGAN1==0)
      {
         NGAN1=10;
         IF(TRAM1==0)
         {
            TRAM1=10;
            IF(CHUC1==0)
            {CHUC1=10;}
         }
      }
   LCD_HIENTHI_SO_Z_TOADO_XY (NGAN1, 2, 0) ;
   LCD_HIENTHI_SO_Z_TOADO_XY (TRAM1, 2, 3) ;
   LCD_HIENTHI_SO_Z_TOADO_XY (CHUC1, 2, 6) ;
   LCD_HIENTHI_SO_Z_TOADO_XY (DONVI1, 2, 9) ;
}

VOID MAIN()
{
   SET_UP_PORT_IC_CHOT ();
   SETUP_LCD ();
   
   SETUP_TIMER_0 (T0_EXT_L_TO_H|T0_DIV_1|T0_8_BIT);
   SET_TIMER0 (0); // GIA TRI LUC DAU BANG 0
   
   LCD_GOTO_XY (0, 0) ;
   LCD_DATA ("**DEM SAN PHAM**");
   
   LCD_COMMAND (0X40);
   FOR (I = 0; I < 64; I++) {LCD_DATA (LCD_MA_8DOAN[I]); }
   LCD_HIENTHI_SO_Z_TOADO_XY (0, 2, 0) ;

   WHILE (TRUE)
   {
      T0 = GET_TIMER0 ();
      HIEN_THI ();
      IF (T0 >= 10000) SET_TIMER0 (1) ;
   }
}


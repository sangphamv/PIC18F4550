
// HIEN THI LCD SO LON
#INCLUDE <TV_PICKIT2_SHIFT_1.c>
#INCLUDE <TV_PICKIT2_SHIFT_LCD.c>

SIGNED INT8 I,DEM;

VOID LCD_HIENTHI_SO_Z_TOADO_XY(SIGNED INT8 LCD_SO,SIGNED INT8 X1, SIGNED Y1)//(so can HT, hang,cot)
   {
   LCD_GOTO_XY (X1, Y1) ;
   FOR (I = 0; I < 6; I++)
   {
      IF (I == 3) LCD_GOTO_XY (X1 + 1, Y1);
      LCD_DATA (LCD_SO_X[LCD_SO][I]);
   }
   }

VOID MAIN()
{
   SET_UP_PORT_IC_CHOT ();
   SETUP_LCD (); // khai bao lcd
   
   LCD_GOTO_XY (0, 0) ;
   LCD_DATA ("**DEM TU 00 DEN 99**");
   
   //ham khoi tao ca ky tu tu tao
   LCD_COMMAND (0X40);
   FOR (I = 0; I < 64; I++) {LCD_DATA (LCD_MA_8DOAN[I]); }
   LCD_HIENTHI_SO_Z_TOADO_XY (0, 2, 0) ;

   //***
   WHILE (TRUE)
   {
      FOR (DEM = 0; DEM < 100; DEM++)
      {
         LCD_HIENTHI_SO_Z_TOADO_XY (DEM / 10, 2, 0) ; //giai ma va hien thi
         LCD_HIENTHI_SO_Z_TOADO_XY (DEM % 10, 2, 3) ;
         DELAY_MS (500);
      }
   }
}


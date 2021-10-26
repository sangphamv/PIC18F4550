#include <TV_PICKIT2_SHIFT_1.c>
#INCLUDE <TV_PICKIT2_SHIFT_LCD.c>
SIGNED INT8 I;
VOID LCD_HIENTHI_SO_Z_TOADO_XY (SIGNED INT8 LCD_SO, SIGNED INT8 X1, SIGNED INT8 Y1)
{
   LCD_GOTO_XY(X1,Y1);
   FOR (I=0;I<6;I++)
   {
      IF (I==3) LCD_GOTO_XY(X1+1,Y1);
      LCD_DATA(LCD_SO_X[LCD_SO][I]);
   }
}
VOID MAIN ()
{
   SET_UP_PORT_IC_CHOT();
   SETUP_LCD();
   
   LCD_GOTO_XY(0,0);
   LCD_DATA("HIEN THI SO 0 HANG 3");
   LCD_COMMAND(0x40);
   DELAY_US(20);
   FOR (I=0;I<64;I++)
     { LCD_DATA(LCD_MA_8DOAN[I]); }
   
   LCD_HIENTHI_SO_Z_TOADO_XY(0,2,0);
   WHILE (TRUE)
   {   }
}

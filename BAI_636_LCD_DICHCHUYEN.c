#INCLUDE <TV_PICKIT2_SHIFT_1.c>
#INCLUDE <TV_PICKIT2_SHIFT_LCD.c>
CONST UNSIGNED CHAR KT1[]={0X00,0X00,0X00,0X00,0XFF,0XFF,0XFF,0XFF};
CONST UNSIGNED CHAR KT2[]={0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF};
SIGNED INT8 I,J;
VOID DICHCHUYEN ()
{  
   FOR(J=0;J<16;J++)
   {
   LCD_GOTO_XY(0,J+1);
   LCD_DATA(' ');
   LCD_DATA(' ');
   LCD_DATA(0);
   LCD_DATA(1);
   LCD_GOTO_XY(1,J+1);
   LCD_DATA(0);
   LCD_DATA(1);
   LCD_DATA(1);
   LCD_DATA(1);
   DELAY_MS(900);
   LCD_GOTO_XY(0,J);
   LCD_DATA(' ');LCD_DATA(' ');
   LCD_GOTO_XY(1,J);
   LCD_DATA(' ');LCD_DATA(' ');
   DELAY_MS(100);
   }
      FOR(J=16;J>0;J--)
   {
   LCD_GOTO_XY(0,J);
   LCD_DATA(' ');
   LCD_DATA(' ');
   LCD_DATA(0);
   LCD_DATA(1);
   LCD_GOTO_XY(1,J);
   LCD_DATA(0);
   LCD_DATA(1);
   LCD_DATA(1);
   LCD_DATA(1);
   DELAY_MS(900);
   LCD_GOTO_XY(0,J);
   LCD_DATA(' ');LCD_DATA(' ');LCD_DATA(' ');LCD_DATA(' ');
   LCD_GOTO_XY(1,J);
   LCD_DATA(' ');LCD_DATA(' ');LCD_DATA(' ');LCD_DATA(' ');
   DELAY_MS(100);
   }
}
VOID MAIN()
{
   SET_UP_PORT_IC_CHOT();
   SETUP_LCD();
   LCD_COMMAND(0X40); //0
   FOR ( I=0;I<8;I++)    { LCD_DATA(KT1[I]); }   
   LCD_COMMAND(0X48); //1
   FOR ( I=0;I<8;I++)    { LCD_DATA(KT2[I]); }   
   WHILE(TRUE)
   {
      DICHCHUYEN ();
   }
}

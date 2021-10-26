#INCLUDE <TV_PICKIT2_SHIFT_1.c>
#INCLUDE <TV_PICKIT2_SHIFT_LCD.c>
#INCLUDE <TV_PICKIT2_SHIFT_KEY4X4_138.c>
SIGNED INT8 MP,I,KQ;
UNSIGNED INT8 MA[80];
VOID HIENTHI_LCD()
{
     IF(MP<10) KQ= MP+0X30;
     ELSE      KQ= MP+0X37;
     FOR(I=79;I>=1;I--) MA[I]=MA[I-1];
     MA[0]=KQ;
     
     LCD_GOTO_XY(0,0);
     DELAY_MS(1);
     FOR(I=19;I>=0;I--)  LCD_DATA(MA[I]);
     
     LCD_GOTO_XY(1,0);
     DELAY_MS(1);
     FOR(I=39;I>=20;I--)  LCD_DATA(MA[I]);
     
     LCD_GOTO_XY(2,0);
     DELAY_MS(1);
     FOR(I=59;I>=40;I--)  LCD_DATA(MA[I]);
     
     LCD_GOTO_XY(3,0);
     DELAY_MS(1);
     FOR(I=79;I>=60;I--)  LCD_DATA(MA[I]);
     
}

VOID MAIN()
{
   SET_UP_PORT_IC_CHOT();SET_TRIS_B(0X3C);
   SETUP_LCD();
   LCD_GOTO_XY(0,19); 
   FOR(I=79;I>=0;I--) {MA[I]=0X5F; LCD_DATA(MA[I]);}
   WHILE(TRUE)
   {
      MP=KEY_4X4_DW();
      IF(MP!=0XFF)  HIENTHI_LCD(); 
          
   }
}

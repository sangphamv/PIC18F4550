#INCLUDE <TV_PICKIT2_SHIFT_1.c>
#INCLUDE <TV_PICKIT2_SHIFT_LCD.c>
#INCLUDE <TV_PICKIT2_SHIFT_KEY4X4_138.c>
SIGNED INT8 MP,I,KQ,K=1;
VOID MAIN()
{
   SET_UP_PORT_IC_CHOT();SET_TRIS_B(0X3C);
   SETUP_LCD();
   LCD_GOTO_XY(0,0);
   LCD_DATA("DIEU KHIEN BUZZER");
   LCD_GOTO_XY(1,0);
   LCD_DATA("BUZZER:XXX,TG:Y");
   KQ=0X31;
   WHILE(TRUE)
   {
   LCD_GOTO_XY(1,14);
   LCD_DATA(KQ);
      MP=KEY_4X4_DW();
      IF(MP!=0XFF)
      {
         IF(MP<10)
            {
               KQ=MP+0X30;
               K=MP;
            }
         IF(MP==10) I=MP    ;  
      }
     IF(K!=0)
       {
         IF(I==10)
            {
               I=0;
               LCD_GOTO_XY(1,0);
               LCD_DATA("BUZZER: ON,TG:");
               BUZZER_ON();
               DELAY_MS(K*1000);
               BUZZER_OFF();
               LCD_GOTO_XY(1,0);
               LCD_DATA("BUZZER:OFF,TG:");
            }
       }
       ELSE
            I=0;
      
   }
}

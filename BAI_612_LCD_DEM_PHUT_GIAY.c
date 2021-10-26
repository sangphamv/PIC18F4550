#INCLUDE <TV_PICKIT2_SHIFT_1.C>
#INCLUDE <TV_PICKIT2_SHIFT_LCD.C>
SIGNED INT PHUT,GIAY;

VOID LCD_HIENTHI_DONGHO()
{
   LCD_GOTO_XY(0,15);
   DELAY_US(20);
   LCD_DATA(PHUT/10+0X30);
   LCD_DATA(PHUT%10+0X30);
   LCD_DATA(' ');
   LCD_DATA(GIAY/10+0X30);
   LCD_DATA(GIAY%10+0X30);
}

VOID MAIN()
{
   SET_UP_PORT_IC_CHOT();
   SETUP_LCD();
   LCD_GOTO_XY(0,0);
   LCD_DATA("DONG HO:");
   GIAY=0;
   PHUT=0;
   WHILE(TRUE)
   {
      LCD_HIENTHI_DONGHO();
      DELAY_MS(1000);
      GIAY++;
      IF(GIAY==60)
      {
         GIAY=0;
         PHUT++;
         IF(PHUT==60) PHUT=0;
      }
   }
}

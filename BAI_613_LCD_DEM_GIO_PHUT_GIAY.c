
#INCLUDE <TV_PICKIT2_SHIFT_1.C>
#INCLUDE <TV_PICKIT2_SHIFT_LCD.C>
SIGNED INT8 GIAY,PHUT,GIO,BDN;

#INT_TIMER1

VOID INTERRUPT_TIMER1()
{
   BDN++; SET_TIMER1 (3036) ;
}

VOID LCD_HIENTHI_DONGHO()
{
   LCD_GOTO_XY(0,12);
   DELAY_US(20);
   LCD_DATA(GIO/10+0X30);
   LCD_DATA(GIO%10+0X30);
   LCD_DATA(':');
   LCD_DATA(PHUT/10+0X30);
   LCD_DATA(PHUT%10+0X30);
   LCD_DATA(':');
   LCD_DATA(GIAY/10+0X30);
   LCD_DATA(GIAY%10+0X30);
}
VOID MAIN()
{
   SET_UP_PORT_IC_CHOT ();
   SETUP_LCD();
   LCD_GOTO_XY(0,0);
   LCD_DATA("DONG HO:");
   SETUP_TIMER_1 (T1_INTERNAL|T1_DIV_BY_8);
   SET_TIMER1 (3036);
   ENABLE_INTERRUPTS (GLOBAL);
   ENABLE_INTERRUPTS (INT_TIMER1);
   GIAY = 0;PHUT=0;GIO=0; BDN = 0;
   WHILE (TRUE)
   {
      IF (BDN < 10) LCD_HIENTHI_DONGHO() ;

      ELSE
      {
         BDN = BDN - 10;
         GIAY++;

         IF (GIAY == 60)
         {
            GIAY = 0;
            PHUT++;

            IF (PHUT == 60)
            {
               PHUT = 0;

               IF (GIO == 60)
               {
                  GIO = 0;
               }
            }
         }
      }
   }
}


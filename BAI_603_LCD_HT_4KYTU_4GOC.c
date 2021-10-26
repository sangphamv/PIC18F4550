#INCLUDE <TV_PICKIT2_SHIFT_1.C>
#INCLUDE <TV_PICKIT2_SHIFT_LCD.C>
VOID MAIN()
{
 SET_UP_PORT_IC_CHOT();
 SETUP_LCD();
 
 LCD_COMMAND(LCD_ADDR_LINE1);
 LCD_DATA("A                   ");
 
  LCD_COMMAND(LCD_ADDR_LINE2);
 LCD_DATA("                   B");
 
  LCD_COMMAND(LCD_ADDR_LINE3);
 LCD_DATA("C                   ");
 
  LCD_COMMAND(LCD_ADDR_LINE4);
 LCD_DATA("                   D");
 WHILE(TRUE){}
}

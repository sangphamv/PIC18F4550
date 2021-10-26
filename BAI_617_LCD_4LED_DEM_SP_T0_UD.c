#INCLUDE <TV_PICKIT2_SHIFT_1.c>
#INCLUDE <TV_PICKIT2_SHIFT_LCD.c>

UNSIGNED INT16 T0=1,DEM=0;
VOID HIENTHI()
{
  LCD_GOTO_XY(0,17);
  DELAY_US(20);
  LCD_DATA(T0/10+48);
  LCD_DATA(T0%10+48);
  LCD_GOTO_XY(1,17);
  DELAY_US(20);
  LCD_DATA(DEM/10%10+48);
  LCD_DATA(DEM%10+48);
}
VOID KTUP()
{
  IF (!INPUT(UP))
  {
    DELAY_MS(20);
    IF (!INPUT(UP))
    {
      T0++;
      IF (T0==100) T0=99;
      WHILE(!INPUT(UP));
    }
  }
}

VOID KTDW()
{
  IF (!INPUT(DW))
  {
    DELAY_MS(20);
    IF (!INPUT(DW))
    {
      T0--;
      IF (T0==0) T0=1;
      WHILE(!INPUT(DW));
    }
  }
}
VOID KTCLR()
{
  IF (!INPUT(CLR))
  {
    DELAY_MS(20);
    IF (!INPUT(CLR))
    {
      T0=1;SET_TIMER0(0);
      WHILE (!INPUT(CLR));
    }
  }
}
VOID MAIN()
{
  SET_UP_PORT_IC_CHOT();
  SETUP_LCD();
  LCD_GOTO_XY(1,0);
  LCD_DATA("DEM SAN PHAM: ");
  LCD_GOTO_XY(0,0);
  LCD_DATA("GIA TRI CAI:  ");
  setup_timer_0(T0_EXT_L_TO_H|T0_DIV_1);
  SET_TIMER0(0);
  DEM=0;
  WHILE(TRUE)
  {
    KTUP();
    KTDW();
    KTCLR();
    HIENTHI();
    XUAT_4LED_7DOAN_4SO(MA7DOAN[T0/10],MA7DOAN[T0%10],MA7DOAN[DEM/10],MA7DOAN[DEM%10]);
    DEM=GET_TIMER0();
    IF (DEM==T0+1) SET_TIMER0(0);
  }
}

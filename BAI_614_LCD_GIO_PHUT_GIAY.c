#INCLUDE <TV_PICKIT2_SHIFT_1.c>
#INCLUDE <TV_PICKIT2_SHIFT_LCD.c>

SIGNED INT8 GIAY,PHUT,GIO,BDN, DEM_TG_EXIT=0;
UNSIGNED CHAR GIA_TRI_MOD;

#int_timer1               
void ngatt1()
{     
    SET_TIMER1(3036);    
    BDN++;               
}

//PHIM MOD
VOID PHIM_MOD()
{
    IF(PHIM_BT2(20))
    {
       GIA_TRI_MOD++;
       IF(GIA_TRI_MOD>=4) GIA_TRI_MOD=0;
       DEM_TG_EXIT=0;
    }
}
//PHIM UP
VOID PHIM_UP()
{
    IF(PHIM_BT0(20))
    {
        IF (!INPUT(BT0))
        {
            SWITCH (GIA_TRI_MOD)
            {
               CASE 1: IF(GIAY==59) GIAY=0;
                       ELSE GIAY++;
                       BREAK;
               CASE 2: IF(PHUT==59) PHUT=0;
                       ELSE PHUT++;
                       BREAK;
               CASE 3: IF(GIO==23) GIO=0;
                       ELSE GIO++;
                       BREAK;
               DEFAULT: BREAK;
            }
        }
    }
}
//PHIM DW
VOID PHIM_DW()
{
    IF(PHIM_BT1(20))
    {
        IF (!INPUT(BT1))
        {
            SWITCH (GIA_TRI_MOD)
            {
               CASE 1: IF(GIAY==0) GIAY=59;
                       ELSE GIAY--;
                       BREAK;
               CASE 2: IF(PHUT==0) PHUT=59;
                       ELSE PHUT--;
                       BREAK;
               CASE 3: IF(GIO==0) GIAY=23;
                       ELSE GIO--;
                       BREAK;
               DEFAULT: BREAK;
            }
        }
    }
}

VOID LCD_HIENTHI_DONGHO()
{
   IF(GIA_TRI_MOD==0)
   {
      LCD_GOTO_XY(0,18);
      DELAY_US(20);
      LCD_DATA(GIAY/10 + 0X30);
      LCD_DATA(GIAY%10 + 0X30);
   
      LCD_GOTO_XY(0,15);
      DELAY_US(20);
      LCD_DATA(PHUT/10 + 0X30);
      LCD_DATA(PHUT%10 + 0X30);
   
      LCD_GOTO_XY(0,12);
      DELAY_US(20);
      LCD_DATA(GIO/10 + 0X30);
      LCD_DATA(GIO%10 + 0X30);
   }
   IF(GIA_TRI_MOD==1)
   {
      LCD_GOTO_XY(0,18);
      DELAY_US(20);
      LCD_DATA("  ");
      
      LCD_GOTO_XY(0,18);
      DELAY_US(20);
      LCD_DATA(GIAY/10 + 0X30);
      LCD_DATA(GIAY%10 + 0X30);
   
      LCD_GOTO_XY(0,15);
      DELAY_US(20);
      LCD_DATA(PHUT/10 + 0X30);
      LCD_DATA(PHUT%10 + 0X30);
   
      LCD_GOTO_XY(0,12);
      DELAY_US(20);
      LCD_DATA(GIO/10 + 0X30);
      LCD_DATA(GIO%10 + 0X30);
   }
   IF(GIA_TRI_MOD==2)
   {
      LCD_GOTO_XY(0,15);
      DELAY_US(20);
      LCD_DATA("  ");
      
      LCD_GOTO_XY(0,18);
      DELAY_US(20);
      LCD_DATA(GIAY/10 + 0X30);
      LCD_DATA(GIAY%10 + 0X30);
   
      LCD_GOTO_XY(0,15);
      DELAY_US(20);
      LCD_DATA(PHUT/10 + 0X30);
      LCD_DATA(PHUT%10 + 0X30);
   
      LCD_GOTO_XY(0,12);
      DELAY_US(20);
      LCD_DATA(GIO/10 + 0X30);
      LCD_DATA(GIO%10 + 0X30);
   }
   IF(GIA_TRI_MOD==3)
   {
      LCD_GOTO_XY(0,12);
      DELAY_US(20);
      LCD_DATA("  ");
      
      LCD_GOTO_XY(0,18);
      DELAY_US(20);
      LCD_DATA(GIAY/10 + 0X30);
      LCD_DATA(GIAY%10 + 0X30);
   
      LCD_GOTO_XY(0,15);
      DELAY_US(20);
      LCD_DATA(PHUT/10 + 0X30);
      LCD_DATA(PHUT%10 + 0X30);
   
      LCD_GOTO_XY(0,12);
      DELAY_US(20);
      LCD_DATA(GIO/10 + 0X30);
      LCD_DATA(GIO%10 + 0X30);
   }
}

VOID MAIN()
{
   SET_UP_PORT_IC_CHOT();    
   SETUP_TIMER_1(T1_INTERNAL | T1_DIV_BY_8);  
   SET_TIMER1(3036);                                              
   ENABLE_INTERRUPTS(GLOBAL);                
   ENABLE_INTERRUPTS(INT_TIMER1);
   GIO=0; PHUT=0; GIAY=0; GIA_TRI_MOD=0; 
   BDN=0;
   
   SETUP_LCD();
   LCD_GOTO_XY(0,0);
   LCD_DATA("DONG HO:");
   
   LCD_GOTO_XY(0,17);
   LCD_DATA(":");
   
   LCD_GOTO_XY(0,14);
   LCD_DATA(":");
   
   WHILE(TRUE)
   {
      If(BDN<10)
           {
              IF((BDN<5) && (INPUT(BT0)) && (INPUT(BT1)) && (INPUT(BT2))) LCD_HIENTHI_DONGHO();
              PHIM_MOD(); PHIM_UP(); PHIM_DW();
           }
           Else
           {
              BDN=BDN-10;
              DEM_TG_EXIT++;
              IF(DEM_TG_EXIT==20) GIA_TRI_MOD=0;
              GIAY++;
              IF(GIAY==60)
              {
                  GIAY=0;
                  PHUT++;
                  IF (PHUT==60)
                  {
                     PHUT=0;
                     GIO++;
                     IF (GIO==24) GIO=0;
                  }
              }
           }
   }
}


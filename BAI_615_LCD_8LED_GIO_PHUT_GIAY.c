#INCLUDE <TV_PICKIT2_SHIFT_1.c>
#INCLUDE <TV_PICKIT2_SHIFT_LCD.c>

SIGNED INT8 GIO=0,PHUT=0,GIAY=0,BD=0,GIA_TRI_MOD=0;
VOID GIAI_MA()
{
     LED_7DQ[7]=MA7DOAN[GIO/10];
     LED_7DQ[6]=MA7DOAN[GIO%10];
     
     LED_7DQ[4]=MA7DOAN[PHUT/10];
     LED_7DQ[3]=MA7DOAN[PHUT%10];
     
     LED_7DQ[1]=MA7DOAN[GIAY/10];
     LED_7DQ[0]=MA7DOAN[GIAY%10];
      IF (GIA_TRI_MOD==1)
     {
       IF (BD<5){LED_7DQ[1]=0XFF;LED_7DQ[0]=0XFF; }
     }
     ELSE IF (GIA_TRI_MOD==2)
     {
       IF (BD<5){LED_7DQ[3]=0XFF;LED_7DQ[4]=0XFF; }
     }
     ELSE IF (GIA_TRI_MOD==3)
     {
        IF (BD<5){LED_7DQ[7]=0XFF;LED_7DQ[6]=0XFF; }
     }
}
VOID KTMOD()
{
  
  IF (!INPUT(BT2))
  {
    DELAY_MS(20);
    IF (!INPUT(BT2))
    {
      GIA_TRI_MOD=0;
      IF (GIA_TRI_MOD==4)
      GIA_TRI_MOD=0;
      WHILE (!INPUT(BT2))
      {
         GIAI_MA();
         HIEN_THI_8LED_7DOAN_QUET();
      }
    }
  }
}
VOID KTUP()
{
  IF (!INPUT(BT0))
  {
    DELAY_MS(20);
    IF (!INPUT(BT0))
    {
      IF (GIA_TRI_MOD==1)
      {
         GIAY++;
         IF (GIAY==60) GIAY=59;
      }
      ELSE IF (GIA_TRI_MOD==2)
      {
         PHUT++;
         IF (PHUT==60) PHUT=59;
      }
      ELSE IF (GIA_TRI_MOD==3)
      {
         GIO++;
         IF (GIO==24) GIO=23;
       }
      WHILE (!INPUT(BT0)) {GIAI_MA();HIEN_THI_8LED_7DOAN_QUET();}
    }
  }
}
VOID KTDW()
{
  IF (!INPUT(BT1))
  {
    DELAY_MS(20);
    IF (!INPUT(BT1))
      {
         IF (GIA_TRI_MOD==1)
         {
            GIAY--;
            IF (GIAY==-1) GIAY=0;
         }
         ELSE IF (GIA_TRI_MOD==2)
         {
            PHUT--;
            IF (PHUT==-1) PHUT=0;
         }
         ELSE IF (GIA_TRI_MOD==3)
         {
            GIO--;
            IF (GIO==-1) GIO=0;
          }
      WHILE (!INPUT(BT1)) {GIAI_MA();HIEN_THI_8LED_7DOAN_QUET();}
    }
  }
}

#INT_TIMER1
VOID NGAT()
{
   BD++;SET_TIMER1(3036);
  IF (BD==10)
  {
    GIAY++;
    BD-=10;
    IF (GIAY==60)
    {
      PHUT++;
      GIAY=0;
      IF (PHUT==60)
      {
         GIO++;
         PHUT=0;
         IF (GIO==24) GIO=0;
      }
    }
  }
}

VOID HIENTHILCD()
{
     LCD_GOTO_XY(0,0);
     IF (GIA_TRI_MOD==0)
     {
         LCD_DATA("DONG HO:");
         GIAI_MA(); HIEN_THI_8LED_7DOAN_QUET();
         LCD_GOTO_XY(0,12);
         LCD_DATA(GIO/10 + 0X30);
         LCD_DATA(GIO%10 + 0X30);
         LCD_DATA(":");
         LCD_GOTO_XY(0,15);
         LCD_DATA(PHUT/10 + 0X30);
         LCD_DATA(PHUT%10 + 0X30);
         LCD_DATA(":");
         LCD_GOTO_XY(0,18);
         LCD_DATA(GIAY/10 + 0X30);
         LCD_DATA(GIAY%10 + 0X30);
     }
    ELSE IF(GIA_TRI_MOD==1)
      {
         
         GIAI_MA(); HIEN_THI_8LED_7DOAN_QUET();
         IF (BD<5)
         {
            LCD_GOTO_XY(0,18);;
            LCD_DATA("  ");
         }
           LCD_GOTO_XY(0,12);   
           LCD_DATA(GIO/10 + 0X30);
           LCD_DATA(GIO%10 + 0X30);
           LCD_DATA(":");
           LCD_DATA(PHUT/10 + 0X30);
           LCD_DATA(PHUT%10 + 0X30);
           LCD_DATA(":");
           LCD_DATA(GIAY/10 + 0X30);
           LCD_DATA(GIAY%10 + 0X30);
     }
      ELSE IF (GIA_TRI_MOD==2)
      {
         GIAI_MA();HIEN_THI_8LED_7DOAN_QUET();
         IF (BD<5)
         {
            LCD_GOTO_XY(0,15); 
            LCD_DATA("  ");
         }
         ELSE
         {
           LCD_GOTO_XY(0,12);   
           LCD_DATA(GIO/10 + 0X30);
           LCD_DATA(GIO%10 + 0X30);
           LCD_DATA(":");
           LCD_DATA(PHUT/10 + 0X30);
           LCD_DATA(PHUT%10 + 0X30);
           LCD_DATA(":");
           LCD_DATA(GIAY/10 + 0X30);
           LCD_DATA(GIAY%10 + 0X30);
         }
       }
      ELSE
      {
       GIAI_MA();
       HIEN_THI_8LED_7DOAN_QUET();
       IF (BD<5)
       {
         LCD_GOTO_XY(0,12);
         LCD_DATA("  ");
       }
         ELSE
         {
           LCD_GOTO_XY(0,12);   
           LCD_DATA(GIO/10 + 0X30);
           LCD_DATA(GIO%10 + 0X30);
           LCD_DATA(":");
           LCD_DATA(PHUT/10 + 0X30);
           LCD_DATA(PHUT%10 + 0X30);
           LCD_DATA(":");
           LCD_DATA(GIAY/10 + 0X30);
           LCD_DATA(GIAY%10 + 0X30);
         }
       
      }
}  
VOID MAIN()
{
  SET_UP_PORT_IC_CHOT();
  SETUP_TIMER_1(T1_INTERNAL|T1_DIV_BY_8);
  SET_TIMER1(3036);
  ENABLE_INTERRUPTS(INT_TIMER1);
  ENABLE_INTERRUPTS(GLOBAL);
  SETUP_LCD();
  WHILE (TRUE)
  {
   GIAI_MA();
   HIEN_THI_8LED_7DOAN_QUET();
   KTMOD();
   KTUP();
   KTDW();
   HIENTHILCD();
  }
}


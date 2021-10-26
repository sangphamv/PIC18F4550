#INCLUDE <TV_PICKIT2_SHIFT_1.C>
SIGNED INT8 GIO, PHUT, GIAY, BDN,GIA_TRI_MOD;

#INT_TIMER1
VOID INTERRUPT_TIMER1()
{
   BDN++;SET_TIMER1(3036);
}
VOID GIAI_MA_GAN_CHO_8LED_QUET()
{
   LED_7DQ[0]=MA7DOAN [GIAY%10];
   LED_7DQ[1]=MA7DOAN [GIAY/10];
   LED_7DQ[3]=MA7DOAN [PHUT%10];
   LED_7DQ[4]=MA7DOAN [PHUT/10];
   LED_7DQ[6]=MA7DOAN [GIO%10];
   LED_7DQ[7]=MA7DOAN [GIO/10];
   
   IF (GIA_TRI_MOD==1)        LED_7DQ[6]=LED_7DQ[6]&0X7F;
   ELSE IF (GIA_TRI_MOD==2)   LED_7DQ[3]=LED_7DQ[3]&0X7F;
   ELSE IF (GIA_TRI_MOD==3)   LED_7DQ[0]=LED_7DQ[0]&0X7F;
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
VOID PHIM_MOD()
{
   IF (PHIM_BT1(200))
   {
      GIA_TRI_MOD++;
      IF(GIA_TRI_MOD>=4) GIA_TRI_MOD=0;
   }
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXX
VOID PHIM_UP()
{
   IF(PHIM_BT0(200))
   {
      SWITCH (GIA_TRI_MOD)
         {
            CASE 1: IF (GIO==23) GIO=0;
                    ELSE GIO++;
                    BREAK;
            CASE 2: IF (PHUT==59) PHUT=0;
                    ELSE PHUT++;
                    BREAK; 
            CASE 3: IF (GIAY==59) GIAY=0;
                    ELSE GIO++;
                    BREAK;
            DEFAULT: BREAK;
         }
         
     }
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
VOID PHIM_DW()
{
   IF(PHIM_BT2(200))
   {
      SWITCH (GIA_TRI_MOD)
         {
            CASE 1: IF (GIO==0) GIO=23;
                    ELSE GIO--;
                    BREAK;
            CASE 2: IF (PHUT==0) PHUT=59;
                    ELSE PHUT--;
                    BREAK; 
            CASE 3: IF (GIAY==0) GIAY=59;
                    ELSE GIAY--;
                    BREAK;
            DEFAULT: BREAK;
         }
         
   }
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXX
VOID MAIN()
{
   SET_UP_PORT_IC_CHOT();
   SETUP_TIMER_1(T1_INTERNAL | T1_DIV_BY_8);
   SET_TIMER1(3036);
   ENABLE_INTERRUPTS(GLOBAL);
   ENABLE_INTERRUPTS(INT_TIMER1);;
   BDN=0; GIAY=0;PHUT=0; GIO=0; GIA_TRI_MOD=0;
   WHILE(TRUE)
   {
      GIAI_MA_GAN_CHO_8LED_QUET();
      IF (BDN<10)
         {
            HIEN_THI_8LED_7DOAN_QUET();
            PHIM_MOD(); PHIM_UP(); PHIM_DW();
         }
      ELSE
         {
            BDN=BDN-10;
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

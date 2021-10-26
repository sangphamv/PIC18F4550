
#INCLUDE <TV_PICKIT2_SHIFT_1.C>

SIGNED INT8 GIAY,PHUT,GIO,BDN;

#INT_TIMER1

VOID INTERRUPT_TIMER1()
{
   BDN++; SET_TIMER1 (3036) ;
}

VOID GIAI_MA_GAN_CHO_8LED_QUET()
{
   LED_7DQ[0] = MA7DOAN [GIAY % 10];
   LED_7DQ[1] = MA7DOAN [GIAY / 10];
   LED_7DQ[3] = MA7DOAN [PHUT % 10];
   LED_7DQ[4] = MA7DOAN [PHUT / 10];
   LED_7DQ[6] = MA7DOAN [GIO % 10];
   LED_7DQ[7] = MA7DOAN [GIO / 10];
}

VOID MAIN()
{
   SET_UP_PORT_IC_CHOT ();
   SETUP_TIMER_1 (T1_INTERNAL|T1_DIV_BY_8);
   SET_TIMER1 (3036);
   ENABLE_INTERRUPTS (GLOBAL);
   ENABLE_INTERRUPTS (INT_TIMER1);
   GIAY = 0;PHUT=0;GIO=0; BDN = 0;
   WHILE (TRUE)
   {
      GIAI_MA_GAN_CHO_8LED_QUET ();
      IF (BDN < 10) HIEN_THI_8LED_7DOAN_QUET () ;

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


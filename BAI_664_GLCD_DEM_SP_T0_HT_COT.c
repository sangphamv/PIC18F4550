
#INCLUDE<TV_PICKIT2_SHIFT_1.C>
#INCLUDE<TV_PICKIT2_SHIFT_GLCD128X64.C>
#INCLUDE<GRAPHICS.C>

UNSIGNED INT8 T0,T0_TAM;
UNSIGNED INT16 I,J,Z,DV,CH,TR;

VOID GM()
{
   DV = T0 % 10;
   CH = T0 / 10 % 10;
   TR = T0 / 100;
   SETUP_GLCD (GLCD_GRAPHIC_MODE);
   GLCD_MAU_NEN (0);
   FOR (I = 0; I < DV; I++)
   {
      glcd_rect (DV, 0, (DV * 5) + 6, 5, 0, 1) ;
   }

   FOR (J = 0; J < CH; J++)
   {
      glcd_rect (CH, 15, (CH * 5) + 6, 20, 0, 1) ;
   }

   FOR (Z = 0; Z < TR; Z++)
   {
      glcd_rect (TR , 30, (TR * 5) + 6, 35, 0, 1) ;
   }
}

VOID MAIN()
{
   SET_UP_PORT_IC_CHOT ();
   SETUP_TIMER_0 (T0_EXT_L_TO_H|T0_DIV_1|T0_8_BIT);
   SET_TIMER0 (0);
   DV=CH=TR=0;
   WHILE (TRUE)
   {
      T0 = GET_TIMER0 ();

      IF (T0 != T0_TAM)
      {
         T0_TAM = T0;
         GM ();
         IF (T0 >= 101) SET_TIMER0 (1) ;       
      }
               GDRAM_VDK_TO_GDRAM_GLCD_ALL ();
         XUAT_4LED_7DOAN_4SO (0XFF, MA7DOAN[TR], MA7DOAN[CH], MA7DOAN[DV]) ;
   }
}


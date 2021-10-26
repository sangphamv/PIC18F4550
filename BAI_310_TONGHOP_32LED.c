#INCLUDE <TV_PICKIT2_SHIFT_1.C>
UNSIGNED INT8 I,J;
UNSIGNED INT16 ZT, ZP;
VOID SANG_TAT_DAN_NGOAI_VAO_32LED_2LAN()
{
   FOR(J=0;J<2;j++)
   {
      FOR(I=0;I<16;I++)
      {
         XUAT_32LED_DON_2WORD(ZP,ZT);
         DELAY_MS(30);
         ZP=(ZP<<1)+1;
         ZT=(ZT>>1)+0X8000;
      }
      FOR(I=0;I<16;I++)
      {
         XUAT_32LED_DON_2WORD(ZP,ZT);
         DELAY_MS(30);
         ZP=(ZP<<1);
         ZT=(ZT>>1);
      }
   }
}
VOID SANG_TAT_DAN_TRONG_RA_32LED_2LAN()
{
   FOR(J=0;J<2;j++)
   {
      FOR(I=0;I<16;I++)
      {
         XUAT_32LED_DON_2WORD(ZP,ZT);
         DELAY_MS(30);
         
         ZP=(ZP>>1)+0X8000; ZT=(ZT<<1)+1;
      }
      FOR(I=0;I<16;I++)
      {
         XUAT_32LED_DON_2WORD(ZP,ZT);
         DELAY_MS(30);
         
         ZP=(ZP>>1);
         ZT=(ZT<<1);
      }
   }
}
VOID SANG_TAT_32LED_5LAN()
{
      FOR (J = 0; J < 5; J++)
   {
      XUAT_32LED_DON_4BYTE (0, 0, 0, 0);
      DELAY_MS (100);
      XUAT_32LED_DON_4BYTE (0XFF, 0XFF, 0XFF, 0XFF) ;
      DELAY_MS (100);
   }
}
VOID MAIN()
{
   SET_UP_PORT_IC_CHOT();
   

   WHILE(TRUE)
   {
      SANG_TAT_32LED_5LAN();
      SANG_TAT_DAN_NGOAI_VAO_32LED_2LAN();
      SANG_TAT_32LED_5LAN();
      SANG_TAT_DAN_TRONG_RA_32LED_2LAN();
   }
}

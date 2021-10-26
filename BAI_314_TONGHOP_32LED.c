
#INCLUDE <TV_PICKIT2_SHIFT_1.C>

UNSIGNED INT8 J=0;
UNSIGNED INT16 ZT=0, ZP=0;

VOID MAIN()
{
   SET_UP_PORT_IC_CHOT ();
   
   WHILE (TRUE)
   {
      IF (J < 5)
      {
         XUAT_32LED_DON_4BYTE (0, 0, 0, 0);
         DELAY_MS (250);
         XUAT_32LED_DON_4BYTE (0XFF, 0XFF, 0XFF, 0XFF) ;
         DELAY_MS (250);
      }

      ELSE IF (J < 21)
      {
         XUAT_32LED_DON_2WORD (ZP, ZT) ;
         DELAY_MS (100) ;
         ZP = (ZP<<1) + 1;
         ZT = (ZT>>1) + 0X8000;
      }

      ELSE IF (J < 38)
      {
         XUAT_32LED_DON_2WORD (ZP, ZT) ;
         DELAY_MS (100) ;
         ZP = (ZP<<1);
         ZT = (ZT>>1);
      }

      ELSE IF (J < 43)
      {
         XUAT_32LED_DON_4BYTE (0, 0, 0, 0);
         DELAY_MS (100);
         XUAT_32LED_DON_4BYTE (0XFF, 0XFF, 0XFF, 0XFF) ;
         DELAY_MS (100);
      }

      ELSE IF (J < 59)
      {
         XUAT_32LED_DON_2WORD (ZP, ZT) ;
         DELAY_MS (100) ;
         
         ZP = (ZP>>1) + 0X8000; ZT = (ZT<<1) +1;
      }

      ELSE IF (J < 76)
      {
         XUAT_32LED_DON_2WORD (ZP, ZT) ;
         DELAY_MS (100) ;
         
         ZP = (ZP>>1);
         ZT = (ZT<<1);
      }

      ELSE
      {
         J = 0;
      }

      J++;
   }
}


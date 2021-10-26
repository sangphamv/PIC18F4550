
#INCLUDE <TV_PICKIT2_SHIFT_1.c>

VOID MAIN()
{
   SET_UP_PORT_IC_CHOT () ;
   SET_TRIS_B (0X3C) ;
   XUAT_32LED_DON_4BYTE (0, 0, 0, 0) ;

   WHILE (TRUE)
   {
      DO{}
      WHILE (INPUT (BT0)) ;
      XUAT_32LED_DON_4BYTE (0, 0, 0, 0XFF) ;
      
      DO{}
      WHILE (INPUT (BT1)) ;
      XUAT_32LED_DON_4BYTE (0, 0, 0, 0) ;
   }
}


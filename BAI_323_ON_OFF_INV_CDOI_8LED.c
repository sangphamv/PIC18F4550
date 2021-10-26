
#INCLUDE <TV_PICKIT2_SHIFT_1.c>

UNSIGNED INT8 Y;

VOID PHIM_INV()
{
   IF ( ! INPUT (INV) )
   {
      DELAY_MS (20) ;
      {
         IF ( ! INPUT (INV) )
         {
            Y = ~Y;
            XUAT_32LED_DON_4BYTE (0, 0, 0, Y) ;
            DO{}
            WHILE ( ! INPUT (INV)) ;
         }
      }
   }
}

VOID MAIN()
{
   SET_UP_PORT_IC_CHOT () ;
   SET_TRIS_B (0X3C) ;
   Y = 0;
   XUAT_32LED_DON_4BYTE (0, 0, 0, 0) ;

   WHILE (TRUE)
   {
      DO{}
      WHILE (INPUT (ON)) ;
      Y = 0X0F;
      XUAT_32LED_DON_4BYTE (0, 0, 0, Y) ;

      DO
      {
         PHIM_INV ();
      }

      WHILE (INPUT (OFF)) ;
      XUAT_32LED_DON_4BYTE (0, 0, 0, 0) ;
   }
}


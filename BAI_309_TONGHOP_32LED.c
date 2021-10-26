
#INCLUDE <TV_PICKIT2_SHIFT_1.C>

UNSIGNED INT8 I,J;

UNSIGNED INT32 Y;

VOID SANG_TAT_32LED_5LAN ()
{
   FOR (J = 0; J < 5; J++)
   {
      XUAT_32LED_DON_4BYTE (0, 0, 0, 0);
      DELAY_MS (100);
      XUAT_32LED_DON_4BYTE (0XFF, 0XFF, 0XFF, 0XFF) ;
      DELAY_MS (100);
   }
}

VOID SANG_TAT_DAN_PST_32LED_2LAN() 
{
   FOR (J = 0; J < 2; J++)
   {
      FOR (I = 0; I < 32; I++)
      {
         XUAT_32LED_DON_1DW (Y);
         DELAY_MS (30);
         Y = (Y<<1) + 1;
      }

      FOR (I = 0; I < 32; I++)
      {
         XUAT_32LED_DON_1DW (Y);
         DELAY_MS (30);
         Y = (Y<<1);
      }
   }
}

VOID SANG_TAT_DAN_TSP_32LED_2LAN()
{
   FOR (J = 0; J < 2; J++)
   {
      FOR (I = 0; I < 32; I++)
      {
         XUAT_32LED_DON_1DW (Y);
         DELAY_MS (30);
         Y = (Y>>1) + 0X80000000;
      }

      FOR (I = 0; I < 32; I++)
      {
         XUAT_32LED_DON_1DW (Y);
         DELAY_MS (30);
         Y = (Y>>1);
      }
   }
}

VOID MAIN()
{
   SET_UP_PORT_IC_CHOT ();
   Y = 0X00000000;

   WHILE (TRUE)
   {
      SANG_TAT_32LED_5LAN ();
      SANG_TAT_DAN_PST_32LED_2LAN ();
      SANG_TAT_32LED_5LAN ();
      SANG_TAT_DAN_TSP_32LED_2LAN ();
   }
}



#INCLUDE <TV_PICKIT2_SHIFT_1.c>
#INCLUDE <TV_PICKIT2_SHIFT_KEY4X4_138.c>

SIGNED INT8 MP;

VOID MAIN()
{
   SET_UP_PORT_IC_CHOT ();
   SET_TRIS_B (0X3C);

   WHILE (TRUE)
   {
      MP = KEY_4X4_UP ();

      IF (MP != 0XFF)
      {
         XUAT_32LED_DON_4BYTE (0, 0, 0, MP) ;
      }
   }
}


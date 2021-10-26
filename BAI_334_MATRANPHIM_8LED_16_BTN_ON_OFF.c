
#INCLUDE <TV_PICKIT2_SHIFT_1.c>
#INCLUDE <TV_PICKIT2_SHIFT_KEY4X4_138.c>

UNSIGNED INT8 Y;
SIGNED INT8 MP;

VOID MAIN()
{
   SET_UP_PORT_IC_CHOT ();
   SET_TRIS_B (0X3C);

   WHILE (TRUE)
   {
      MP = KEY_4X4_DW ();
     
      
      IF (MP != 0XFF)
      {
         
         IF (MP == 0) Y = 0X01|Y;
         IF (MP == 1) Y = 0X02|Y;
         IF (MP == 2) Y = 0X04|Y;
         IF (MP == 3) Y = 0X08|Y;
         IF (MP == 4) Y = 0X10|Y;
         IF (MP == 5) Y = 0X20|Y;
         IF (MP == 6) Y = 0X40|Y;
         IF (MP == 7) Y = 0X80|Y;
         IF (MP == 8) Y = 0XFE&Y;
         IF (MP == 9) Y = 0XFD&Y;
         IF (MP == 10) Y=0XFB&Y;
         IF (MP == 11) Y=0XF7&Y;
         IF (MP == 12) Y=0XEF&Y;
         IF (MP == 13) Y=0XDF&Y;
         IF (MP == 14) Y=0XBF&Y;
         IF (MP == 15) Y=0X7F&Y;
         XUAT_32LED_DON_4BYTE (0, 0, 0, Y);
      }
   }
}


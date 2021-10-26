#include <TV_PICKIT2_SHIFT_1.c>
#INCLUDE <TV_PICKIT2_SHIFT_KEY4X4_138.c>
UNSIGNED INT8 MP,S4,S3,S2,S1;
VOID MAIN()
{
   SET_UP_PORT_IC_CHOT(); SET_TRIS_B(0X3C);S4=S3=S2=S1=0X7F;
   XUAT_4LED_7DOAN_4SO(S4,S3,S2,S1);
   WHILE(TRUE)
   {
      
      MP=KEY_4X4_DW();
      IF(MP!=0XFF) 
      {
         S4=S3;
         S3=S2;
         S2=S1;
         S1=MA7DOAN[MP];
         XUAT_4LED_7DOAN_4SO(S4,S3,S2,S1);
      }
         
   }
}

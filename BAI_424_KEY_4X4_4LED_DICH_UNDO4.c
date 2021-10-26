#include <TV_PICKIT2_SHIFT_1.c>
#INCLUDE <TV_PICKIT2_SHIFT_KEY4X4_138.c>
UNSIGNED INT32 MP,KQ;
VOID MAIN()
{
   SET_UP_PORT_IC_CHOT(); SET_TRIS_B(0X3C);KQ=0;
   WHILE(TRUE)
   {  
      MP=KEY_4X4_DW();
      IF(MP!=0XFF) 
      {
        IF(MP<=9)
        { 
            KQ= KQ*10 +MP;
           IF(KQ>=10000)  KQ=KQ%10000;      
           XUAT_4LED_7DOAN_GIAIMA_XOA_SO0(KQ);
        }
        IF(MP==12)
        {
            XUAT_4LED_7DOAN_4SO(0X7F,0X7F,0X7F,0X7F);
            KQ=0;
        }
        IF(MP==11)
        { 
            
           KQ= KQ/10;
           XUAT_4LED_7DOAN_GIAIMA_XOA_SO0(KQ);
        } 
      }    
   }
}

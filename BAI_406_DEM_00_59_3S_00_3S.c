#INCLUDE <TV_PICKIT2_SHIFT_1.C>
SIGNED INT16 I;
VOID MAIN()
{     

      SET_UP_PORT_IC_CHOT();
      WHILE(TRUE)
      {
         I=0;
         DO
         {
         XUAT_4LED_7DOAN_2SO(MA7DOAN[I/10],MA7DOAN[I%10]);
         DELAY_MS(100);
         }   
         WHILE(I++<59);
         DELAY_MS(3000);
         I=59;
         DO
         {
         XUAT_4LED_7DOAN_2SO(MA7DOAN[I/10],MA7DOAN[I%10]);
         DELAY_MS(100);
         }
         WHILE(I-->0);
         DELAY_MS(3000);
      }
}

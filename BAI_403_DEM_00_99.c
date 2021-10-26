#INCLUDE <TV_PICKIT2_SHIFT_1.C>
SIGNED INT8 I;
VOID MAIN()
{     SET_UP_PORT_IC_CHOT();
      WHILE(TRUE)
      {
         FOR (I=0;I<99;I++)
            {
               XUAT_4LED_7DOAN_2SO(MA7DOAN[I/10],MA7DOAN[I%10]);
               DELAY_MS(200);
            }
      }
}

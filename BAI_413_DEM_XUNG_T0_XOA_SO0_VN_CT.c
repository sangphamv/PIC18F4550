#INCLUDE <TV_PICKIT2_SHIFT_1.C>
UNSIGNED INT8 T0,T0_TAM;
VOID MAIN()
{
   SET_UP_PORT_IC_CHOT();
   SETUP_TIMER_0 (T0_EXT_L_TO_H|T0_DIV_1|T0_8_BIT);
   SET_TIMER0(0);
   T0_TAM = T0 = 0;
   XUAT_4LED_7DOAN_GIAIMA_XOA_SO0(T0);
   WHILE (TRUE)
   {
      T0 = GET_TIMER0();
      IF ( T0!=T0_TAM)
      {
         T0_TAM = T0;
         XUAT_4LED_7DOAN_GIAIMA_XOA_SO0(T0);
         IF (T0>=101)  SET_TIMER0(1);
         
      }
   }
}

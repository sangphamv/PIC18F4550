
#INCLUDE <TV_PICKIT2_SHIFT_1.c>

UNSIGNED INT8 T0;
UNSIGNED INT16 DONVI, CHUC, TRAM;

VOID GIAI_MA_HIEN_THI (UNSIGNED INT16 TAM)
{
   DONVI = MA7DOAN[TAM % 10];
   CHUC = MA7DOAN[TAM / 10 % 10];
   TRAM = MA7DOAN[TAM / 100];

   IF (TRAM == 0XC0)//0
   {
      TRAM = 0XFF;// TAT LED

      IF (CHUC == 0XC0)
      {
         CHUC = 0XFF;
      }

   }

   XUAT_4LED_7DOAN_4SO (0XFF,TRAM, CHUC, DONVI) ;
}

VOID MAIN()
{
   SET_UP_PORT_IC_CHOT () ;
   SETUP_TIMER_0 (T0_EXT_L_TO_H|T0_DIV_1|T0_8_BIT);
   SET_TIMER0 (90) ;

   WHILE (TRUE)
   {
      T0 = GET_TIMER0 () ;
      GIAI_MA_HIEN_THI (T0);
      IF (T0 >= 101) SET_TIMER0 (1);
   }
}



#INCLUDE <TV_PICKIT2_SHIFT_1.c>
#INCLUDE <TV_PICKIT2_SHIFT_STEP_MOTOR.c>

CONST UNSIGNED CHAR MA[9]={45,40,35,30,25,20,15,10,5};

SIGNED INT8 X;
UNSIGNED INT16 I;
INT1 TT;

VOID KT_PHIM()
{
   IF ( ! INPUT (UP) )
   {
      DELAY_MS (20) ;

      IF ( ! INPUT (UP) )
      {
         TT = 1;
         X++;
         I = 0;
         IF (X > 9) X=9;
         WHILE ( ! INPUT (UP)) ;
      }
   }

   
   IF ( ! INPUT (DW) )
   {
      DELAY_MS (20) ;

      IF ( ! INPUT (DW) )
      {
         TT = 1;
         I = 0;
         X--;
         IF (X < 0) X=1;
         WHILE ( ! INPUT (DW)) ;
      }
   }

   IF ( ! INPUT (STOP) )
   {
      TT = 0;
   }

   IF ( ! INPUT (INV) )
   {
      DELAY_MS (20) ;

      IF ( ! INPUT (INV) )
      {
         STEPMOTOR_TN = ~STEPMOTOR_TN;
         WHILE ( ! INPUT (INV)) ;
      }
   }

   IF ( ! INPUT (STOP)) TT = 0;
}

VOID MAIN()
{
   SET_UP_PORT_IC_CHOT () ;
   X = 0; I = 0; TT = 0;
   
   STEPMOTOR_ONOFF = 1; //DE KHOI CANH BAO
   XUAT_4LED_7DOAN_4SO (MA7DOAN[X], MA7DOAN[I / 100], MA7DOAN[I / 10 % 10], MA7DOAN[I % 10]) ;

   WHILE (TRUE)
   {
      KT_PHIM () ;
      STEPMOTOR_DELAY = MA[X - 1];

      IF (TT == 1)
      {
         MOTOR_STEP_RUN_HS () ;
         DELAY_MS (STEPMOTOR_DELAY) ;
         I++;
         IF (I == 400) I=0;
         XUAT_4LED_7DOAN_4SO (MA7DOAN[X], MA7DOAN[I / 100], MA7DOAN[I / 10 % 10], MA7DOAN[I % 10]) ;
      }
   }
}


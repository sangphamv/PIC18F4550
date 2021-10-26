#INCLUDE <TV_PICKIT2_SHIFT_1.c>
#INCLUDE <TV_PICKIT2_SHIFT_STEP_MOTOR.c>
UNSIGNED INT16 I,Y;
VOID PHIM_INV()
{
  IF (! INPUT(INV))
    { 
       DELAY_MS(20);
       {
         IF (! INPUT(INV))
           {

               STEPMOTOR_TN=~STEPMOTOR_TN;
               I=0;Y=0;
           DO
             {
               MOTOR_STEP_RUN_FS();
               DELAY_MS(STEPMOTOR_DELAY);
             }
         WHILE(! INPUT(INV));
            }
        }
    }
} 
VOID MAIN()
{ 
    SET_UP_PORT_IC_CHOT();
    STEPMOTOR_DELAY=40; 
    STEPMOTOR_ONOFF=1; //DE KHOI CANH BAO
    I=0;
    Y=0;
    WHILE(TRUE)
    { 
       WHILE(INPUT(ON));  //CHO NHAN ON
       DO
        {
          MOTOR_STEP_RUN_FS();
          DELAY_MS(STEPMOTOR_DELAY);
           I++;
           IF(I>200) 
             {
               I=0;
               Y++;
               
             }
           XUAT_4LED_7DOAN_4SO(MA7DOAN[Y],MA7DOAN[I/100],MA7DOAN[I/10%10],MA7DOAN[I%10]);
          PHIM_INV();
        }
       WHILE (INPUT(OFF)); 
    }
}


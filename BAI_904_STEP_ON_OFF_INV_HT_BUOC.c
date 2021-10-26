#INCLUDE <TV_PICKIT2_SHIFT_1.c>
#INCLUDE <TV_PICKIT2_SHIFT_STEP_MOTOR.c>
UNSIGNED INT16 I;
VOID PHIM_INV()
{
  IF (! INPUT(INV))
    { 
       DELAY_MS(20);
       {
         IF (! INPUT(INV))
           {

               STEPMOTOR_TN=~STEPMOTOR_TN;
               I=0;
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
    STEPMOTOR_ONOFF=1;  //DE KHOI CANH BAO
    WHILE(TRUE)
    { 
       WHILE(INPUT(ON));  //CHO NHAN ON
       DO
        {
          MOTOR_STEP_RUN_FS();
          DELAY_MS(STEPMOTOR_DELAY);
           I++;
          XUAT_4LED_7DOAN_4SO(0XFF,MA7DOAN[I/100],MA7DOAN[I/10%10],MA7DOAN[I%10]);
          PHIM_INV();
        }
       WHILE (INPUT(OFF)); 
    }
}

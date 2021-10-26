
#include <tv_pickit2_shift_1.c>
#include <tv_pickit2_shift_step_motor.c>

void phim_inv()
{
   IF (!input(inv))
   {
      delay_ms (20) ;
      {
         IF (!input (inv))
         {
            stepmotor_tn = ~stepmotor_tn;

            DO
            {
               motor_step_run_fs () ;
               delay_ms (stepmotor_delay) ;
            }

            WHILE ( ! input (inv)) ;
         }
      }
   }
}

void main()
{
   set_up_port_ic_chot();
   stepmotor_delay = 5;
   stepmotor_onoff = 1; //de khoi canh bao
   WHILE (true)
   {
      WHILE (input (on)); //cho nhan on
      DO
      {
         motor_step_run_fs () ;
         delay_ms (stepmotor_delay) ;
         phim_inv () ;
      }

      WHILE (input (off));
   }
}


#INCLUDE <TV_PICKIT2_SHIFT_1.c>
#INCLUDE <TV_PICKIT2_SHIFT_STEP_MOTOR.c>
#INCLUDE <TV_PICKIT2_SHIFT_KEY4X4_138.c>

SIGNED INT8 X,MP,SO;
UNSIGNED INT16 I;
INT1 TT;
VOID KT_PHIM()
{
      MP=KEY_4X4_DW();
      IF(MP!=0XFF) 
      { 
        IF(MP<=9) SO=MP;
        IF(MP==13) TT=1;         
      }
}

VOID MAIN()
{ 
    SET_UP_PORT_IC_CHOT();
    X=0;I=0;TT=0;SO=0;
   STEPMOTOR_DELAY=6;
    STEPMOTOR_ONOFF=1;  //DE KHOI CANH BAO
    XUAT_4LED_7DOAN_4SO(MA7DOAN[X],MA7DOAN[I/100],MA7DOAN[I/10%10],MA7DOAN[I%10]);
    WHILE(TRUE)
    { 
         KT_PHIM();
          
         IF(TT==1)
         {
             STEP_MOTOR_QUAY_THUAN_FS();
             DELAY_MS(STEPMOTOR_DELAY);
             I++;
         IF(I==200)
            {
               I=0;
               SO--;
               IF(SO==0) TT=0;
            }
         
         }
         XUAT_4LED_7DOAN_4SO(MA7DOAN[SO],MA7DOAN[I/100],MA7DOAN[I/10%10],MA7DOAN[I%10]);
    }
}


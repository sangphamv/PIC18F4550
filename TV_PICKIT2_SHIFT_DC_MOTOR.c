INT1 DCMOTOR_TN = 0, DCMOTOR_ONOFF=0;
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//CAC HAM CHO DK DONG CO DC ON OFF
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
VOID DC_MOTOR_ENABLE()
{
      DC_ENABLE=1;
      XUAT_BUZZER_RELAY();
}
VOID DC_MOTOR_QUAY_THUAN()
{
      OUTPUT_HIGH(PIN_C1);
      OUTPUT_LOW(PIN_C2);
}
VOID DC_MOTOR_QUAY_NGHICH()
{
      OUTPUT_LOW(PIN_C1);
      OUTPUT_HIGH(PIN_C2);
}
VOID DC_MOTOR_STOP()
{
      OUTPUT_LOW(PIN_C1);
      OUTPUT_LOW(PIN_C2);
}
VOID DC_MOTOR_CONTROL()
{
      IF (DCMOTOR_ONOFF==1)
      {
         IF (DCMOTOR_TN)   DC_MOTOR_QUAY_THUAN();
         ELSE              DC_MOTOR_QUAY_NGHICH();
      }
      ELSE                 DC_MOTOR_STOP();
      
}         
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//CAC HAM CHO DK DONG CO DC BANG PWM
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
UNSIGNED INT16    PWM_DUTY;
VOID DC_MOTOR_KTAO_CCP1_THUAN()
{     
      SETUP_CCP2(CCP_OFF);      
      SETUP_CCP1(CCP_PWM);
      OUTPUT_LOW(PIN_C1);      
}
VOID DC_MOTOR_KTAO_CCP2_NGHICH()
{            
      SETUP_CCP1(CCP_OFF);      
      SETUP_CCP2(CCP_PWM);
      OUTPUT_LOW(PIN_C2);
}
VOID DC_MOTOR_KTAO_CCPX_KTAO()
{         
     IF (DCMOTOR_TN)   DC_MOTOR_KTAO_CCP1_THUAN();
     ELSE               DC_MOTOR_KTAO_CCP2_NGHICH();            
}
VOID DC_MOTOR_PWW_SETUP_DUTY()
{     
     IF (DCMOTOR_TN)   SET_PWM1_DUTY(PWM_DUTY);
     ELSE               SET_PWM2_DUTY(PWM_DUTY);     
} 
VOID DC_MOTOR_PWM_CCP1_CCP2_STOP()
{         
      PWM_DUTY=0;            
      SETUP_CCP1(CCP_OFF);
      SETUP_CCP2(CCP_OFF);
      DC_MOTOR_KTAO_CCPX_KTAO();
      DC_MOTOR_PWW_SETUP_DUTY();
}

#INCLUDE <TV_PICKIT2_SHIFT_1.c>
#INCLUDE <TV_PICKIT2_SHIFT_32LED_DON.C>
SIGNED INT8 TTCT=1;
UNSIGNED INT8 T0;
UNSIGNED INT16 DONVI, CHUC, TRAM;
VOID GIAI_MA_HIEN_THI (UNSIGNED INT16 TAM)
{
   DONVI=MA7DOAN[TAM%10];
   CHUC=MA7DOAN[TAM/10%10];
   TRAM=MA7DOAN[TAM/100];
   IF (TRAM==0XC0)
   {
      TRAM=0XFF;
      IF (CHUC==0XC0) 
      {
         CHUC=0XFF;
      }
     
   }
   //XUAT_4LED_7DOAN_4SO(MA7DOAN[TTCT],TRAM,CHUC,DONVI);
}
VOID PHIM_UP()
{
   IF(!INPUT(UP)&&(TTCT<7))
   {
      DELAY_MS(10);
      IF(!INPUT(UP))
      {
         TTCT++;
         WHILE(!INPUT(UP));
       
      }
   }
}
//*********************
VOID PHIM_DW()
{
   IF(!INPUT(DW)&&(TTCT>1))
   {
      DELAY_MS(10);
      IF(!INPUT(DW))
      {
         TTCT--;
         WHILE(!INPUT(DW));
       
      }
   }
}
//******************************************
VOID PHIM_CLR()
{
   IF(!INPUT(CLR)&&(TTCT>1))
   {

         TTCT=1;
         RESET_TOAN_BO_BIEN();
       
      
   }
}
//**********************
VOID MAIN()
{
   SET_UP_PORT_IC_CHOT();
   SET_TRIS_B(0X3C);
   SETUP_TIMER_0 (T0_EXT_L_TO_H|T0_DIV_1|T0_8_BIT);
   SET_TIMER0(0);
   WHILE(TRUE)
   {
      T0=GET_TIMER0();
      GIAI_MA_HIEN_THI (T0);
      IF (T0>=101) SET_TIMER0(1);
      XUAT_4LED_7DOAN_4SO(MA7DOAN[TTCT],TRAM,CHUC,DONVI);
      IF (TTCT==1)      SANG_TAT_32LED(10,0);
      IF (TTCT==2)      SANG_TAT_DAN_PST_32LED(10,0);
      IF (TTCT==3)      SANG_TAT_DAN_TSP_32LED(10,0);
      IF (TTCT==4)      SANG_TAT_DAN_NGOAI_VAO_32LED(10,0);
      IF (TTCT==5)      SANG_TAT_DAN_TRONG_RA_32LED(10,0);
      IF (TTCT==6)      SANG_DON_PST_32LED(10,0);
      IF (TTCT==7)      SANG_DON_TSP_32LED(10,0);
      PHIM_DW();
      PHIM_UP();
      PHIM_CLR();
   }
}     

 


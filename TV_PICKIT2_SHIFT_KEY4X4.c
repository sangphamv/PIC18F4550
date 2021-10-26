UNSIGNED INT KEY_NHAN()
{     SIGNED INT8  MAQUETCOT,MAPHIM,HANG,COT;
      MAQUETCOT = 0B11111110;   MAPHIM=HANG=0XFF;
      FOR(COT=0;COT<4;COT++)
         {   
            OUTPUT_B(MAQUETCOT);  MAQUETCOT  = (MAQUETCOT<<1) + 0x1;
            IF         (!INPUT(PIN_B4))      {HANG=0;   BREAK;}
            ELSE    IF (!INPUT(PIN_B5))      {HANG=1;   BREAK;}
            ELSE    IF (!INPUT(PIN_B6))      {HANG=2;   BREAK;}
            ELSE    IF (!INPUT(PIN_B7))      {HANG=3;   BREAK;}
         }          
      IF (HANG!=0XFF)   MAPHIM   = COT*4 + HANG;
      RETURN(MAPHIM);
  }

UNSIGNED INT KEY_4X4()
{  UNSIGNED INT8  MPT1,MPT2;
      MPT1=KEY_NHAN();
      IF (MPT1!=0XFF)   
      {                         
         DO{MPT2=KEY_NHAN();}
         WHILE (MPT2==MPT1);
      }             
      RETURN(MPT1);
}

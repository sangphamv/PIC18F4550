CONST UNSIGNED CHAR MAQUETKEY[4]= {0x3F,0x7F,0xBF,0xFF};
UNSIGNED INT8  MPT1=0,MPT2=0;  
UNSIGNED INT KEY_NHAN()
{     SIGNED INT8 MAPHIM,HANG,COT;
      MAPHIM=HANG=0XFF;
      FOR(COT=0;COT<4;COT++)
            {   
               OUTPUT_B(MAQUETKEY[COT]);
               IF         (!INPUT(PIN_B2))      {HANG=0;   BREAK;}
               ELSE    IF (!INPUT(PIN_B3))      {HANG=1;   BREAK;}
               ELSE    IF (!INPUT(PIN_B4))      {HANG=2;   BREAK;}
               ELSE    IF (!INPUT(PIN_B5))      {HANG=3;   BREAK;}
            }          
         IF (HANG!=0XFF)   MAPHIM   = COT*4 + HANG;
         RETURN(MAPHIM);
}
UNSIGNED INT KEY_4X4()
{            
      MPT1=KEY_NHAN();
      IF (MPT1!=0XFF)   
      {  
         IF (MPT1!=MPT2)
            {
               RETURN(MPT1);  //PHIM MOI
               MPT2=MPT1;
            }
         ELSE
         {
            DELAY_MS(1);
            MPT1=KEY_NHAN();
            DO
            {
               MPT2=KEY_NHAN();
               }
            WHILE (MPT2!=MPT1);
               RETURN(MPT1);     //THOAT VI TRUNG MA PHIM DA NHAN
               MPT2=MPT1;           
         }
      }  
      ELSE 
      {
         RETURN(MPT1);  //THOAT VI KHONG NHAN
         MPT2=MPT1;
      }      
}



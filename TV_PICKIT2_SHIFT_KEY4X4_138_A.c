CONST UNSIGNED CHAR MAQUETKEY[4]= {0x3F,0x7F,0xBF,0xFF};//{0x3F,0x7F,0xBF,0xFF};


unsigned char KEY_4X4();
unsigned char HANG;
void KEY_KIEMTRA()
{      
         HANG=0XFF;
         IF         (!INPUT(PIN_B2))      {HANG=0;  }
         ELSE    IF (!INPUT(PIN_B3))      {HANG=1;  }
         ELSE    IF (!INPUT(PIN_B4))      {HANG=2;  }
         ELSE    IF (!INPUT(PIN_B5))      {HANG=3;  }
}

UNSIGNED INT KEY_NHAN()
{     SIGNED INT8 MAPHIM,COT;
      MAPHIM=0XFF;
      
      OUTPUT_LOW(PIN_B7); 
      OUTPUT_LOW(PIN_B6);
      COT=0;   KEY_KIEMTRA();
      IF (HANG!=0XFF)   
      {
               MAPHIM   = COT*4 + HANG;
               return(MAPHIM);
      }
               
      OUTPUT_LOW(PIN_B7); 
      OUTPUT_HIGH(PIN_B6);
      COT=1;   KEY_KIEMTRA();
      IF (HANG!=0XFF)   
      {
               MAPHIM   = COT*4 + HANG;
               return(MAPHIM);
      }
      OUTPUT_HIGH(PIN_B7); 
      OUTPUT_LOW(PIN_B6);
      COT=2;   KEY_KIEMTRA();
      IF (HANG!=0XFF)   
      {
               MAPHIM   = COT*4 + HANG;
               return(MAPHIM);
      }
      OUTPUT_HIGH(PIN_B7); 
      OUTPUT_HIGH(PIN_B6);
      COT=3;   KEY_KIEMTRA();
      IF (HANG!=0XFF)   
      {
               MAPHIM   = COT*4 + HANG;
               return(MAPHIM);
      }                 
               
               
}
UNSIGNED INT KEY_4X4()
{  UNSIGNED INT8  MPT1,MPT2;      
      MPT1=KEY_NHAN();         
      IF (MPT1!=0XFF)   
      {  DELAY_MS(5);  
         MPT1=KEY_NHAN();
         DO{MPT2=KEY_NHAN();}
         WHILE (MPT2==MPT1);
      }             
      RETURN(MPT1);
}



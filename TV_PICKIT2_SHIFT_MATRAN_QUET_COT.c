#INCLUDE <TV_PICKIT2_SHIFT_FONT.c>
//DU LIEU MA QUET COT
CONST UNSIGNED INT16 MA_QUET_COT_DO[8]={
0x0200,0x0800,0x2000,0x8000,0x0040,0x0010,0x0004,0x0001};
CONST UNSIGNED INT16 MA_QUET_COT_XANH[]={
0x0100,0x0400,0x1000,0x4000,0x0080,0x0020,0x0008,0x0002};
CONST UNSIGNED INT16 MA_QUET_COT_CAM[]={
0x0300,0x0C00,0x3000,0xC000,0x00C0,0x0030,0x000C,0x0003};

#DEFINE  TG_DELAY    100
#DEFINE  SLKT_HIENTHI    40
UNSIGNED INT8   DL_HIENTHI[6*SLKT_HIENTHI];
UNSIGNED INT8   SLKT,MTB0,MTB1,MTB2;    
UNSIGNED INT16  MA_HANG, MQC_LED0, MQC_LED1, MQC_LED2;
UNSIGNED INT32  TT_QC=1; 

UNSIGNED INT8 DOI_1_BIT_1_SANG_THUTU(UNSIGNED INT8 BX)
{   
   UNSIGNED INT8 TTCOT=0;
   BX= BX>>1;
   WHILE(BX!=0)
   {
      TTCOT++;
      BX= BX>>1;
   }   
   RETURN(TTCOT);
}

VOID LAY_MA_KY_TU(UNSIGNED INT8 SLKT_X)
{   
   UNSIGNED INT8  KYTU,I,N,J;
   N=0;
   FOR (I=0; I<SLKT_X; I++)
   {
      KYTU = CHUOI_HIENTHI[I];
      IF ((KYTU>=0X41)&&(KYTU<=0X5A))        KYTU = KYTU - 0X41;
      ELSE IF ((KYTU>=0X30)&&(KYTU<=0X39))   KYTU = (KYTU - 0X30) + 26;      
      FOR(J=0;J<6 ;J++,N++)  
      DL_HIENTHI[N]=HIEU_CHINH_4BIT_CAO(MATRAN_KYTU[KYTU][J]);
   }
}

VOID LAY_MA_QUET_24_COT_XANH()
{   
   MTB0 = TT_QC;
   MTB1 = TT_QC>>8;
   MTB2 = TT_QC>>16;
   IF (MTB0!=0)  
   {  
      MTB0=DOI_1_BIT_1_SANG_THUTU(MTB0);
      MQC_LED0 = MA_QUET_COT_XANH[MTB0];
      MQC_LED1 = 0;
      MQC_LED2 = 0;
   }
   ELSE IF (MTB1!=0)  
   {        
      MTB1=DOI_1_BIT_1_SANG_THUTU(MTB1);
      MQC_LED0 = 0;
      MQC_LED1 = MA_QUET_COT_XANH[MTB1];
      MQC_LED2 = 0;
   }                 
   ELSE IF (MTB2!=0)  
   {        
      MTB2=DOI_1_BIT_1_SANG_THUTU(MTB2);
      MQC_LED0 = 0;
      MQC_LED1 = 0;
      MQC_LED2 = MA_QUET_COT_XANH[MTB2];
   }   
}

VOID LAY_MA_QUET_24_COT_DO()
{   
   MTB0 = TT_QC;
   MTB1 = TT_QC>>8;
   MTB2 = TT_QC>>16;
   IF (MTB0!=0)  
   {  
      MTB0=DOI_1_BIT_1_SANG_THUTU(MTB0);
      MQC_LED0 = MA_QUET_COT_DO[MTB0];
      MQC_LED1 = 0;
      MQC_LED2 = 0;
   }
   ELSE IF (MTB1!=0)  
   {        
      MTB1=DOI_1_BIT_1_SANG_THUTU(MTB1);
      MQC_LED0 = 0;
      MQC_LED1 = MA_QUET_COT_DO[MTB1];
      MQC_LED2 = 0;
   }                 
   ELSE IF (MTB2!=0)  
   {        
      MTB2=DOI_1_BIT_1_SANG_THUTU(MTB2);
      MQC_LED0 = 0;      
      MQC_LED1 = 0;
      MQC_LED2 = MA_QUET_COT_DO[MTB2];
   }   
}

VOID LAY_MA_QUET_24_COT_CAM()
{   
   MTB0 = TT_QC;
   MTB1 = TT_QC>>8;
   MTB2 = TT_QC>>16;
   IF (MTB0!=0)  
   {  
      MTB0=DOI_1_BIT_1_SANG_THUTU(MTB0);
      MQC_LED0 = MA_QUET_COT_CAM[MTB0];
      MQC_LED1 = 0;
      MQC_LED2 = 0;
   }
   ELSE IF (MTB1!=0)  
   {        
      MTB1=DOI_1_BIT_1_SANG_THUTU(MTB1);
      MQC_LED0 = 0;
      MQC_LED1 = MA_QUET_COT_CAM[MTB1];
      MQC_LED2 = 0;
   }                 
   ELSE IF (MTB2!=0)  
   {        
      MTB2=DOI_1_BIT_1_SANG_THUTU(MTB2);
      MQC_LED0 = 0;      
      MQC_LED1 = 0;
      MQC_LED2 = MA_QUET_COT_CAM[MTB2];
   }   
}
VOID LAY_SO_LUONG_KY_TU_CHUOI()
{   
   SLKT=0;
   WHILE(CHUOI_HIENTHI[SLKT])
   {
      SLKT++;}
      XUAT_4LED_7DOAN_GIAIMA_XOA_SO0(SLKT);
}

VOID QUET_4KYTU_MAU_XANH(UNSIGNED INT8 SCK, UNSIGNED INT8 VITRI)
{
   UNSIGNED INT8 CK, J;
   FOR (CK=0;CK<SCK;CK++)
   {
      TT_QC = 1;
      FOR(J=VITRI;J<VITRI+24;J++)
      {
         LAY_MA_QUET_24_COT_XANH();
         MA_HANG = DL_HIENTHI[J];
         XUAT_MATRANLED(MA_HANG,MQC_LED2,MQC_LED1,MQC_LED0);
         DELAY_US(TG_DELAY);   
         XUAT_MATRANLED(0,0,0,0);
         TT_QC = TT_QC << 1;         
      }
   }
}        
    

VOID QUET_4KYTU_MAU_DO(UNSIGNED INT8 SCK, UNSIGNED INT8 VITRI)
{   
   UNSIGNED INT8 CK, J;
   FOR (CK=0;CK<SCK;CK++)
   {     
         TT_QC = 1;
         FOR(J=VITRI;J<VITRI+24;J++)
         {
            LAY_MA_QUET_24_COT_DO();
            MA_HANG = DL_HIENTHI[J];
            XUAT_MATRANLED(MA_HANG,MQC_LED2,MQC_LED1,MQC_LED0);     
            DELAY_US(TG_DELAY);
            XUAT_MATRANLED(0,0,0,0);
            TT_QC = TT_QC <<1;
         }
   }
}  

VOID QUET_4KYTU_MAU_CAM(UNSIGNED INT8 SCK, UNSIGNED INT8 VITRI)
{   
   UNSIGNED INT8 CK, J;
   FOR (CK=0;CK<SCK;CK++)
   {     
         TT_QC = 1;
         FOR(J=VITRI;J<VITRI+24;J++)
         {
            LAY_MA_QUET_24_COT_CAM();
            MA_HANG = DL_HIENTHI[J];
            XUAT_MATRANLED(MA_HANG,MQC_LED2,MQC_LED1,MQC_LED0);     
            DELAY_US(TG_DELAY);
            XUAT_MATRANLED(0,0,0,0);
            TT_QC = TT_QC <<1;
         }
   }
}  



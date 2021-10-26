#INCLUDE "D:\TTVXL\TV_PICKIT2_SHIFT_1.c"
#INCLUDE "D:\TTVXL\TV_PICKIT2_SHIFT_DS13B07_I2C.C"

UNSIGNED CHAR GIATRI_MOD;
UNSIGNED INT8 BDN;
#INT_TIMER1
VOID NGAT()
{
   SET_TIMER1(3036);
   BDN++;
}
void HIEN_THI_GIA_TRI_MOD ( )
{ 
 LCD_COMMAND(0x8A);
 LCD_DATA(GIATRI_MOD+0X30);
} 
VOID PHIM_MOD()
{
       IF (! INPUT(MOD))
       { 
      
             DELAY_MS(20);
             {
             IF (! INPUT(MOD))
             {
             IF(GIATRI_MOD<6)  GIATRI_MOD++;
             ELSE GIATRI_MOD=0;
             HIEN_THI_GIA_TRI_MOD ( );
             DO{}
             WHILE(! INPUT(MOD));
              }
               }
         }
}
UNSIGNED INT8 HIEU_CHINH_SO_BCD_TANG(UNSIGNED INT8 X )
{
 UNSIGNED INT8 Y;
 Y = X;
 X = X & 0X0F;
 IF (X==0X0A)  Y = Y + 6; 
 RETURN(Y); 
}
UNSIGNED INT8 HIEU_CHINH_SO_BCD_GIAM(UNSIGNED INT8 X )
{
 UNSIGNED INT8 Y;
 Y = X;
 X = X & 0X0F;
 IF (X==0X0F)  Y = Y - 6; 
 RETURN(Y); 
}
VOID LUU_GIAI_MA_HIEN_THI_SAU_KHI_CHINH()
{
 NAP_THOI_GIAN_HTAI_VAO_DS13B07();
 HIEN_THI_THOI_GIAN_DS13B07 ( );
}
VOID PHIM_UP()
{
 IF (! INPUT(UP))
 {
          DELAY_MS(20);
          IF (! INPUT(UP))
          {
          SWITCH (GIATRI_MOD)
          {
          CASE 1:  IF (GIAY_DS13==0X59) GIAY_DS13=0;
          ELSE
           {    
                  GIAY_DS13++;
                GIAY_DS13=HIEU_CHINH_SO_BCD_TANG(GIAY_DS13);
          }
          LUU_GIAI_MA_HIEN_THI_SAU_KHI_CHINH();
          BREAK;
          CASE 2:  IF (PHUT_DS13==0X59) PHUT_DS13=0;
          ELSE
          {  PHUT_DS13++;
          PHUT_DS13=HIEU_CHINH_SO_BCD_TANG(PHUT_DS13);}
          LUU_GIAI_MA_HIEN_THI_SAU_KHI_CHINH();
           BREAK;
          CASE 3:  IF (GIO_DS13==0X23) GIO_DS13=0;
          ELSE
          {  GIO_DS13++;
          GIO_DS13=HIEU_CHINH_SO_BCD_TANG(GIO_DS13);}
          LUU_GIAI_MA_HIEN_THI_SAU_KHI_CHINH();
          BREAK;
         
          CASE 4:  IF (NGAY_DS13==0X31) NGAY_DS13=1;
          ELSE
           {  NGAY_DS13++;
          NGAY_DS13=HIEU_CHINH_SO_BCD_TANG(NGAY_DS13);}
          LUU_GIAI_MA_HIEN_THI_SAU_KHI_CHINH(); 
          BREAK;
          CASE 5:  IF (THANG_DS13==0X12) THANG_DS13=1;
          ELSE
          {  THANG_DS13++;
          THANG_DS13=HIEU_CHINH_SO_BCD_TANG(THANG_DS13);}
          LUU_GIAI_MA_HIEN_THI_SAU_KHI_CHINH(); 
          BREAK;
          CASE 6:  IF (NAM_DS13==0X99) NAM_DS13=0;
          ELSE
          {  NAM_DS13++;
          NAM_DS13=HIEU_CHINH_SO_BCD_TANG(NAM_DS13);}
          LUU_GIAI_MA_HIEN_THI_SAU_KHI_CHINH(); 
          BREAK; 
          DEFAULT: BREAK;
          } 
          DO{}
          WHILE(! INPUT(UP));
          }
   }
} 
VOID PHIM_DW()
{
 IF (! INPUT(DW))
 { 
 DELAY_MS(20);
 IF (! INPUT(DW))
 {
 SWITCH (GIATRI_MOD)
 {
 CASE 1:  IF (GIAY_DS13==0) GIAY_DS13=0X59;
 ELSE
 {  GIAY_DS13--;
 GIAY_DS13=HIEU_CHINH_SO_BCD_GIAM(GIAY_DS13);}
 LUU_GIAI_MA_HIEN_THI_SAU_KHI_CHINH();
 BREAK;
 CASE 2:  IF (PHUT_DS13==0) PHUT_DS13=0X59;
 ELSE
 {  PHUT_DS13--;
 PHUT_DS13=HIEU_CHINH_SO_BCD_GIAM(PHUT_DS13);}
 LUU_GIAI_MA_HIEN_THI_SAU_KHI_CHINH();
 BREAK; 
 CASE 3:  IF (GIO_DS13==0) GIO_DS13=0X23;
 ELSE
 {  GIO_DS13--;
 GIO_DS13=HIEU_CHINH_SO_BCD_GIAM(GIO_DS13);}
 LUU_GIAI_MA_HIEN_THI_SAU_KHI_CHINH();
  BREAK; 
 CASE 4:  IF (NGAY_DS13==0) NGAY_DS13=0X31;
 ELSE
 {    NGAY_DS13--;
      NGAY_DS13=HIEU_CHINH_SO_BCD_GIAM(NGAY_DS13);}
      LUU_GIAI_MA_HIEN_THI_SAU_KHI_CHINH();
      BREAK; 
 CASE 5:  IF (THANG_DS13==1) THANG_DS13=0X12;

         ELSE
       {  THANG_DS13--;
        THANG_DS13=HIEU_CHINH_SO_BCD_GIAM(THANG_DS13);
        }
       LUU_GIAI_MA_HIEN_THI_SAU_KHI_CHINH();
       BREAK; 
 CASE 6:  IF (NAM_DS13==0) NAM_DS13=0X99;
 ELSE
 {  NAM_DS13--;
 NAM_DS13=HIEU_CHINH_SO_BCD_GIAM(NAM_DS13);}
 LUU_GIAI_MA_HIEN_THI_SAU_KHI_CHINH();
 BREAK; 
  DEFAULT: BREAK;
 }
 DO{}
 WHILE(! INPUT(DW));
 }
 }
}
VOID NHAP_NHAY_CON_TRO()
{ 
    SWITCH (GIATRI_MOD)
    {
       CASE 1:  LCD_COMMAND(0X91); 
                LCD_DATA("   "); 
                             
                BREAK;
       CASE 2:  LCD_COMMAND(0X8E); 
                LCD_DATA("   "); 
                             
                BREAK;
       CASE 3:   LCD_COMMAND(0X8B); 
                LCD_DATA("   "); 
                            
                BREAK;
       CASE 4:   LCD_COMMAND(0XCC); 
                LCD_DATA("   "); 
                             
                BREAK;
       CASE 5:   LCD_COMMAND(0XCE); 
                LCD_DATA("   "); 
                          
                BREAK;
       CASE 6:   LCD_COMMAND(0XD1); 
                LCD_DATA("   "); 
                           
                BREAK;
       DEFAULT:  BREAK; 
    }
} 
VOID KT_PHIM()
{
   PHIM_MOD();
   PHIM_UP();
   PHIM_DW();
}
VOID MAIN()
   {  SET_UP_PORT_IC_CHOT(); 
    SETUP_LCD(); 
    
    LCD_COMMAND(LCD_ADDR_LINE1); 
    LCD_DATA("CLOCK:"); 
    
    DOC_THOI_GIAN_TU_REALTIME(); 
    IF (MA_DS13!=MA_DS)
    {
       THIET_LAP_THOI_GIAN_HIEN_TAI();
       NAP_THOI_GIAN_HTAI_VAO_DS13B07(); 
    }
    
    GIATRI_MOD=0;
    HIEN_THI_GIA_TRI_MOD ( );
    DOC_THOI_GIAN_TU_REALTIME();
    GIAYTAM=GIAY_DS13;
     SETUP_TIMER_1(T1_INTERNAL|T1_DIV_BY_8);
   SET_TIMER1(3036);
   ENABLE_INTERRUPTS(GLOBAL);
   ENABLE_INTERRUPTS(INT_TIMER1);
 WHILE(TRUE)
   { 
     IF(BDN<10)
      {
         DOC_THOI_GIAN_TU_REALTIME(); 
         KT_PHIM();
         IF((GIATRI_MOD!=0)&&(BDN<5)) NHAP_NHAY_CON_TRO();
         ELSE   
           {           
             
                HIEN_THI_GIA_TRI_MOD ( );
                HIEN_THI_THOI_GIAN_DS13B07 ( );
           } 
      }
      ELSE
         {
            BDN=BDN-10;
            DOC_THOI_GIAN_TU_REALTIME(); 
            KT_PHIM();
            HIEN_THI_GIA_TRI_MOD ( );
            HIEN_THI_THOI_GIAN_DS13B07 ( );
         }
   }
}


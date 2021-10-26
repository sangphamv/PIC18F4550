#INCLUDE <TV_PICKIT2_SHIFT_LCD.c>
#define   GIAY_HTAI      0X55
#define   PHUT_HTAI      0X33
#define   GIO_HTAI       0X08
#define   THU_HTAI       8
#define   NGAY_HTAI      0X16
#define   THANG_HTAI     0X06
#define   NAM_HTAI       0X13      
#define   MA_DS          0X98

#define  ADDR_WR_13B07   0xD0
#define  ADDR_RD_13B07   0xD1
#define  ADDR_MEM        0x00

UNSIGNED  CHAR    NAM_DS13,THANG_DS13,NGAY_DS13,THU_DS13,GIO_DS13,
                  PHUT_DS13,GIAY_DS13,MA_DS13,CONTROL_DS13,GIAYTAM;
                               
void THIET_LAP_THOI_GIAN_HIEN_TAI()
{     GIAY_DS13   =   GIAY_HTAI;       PHUT_DS13  =    PHUT_HTAI;   
      GIO_DS13    =   GIO_HTAI;        THU_DS13   =    THU_HTAI;
      NGAY_DS13   =   NGAY_HTAI;       THANG_DS13 =    THANG_HTAI;   
      NAM_DS13    =   NAM_HTAI;   
      CONTROL_DS13 = 0X90;             MA_DS13      =   MA_DS;
}
 
void NAP_THOI_GIAN_HTAI_VAO_DS13B07()
{     I2C_START();         
      I2C_WRITE(ADDR_WR_13B07);    
      I2C_WRITE(0X00);
      I2C_WRITE(GIAY_DS13);        I2C_WRITE(PHUT_DS13);      
      I2C_WRITE(GIO_DS13);         I2C_WRITE(THU_DS13);      
      I2C_WRITE(NGAY_DS13);        I2C_WRITE(THANG_DS13);            
      I2C_WRITE(NAM_DS13);         I2C_WRITE(CONTROL_DS13);   
      I2C_WRITE(MA_DS13);
      I2C_STOP();
}
    
void DOC_THOI_GIAN_TU_REALTIME()
{   
      I2C_START();
      I2C_WRITE(ADDR_WR_13B07);
      I2C_WRITE(ADDR_MEM);                     
      I2C_START();                
                
      I2C_WRITE(ADDR_RD_13B07);
      GIAY_DS13      =  I2C_READ();              
      PHUT_DS13      =  I2C_READ();             
      GIO_DS13       =  I2C_READ();             
      THU_DS13       =  I2C_READ(); 
      NGAY_DS13      =  I2C_READ(); 
      THANG_DS13     =  I2C_READ(); 
      NAM_DS13       =  I2C_READ(); 
      CONTROL_DS13   =  I2C_READ();          
      MA_DS13        =  I2C_READ(0);     //NOT ACK
      I2C_STOP();
}    

   
void DOC_GIAY_TU_REALTIME()
{   
      I2C_START();
      I2C_WRITE(ADDR_WR_13B07);
      I2C_WRITE(ADDR_MEM);                     
      I2C_START();                
                
      I2C_WRITE(ADDR_RD_13B07);
      GIAY_DS13      =  I2C_READ(0);              
      I2C_STOP();
}  
        
 
void HIEN_THI_THOI_GIAN_DS13B07 ( )
{     LCD_COMMAND (0x8C);   
      LCD_DATA(GIO_DS13/16  +0X30);    LCD_DATA(GIO_DS13%16  +0X30);
      LCD_DATA(' ');
      LCD_DATA(PHUT_DS13/16 +0X30);    LCD_DATA(PHUT_DS13%16 +0X30);
      LCD_DATA(' ');
      LCD_DATA(GIAY_DS13/16 +0X30);    LCD_DATA(GIAY_DS13%16 +0X30);
      LCD_COMMAND (0xCC);  
      LCD_DATA(NGAY_DS13/16 +0X30);    LCD_DATA(NGAY_DS13%16 +0X30);
      LCD_DATA(' ');
      LCD_DATA(THANG_DS13/16 +0X30);   LCD_DATA(THANG_DS13%16 +0X30);
      LCD_DATA(' ');
      LCD_DATA(NAM_DS13/16 +0X30);     LCD_DATA(NAM_DS13%16 +0X30); 
}



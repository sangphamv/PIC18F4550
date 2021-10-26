#INCLUDE <TV_PICKIT2_SHIFT_1.c>
#INCLUDE <TV_PICKIT2_SHIFT_DS1307_I2C.C>
UNSIGNED INT8 I;
INT1 K=0;
VOID PHIM_MOD()
{
       IF (! INPUT(MOD))
       { 
         DELAY_MS(20); 
         IF (! INPUT(MOD))
          { 
          LCD_COMMAND(0X01);
            K=~K;
            WHILE(! INPUT(MOD));
           }              
        }
}
VOID LCD_HIENTHI_SO_Z_TOADO_XY(SIGNED INT8 LCD_SO,SIGNED INT8 X1, SIGNED Y1)
   {
      LCD_GOTO_XY(X1,Y1);
      FOR (I=0;I<6;I++)
         {
            IF(I==3) LCD_GOTO_XY(X1+1,Y1);
            LCD_DATA(LCD_SO_X[LCD_SO][I]);
         }
   }
VOID HIENTHI_TO()
{
   LCD_HIENTHI_SO_Z_TOADO_XY(GIO_DS13/16,0,0);
   LCD_HIENTHI_SO_Z_TOADO_XY(GIO_DS13%16,0,3);
    
   LCD_HIENTHI_SO_Z_TOADO_XY(PHUT_DS13/16,0,7);
   LCD_HIENTHI_SO_Z_TOADO_XY(PHUT_DS13%16,0,10);
      
   LCD_HIENTHI_SO_Z_TOADO_XY(GIAY_DS13/16,0,14);
   LCD_HIENTHI_SO_Z_TOADO_XY(GIAY_DS13%16,0,17);
}

VOID HIENTHI_NHO()
{
      LCD_COMMAND (0x85);   
      LCD_DATA(GIO_DS13/16  +0X30);    LCD_DATA(GIO_DS13%16  +0X30);
      LCD_DATA(' ');
      LCD_DATA(PHUT_DS13/16 +0X30);    LCD_DATA(PHUT_DS13%16 +0X30);
      LCD_DATA(' ');
      LCD_DATA(GIAY_DS13/16 +0X30);    LCD_DATA(GIAY_DS13%16 +0X30);
      LCD_COMMAND (0xC5);  
      LCD_DATA(NGAY_DS13/16 +0X30);    LCD_DATA(NGAY_DS13%16 +0X30);
      LCD_DATA(' ');
      LCD_DATA(THANG_DS13/16 +0X30);   LCD_DATA(THANG_DS13%16 +0X30);
      LCD_DATA(' ');
      LCD_DATA(NAM_DS13/16 +0X30);     LCD_DATA(NAM_DS13%16 +0X30); 
}
VOID MAIN()
{
    SET_UP_PORT_IC_CHOT();
    SETUP_LCD();
    
    DOC_THOI_GIAN_TU_REALTIME();
    IF(MA_DS13!=MA_DS)
        {
            THIET_LAP_THOI_GIAN_HIEN_TAI();
            NAP_THOI_GIAN_HTAI_VAO_DS13B07();
        }
    DOC_THOI_GIAN_TU_REALTIME();
    GIAYTAM=GIAY_DS13;
    WHILE(TRUE)
    {
      DOC_THOI_GIAN_TU_REALTIME();
      PHIM_MOD();
      IF(GIAYTAM != GIAY_DS13)
        {   
            GIAYTAM = GIAY_DS13;
           IF(K==0) HIENTHI_TO();
           ELSE HIENTHI_NHO();
        }
    
    }
}


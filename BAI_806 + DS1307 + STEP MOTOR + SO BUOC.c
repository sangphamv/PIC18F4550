#INCLUDE <TV_PICKIT2_SHIFT_1.C>
#INCLUDE <TV_PICKIT2_SHIFT_DS1307_I2C.C>
#INCLUDE <TV_PICKIT2_SHIFT_DS18B20.c> 
#INCLUDE <TV_PICKIT2_SHIFT_STEP_MOTOR.C>

//Muon sua ngay bao nhieu thi vo thu vien sua lai htai
UNSIGNED CHAR GIATRI_MOD;
UNSIGNED INT8 TGIAN[20];
UNSIGNED INT16 BDN,GIO=0,PHUT=0,GIAY=0;
INT1 TT_DC, TT_SS;
UNSIGNED INT8 SO_BUOC;

#INT_TIMER1
VOID INTERRUPT_TIMER1()
{
   BDN++;
   SET_TIMER1(3036);
}
VOID GIAI_MA()
{
   TGIAN[0]=GIAY_DS13%16 +0X30;
   TGIAN[1]=GIAY_DS13/16 +0X30;
   
   TGIAN[2]=PHUT_DS13%16 +0X30;
   TGIAN[3]=PHUT_DS13/16 +0X30;
   
   TGIAN[4]=GIO_DS13%16 +0X30;
   TGIAN[5]=GIO_DS13/16 +0X30;
   
   TGIAN[6]=NGAY_DS13%16 +0X30;
   TGIAN[7]=NGAY_DS13/16 +0X30;
   
   TGIAN[8]=THANG_DS13%16 +0X30;
   TGIAN[9]=THANG_DS13/16 +0X30;
   
   TGIAN[10]=NAM_DS13%16 +0X30;
   TGIAN[11]=NAM_DS13/16 +0X30;
   
   IF(THU_DS13==1)
   {
      TGIAN[12]="N";
      TGIAN[13]="C";
   }
   ELSE
   {
      TGIAN[12]=THU_DS13 +0X30;
      TGIAN[13]=' ';
   }
   
   TGIAN[14]=GIAY%16 +0X30;
   TGIAN[15]=GIAY/16 +0X30;
   
   TGIAN[16]=PHUT%16 +0X30;
   TGIAN[17]=PHUT/16 +0X30;
   
   TGIAN[18]=GIO%16 +0X30;
   TGIAN[19]=GIO/16 +0X30;
   
}
VOID HIEN_THI()
{     LCD_GOTO_XY(0,0);
      LCD_DATA("DONG HO:");

      LCD_GOTO_XY(0,12);   
      LCD_DATA( TGIAN[5]);    LCD_DATA( TGIAN[4]);
      LCD_DATA(' ');
      LCD_DATA( TGIAN[3]);    LCD_DATA( TGIAN[2]);
      LCD_DATA(' ');
      LCD_DATA( TGIAN[1]);    LCD_DATA( TGIAN[0]);
      
      LCD_GOTO_XY(1,0);
      LCD_DATA("THU:  ");
      LCD_DATA(TGIAN[13]);    LCD_DATA(TGIAN[12]);
      
      
      LCD_GOTO_XY(1,12);
      LCD_DATA( TGIAN[7]);    LCD_DATA( TGIAN[6]);
      LCD_DATA(' ');
      LCD_DATA( TGIAN[9]);   LCD_DATA( TGIAN[8]);
      LCD_DATA(' ');
      LCD_DATA( TGIAN[11]);     LCD_DATA( TGIAN[10]); 
      
      LCD_GOTO_XY(2,0);
      LCD_DATA("GIA TRI MOD:");
      LCD_GOTO_XY(2,14);
      LCD_DATA(GIATRI_MOD + 0X30);
      
      LCD_GOTO_XY(3,0);
      LCD_DATA("HEN GIO:");
      LCD_GOTO_XY(3,12);
      LCD_DATA( TGIAN[19]);    LCD_DATA( TGIAN[18]);
      LCD_DATA(' ');
      LCD_DATA( TGIAN[17]);   LCD_DATA( TGIAN[16]);
      LCD_DATA(' ');
      LCD_DATA( TGIAN[15]);     LCD_DATA( TGIAN[14]); 
//!      LCD_GOTO_XY(3,0);
//!      LCD_DATA("GIA TRI BDN:");
//!      LCD_GOTO_XY(3,14);
//!      LCD_DATA(BDN + 0X30);
   
}
VOID TAT_SO()
{
  SWITCH (GIATRI_MOD)
  {
   CASE 1: TGIAN[0]=' ';  TGIAN[1]=' '; BREAK;
   CASE 2: TGIAN[2]=' ';  TGIAN[3]=' '; BREAK;
   CASE 3: TGIAN[4]=' ';  TGIAN[5]=' '; BREAK;
   CASE 4: TGIAN[6]=' ';  TGIAN[7]=' '; BREAK;
   CASE 5: TGIAN[8]=' ';  TGIAN[9]=' '; BREAK;
   CASE 6: TGIAN[10]=' '; TGIAN[11]=' '; BREAK;
   CASE 7: TGIAN[12]=' '; TGIAN[13]=' '; BREAK;
   CASE 8: TGIAN[14]=' '; TGIAN[15]=' '; BREAK;
   CASE 9: TGIAN[16]=' '; TGIAN[17]=' '; BREAK;
   CASE 10: TGIAN[18]=' '; TGIAN[19]=' '; BREAK;
   DEFAULT:BREAK;
  }
}

VOID PHIM_MOD()
{
   IF (!INPUT(MOD))
   {
      DELAY_MS(20);
      {
         IF(!INPUT(MOD))
         {
            IF(GIATRI_MOD<10)  GIATRI_MOD++;
            ELSE              GIATRI_MOD=0;
            
            DO{}
            WHILE (!INPUT(MOD));
         }
      }
   }
}
UNSIGNED INT8 HIEU_CHINH_SO_BCD_TANG(UNSIGNED INT8 X)
{
   UNSIGNED INT8 Y;
   Y = X;
   X = X & 0X0F;
   IF (X==0X0A)  Y = Y + 6;
   RETURN (Y);
}

UNSIGNED INT8 HIEU_CHINH_SO_BCD_GIAM(UNSIGNED INT8 X)
{
   UNSIGNED INT8 Y;
   Y = X;
   X = X & 0X0F;
   IF (X==0X0F)  Y = Y - 6;
   RETURN (Y);
}

VOID LUU_GIAI_MA_HIEN_THI_SAU_KHI_CHINH()
{
   NAP_THOI_GIAN_HTAI_VAO_DS13B07();
   HIEN_THI_THOI_GIAN_DS13B07();
}

VOID PHIM_UP()
{
   IF(!INPUT(UP))
   {
      DELAY_MS(20);
      IF(!INPUT(UP))
      {
         SWITCH (GIATRI_MOD)
         {
            CASE 1: IF (GIAY_DS13==0X59)  GIAY_DS13=0;
                    ELSE 
                    {
                        GIAY_DS13++;
                        GIAY_DS13=HIEU_CHINH_SO_BCD_TANG(GIAY_DS13);
                    }
                    LUU_GIAI_MA_HIEN_THI_SAU_KHI_CHINH();
                    BREAK;
            
            CASE 2: IF (PHUT_DS13==0X59)  PHUT_DS13=0;
                    ELSE 
                    {
                    PHUT_DS13++;
                    PHUT_DS13=HIEU_CHINH_SO_BCD_TANG(PHUT_DS13);
                    }
                    LUU_GIAI_MA_HIEN_THI_SAU_KHI_CHINH();
                    BREAK;
                    
            CASE 3: IF (GIO_DS13==0X23)  GIO_DS13=0;
                    ELSE 
                    {
                    GIO_DS13++;
                    GIO_DS13=HIEU_CHINH_SO_BCD_TANG(GIO_DS13);
                    }
                    LUU_GIAI_MA_HIEN_THI_SAU_KHI_CHINH();
                    BREAK;
                    
            CASE 4: IF (NGAY_DS13==0X31)  NGAY_DS13=0;
                    ELSE 
                    {
                    NGAY_DS13++;
                    NGAY_DS13=HIEU_CHINH_SO_BCD_TANG(NGAY_DS13);
                    }
                    LUU_GIAI_MA_HIEN_THI_SAU_KHI_CHINH();
                    BREAK;      
                    
            CASE 5: IF (THANG_DS13==0X12)  THANG_DS13=0;
                    ELSE 
                    {
                    THANG_DS13++;
                    THANG_DS13=HIEU_CHINH_SO_BCD_TANG(THANG_DS13);
                    }
                    LUU_GIAI_MA_HIEN_THI_SAU_KHI_CHINH();
                    BREAK;
            
            CASE 6: IF (NAM_DS13==0X99)  NAM_DS13=0;
                    ELSE 
                    {
                    NAM_DS13++;
                    NAM_DS13=HIEU_CHINH_SO_BCD_TANG(NAM_DS13);
                    }
                    LUU_GIAI_MA_HIEN_THI_SAU_KHI_CHINH();
                    BREAK;
            CASE 7: IF(THU_DS13==7) THU_DS13=1; //Luu y cho so sanh nay khi nhan thi phim dang o so 7, neu so sanh voi 8 thi sai
                    ELSE
                    {
                    THU_DS13++;
                    THU_DS13=HIEU_CHINH_SO_BCD_TANG(THU_DS13);
                    }
                    LUU_GIAI_MA_HIEN_THI_SAU_KHI_CHINH();
                    BREAK;
            CASE 8: IF (GIAY==0X59)  GIAY=0X00;
                    ELSE 
                    {
                        GIAY++;
                        GIAY=HIEU_CHINH_SO_BCD_TANG(GIAY);
                    }
                    LUU_GIAI_MA_HIEN_THI_SAU_KHI_CHINH();
                    BREAK;
            CASE 9: IF(PHUT==0X59) PHUT=0X00; //Luu y cho so sanh nay khi nhan thi phim dang o so 7, neu so sanh voi 8 thi sai
                    ELSE
                    {
                    PHUT++;
                    PHUT=HIEU_CHINH_SO_BCD_TANG(PHUT);
                    }
                    LUU_GIAI_MA_HIEN_THI_SAU_KHI_CHINH();
                    BREAK;
            CASE 10: IF(GIO==0X23) GIO=0X00; //Luu y cho so sanh nay khi nhan thi phim dang o so 7, neu so sanh voi 8 thi sai
                    ELSE
                    {
                    GIO++;
                    GIO=HIEU_CHINH_SO_BCD_TANG(GIO);
                    }
                    LUU_GIAI_MA_HIEN_THI_SAU_KHI_CHINH();
                    BREAK;            
            DEFAULT:BREAK;
         }
         DO{}
         WHILE(!INPUT(UP));
      }
   }
}

VOID PHIM_DW()
{
   IF(!INPUT(DW))
   {
      DELAY_MS(20);
      IF(!INPUT(DW))
      {
         SWITCH (GIATRI_MOD)
         {
            CASE 1: IF (GIAY_DS13==0)  GIAY_DS13=0X59;
                    ELSE 
                    {
                        GIAY_DS13--;
                        GIAY_DS13=HIEU_CHINH_SO_BCD_GIAM(GIAY_DS13);
                    }
                    LUU_GIAI_MA_HIEN_THI_SAU_KHI_CHINH();
                    BREAK;
            
            CASE 2: IF (PHUT_DS13==0)  PHUT_DS13=0X59;
                    ELSE 
                    {
                    PHUT_DS13--;
                    PHUT_DS13=HIEU_CHINH_SO_BCD_GIAM(PHUT_DS13);
                    }
                    LUU_GIAI_MA_HIEN_THI_SAU_KHI_CHINH();
                    BREAK;
                    
            CASE 3: IF (GIO_DS13==0)  GIO_DS13=0X23;
                    ELSE 
                    {
                    GIO_DS13--;
                    GIO_DS13=HIEU_CHINH_SO_BCD_GIAM(GIO_DS13);
                    }
                    LUU_GIAI_MA_HIEN_THI_SAU_KHI_CHINH();
                    BREAK;
                    
            CASE 4: IF (NGAY_DS13==0)  NGAY_DS13=0X31;
                    ELSE 
                    {
                    NGAY_DS13--;
                    NGAY_DS13=HIEU_CHINH_SO_BCD_GIAM(NGAY_DS13);
                    }
                    LUU_GIAI_MA_HIEN_THI_SAU_KHI_CHINH();
                    BREAK;      
                    
            CASE 5: IF (THANG_DS13==0)  THANG_DS13=0X12;
                    ELSE 
                    {
                    THANG_DS13--;
                    THANG_DS13=HIEU_CHINH_SO_BCD_GIAM(THANG_DS13);
                    }
                    LUU_GIAI_MA_HIEN_THI_SAU_KHI_CHINH();
                    BREAK;
            
            CASE 6: IF (NAM_DS13==0)  NAM_DS13=0X99;
                    ELSE 
                    {
                    NAM_DS13--;
                    NAM_DS13=HIEU_CHINH_SO_BCD_GIAM(NAM_DS13);
                    }
                    LUU_GIAI_MA_HIEN_THI_SAU_KHI_CHINH();
                    BREAK;
            CASE 7: IF(THU_DS13==1) THU_DS13=7;
                    ELSE
                    {
                    THU_DS13--;
                    THU_DS13=HIEU_CHINH_SO_BCD_TANG(THU_DS13);
                    }
                    LUU_GIAI_MA_HIEN_THI_SAU_KHI_CHINH();
                    BREAK; 
            CASE 8: IF (GIAY==0X00)  GIAY=0X59;
                    ELSE 
                    {
                        GIAY--;
                        GIAY=HIEU_CHINH_SO_BCD_GIAM(GIAY);
                    }
                    LUU_GIAI_MA_HIEN_THI_SAU_KHI_CHINH();
                    BREAK;
            CASE 9: IF(PHUT==0X00) PHUT=0X59; //Luu y cho so sanh nay khi nhan thi phim dang o so 7, neu so sanh voi 8 thi sai
                    ELSE
                    {
                    PHUT--;
                    PHUT=HIEU_CHINH_SO_BCD_GIAM(PHUT);
                    }
                    LUU_GIAI_MA_HIEN_THI_SAU_KHI_CHINH();
                    BREAK;
            CASE 10: IF(GIO==0X00) GIO=0X23; //Luu y cho so sanh nay khi nhan thi phim dang o so 7, neu so sanh voi 8 thi sai
                    ELSE
                    {
                    GIO--;
                    GIO=HIEU_CHINH_SO_BCD_GIAM(GIO);
                    }
                    LUU_GIAI_MA_HIEN_THI_SAU_KHI_CHINH();
                    BREAK; 
            DEFAULT:BREAK;
         }
         DO{}
         WHILE(!INPUT(DW));
      }
   }
}
VOID SO_SANH()
{
   IF((GIO==GIO_DS13)&&(PHUT==PHUT_DS13))
   {
      IF(GIAY_DS13<0X10)
      {
         XUAT_32LED_DON_4BYTE(0XFF,0X00,0X00,0XFF);
      }
      ELSE
      {
         XUAT_32LED_DON_4BYTE(0XFF,0XFF,0XFF,0XFF);
      }
   }
}


VOID KT_SS()
{
   IF(!INPUT(BT2))
   {
      DELAY_MS(20);
      IF(!INPUT(BT2))
      {
         TT_SS = ~TT_SS;
         
         WHILE(!INPUT(BT2));
      }
   }
}

VOID MAIN()
{
   SET_UP_PORT_IC_CHOT();
   SETUP_LCD();
   
   SETUP_TIMER_1(T1_INTERNAL | T1_DIV_BY_8);
   SET_TIMER1(3036);
   ENABLE_INTERRUPTS(GLOBAL);
   ENABLE_INTERRUPTS(INT_TIMER1);
   BDN=0;
   
   
   LCD_COMMAND(LCD_ADDR_LINE1);
   DOC_THOI_GIAN_TU_REALTIME();
   IF (MA_DS13!=MA_DS)
   {
      THIET_LAP_THOI_GIAN_HIEN_TAI();
      NAP_THOI_GIAN_HTAI_VAO_DS13B07();
   }
   GIATRI_MOD=0;
   DOC_THOI_GIAN_TU_REALTIME();
   GIAYTAM=GIAY_DS13;
   
   //DS18B20
   KHOI_TAO_DS18B20();
   
   //STEPPER MOTOR
   STEPMOTOR_DELAY=100;
   STEPMOTOR_ONOFF=1; //DE KHOI CANH BAO
   SO_BUOC = 0;
   TT_DC=1;
   TT_SS=1;
   
   WHILE(TRUE)
   {
      DOC_THOI_GIAN_TU_REALTIME();
      SO_SANH();
      IF(GIAYTAM!=GIAY_DS13)
      {
         GIAYTAM=GIAY_DS13;    
         HIEN_THI_THOI_GIAN_DS13B07();
      }
      GIAI_MA();
      IF(GIATRI_MOD!=0)
      {
         IF(BDN<10)
         {
            IF(BDN<5)
            {
               TAT_SO();
            }
         }
         ELSE
         {
            BDN=BDN-10;
         }
      }
      HIEN_THI();
      PHIM_MOD();
      PHIM_UP(); 
      PHIM_DW();
      
      //DS18B20
      IF(TOUCH_PRESENT()) { DOC_GIATRI_DS18B20();}
//!      XUAT_4LED_7DOAN_GIAIMA_XOA_SO0((DS18A>>4)&0xff);
      
      //STEPPER MOTOR
      IF(SO_BUOC == 50) 
      {
         TT_DC = 0;
      }
      IF(SO_BUOC == 0) 
      {
         TT_DC = 1;
      }
      
      KT_SS();
      IF(TT_SS == 1)
      {
         IF(TT_DC == 1)
         {
            STEP_MOTOR_QUAY_THUAN_FS();
            DELAY_MS(STEPMOTOR_DELAY);
            SO_BUOC++;
         }
         ELSE
         {
            STEP_MOTOR_QUAY_NGHICH_FS();
            DELAY_MS(STEPMOTOR_DELAY);
            SO_BUOC--;
         }
         
         IF(SO_BUOC == 51) 
         {
            TT_DC = 0;
         }
         IF(SO_BUOC == 0) 
         {
            TT_DC = 1;
            SO_BUOC = 0;
         }
      }
      
      XUAT_4LED_7DOAN_4SO(MA7DOAN[SO_BUOC/10],MA7DOAN[SO_BUOC%10],
                          MA7DOAN[((DS18A>>4)&0xff)/10],MA7DOAN[((DS18A>>4)&0xff)%10]);
   }
}


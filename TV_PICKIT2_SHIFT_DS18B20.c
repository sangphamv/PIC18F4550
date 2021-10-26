#DEFINE     TOUCH_PIN PIN_A5
#INCLUDE    <TOUCH.c>
#DEFINE       SKIP_ROM              0xCC
#DEFINE       CONVERT_T             0x44
#DEFINE       READ_SCRATCHPAD       0xBE
#DEFINE       WRITE_SCRATCHPAD      0x4E
#DEFINE       COPY_SCRATCHPAD       0x48    
UNSIGNED INT8     DS18AL, DS18AH, DS18A_TAM;
UNSIGNED INT16    DS18A;
VOID  KHOI_TAO_DS18B20()
{                         
      TOUCH_PRESENT();
      TOUCH_WRITE_BYTE(SKIP_ROM);      
      TOUCH_WRITE_BYTE(WRITE_SCRATCHPAD);    
      TOUCH_WRITE_BYTE(0x0);       // ghi 2 byte rong
      TOUCH_WRITE_BYTE(0x0);       //
      TOUCH_WRITE_BYTE(0x1F);      //Cau hinh do phan giai 9 bit

      TOUCH_PRESENT();
      TOUCH_WRITE_BYTE(SKIP_ROM);      
      TOUCH_WRITE_BYTE(COPY_SCRATCHPAD); 
}
VOID  DOC_GIATRI_DS18B20()
{ 
      TOUCH_WRITE_BYTE(SKIP_ROM);
      TOUCH_WRITE_BYTE (CONVERT_T);   
      TOUCH_PRESENT();
      TOUCH_WRITE_BYTE(SKIP_ROM);
      TOUCH_WRITE_BYTE(READ_SCRATCHPAD);  
      DS18AL = TOUCH_READ_BYTE();
      DS18AH = TOUCH_READ_BYTE();      
      DS18A   =  MAKE16(DS18AH,DS18AL);        
}
            


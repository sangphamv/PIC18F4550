#define  ADDR_WR_24XXX   0xA0
#define  ADDR_RD_24XXX   0xA1
void RESET_24XXX()
{                
      OUTPUT_HIGH(PIN_B1);     
      I2C_START();         
      I2C_STOP();
}
void KHOI_TAO_GHI_24XXX(UNSIGNED INT16 ADDR)
{          
      I2C_START();   
      I2C_WRITE(ADDR_WR_24XXX);  
      I2C_WRITE(ADDR>>8);         
      I2C_WRITE(ADDR);         
}
    
void KHOI_TAO_DOC_24XXX(UNSIGNED INT16 ADDR)
{   
      I2C_START();
      I2C_WRITE(ADDR_WR_24XXX);  
      I2C_WRITE(ADDR>>8);        
      I2C_WRITE(ADDR);           
      I2C_START();                
      I2C_WRITE(ADDR_RD_24XXX);  
}    
void GHI_1BYTE_24XXX(UNSIGNED INT16 ADDR,UNSIGNED INT8 DATA_1BYTE)
{          
      I2C_START();   
      I2C_WRITE(ADDR_WR_24XXX);  
      I2C_WRITE(ADDR>>8);         
      I2C_WRITE(ADDR);   
      I2C_WRITE(DATA_1BYTE);   
      I2C_STOP();
}

UNSIGNED INT8 DOC_1BYTE_24XXX(UNSIGNED INT16 ADDR)
{   
      UNSIGNED INT8 DATA_1BYTE;
      I2C_START();
      I2C_WRITE(ADDR_WR_24XXX);  
      I2C_WRITE(ADDR>>8);        
      I2C_WRITE(ADDR);           
      I2C_START();                
      I2C_WRITE(ADDR_RD_24XXX);  
      DATA_1BYTE =  I2C_READ(0);
      I2C_STOP();
      RETURN(DATA_1BYTE);
}  

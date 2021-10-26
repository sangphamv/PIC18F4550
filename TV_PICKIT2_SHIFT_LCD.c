UNSIGNED INT8 LCD_CONTROL;  
#bit LCD_P = LCD_CONTROL.3
#bit LCD_RS = LCD_CONTROL.2
#bit LCD_RW = LCD_CONTROL.1
#bit LCD_E  = LCD_CONTROL.0

#DEFINE LCD_FUNCTION_SET       0X38
#DEFINE LCD_DISPLAY_CONTROL    0X0C
#DEFINE LCD_CLEAR_DISPLAY      0X01
#DEFINE LCD_ENTRY_MODE         0X06
#DEFINE LCD_SHIFT_LEFT         0X18
#DEFINE LCD_SHIFT_RIGHT        0X1C

#DEFINE LCD_ADDR_LINE1         0X80
#DEFINE LCD_ADDR_LINE2         0XC0
#DEFINE LCD_ADDR_LINE3         0X94
#DEFINE LCD_ADDR_LINE4         0XD4

VOID LCD_XUAT_8BIT(INT8 LCD_DATA_X)
{
      LCD_E=1; XUAT_LCD20X4(LCD_CONTROL,LCD_DATA_X);     
      LCD_E=0; XUAT_LCD20X4(LCD_CONTROL,LCD_DATA_X); 
}
void LCD_COMMAND(INT8 LCD_DATA_X)   
  {
      LCD_RS = 0;
      LCD_XUAT_8BIT(LCD_DATA_X);
      DELAY_US(20);
  }
void LCD_DATA(INT8 LCD_DATA_X)       
  {
      LCD_RS = 1;     
      LCD_XUAT_8BIT(LCD_DATA_X);
      DELAY_US(20);
  }
  
VOID SETUP_LCD ()
{                     
         LCD_E  = 0; 
         LCD_RW = 0; 
         LCD_RS = 1; 
         LCD_P =0;
         LCD_COMMAND(LCD_FUNCTION_SET);         
         DELAY_US(40);
         LCD_COMMAND(LCD_DISPLAY_CONTROL);   
         DELAY_US(40);
         LCD_COMMAND(LCD_CLEAR_DISPLAY);      
         DELAY_MS(2);
         LCD_COMMAND(LCD_ENTRY_MODE);       
         DELAY_US(40);                
}

CONST UNSIGNED CHAR LCD_SO_X[11][6] ={
                  0,1,2,5,3,4,               // SO 0
                  1,2,32,3,7,3,              // SO 1
                  6,6,2,5,3,3,               // SO 2
                  6,6,2,3,3,4,               // SO 3
                  7,3,7,32,32,7,             // SO 4
                  7,6,6,3,3,4,               // SO 5
                  0,6,6,5,3,4,               // SO 6
                  1,1,7,32,32,7,             // SO 7
                  0,6,2,5,3,4,               // SO 8
                  0,6,2,3,3,4
                  32,32,32,32,32,32};             // SO 9
                  
CONST UNSIGNED CHAR LCD_SO_XX[10][9] ={
                  0,1,2,7,32,7,5,3,4,               // SO 0
                  1,2,32,3,7,3,              // SO 1
                  6,6,2,5,3,3,               // SO 2
                  6,6,2,3,3,4,               // SO 3
                  7,3,7,32,32,7,             // SO 4
                  7,6,6,3,3,4,               // SO 5
                  0,6,6,5,3,4,               // SO 6
                  1,1,7,32,32,7,             // SO 7
                  0,6,2,5,3,4,               // SO 8
                  0,6,2,3,3,4};             // SO 9                  
                  
CONST UNSIGNED CHAR LCD_MA_8DOAN[] = {
   0x07,0x0F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,  //DOAN F - 0
   0x1F,0x1F,0x1F,0X00,0X00,0X00,0X00,0X00,  //DOAN A - 1
   0x1C,0x1E,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,  //DOAN B - 2
   0X00,0X00,0X00,0X00,0X00,0x1F,0x1F,0x1F,  //DOAN D - 3
   0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1E,0x1C,  //DOAN C - 4
   0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x0F,0x07,  //DOAN E - 5
   0x1F,0x1F,0x1F,0X00,0X00,0X00,0x1F,0x1F,  //DOAN G+D-6 
   0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F}; //DOAN I  -7
   
VOID LCD_GOTO_XY(SIGNED INT8 X, SIGNED INT8 Y)
{ 
   CONST UNSIGNED INT8 LCD_VITRI[]={0x80,0xC0,0x94,0xD4};
   LCD_COMMAND(LCD_VITRI[X]+Y);
}

VOID XXX()
{ 
   SIGNED INT8 X;
   X= LCD_SO_X[0][0];
   X= LCD_MA_8DOAN[0];
}

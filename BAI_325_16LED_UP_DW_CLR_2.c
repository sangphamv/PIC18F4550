
#INCLUDE <TV_PICKIT2_SHIFT_1.c>

UNSIGNED INT16  Y;
INT8 TT;

VOID NUT_UP()
{
   IF ( ! INPUT (UP) )
   {
         DELAY_MS (20) ;
         {
            IF ( ! INPUT (UP) )
            {
               IF (TT == 0)
               {                           
                     Y = (Y<<1) |0X0001;
                     XUAT_32LED_DON_2WORD (0, Y) ;
                     //XUAT_32LED_DON_4BYTE(0,0,Y>>8,Y);
                     DELAY_MS (200) ;                                      
               }

               IF (TT == 1)
               {                                
                     Y = (Y>>1) | 0X8000;
                     XUAT_32LED_DON_2WORD (0, Y) ;
                     DELAY_MS (200) ;                                       
               }
               DO{}
               WHILE ( ! INPUT (UP)) ;
            }
         }
   }
}

VOID NUT_DW()
{
   IF ( ! INPUT (DW) )
   {      
         DELAY_MS (20) ;
         {
            IF ( ! INPUT (DW) )            
            {
               IF (TT == 0)
               {                                 
                     Y = (Y>>1);
                     XUAT_32LED_DON_2WORD (0, Y) ;                     
                     DELAY_MS (200) ;                   
               }

               IF (TT == 1)
               {                                   
                     Y = (Y<<1);
                     XUAT_32LED_DON_2WORD (0, Y) ;
                     DELAY_MS (200) ;                                     
               }
               DO{}
               WHILE ( ! INPUT (UP)) ;
            }

         }
   }
}

VOID NUT_CLR()
{
   IF ( ! INPUT (CLR) )
   {
      DELAY_MS (20) ;
      {
         IF ( ! INPUT (CLR) )
         {
            TT++;
            IF (TT == 2) TT=0;
            WHILE ( ! INPUT (CLR)) ;
         }
      }
   }
}

VOID MAIN()
{
   SET_UP_PORT_IC_CHOT () ;
   SET_TRIS_B (0X3C) ;
   Y = 0;
   TT = 0;
   XUAT_32LED_DON_2WORD (0, 0) ;
   WHILE (TRUE)
   {
      NUT_UP () ;
      NUT_DW () ;
      NUT_CLR () ;
   }
}


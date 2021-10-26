
#INCLUDE<TV_PICKIT2_SHIFT_1.C>

UNSIGNED INT8 DEM_LED=0;
UNSIGNED INT32 Y;

VOID STD_PST_TSP()
{
   IF (DEM_LED < 32)
   {
      xuat_32led_don_1dw (y) ;
      y = (y<<1) + 1;
      DELAY_MS(300);
   }

   else IF (dem_led < 64)
   {
      xuat_32led_don_1dw (y) ;
      y = (y<<1);
      DELAY_MS(300);
   }

   ELSE IF (DEM_LED <96)
   {
      
      XUAT_32LED_DON_1DW (Y);
      Y= (Y>>1)+0x80000000;
      DELAY_MS(300);
   }

   ELSE if (DEM_LED <128)
   {
      XUAT_32LED_DON_1DW(Y);
      Y= (Y>>1);
      DELAY_MS(300);
      
   }
   ELSE
   {
      DEM_LED=0;
      Y=0;
      
   }
   DEM_LED++;
}

void main()
{
   set_up_port_ic_chot () ;
   y = 0;

   WHILE (true)
   {
      STD_PST_TSP () ;

      //cac yeu cau dieu khien khac
   }
}


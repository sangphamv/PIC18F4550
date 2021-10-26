
#INCLUDE<TV_PICKIT2_SHIFT_1.C>

UNSIGNED INT8 DEM_LED;
UNSIGNED INT32 Y;

VOID DELAY_TUY_Y(UNSIGNED INT8 DL2)
{
   UNSIGNED INT8 DL;
   FOR (DL = 0; DL < DL2; DL++) DELAY_MS (10);
}

VOID SANG_TAT_DAN_PST_32LED(UNSIGNED INT8 DL)
{
   IF (DEM_LED < 32)
   {
      xuat_32led_don_1dw (y) ;
      y = (y<<1) + 1;
      delay_tuy_y (dl) ;
   }

   else IF (dem_led < 64)
   {
      xuat_32led_don_1dw (y) ;
      y = (y<<1);
      delay_tuy_y (dl) ;
   }

   ELSE
   {
      dem_led = 0;
      y = 0;
   }

   dem_led++;
}

void main()
{
   set_up_port_ic_chot () ;
   y = 0;
   DEM_LED=1;

   WHILE (true)
   {
      sang_tat_dan_pst_32led (2) ;

      //cac yeu cau dieu khien khac
   }
}


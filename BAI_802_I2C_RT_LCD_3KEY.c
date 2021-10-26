
#include <tv_pickit2_shift_1.c>
//#include <tv_pickit2_shift_lcd.c>
#include <tv_pickit2_shift_DS1307_i2c.c>

unsigned INT16 k;
unsigned CHAR giatri_mod;

void hien_thi_gia_tri_mod ( )
{
   lcd_command(0x8a);
   lcd_data (giatri_mod + 0x30) ;
}

void phim_mod()
{
   IF (!input (mod))
   {
      delay_ms (20) ;
      {
         IF (!input (mod))
         {
            IF (giatri_mod < 3) giatri_mod++;
            ELSE giatri_mod = 0;
            hien_thi_gia_tri_mod ();
            WHILE ( ! input (mod)) ;
         }
      }
   }
}

unsigned int8 hieu_chinh_so_bcd_tang(UNSIGNED int8 x )
{
   UNSIGNED int8 y;
   y = x;
   x = x&0x0f;
   IF (x == 0x0a) y = y + 6;
   RETURN (y) ;
}

unsigned int8 hieu_chinh_so_bcd_giam(UNSIGNED int8 x )
{
   UNSIGNED int8 y;
   y = x;
   x = x&0x0f;
   IF (x == 0x0f) y = y - 6;
   RETURN (y) ;
}

void luu_giai_ma_hien_thi_sau_khi_chinh()
{
   nap_thoi_gian_htai_vao_ds13B07 () ;
   hien_thi_thoi_gian_ds13B07 ();
}

void phim_up()
{
   IF (!input (up))
   {
      delay_ms (20) ;

      IF (!input (up))
      {
         SWITCH (giatri_mod)
         {
            case 1: IF (giay_ds13 == 0x59) giay_ds13 = 0;

            ELSE
            {
               giay_ds13++;
               giay_ds13 = hieu_chinh_so_bcd_tang (giay_ds13) ;
            }

            luu_giai_ma_hien_thi_sau_khi_chinh () ;
            BREAK;
            case 2: IF (phut_ds13 == 0x59) phut_ds13 = 0;

            ELSE
            {
               phut_ds13++;
               phut_ds13 = hieu_chinh_so_bcd_tang (phut_ds13) ;
            }

            luu_giai_ma_hien_thi_sau_khi_chinh () ;
            BREAK;
            case 3: IF (gio_ds13 == 0x23) gio_ds13 = 0;

            ELSE
            {
               gio_ds13++;
               gio_ds13=hieu_chinh_so_bcd_tang(gio_ds13);
            }

            luu_giai_ma_hien_thi_sau_khi_chinh () ;
            BREAK;
            DEFAULT: break;
         }

         WHILE ( ! input (up)) ;
      }
   }
}

void phim_dw()
{
   IF (!input (dw))
   {
      delay_ms (20) ;

      IF (!input (dw))
      {
         SWITCH (giatri_mod)
         {
            case 1: IF (giay_ds13 == 0) giay_ds13 = 0x59;

            ELSE
            {
               giay_ds13--;
               giay_ds13 = hieu_chinh_so_bcd_giam (giay_ds13) ;
            }

            luu_giai_ma_hien_thi_sau_khi_chinh () ;
            BREAK;
            case 2: IF (phut_ds13 == 0) phut_ds13 = 0x59;

            ELSE
            {
               phut_ds13--;
               phut_ds13 = hieu_chinh_so_bcd_giam (phut_ds13) ;
            }

            luu_giai_ma_hien_thi_sau_khi_chinh () ;
            BREAK;
            case 3: IF (gio_ds13 == 0) gio_ds13 = 0x23;

            ELSE
            {
               gio_ds13--;
               gio_ds13 = hieu_chinh_so_bcd_giam (gio_ds13) ;
            }

            luu_giai_ma_hien_thi_sau_khi_chinh () ;
            BREAK;
            DEFAULT: break;
         }

         WHILE ( ! input (dw)) ;
      }
   }
}

void main()
{
   set_up_port_ic_chot();
   setup_lcd () ;
   lcd_command (lcd_addr_line1) ;
   lcd_data ("clock:") ;
   doc_thoi_gian_tu_realtime () ;

   IF (ma_ds13 != ma_ds)
   {
      thiet_lap_thoi_gian_hien_tai () ;
      nap_thoi_gian_htai_vao_ds13B07 () ;

   }

   giatri_mod = 0;
   hien_thi_gia_tri_mod ();
   doc_thoi_gian_tu_realtime () ;
   giaytam = giay_ds13;

   WHILE (true)
   {
      doc_thoi_gian_tu_realtime () ;

      IF (giaytam != giay_ds13)
      {
         giaytam = giay_ds13;
         hien_thi_gia_tri_mod ();
         hien_thi_thoi_gian_ds13B07 ();

      }

      FOR (k = 0; k < 10000; k++)
      {
         phim_mod () ;
         phim_up();
         phim_dw();
      }
   }
}


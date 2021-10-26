
#INCLUDE  <TV_PICKIT2_SHIFT_1.c>
#INCLUDE <TV_PICKIT2_SHIFT_32LED_DON.c>
#INCLUDE <TV_PICKIT2_SHIFT_GLCD128X64.c>
#INCLUDE <TV_PICKIT2_SHIFT_LCD.c>

SIGNED INT8 GIO, PHUT, GIAY, BDN, GIA_TRI_MOD, DEM_TG_EXIT=0;
UNSIGNED INT8 T0, T0_TAM;
VOID DELAY_QUET_8LED(UNSIGNED INT8 DL);

#INT_timer1

void interrupt_timer1()
{  BDN++;  SET_TIMER1(3036);  }
VOID GLCD_HIENTHI_T0(UNSIGNED INT8 T0)
{
   GLCD_COMMAND (GLCD_ADDR_LINE2) ;
   GLCD_DATA (T0 / 100 % 10 + 0X30);
   GLCD_DATA (T0 / 10 % 10 + 0X30);
   GLCD_DATA (T0 % 10 + 0X30);
   LCD_COMMAND (LCD_ADDR_LINE2) ;
   LCD_DATA (T0 / 100 % 10 + 0X30);
   LCD_DATA (T0 / 10 % 10 + 0X30);
   LCD_DATA (T0 % 10 + 0X30);
}

VOID GIAI_MA_GAN_CHO_8LED_QUET()
{
   LED_7DQ[0] = MA7DOAN [GIAY % 10];
   LED_7DQ[1] = MA7DOAN [GIAY / 10];
   LED_7DQ[3] = MA7DOAN [PHUT % 10];
   LED_7DQ[4] = MA7DOAN [PHUT / 10];
   LED_7DQ[6] = MA7DOAN [GIO % 10];
   LED_7DQ[7] = MA7DOAN [GIO / 10];
}

VOID TAT_2LED_CHINH()
{
   IF (GIA_TRI_MOD == 1) { LED_7DQ[7] = 0XFF; LED_7DQ[6] = 0XFF;}
   ELSE IF (GIA_TRI_MOD == 2) { LED_7DQ[4] = 0XFF; LED_7DQ[3] = 0XFF; }
   ELSE IF (GIA_TRI_MOD == 3) { LED_7DQ[1] = 0XFF; LED_7DQ[0] = 0XFF; }
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
VOID PHIM_MOD()
{
   IF (INPUT (MOD) == 0)
   {
      DELAY_MS (20) ;

      IF (INPUT (MOD) == 0)
      {
         GIA_TRI_MOD++;
         IF (GIA_TRI_MOD >= 4) GIA_TRI_MOD = 0;
         DEM_TG_EXIT = 0;
         WHILE (INPUT (MOD) == 0);
      }
   }
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
VOID PHIM_UP()
{
   IF(INPUT(UP)==0)
   {
      DELAY_MS (20) ;

      IF (INPUT (UP) == 0)
      {
         DEM_TG_EXIT = 0;

         SWITCH (GIA_TRI_MOD)
         {
            CASE 1: IF (GIO == 23) GIO = 0;
            ELSE GIO++;
            BREAK;
            CASE 2: IF (PHUT == 59) PHUT = 0;
            ELSE PHUT++;
            BREAK;
            CASE 3: IF (GIAY == 59) GIAY = 0;
            ELSE GIAY++;
            BREAK;
            DEFAULT: BREAK;
         }

         WHILE (INPUT (UP) == 0);
      }
   }
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
VOID PHIM_DW()
{
   IF (INPUT (DW) == 0)
   {
      DELAY_MS (20) ;

      IF (INPUT (DW) == 0)
      {
         DEM_TG_EXIT = 0;

         SWITCH (GIA_TRI_MOD)
         {
            CASE 1: IF (GIO == 0) GIO = 23;
            ELSE GIO--;
            BREAK;
            CASE 2: IF (PHUT == 0) PHUT = 59;
            ELSE PHUT--;
            BREAK;
            CASE 3: IF (GIAY == 0) GIAY = 59;
            ELSE GIAY--;
            BREAK;
            DEFAULT: BREAK;
         }

         WHILE (INPUT (DW) == 0);
      }
   }
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
VOID MAIN()
{
   SET_UP_PORT_IC_CHOT ();
   SETUP_TIMER_1 (T1_INTERNAL|T1_DIV_BY_8);
   SET_TIMER1 (3036);
   ENABLE_INTERRUPTS (GLOBAL) ;
   ENABLE_INTERRUPTS (INT_TIMER1); ;
   BDN = 0; GIAY = 0X00; PHUT = 0; GIO = 0; GIA_TRI_MOD = 0;
   SETUP_GLCD(GLCD_GRAPHIC_MODE);
   GLCD_MAU_NEN (0) ;
   GLCD_XUAT_ANH(64,64,64,0);
   GDRAM_VDK_TO_GDRAM_GLCD_ALL() ;
   SETUP_GLCD(GLCD_TEXT_MODE);
   GLCD_COMMAND (GLCD_ADDR_LINE1) ;
   GLCD_DATA ("DEM SP:");
   SETUP_LCD ();
   LCD_COMMAND (LCD_ADDR_LINE1) ;
   LCD_DATA ("LCD: DEM SAN PHAM:") ;
   SETUP_TIMER_0 (T0_EXT_L_TO_H|T0_DIV_1|T0_8_BIT);
   SET_TIMER0 (0);
   T0_TAM = T0 = 0;
   XUAT_4LED_7DOAN_GIAIMA_XOA_SO0 (T0) ;
   GLCD_HIENTHI_T0 (T0) ;

   WHILE (TRUE)
   {
      GIAI_MA_GAN_CHO_8LED_QUET () ;
      
      IF (BDN < 10)
      {
         IF ((BDN < 5)&& (INPUT (BT0)) && (INPUT (BT2))) TAT_2LED_CHINH ();
         HIEN_THI_8LED_7DOAN_QUET_ALL () ;
         PHIM_MOD () ;
         PHIM_UP () ;
         PHIM_DW () ;
         T0 = GET_TIMER0 () ;

         IF (T0 != T0_TAM)
         {
            T0_TAM = T0;
            GLCD_HIENTHI_T0 (T0) ;
            XUAT_4LED_7DOAN_GIAIMA_XOA_SO0 (T0) ;
            IF (T0 >= 101) SET_TIMER0 (1);
         }

         IF (TTCT_TD == 1) SANG_TAT_32LED (2, 1);
         IF (TTCT_TD == 2) SANG_TAT_DAN_PST_32LED (5, 1);
         IF (TTCT_TD == 3) SANG_TAT_DAN_TSP_32LED (5, 1);
         IF (TTCT_TD == 4) SANG_TAT_DAN_NGOAI_VAO_32LED (5, 1);
         IF (TTCT_TD == 5) SANG_TAT_DAN_TRONG_RA_32LED (5, 1);
         IF (TTCT_TD == 6) SANG_DON_PST_32LED (5, 1);
         IF (TTCT_TD == 7) DIEM_SANG_DICH_TRAI_MAT_DAN_32LED (5, 1); //
         IF (TTCT_TD == 8) SANG_DON_TSP_32LED (5, 1);
         IF (TTCT_TD == 9) DIEM_SANG_DICH_PHAI_MAT_DAN_32LED (5, 1); //
         IF (TTCT_TD == 10) SANG_TAT_DAN_TRAI_SANG_PHAI_2X16LED (5, 1);
         IF (TTCT_TD == 11) SANG_TAT_DAN_PHAI_SANG_TRAI_2X16LED (5, 1);
         IF (TTCT_TD == 12) DIEM_SANG_DI_CHUYEN_PST_32LED (5, 1);
         IF (TTCT_TD == 13) DIEM_SANG_DI_CHUYEN_TSP_32LED (5, 1);
         IF (TTCT_TD == 14) SANG_DON_TNT_32LED (5, 1);
         IF (TTCT_TD == 15) SANG_DON_TTR_32LED (5, 1);
         IF (TTCT_TD > 15) TTCT_TD = 1;
      }

      ELSE
      {
         BDN = BDN - 10;
         DEM_TG_EXIT++;
         IF (DEM_TG_EXIT == 20) GIA_TRI_MOD = 0;
         GIAY++;

         IF (GIAY == 60)
         {
            GIAY = 0;
            PHUT++;

            IF (PHUT == 60)
            {
               PHUT = 0;
               GIO++;
               IF (GIO == 24) GIO = 0;
            }
         }
      }
   }
}


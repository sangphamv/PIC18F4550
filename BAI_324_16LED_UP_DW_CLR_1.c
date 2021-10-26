#INCLUDE <TV_PICKIT2_SHIFT_1.c>
UNSIGNED INT16  Y;
VOID NUT_UP()
{
   IF(!INPUT(UP))
        {
            DELAY_MS(20);
            {
                IF(!INPUT(UP))
                {
                Y=(Y<<1)+1;
                XUAT_32LED_DON_2WORD(0,Y);
                DO{}
                WHILE(!INPUT(UP));
                }
            }  
        }
}
VOID NUT_DW()
{
   IF(!INPUT(DW))
        {
            DELAY_MS(20);
            {
                IF(!INPUT(DW))
                {
                Y=(Y>>1);
                XUAT_32LED_DON_2WORD(0,Y);
                DO{}
                WHILE(!INPUT(DW));
                }
            }  
        }
}
VOID NUT_CLR()
{
   IF(!INPUT(CLR))
        {
            DELAY_MS(20);
            {
                IF(!INPUT(CLR))
                {
                Y=0;
                XUAT_32LED_DON_2WORD(0,0);
                DO{}
                WHILE(!INPUT(CLR));
                }
            }  
        }
}
VOID MAIN()
{
    SET_UP_PORT_IC_CHOT();
    SET_TRIS_B(0X3C);
    Y=0X00;
    XUAT_32LED_DON_4BYTE(0,0,0,0);
    WHILE(TRUE)
    {
      NUT_UP();
      NUT_DW();
      NUT_CLR();
    }   
}

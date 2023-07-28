#include<stdio.h>
#include"dbus_wtr.h"
RC_Ctl_t RC_CtrlData;
uint8_t RxData[15];

//解码函数
void RemoteDataProcess(uint8_t *pData)
{
 if(pData == NULL)
 {
 return;
 }
 
    RC_CtrlData.rc.ch0 = ((int16_t)pData[0] | ((int16_t)pData[1] << 8)) & 0x07FF; 
    RC_CtrlData.rc.ch0-=1024;
    RC_CtrlData.rc.ch1 = (((int16_t)pData[1] >> 3) | ((int16_t)pData[2] << 5)) & 0x07FF;
    RC_CtrlData.rc.ch1-=1024;
    RC_CtrlData.rc.ch2 = (((int16_t)pData[2] >> 6) | ((int16_t)pData[3] << 2) |((int16_t)pData[4] << 10)) & 0x07FF;
    RC_CtrlData.rc.ch2-=1024;
    RC_CtrlData.rc.ch3 = (((int16_t)pData[4] >> 1) | ((int16_t)pData[5]<<7)) & 0x07FF;
    RC_CtrlData.rc.ch3-=1024;

    /* prevent remote control zero deviation */
    if(RC_CtrlData.rc.ch0 <= 5 && RC_CtrlData.rc.ch0 >= -5)
        RC_CtrlData.rc.ch0 = 0;
    if(RC_CtrlData.rc.ch1 <= 5 && RC_CtrlData.rc.ch1 >= -5)
        RC_CtrlData.rc.ch1 = 0;
    if(RC_CtrlData.rc.ch2 <= 5 && RC_CtrlData.rc.ch2 >= -5)
        RC_CtrlData.rc.ch2 = 0;
    if(RC_CtrlData.rc.ch3 <= 5 && RC_CtrlData.rc.ch3 >= -5)
        RC_CtrlData.rc.ch3 = 0;



    RC_CtrlData.rc.s1 = ((pData[5] >> 4) & 0x000C) >> 2;
    RC_CtrlData.rc.s2 = ((pData[5] >> 4) & 0x0003);

    if ((abs(RC_CtrlData.rc.ch0) > 660) || (abs(RC_CtrlData.rc.ch1) > 660) || (abs(RC_CtrlData.rc.ch2) > 660) || (abs(RC_CtrlData.rc.ch3) > 660))
    {
        memset(RC_CtrlData.rc, 0, sizeof(RC_Ctl_t));
        return ;
    }
    /*
    RC_CtrlData.mouse.x = ((int16_t)pData[6]) | ((int16_t)pData[7] << 8);
     RC_CtrlData.mouse.y = ((int16_t)pData[8]) | ((int16_t)pData[9] << 8);
    RC_CtrlData.mouse.z = ((int16_t)pData[10]) | ((int16_t)pData[11] << 8); 
    RC_CtrlData.mouse.press_l = pData[12];
    RC_CtrlData.mouse.press_r = pData[13];
    RC_CtrlData.key.v = ((int16_t)pData[14]);// | ((int16_t)pData[15] << 8);
    */
}

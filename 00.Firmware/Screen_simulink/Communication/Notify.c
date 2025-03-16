#include "../Communication/Notify.h"
#include <string.h>  




/*! 
*  \brief  按钮控件通知
*  \details  当按钮状态改变(或调用GetControlValue)时，执行此函数
*  \param screen_id 画面ID
*  \param control_id 控件ID
*  \param state 按钮状态：0弹起，1按下
*/
void NotifyButton(uint16_t screen_id, uint16_t control_id, uint8_t state)
{
    // TODO: 处理按钮控件通知
    if(screen_id==0x01 && control_id==0x01)
    {
        if(state == 0x01)
        {

        }
    }

}

char Threshold_test[10];
void NotifyText(uint16_t screen_id, uint16_t control_id, const char text[])
{
    if(screen_id==0x02 && control_id==0x02)//user setting
    {
        // TODO: 处理文本控件通知
       memcpy(Threshold_test,text,10);
    }
}
#include "../Communication/Notify.h"
#include <string.h>  




/*! 
*  \brief  ��ť�ؼ�֪ͨ
*  \details  ����ť״̬�ı�(�����GetControlValue)ʱ��ִ�д˺���
*  \param screen_id ����ID
*  \param control_id �ؼ�ID
*  \param state ��ť״̬��0����1����
*/
void NotifyButton(uint16_t screen_id, uint16_t control_id, uint8_t state)
{
    // TODO: ����ť�ؼ�֪ͨ
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
        // TODO: �����ı��ؼ�֪ͨ
       memcpy(Threshold_test,text,10);
    }
}
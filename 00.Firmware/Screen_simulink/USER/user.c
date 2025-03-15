#include "../USER/user.h"
#include "../BSP/driver.h"
#include "../Communication/protocol.h"
#include "../Communication/SendMessage.h"
#include "../Task/sys_task.h"
#include "../Task/sys_time.h"
static float sin[256] = {1,1,1,1,1,2,3,4,6,8,10,13,15,
    19,22,25,29,33,38,42,47,52,57,62,68,73,79,85,91,97,103,109,115,121,127,134,
    140,146,152,158,164,170,176,182,187,193,198,203,208,213,217,222,226,230,233,
    236,240,242,245,247,249,251,252,253,254,254,254,254,254,253,252,251,249,247,
    245,242,240,236,233,230,226,222,217,213,208,203,198,193,187,182,176,170,164,
    158,152,146,140,134,128,121,115,109,103,97,91,85,79,73,68,62,57,52,47,42,38,
    33,29,25,22,19,15,13,10,8,6,4,3,2,1,1,1,1,1,2,3,4,6,8,10,13,15,
    19,22,25,29,33,38,42,47,52,57,62,68,73,79,85,91,97,103,109,115,121,127,134,
    140,146,152,158,164,170,176,182,187,193,198,203,208,213,217,222,226,230,233,
    236,240,242,245,247,249,251,252,253,254,254,254,254,254,253,252,251,249,247,
    245,242,240,236,233,230,226,222,217,213,208,203,198,193,187,182,176,170,164,
    158,152,146,140,134,128,121,115,109,103,97,91,85,79,73,68,62,57,52,47,42,38,
    33,29,25,22,19,15,13,10,8,6,4,3,2};
static uint32_t num = 0;//曲线采样点计数


sys_task_t task_Display_GrapDate;
sys_task_t task_DaCai_protocol;
void  Display_GrapDate (void);
void user_setup(void)
{

    init_driver();
    sys_task_create(&task_Display_GrapDate,  Display_GrapDate, 10);
    sys_task_create(&task_DaCai_protocol,  DaCai_protocol, 10);

    sys_task_start(&task_DaCai_protocol);
    sys_task_start(&task_Display_GrapDate);

}

void user_loop(void)
{
    sys_task_process();
}



void  Display_GrapDate (void)
{
    SendTextInt32(0x01,0x02,200,0,3);
    SendTextString(0x01,0x06,"Hello World!");
    // SendGrapDate(4,2,0,&sin[num],2);                                    //添加数据到曲线  一次两个数据
    SendHistoryData(4,2,sin[num],1);
    num += 1;                                                                        
    if(num >= 255)                                                                
    {                                                                             
        num =0;                                                                  
    }
}



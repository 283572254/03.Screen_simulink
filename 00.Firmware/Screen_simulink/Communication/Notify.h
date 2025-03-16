#ifndef NOTIFY_H
#define NOTIFY_H

#include "main.h"

void NotifyButton(uint16_t screen_id, uint16_t control_id, uint8_t state);
void NotifyText(uint16_t screen_id, uint16_t control_id, const char* text);
#endif // !NOTIFY_H

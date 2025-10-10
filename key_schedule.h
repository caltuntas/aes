#ifndef KEY_SCHEDULE_H
#define KEY_SCHEDULE_H

#include <stdint.h>

uint32_t convert_to_uint32(uint8_t arr[4]);
void convert_to_uint8_array(uint32_t w,uint8_t arr[4]);
uint32_t rot_word(uint32_t w);
uint32_t sub_word(uint32_t w);
uint32_t rcon(uint8_t round, uint32_t w);

#endif

#ifndef KEY_SCHEDULE_H
#define KEY_SCHEDULE_H

#include <stdint.h>

uint32_t convert_to_uint32(uint8_t arr[4]);
void convert_to_uint8_array(uint32_t w,uint8_t arr[4]);
uint32_t rot_word(uint32_t w);
uint32_t sub_word(uint32_t w);
uint32_t rcon(uint8_t round, uint32_t w);
void expand_key(uint8_t round, uint8_t key[16], uint8_t res[16]);
void add_round_key(uint8_t round,uint8_t text[16], uint8_t key[16], uint8_t res[16]);
void sub_bytes(uint8_t state[16], uint8_t res[16]);
void inv_sub_bytes(uint8_t state[16], uint8_t res[16]);
void shift_rows(uint8_t state[16], uint8_t res[16]);
void inv_shift_rows(uint8_t state[16], uint8_t res[16]);
void mix_columns(uint8_t state[16], uint8_t res[16]);
void inv_mix_columns(uint8_t state[16], uint8_t res[16]);
void aes_round(uint8_t state[16], uint8_t key[16], uint8_t res[16]);
void aes_dec_round(uint8_t state[16], uint8_t key[16], uint8_t res[16]) ;
void aes_final_round(uint8_t state[16], uint8_t key[16], uint8_t res[16]);
void aes_dec_final_round(uint8_t state[16], uint8_t key[16], uint8_t res[16]);
void aes_enc(uint8_t text[16], uint8_t key[16], uint8_t res[16]);
void aes_dec(uint8_t text[16], uint8_t key[16], uint8_t res[16]);
uint8_t mul(uint8_t coefficient, uint8_t val) ;

#endif

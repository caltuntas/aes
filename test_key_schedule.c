#include "test-framework/unity.h"
#include "key_schedule.h"
#include <stdlib.h>
#include <stdio.h>
#define ARRAY_LEN(arr) (sizeof(arr)/sizeof(arr[0]))

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_rot_word(void)
{
    uint32_t actual = convert_to_uint32((uint8_t[4]){0x09,0xcf,0x4f,0x3c});
    uint32_t expected = convert_to_uint32((uint8_t[4]){0xcf,0x4f,0x3c,0x09});
    uint32_t res = rot_word(actual);
    TEST_ASSERT_EQUAL_INT(res,expected);
}

static void test_sub_word(void)
{
    uint32_t actual = convert_to_uint32((uint8_t[4]){0xcf,0x4f,0x3c,0x09});
    uint32_t expected = convert_to_uint32((uint8_t[4]){0x8a,0x84,0xeb,0x01});
    uint32_t res = sub_word(actual);
    TEST_ASSERT_EQUAL_INT(res,expected);
}

static void test_rcon(void)
{
    TEST_ASSERT_EQUAL_INT(rcon(1,convert_to_uint32((uint8_t[4]){0x8a,0x84,0xeb,0x01})),
                                 convert_to_uint32((uint8_t[4]){0x8b,0x84,0xeb,0x01}));
    TEST_ASSERT_EQUAL_INT(rcon(2,convert_to_uint32((uint8_t[4]){0x8a,0x84,0xeb,0x01})),
                                 convert_to_uint32((uint8_t[4]){0x88,0x84,0xeb,0x01}));
    TEST_ASSERT_EQUAL_INT(rcon(9,convert_to_uint32((uint8_t[4]){0x8a,0x84,0xeb,0x01})),
                                 convert_to_uint32((uint8_t[4]){0x91,0x84,0xeb,0x01}));
}

static void test_convert(void)
{
    uint32_t actual = convert_to_uint32((uint8_t[4]){0x09,0xcf,0x4f,0x3c});
    uint8_t arr[4] = {0};
    convert_to_uint8_array(actual,arr);
    uint8_t expected[] ={0x09,0xcf,0x4f,0x3c};
    uint32_t res = rot_word(actual);
    TEST_ASSERT_EQUAL_HEX8_ARRAY(expected,arr,4);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_rot_word);
    RUN_TEST(test_sub_word);
    RUN_TEST(test_rcon);
    RUN_TEST(test_convert);
    return UNITY_END();
}

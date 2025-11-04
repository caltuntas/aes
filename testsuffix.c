#include <stdio.h>
#include <stdint.h>

int main() {
    // Your case - no issues
    uint8_t key[16] = {0x54,0x68,0x61,0x74,0x73,0x20,0x6d,0x79,
                       0x20,0x4b,0x75,0x6e,0x67,0x20,0x46,0x75};
    
    // This might generate warnings
    uint8_t large[] = {0xFF, 0x80, 0xFE};  // Values > 127
    
    for(int i = 0; i < 3; i++) {
        printf("key[%d] = %u (0x%02x)\n", i, large[i], large[i]);
    }

    for(int i = 0; i < 16; i++) {
        printf("key[%d] = %u (0x%02x)\n", i, key[i], key[i]);
    }

unsigned int values[] = { 0x1234, 0x5678, 0x9abc, 0xffffffff };
    
    for (int i = 0; i < 4; i++) {
        printf("values[%d] = %u (hex: 0x%x)\n", i, values[i], values[i]);
    }
    
    return 0;
}

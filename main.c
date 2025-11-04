#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "aes.h"

int main(int arc, char **argv) {
  char *key = argv[1];
  printf("key=%s\n",key);

  uint8_t array[16] = {0};

  int i=0;
  char prev=0;
  char *str = key;
  while(str && *str!='\0') {
    if (i && (i % 2)) {
      char byte[3] ={0};
      byte[0]=prev;
      byte[1]=*str;
      uint8_t num = (uint8_t)strtol(byte,NULL,16);
      int index = (i-2)/2+1;
      if (i ==1)
        index =0;
      array[index] = num;
      printf("i=%d array[%d]=0x%02x\n",i,index,num);
    }
    prev=*str;
    str++;
    i++;
  }

  printf("key\n");
  print_block(array);

  for (int i=0; i<11; i++) {
    expand_key(i,array);
    printf("round[%d] key\n",i);
    print_block(array);
  }
  return 0;
}

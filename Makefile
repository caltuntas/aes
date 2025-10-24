CFLAGS = -O2 -g
all:
	gcc $(CFLAGS) main.c key_schedule.c -o aes

test:
	gcc -g test-framework/unity.c key_schedule.c test_key_schedule.c -o test_key_schedule.out
	./test_key_schedule.out

clean:
	rm -rf *.out *.o *.dSYM

.PHONY: test

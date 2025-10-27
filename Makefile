CFLAGS = -O2 -g
all:
	gcc $(CFLAGS) main.c aes.c -o aes

test:
	gcc -g test-framework/unity.c aes.c test_aes.c -o test_aes.out
	./test_aes.out

clean:
	rm -rf *.out *.o *.dSYM

.PHONY: test

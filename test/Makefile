CC=clang
CFLAGS=-O0 -mavx2
INCLUDE=-I../inc

run_test:test_avx2.exe
	./test_avx2.exe
test_avx2.exe:test_avx2.c
	$(CC) $(CFLAGS) $(INCLUDE) $< -o $@

.PHONY:clean run_test
clean:
	rm -rf *.exe *.o

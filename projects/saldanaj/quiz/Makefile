CFLAGS = -Wall -fpic -coverage -lm

default: all

all: testme.c
	gcc -o testme testme.c $(CFLAGS)
	# echo "testme.c results: " >> tests.out
	# ./testme >> tests.out
	./testme
	# gcov testme.c >> tests.out
	gcov testme.c

clean:
	rm testme *.gcno *.gcov *.out *.gcda


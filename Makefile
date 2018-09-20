all: screen_lib.o
	gcc test.c screen_lib.c -o test -Wall -ansi -pedantic -g 
clean:
	rm test *.o
	
run:
	./test

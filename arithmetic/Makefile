CC=gcc
CFLAGS=-c -pg
#CFLAGS=-c -fprofile-arcs -ftest-coverage(GNU Coverage tool)
calc:main.o add.o sub.o mul.o mod.o div.o
	$(CC) -pg -o calc main.o add.o sub.o mul.o mod.o div.o
	#$(CC) -fprofile-arcs -ftest-coverage -o calc main.o add.o sub.o mul.o mod.o div.o(GNU Coverage tool)
main.o:main.c
	$(CC) $(CFLAGS) main.c
add.o:add.c
	$(CC) $(CFLAGS) add.c
div.o:div.c
	$(CC) $(CFLAGS) div.c
sub.o:sub.c
	gcc $(CFLAGS) sub.c
mod.o:mod.c
	gcc $(CFLAGS) mod.c
mul.o:mul.c
	gcc $(CFLAGS) mul.c
clean:
	rm *.o *calc *.out

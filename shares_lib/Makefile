CC=gcc
CFLAGS=-fPIC -c
calc:main.o add.o sub.o mul.o mod.o div.o
	$(CC) -shared -o libarith.so main.o add.o sub.o mul.o mod.o div.o
	$(CC) -o calc main.c -L. -larith
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
	rm *.o *.so calc

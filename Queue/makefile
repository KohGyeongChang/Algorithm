DEBUG = -g -DDEBUGINFO
GCC = gcc
CFLAGS = -O2 -Wall $(DEBUG)
OBJECTS = main.o queue.o
EXE:testOut

main.o:main.c
	$(GCC) $(CFLAGS) -c main.c

queue.o:queue.c
	$(GCC) $(CFLAGS) -c queue.c

testOut: $(OBJECTS)
	$(GCC) $(OBJECTS) -o testOut

clean:
	rm -f *.o testOut

run:
	./testOut


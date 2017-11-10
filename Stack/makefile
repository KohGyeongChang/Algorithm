DEBUG = -g -DDEBUGINFO
GCC = gcc
CFLAGS = -O2 -Wall $(DEBUG)
OBJECTS = main.o stack.o
EXE:testOut

main.o:main.c
	$(GCC) $(CFLAGS) -c main.c

stack.o:stack.c
	$(GCC) $(CFLAGS) -c stack.c

testOut: $(OBJECTS)
	$(GCC) $(OBJECTS) -o testOut

clean:
	rm -f *.o testOut

run:
	./testOut


DEBUG = -g -DDEBUGINFO
GCC = gcc
CFLAGS = -O2 -Wall $(DEBUG)
OBJECTS = main.o
EXE:testOut

main.o:main.c
	$(GCC) $(CFLAGS) -c main.c

testOut: $(OBJECTS)
	$(GCC) $(OBJECTS) -o testOut

clean:
	rm -f *.o testOut

run:
	./testOut


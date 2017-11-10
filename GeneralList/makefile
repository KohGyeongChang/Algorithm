DEBUG = -g -DDEBUGINFO
GCC = gcc
CFLAGS = -O2 -Wall $(DEBUG)
OBJECTS = main.o generalList.o
EXE:testOut

main.o:main.c
	$(GCC) $(CFLAGS) -c main.c

generalList.o:generalList.c
	$(GCC) $(CFLAGS) -c generalList.c

testOut: $(OBJECTS)
	$(GCC) $(OBJECTS) -o testOut

clean:
	rm -f *.o testOut

run:
	./testOut


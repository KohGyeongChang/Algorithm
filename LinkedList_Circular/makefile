DEBUG = -g -DDEBUGINFO
GCC = gcc
CFLAGS = -O2 -Wall $(DEBUG)
OBJECTS = main.o circularLinkedList.c
EXE:testOut

main.o:main.c
	$(GCC) $(CFLAGS) -c main.c

circularLinkedList.o:circularLinkedList.c
	$(GCC) $(CFLAGS) -c circularLinkedList.c

testOut: $(OBJECTS)
	$(GCC) $(OBJECTS) -o testOut

clean:
	rm -f *.o testOut

run:
	./testOut


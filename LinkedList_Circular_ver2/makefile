DEBUG = -g -DDEBUGINFO
CC = gcc
CFLAGS = -O2 -Wall $(DEBUG)
OBJECTS = main.o circularLinkedList.c
EXE = testCircularList

all : $(EXE)

main.o:main.c
	$(CC) $(CFLAGS) -c main.c

circularLinkedList.o:circularLinkedList.c
	$(CC) $(CFLAGS) -c circularLinkedList.c

$(EXE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXE) 

clean:
	rm -f *.o $(EXE) 

run:
	./$(EXE)


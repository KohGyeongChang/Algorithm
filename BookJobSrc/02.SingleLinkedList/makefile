.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
CC = gcc
CFLAGS = -O2 -Wall $(DEBUG)
OBJECTS = main.o singlelinkedlist.o
TARGET = testSingleLinkedList

all : $(TARGET) 


$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(INC)

main.o:main.c
	$(CC) $(CFLAGS) -c main.c $(INC)

singlelinkedlist.o:singlelinkedlist.c
	$(CC) $(CFLAGS) -c singlelinkedlist.c $(INC)

clean:
	rm -f $(OBJECTS) $(TARGET)

run:
	./$(TARGET)


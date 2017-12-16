.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
CC = gcc
CFLAGS = -O2 -Wall $(DEBUG)
OBJECTS = main.o queue.o
TARGET = testQueue

all : $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) 

main.o:main.c
	$(CC) $(CFLAGS) -c main.c 

queue.o:queue.c
	$(CC) $(CFLAGS) -c queue.c 

clean:
	rm -f $(OBJECTS) $(TARGET)

run:
	./$(TARGET)


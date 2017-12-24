.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
CC = gcc
CFLAGS = -O2 -Wall $(DEBUG)
OBJECTS = main.o bubbleSort.o
TARGET = testSortBubble

all : $(TARGET) 

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) 

main.o:main.c
	$(CC) $(CFLAGS) -c main.c

bubbleSor.o:bubbleSort.c
	$(CC) $(CFLAGS) -c bubbleSort.c

clean:
	rm -f $(OBJECTS) $(TARGET)

run:
	./$(TARGET)


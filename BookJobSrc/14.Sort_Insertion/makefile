.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
CC = gcc
CFLAGS = -O2 -Wall $(DEBUG)
OBJECTS = main.o insertionSort.o
TARGET = testSortInsertion

all : $(TARGET) 

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) 

main.o:main.c
	$(CC) $(CFLAGS) -c main.c 

insertionSort.o:insertionSort.c
	$(CC) $(CFLAGS) -c insertionSort.c 

clean:
	rm -f $(OBJECTS) $(TARGET)

run:
	./$(TARGET)


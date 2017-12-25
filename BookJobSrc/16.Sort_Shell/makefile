.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
CC = gcc
CFLAGS = -O2 -Wall $(DEBUG)
OBJECTS = main.o shellSort.o
TARGET = testSortShell

all : $(TARGET) 

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

main.o:main.c
	$(CC) $(CFLAGS) -c main.c

shellSort.o:shellSort.c
	$(CC) $(CFLAGS) -c shellSort.c

clean:
	rm -f $(OBJECTS) $(TARGET)

run:
	./$(TARGET)


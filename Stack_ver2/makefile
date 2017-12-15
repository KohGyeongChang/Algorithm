.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
CC = gcc
CFLAGS = -O2 -Wall $(DEBUG)
OBJECTS = main.o stack.o
TARGET = testStack

all : $(TARGET) 

StackLib : 
	cd ./lib;$(MAKE)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) 

main.o:main.c
	$(CC) $(CFLAGS) -c main.c 

stack.o:stack.c
	$(CC) $(CFLAGS) -c stack.c 

clean:
	rm -f $(OBJECTS) $(TARGET)

run:
	./$(TARGET)


.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
CC = gcc
CFLAGS = -O2 -Wall $(DEBUG)
OBJECTS = main.o binarytree_levelorder.o queue.o
TARGET = testTreeLevelOrder

all : $(TARGET) 

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(INC)

main.o:main.c
	$(CC) $(CFLAGS) -c main.c $(INC)

binarytree_levelorder.o:binarytree_levelorder.c
	$(CC) $(CFLAGS) -c binarytree_levelorder.c $(INC)

queue.o:queue.c
	$(CC) $(CFLAGS) -c queue.c $(INC)

clean:
	rm -f $(OBJECTS) $(TARGET)

run:
	./$(TARGET)


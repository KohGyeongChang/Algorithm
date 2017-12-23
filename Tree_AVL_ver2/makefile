.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
CC = gcc
CFLAGS = -O2 -Wall $(DEBUG)
OBJECTS = main.o tree_avl.o queue.o
TARGET = testTreeAVL

all : $(TARGET) 

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(INC)

main.o:main.c
	$(CC) $(CFLAGS) -c main.c $(INC)

tree_avl.o:tree_avl.c
	$(CC) $(CFLAGS) -c tree_avl.c $(INC)

queue.o:queue.c
	$(CC) $(CFLAGS) -c queue.c $(INC)

clean:
	rm -f $(OBJECTS) $(TARGET)

run:
	./$(TARGET)


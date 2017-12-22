.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
CC = gcc
CFLAGS = -O2 -Wall $(DEBUG)
OBJECTS = main.o binary_search_tree.o stack.o
TARGET = testBinarySearchTree

all : $(TARGET) 


$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(INC)

main.o:main.c
	$(CC) $(CFLAGS) -c main.c $(INC)

binary_search_tree.o:binary_search_tree.c
	$(CC) $(CFLAGS) -c binary_search_tree.c $(INC)

stack.o:stack.c
	$(CC) $(CFLAGS) -c stack.c $(INC)

clean:
	rm -f $(OBJECTS) $(TARGET)

run:
	./$(TARGET)


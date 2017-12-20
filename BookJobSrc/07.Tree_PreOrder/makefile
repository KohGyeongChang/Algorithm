.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
CC = gcc
CFLAGS = -O2 -Wall $(DEBUG)
OBJECTS = main.o binarytree_preorder.o stack.o
TARGET = testTreePreOrder

all : $(TARGET) 


$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(INC)

main.o:main.c
	$(CC) $(CFLAGS) -c main.c $(INC)

binarytree_preorder.o:binarytree_preorder.c
	$(CC) $(CFLAGS) -c binarytree_preorder.c $(INC)

stack.o:stack.c
	$(CC) $(CFLAGS) -c stack.c $(INC)

clean:
	rm -f $(OBJECTS) $(TARGET)

run:
	./$(TARGET)


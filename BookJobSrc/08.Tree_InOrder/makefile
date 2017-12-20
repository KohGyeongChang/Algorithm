.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
CC = gcc
CFLAGS = -O2 -Wall $(DEBUG)
OBJECTS = main.o binarytree_inorder.o stack.o
TARGET = testTreePreOrder

all : $(TARGET) 


$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(INC)

main.o:main.c
	$(CC) $(CFLAGS) -c main.c $(INC)

binarytree_inorder.o:binarytree_inorder.c
	$(CC) $(CFLAGS) -c binarytree_inorder.c $(INC)

stack.o:stack.c
	$(CC) $(CFLAGS) -c stack.c $(INC)

clean:
	rm -f $(OBJECTS) $(TARGET)

run:
	./$(TARGET)


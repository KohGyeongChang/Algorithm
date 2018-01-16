.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
CC = gcc
CFLAGS = -O2 -Wall $(DEBUG)
OBJECTS = main.o binarytree_postorder.o stack.o
TARGET = testTreePreOrder

all : $(TARGET) 


$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(INC)

main.o:main.c
	$(CC) $(CFLAGS) -c main.c $(INC)

binarytree_postorder.o:binarytree_postorder.c
	$(CC) $(CFLAGS) -c binarytree_postorder.c $(INC)

stack.o:stack.c
	$(CC) $(CFLAGS) -c stack.c $(INC)

clean:
	rm -f $(OBJECTS) $(TARGET)

run:
	./$(TARGET)


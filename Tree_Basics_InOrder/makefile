.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
GCC = gcc
CFLAGS = -O2 -Wall $(DEBUG)
OBJECTS = main.o 
TARGET = testTreeInOrder
INC = -L./lib -lBCtreeinorder -lBCtreestack

all : TreeStackLib TreeInOrderLib $(TARGET) 

TreeStackLib :
	cd ./lib;$(MAKE) -f makefile_stack

TreeInOrderLib :
	cd ./lib;$(MAKE)

$(TARGET): $(OBJECTS)
	$(GCC) -o $(TARGET) $(OBJECTS) $(INC)

main.o:main.c
	$(GCC) $(CFLAGS) -c main.c $(INC)

clean:
	cd ./lib;$(MAKE) clean
	cd ./lib;$(MAKE) -f makefile_stack clean
	rm -f $(OBJECTS) $(TARGET)

run:
	./$(TARGET)


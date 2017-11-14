.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
GCC = gcc
CFLAGS = -O2 -Wall $(DEBUG)
OBJECTS = main.o 
TARGET = testTreePreOrder
INC = -L./lib -lBCtreepreorder -lBCtreestack

all : TreeStackLib TreePreOrderLib $(TARGET) 

TreeStackLib :
	cd ./lib;$(MAKE) -f makefile_stack

TreePreOrderLib :
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


.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
GCC = gcc
CFLAGS = -O2 -Wall $(DEBUG)
OBJECTS = main.o 
TARGET = testTreePreOrder
INC = -L./lib -lBCtreepreorder -L../Tree_CommLib/Stack -lBCtreestack

all : TreeStackLib TreePreOrderLib $(TARGET) 

TreeStackLib :
	cd ../Tree_CommLib/Stack;$(MAKE) 

TreePreOrderLib :
	cd ./lib;$(MAKE)

$(TARGET): $(OBJECTS)
	$(GCC) -o $(TARGET) $(OBJECTS) $(INC)

main.o:main.c
	$(GCC) $(CFLAGS) -c main.c $(INC)

clean:
	cd ./lib;$(MAKE) clean
	cd ../Tree_CommLib/Stack;$(MAKE) clean
	rm -f $(OBJECTS) $(TARGET)

run:
	./$(TARGET)


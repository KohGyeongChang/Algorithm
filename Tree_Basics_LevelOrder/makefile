.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
GCC = gcc
CFLAGS = -O2 -Wall $(DEBUG)
OBJECTS = main.o 
TARGET = testTreeLevelOrder
INC = -L./lib -lBCtreelevelorder -L../Tree_CommLib/Queue -lBCtreequeue

all : TreeQueueLib TreeLevelOrderLib $(TARGET) 

TreeQueueLib :
	cd ../Tree_CommLib/Queue;$(MAKE) 

TreeLevelOrderLib :
	cd ./lib;$(MAKE)

$(TARGET): $(OBJECTS)
	$(GCC) -o $(TARGET) $(OBJECTS) $(INC)

main.o:main.c
	$(GCC) $(CFLAGS) -c main.c $(INC)

clean:
	cd ./lib;$(MAKE) clean
	cd ../Tree_CommLib/Queue;$(MAKE) clean
	rm -f $(OBJECTS) $(TARGET)

run:
	./$(TARGET)


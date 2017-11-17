.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
GCC = gcc
CFLAGS = -O2 -Wall $(DEBUG)
OBJECTS = main.o 
TARGET = testTreeAVLRR
INC = -L./lib -lBCtreeavlrr -L../Tree_CommLib/Queue -lBCtreequeue

all : TreeQueueLib TreeAVLRRLib $(TARGET) 

TreeQueueLib :
	cd ../Tree_CommLib/Queue;$(MAKE) 

TreeAVLRRLib :
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


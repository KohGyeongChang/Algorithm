.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
CC = gcc
CFLAGS = -fPIC -O2 -Wall $(DEBUG)
OBJECTS = tree_levelorder.o
AR = ar
ARFLAGS = rc
INC = -L../../Tree_CommLib/Queue -lBCtreequeue
TARGET = libBCtreelevelorder.a


$(TARGET): $(OBJECTS)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJECTS) 

tree_levelorder.o:tree_levelorder.c
	$(CC) $(CFLAGS) -c tree_levelorder.c $(INC)

clean:
	rm -f $(OBJECTS) $(TARGET)


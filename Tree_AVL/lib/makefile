.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
GCC = gcc
CFLAGS = -fPIC -O2 -Wall $(DEBUG)
OBJECTS = tree_avl.o
AR = ar
ARFLAGS = rc
INC = -L../../Tree_CommLib/Queue -lBCtreequeue
TARGET = libBCtreeavl.a


$(TARGET): $(OBJECTS)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJECTS) 

tree_avl.o:tree_avl.c
	$(GCC) $(CFLAGS) -c tree_avl.c $(INC)

clean:
	rm -f $(OBJECTS) $(TARGET)


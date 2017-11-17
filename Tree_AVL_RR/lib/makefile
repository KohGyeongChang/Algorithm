.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
GCC = gcc
CFLAGS = -fPIC -O2 -Wall $(DEBUG)
OBJECTS = tree_avl_rr.o
AR = ar
ARFLAGS = rc
INC = -L../../Tree_CommLib/Queue -lBCtreequeue
TARGET = libBCtreeavlrr.a


$(TARGET): $(OBJECTS)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJECTS) 

tree_avl_rr.o:tree_avl_rr.c
	$(GCC) $(CFLAGS) -c tree_avl_rr.c $(INC)

clean:
	rm -f $(OBJECTS) $(TARGET)


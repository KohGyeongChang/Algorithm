.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
GCC = gcc
CFLAGS = -fPIC -O2 -Wall $(DEBUG)
OBJECTS = tree_preorder.o
AR = ar
ARFLAGS = rc
INC = -L../../Tree_CommLib/Stack -lBCtreestack
TARGET = libBCtreepreorder.a


$(TARGET): $(OBJECTS)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJECTS) 

tree_preorder.o:tree_preorder.c
	$(GCC) $(CFLAGS) -c tree_preorder.c $(INC)

clean:
	rm -f $(OBJECTS) $(TARGET)


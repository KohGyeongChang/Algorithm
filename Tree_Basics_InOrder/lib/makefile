.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
GCC = gcc
CFLAGS = -fPIC -O2 -Wall $(DEBUG)
OBJECTS = tree_inorder.o
AR = ar
ARFLAGS = rc
INC = -L./ -lBCtreestack
TARGET = libBCtreeinorder.a


$(TARGET): $(OBJECTS)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJECTS) 

tree_inorder.o:tree_inorder.c
	$(GCC) $(CFLAGS) -c tree_inorder.c $(INC)

clean:
	rm -f $(OBJECTS) $(TARGET)


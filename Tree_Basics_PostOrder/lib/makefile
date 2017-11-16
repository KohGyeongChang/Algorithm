.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
GCC = gcc
CFLAGS = -fPIC -O2 -Wall $(DEBUG)
OBJECTS = tree_postorder.o
AR = ar
ARFLAGS = rc
INC = -L../../Tree_CommLib/Stack -lBCtreestack
TARGET = libBCtreepostorder.a


$(TARGET): $(OBJECTS)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJECTS) 

tree_postorder.o:tree_postorder.c
	$(GCC) $(CFLAGS) -c tree_postorder.c $(INC)

clean:
	rm -f $(OBJECTS) $(TARGET)


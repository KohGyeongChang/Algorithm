.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
GCC = gcc
CFLAGS = -fPIC -O2 -Wall $(DEBUG)
OBJECTS = stack.o
AR = ar
ARFLAGS = rc
TARGET = libBCstack.a


$(TARGET): $(OBJECTS)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJECTS) 

stack.o:stack.c
	$(GCC) $(CFLAGS) -c stack.c

clean:
	rm -f $(OBJECTS) $(TARGET)


.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
GCC = gcc
CFLAGS = -fPIC -O2 -Wall $(DEBUG)
OBJECTS = queue.o
AR = ar
ARFLAGS = rc
TARGET = libBCqueue.a

$(TARGET): $(OBJECTS)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJECTS)

queue.o:queue.c
	$(GCC) $(CFLAGS) -c queue.c


clean:
	rm -f $(OBJECTS) $(TARGET)


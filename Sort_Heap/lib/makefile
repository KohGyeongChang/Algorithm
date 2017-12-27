.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
CC = gcc
CFLAGS = -fPIC -O2 -Wall $(DEBUG)
OBJECTS = heapSort.o
AR = ar
ARFLAGS = rc
TARGET = libBCsortheap.a

$(TARGET): $(OBJECTS)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJECTS) 

heapSort.o:heapSort.c
	$(CC) $(CFLAGS) -c heapSort.c

clean:
	rm -f $(OBJECTS) $(TARGET)


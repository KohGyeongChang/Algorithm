.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
CC = gcc
CFLAGS = -fPIC -O2 -Wall $(DEBUG)
OBJECTS = mergeSort.o
AR = ar
ARFLAGS = rc
TARGET = libBCsortmerge.a

$(TARGET): $(OBJECTS)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJECTS) 

mergeSort.o:mergeSort.c
	$(CC) $(CFLAGS) -c mergeSort.c

clean:
	rm -f $(OBJECTS) $(TARGET)


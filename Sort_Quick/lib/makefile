.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
CC = gcc
CFLAGS = -fPIC -O2 -Wall $(DEBUG)
OBJECTS = quickSort.o
AR = ar
ARFLAGS = rc
TARGET = libBCsortquick.a

$(TARGET): $(OBJECTS)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJECTS) 

quickSort.o:quickSort.c
	$(CC) $(CFLAGS) -c quickSort.c

clean:
	rm -f $(OBJECTS) $(TARGET)


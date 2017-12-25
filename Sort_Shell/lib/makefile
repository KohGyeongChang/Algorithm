.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
CC = gcc
CFLAGS = -fPIC -O2 -Wall $(DEBUG)
OBJECTS = shellSort.o
AR = ar
ARFLAGS = rc
TARGET = libBCsortshell.a

$(TARGET): $(OBJECTS)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJECTS) 

shellSort.o:shellSort.c
	$(CC) $(CFLAGS) -c shellSort.c

clean:
	rm -f $(OBJECTS) $(TARGET)


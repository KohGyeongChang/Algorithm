.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
CC = gcc
CFLAGS = -fPIC -O2 -Wall $(DEBUG)
OBJECTS = hash.o
AR = ar
ARFLAGS = rc
TARGET = libBChash.a

$(TARGET): $(OBJECTS)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJECTS) 

hash.o:hash.c
	$(CC) $(CFLAGS) -c hash.c

clean:
	rm -f $(OBJECTS) $(TARGET)


.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
CC = gcc
CFLAGS = -fPIC -O2 -Wall $(DEBUG)
OBJECTS = arrayList.o
AR = ar
ARFLAGS = rc
TARGET = libBCarraylist.a

$(TARGET): $(OBJECTS)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJECTS) 

arrayList.o:arrayList.c
	$(CC) $(CFLAGS) -c arrayList.c

clean:
	rm -f $(OBJECTS) $(TARGET)


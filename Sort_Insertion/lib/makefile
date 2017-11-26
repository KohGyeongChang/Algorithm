.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
GCC = gcc
CFLAGS = -fPIC -O2 -Wall $(DEBUG)
OBJECTS = insertionSort.o
AR = ar
ARFLAGS = rc
TARGET = libBCsortinsertion.a

$(TARGET): $(OBJECTS)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJECTS) 

insertionSort.o:insertionSort.c
	$(GCC) $(CFLAGS) -c insertionSort.c

clean:
	rm -f $(OBJECTS) $(TARGET)


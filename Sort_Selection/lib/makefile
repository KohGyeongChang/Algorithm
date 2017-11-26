.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
GCC = gcc
CFLAGS = -fPIC -O2 -Wall $(DEBUG)
OBJECTS = selectionSort.o
AR = ar
ARFLAGS = rc
TARGET = libBCsortselection.a

$(TARGET): $(OBJECTS)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJECTS) 

selectionSort.o:selectionSort.c
	$(GCC) $(CFLAGS) -c selectionSort.c

clean:
	rm -f $(OBJECTS) $(TARGET)


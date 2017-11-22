.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
GCC = gcc
CFLAGS = -fPIC -O2 -Wall $(DEBUG)
OBJECTS = generalList.o
AR = ar
ARFLAGS = rc
TARGET = libBCgeneralList.a


$(TARGET): $(OBJECTS)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJECTS) 

generalList.o:generalList.c
	$(GCC) $(CFLAGS) -c generalList.c

clean:
	rm -f $(OBJECTS) $(TARGET)


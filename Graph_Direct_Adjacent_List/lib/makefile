.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
GCC = gcc
CFLAGS = -fPIC -O2 -Wall $(DEBUG)
OBJECTS = graph_directed_al.o
AR = ar
ARFLAGS = rc
TARGET = libBCgraphdal.a


$(TARGET): $(OBJECTS)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJECTS) 

graph_directed_al.o:graph_directed_al.c
	$(GCC) $(CFLAGS) -c graph_directed_al.c

clean:
	rm -f $(OBJECTS) $(TARGET)


.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
GCC = gcc
CFLAGS = -fPIC -O2 -Wall $(DEBUG)
OBJECTS = graph_directed_am.o
AR = ar
ARFLAGS = rc
TARGET = libBCgraphdam.a


$(TARGET): $(OBJECTS)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJECTS) 

graph_directed_am.o:graph_directed_am.c
	$(GCC) $(CFLAGS) -c graph_directed_am.c

clean:
	rm -f $(OBJECTS) $(TARGET)


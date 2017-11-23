.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
CC = gcc
CFLAGS = -fPIC -O2 -Wall $(DEBUG)
OBJECTS = graph_directed_al.o
AR = ar
ARFLAGS = rc
LIBS = -L../../GeneralList/lib -lBCgeneralList
TARGET = libBCgraphdal.a

$(TARGET): $(OBJECTS)
	$(AR) $(ARFLAGS) $(TARGET) $(OBJECTS) 

graph_directed_al.o:graph_directed_al.c
	$(CC) $(CFLAGS) -c graph_directed_al.c $(LIBS)

clean:
	rm -f $(OBJECTS) $(TARGET)


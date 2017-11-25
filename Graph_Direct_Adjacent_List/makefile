.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
CC = gcc
CFLAGS = -O2 -Wall $(DEBUG)
OBJECTS = main.o 
TARGET = testGDAL
LIBS = -L./lib -lBCgraphdal -L../Graph_CommLib -lBCgeneralList

all : GeneralListLIB GraphDALLib $(TARGET) 

GeneralListLIB:
	cd ../Graph_CommLib;$(MAKE)

GraphDALLib: 
	cd ./lib;$(MAKE)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(LIBS)

main.o:main.c
	$(CC) $(CFLAGS) -c main.c $(LIBS)

clean:
	cd ../Graph_CommLib;$(MAKE) clean
	cd ./lib;$(MAKE) clean
	rm -f $(OBJECTS) $(TARGET)

run:
	./$(TARGET)


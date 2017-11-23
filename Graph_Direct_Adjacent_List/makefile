.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
CC = gcc
CFLAGS = -O2 -Wall $(DEBUG)
OBJECTS = main.o 
TARGET = testGDAL
LIBS = -L./lib -lBCgraphdal 

all : GeneralListLIB GraphDALLib $(TARGET) 

GeneralListLIB:
	cd ../GeneralList/lib;$(MAKE)

GraphDALLib: 
	cd ./lib;$(MAKE)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(LIBS)

main.o:main.c
	$(CC) $(CFLAGS) -c main.c $(LIBS)

clean:
	cd ../GeneralList/lib;$(MAKE) clean
	cd ./lib;$(MAKE) clean
	rm -f $(OBJECTS) $(TARGET)

run:
	./$(TARGET)


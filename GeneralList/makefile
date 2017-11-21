.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
GCC = gcc
CFLAGS = -O2 -Wall $(DEBUG)
OBJECTS = main.o 
TARGET = testGeneralList
INC = 
LIBS = -L./lib -lBCgeneralList

all : GeneralListLIB $(TARGET)

GeneralListLIB:
	cd ./lib;$(MAKE)

$(TARGET): $(OBJECTS)
	$(GCC) $(OBJECTS) -o $(TARGET) $(LIBS)

main.o:main.c
	$(GCC) $(CFLAGS) -c main.c $(LIBS)

clean:
	cd ./lib;$(MAKE) clean
	rm -f *.o $(TARGET)

run:
	./$(TARGET)


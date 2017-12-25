.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
CC = gcc
CFLAGS = -O2 -Wall $(DEBUG)
OBJECTS = main.o 
TARGET = testSortShell
INC = -L./lib -lBCsortshell

all : SortShellLib $(TARGET) 

SortShellLib : 
	cd ./lib;$(MAKE)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(INC)

main.o:main.c
	$(CC) $(CFLAGS) -c main.c $(INC)

clean:
	cd ./lib;$(MAKE) clean
	rm -f $(OBJECTS) $(TARGET)

run:
	./$(TARGET)


.SUFFIXES = .c .o
DEBUG = -g -DDEBUGINFO
GCC = gcc
CFLAGS = -O2 -Wall $(DEBUG)
OBJECTS = main.o selectionSort.o
TARGET = testSortSelection

all : $(TARGET) 

$(TARGET): $(OBJECTS)
	$(GCC) -o $(TARGET) $(OBJECTS) 

main.o:main.c
	$(GCC) $(CFLAGS) -c main.c 

selectionSort.o:selectionSort.c
	$(GCC) $(CFLAGS) -c selectionSort.c 

clean:
	rm -f $(OBJECTS) $(TARGET)

run:
	./$(TARGET)


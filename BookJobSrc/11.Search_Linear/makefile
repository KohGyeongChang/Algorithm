DEBUG = -g -DDEBUGINFO
CC = gcc
CFLAGS = -O2 -Wall $(DEBUG)
OBJECTS = main.o search_linear.o
TARGET = testSearchLinear

all : $(TARGET)

main.o:main.c
	$(CC) $(CFLAGS) -c main.c

search_linear.o:search_linear.c
	$(CC) $(CFLAGS) -c search_linear.c

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

clean:
	rm -f *.o $(TARGET)

run:
	./$(TARGET)


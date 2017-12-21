DEBUG = -g -DDEBUGINFO
CC = gcc
CFLAGS = -O2 -Wall $(DEBUG)
OBJECTS = main.o search_binary.o
EXE = testSearchBinary

all : $(EXE)

main.o:main.c
	$(CC) $(CFLAGS) -c main.c

search_binary.o:search_binary.c
	$(CC) $(CFLAGS) -c search_binary.c

$(EXE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXE) 

clean:
	rm -f *.o $(EXE) 

run:
	./$(EXE)


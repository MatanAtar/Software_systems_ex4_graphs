CC=gcc
AR=ar
FLAGS= -Wall -g 
OBJECTS_MAIN=main.o

all: graph

graph: $(OBJECTS_MAIN) 
	$(CC) $(FLAGS) -o graph $(OBJECTS_MAIN) 

main.o: main.c  graphs.h
	$(CC) $(FLAGS) -c main.c 


.PHONY: clean all

clean:
	rm -f *.o *.a *.so graph



CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB=my_mat.o
FLAGS= -Wall -g

all:  fwmymat.a  connections	
connections: $(OBJECTS_MAIN) fwmymat.a 
	$(CC) $(FLAGS) -o connections $(OBJECTS_MAIN) fwmymat.a
fwmymat.a: $(OBJECTS_LIB)
	$(AR) -rcs fwmymat.a $(OBJECTS_LIB)	
my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -o my_mat.o my_mat.c
main.o: main.c my_mat.h  
	$(CC) $(FLAGS) -o main.o main.c 

.PHONY: clean all

clean:
	rm -f *.o *.a *.so connections

CC=gcc
AR=ar -rcs
OBJECTS_MAIN=main.o
OBJECTS_MY_MAT=my_mat.o
FLAGS= -Wall -g

all: connections mymatso mymata
mymatso = my_mat.so
mymata = my_mat.a
connections: $(OBJECTS_MAIN) my_mat.a
	$(CC) $(FLAGS) -o connections $(OBJECTS_MAIN) my_mat.a
mymatso: $(OBJECTS_MY_MAT)
	$(CC) -shared -o mymatso $(OBJECTS_MY_MAT)
mymata: $(OBJECTS_MY_MAT)
	$(AR) mymata $(OBJECTS_MY_MAT)
my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c
main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm -f *.o *.a *.so *.txt mymatso mymata connections

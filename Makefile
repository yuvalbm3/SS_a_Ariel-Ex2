CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_MY_MAT=my_mat.o
FLAGS= -Wall -g

all: my_mat.so my_mat.a progmains 
progmains: $(OBJECTS_MAIN) my_mat.a
	$(CC) $(FLAGS) -o progmains $(OBJECTS_MAIN) my_mat.a
my_mat.so: $(OBJECTS_MY_MAT)
	$(CC) -shared -o my_mat.so $(OBJECTS_MY_MAT)
my_mat.a: $(OBJECTS_MY_MAT)
	$(AR) my_mat.a $(OBJECTS_MY_MAT)
my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c
main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm -f *.o *.a *.so progmains progmaind

CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_MY_MAT=my_mat.o
FLAGS= -Wall -g

all: my_mat.so my_mat.a progmains progmaind
progmains: $(OBJECTS_MAIN) my_mat.a
	$(CC) $(FLAGS) -o progmains $(OBJECTS_MAIN) my_mat.a
progmaind: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o progmaind $(OBJECTS_MAIN) ./my_mat.so
my_mat.so: $(OBJECTS_LIB)
	$(CC) -shared -o my_mat.so $(OBJECTS_MY_MAT)
my_mat.a: $(OBJECTS_LIB)
	$(AR) -rcs my_mat.a $(OBJECTS_MY_MAT)
my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c
main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm -f *.o *.a *.so progmains progmaind

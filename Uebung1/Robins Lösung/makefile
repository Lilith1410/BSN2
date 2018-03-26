G_ARGS = --debug -ansi -pedantic-errors -Wall

all: file1.o file2.o testprog

libmy_library.a: file1.o file2.o
	ar rcs libmy_library.a file1.o file2.o

libmy_dinamic_library.so.1.0: file1.o file2.o
	gcc -shared -Wl,-soname,libmy_dinamic_library.so.1 -o libmy_dinamic_library.so.1.0 file1.o file2.o -lc

testprog: testprog.c libmy_library.a
	gcc $(G_ARGS) -o testprog testprog.c -L. -l my_library

file1.o: file1.c file1.h
	gcc $(G_ARGS) -c file1.c

file2.o: file2.c file2.h
	gcc $(G_ARGS) -c file2.c

clean:
	rm -f file1.o file2.o testprog libmy_library.a
# mit -f sag ich rm dass er die nicht existierenden ignorieren soll #

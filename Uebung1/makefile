GCC_ARGS = --debug -ansi -pedantic-errors -Wall

prog: main.o file1.o file2.o
	gcc $(GCC_ARGS) -o prog main.o file1.o file2.o

#direkte Übernahme aus Robins Lösung#

all: file1.o file2.o main

#Exkurs: static library erstellen mit $ar rcs library_name.a file.o [weitere .o-Dateien] # 
my_library.a: file1.o file2.o
	ar rcs my_library.a file1.o file2.o 
# automatisiertes erstellen der static library, welche abhängig ist von file1.o und file2.o # 


main: main.c my_library.a 
	gcc $(GCC_ARGS) -o main main.c -L. -l my_library.
#Zusammenfassung: Programm main ist abhängig von main.c (Source Code inkl. main) und der Library, die #
#aus file1.o und file2.o besteht. -l steht für load und lädt die library ein. -L. steht für ? # 

main.o: main.c file1.h file2.h
	gcc $(GCC_ARGS) -c main.c

file1.o: file1.c file1.h 
	gcc $(GCC_ARGS) -c file1.c

file2.o: file2.c file2.h 
	gcc $(GCC_ARGS) -c file2.c

clean: 
	rm -f prog file1.o file2.o main.o 
# -f sagt rm, dass er nicht existierenden files ignorieren soll # 

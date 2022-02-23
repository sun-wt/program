all: hw0101.o func0101.c 
	gcc func0101.c hw0101.o -o hw0101

hw0101: hw0101.c
	gcc -c hw0101.c -o hw0101.o 
	gcc -shared hw0101.o -o libhw0101.so

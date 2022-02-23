all: hw0101.o func0101.c hw0102.o func0102.c 
	gcc func0101.c hw0101.o -o hw0101
	gcc func0102.c hw0102.o -o hw0102

hw0101: hw0101.c
	gcc -c hw0101.c -o hw0101.o 
	gcc -shared hw0101.o -o libhw0101.so

hw0102: hw0102.c
	gcc -c hw0102.c -o hw0102.o 
	gcc -shared hw0102.o -o libhw0102.so
all: hw0101.o func0101.c hw0102.o func0102.c hw0103.o func0103.c hw0104.o func0104.c 
	gcc func0101.c hw0101.o -o hw0101
	gcc func0102.c hw0102.o -o hw0102
	gcc func0103.c hw0103.o -o hw0103 -lm
	gcc func0104.c hw0104.o -o hw0104 -lm

hw0101: hw0101.c
	gcc -c hw0101.c -o hw0101.o 
	gcc -shared hw0101.o -o libhw0101.so

hw0102: hw0102.c
	gcc -c hw0102.c -o hw0102.o 
	gcc -shared hw0102.o -o libhw0102.so

hw0103: hw0103.c
	gcc -c hw0103.c -o hw0103.o -lm
	gcc -shared hw0103.o -o libhw0103.so

hw0104: hw0104.c
	gcc -c hw0104.c -o hw0104.o -lm
	gcc -shared hw0104.o -o libhw0104.so
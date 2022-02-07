CFLAGS = -O3 -Wall
INCLUDE = -I curl-7.63.0/include
LIB = -L curl-7.63.0/lib/.libs/

all: hw0501.o hw0502.o hw0503.o test-1.o
	gcc hw0501.o -o hw0501 -lm
	gcc hw0502.o -o hw0502 
	gcc ${CFLAGS} ${INCLUDE} ${LIB} hw0503.c -o hw0503 -lcurl -lm
	

hw0501: hw0501.c
	gcc -c hw0501.c -o hw0501.o -lm
	gcc -shared hw0501.o -o libhw0501.so

hw0502: hw0502.c
	gcc -c hw0502.c -o hw0502.o -lm
	gcc -shared hw0502.o -o libhw0502.so

hw0503: hw0503.c
	gcc -g -fPIC -c hw0503.c
	gcc -shared hw0503.o -o libfoo.so


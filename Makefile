CC=clang++
CFLAGS=-Iinclude -g3 -Wall -Wextra -Wconversion -Wdouble-promotion -Wno-unused-parameter -Wno-unused-function -Wno-sign-conversion 
LDFLAGS=-Llib -lraylib -lm -lpthread -ldl -lrt -lX11

all: two

two: main.o
	$(CC) -o two main.o $(LDFLAGS)

main.o: src/main.cpp
	$(CC) -c src/main.cpp $(CFLAGS)

clean:
	rm -f *.o *~ app_name

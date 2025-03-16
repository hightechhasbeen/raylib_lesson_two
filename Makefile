CC=clang++
CFLAGS=-Iinclude -g3 -Wall -Wextra -Wconversion -Wdouble-promotion -Wno-unused-parameter -Wno-unused-function -Wno-sign-conversion 
LDFLAGS=-Llib -lraylib -lm -lpthread -ldl -lrt -lX11

all: app_name

app_name: main.o
	$(CC) -o app_name main.o $(LDFLAGS)

main.o: src/main.cpp
	$(CC) -c src/main.cpp $(CFLAGS)

clean:
	rm -f *.o *~ app_name

all: bounce

bounce: bounce.cpp
	g++ bounce.cpp -Wall -o pong

clean:
	rm -f *.o

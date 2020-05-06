all: bounce titles kbhit

bounce: bounce.cpp
	g++ bounce.cpp -Wall -o pong

titles: titles.cpp
	g++ titles.cpp -Wall -o titles

kbhit: kbhit_test.cpp
	g++ kbhit_test.cpp -Wall -o kb

clean:
	rm -f *.o

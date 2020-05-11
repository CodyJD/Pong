all: bounce titles
# invisible
# nonblock
# kbhit

bounce: bounce.cpp titles.cpp
	g++ bounce.cpp -Wall -o pong

titles: titles.cpp
	g++ titles.cpp -Wall -o titles

# kbhit: kbhit_test.cpp
# 	g++ kbhit_test.cpp -Wall -o kb

# invisible: invisible_test.cpp
# 	g++ invisible_test.cpp -Wall -o invi

# nonblock: nonblock.cpp
# 	g++ nonblock.cpp -Wall -o nb

clean:
	rm -f *.o

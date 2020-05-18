all: pong

SOURCE = bounce.cpp titles.cpp
HEADER = titles.h

pong: $(SOURCE) $(HEADER)
	g++ $(SOURCE) -Wall -o pong

clean:
	rm -f *.o

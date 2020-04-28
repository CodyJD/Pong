all: collision lineline orbit

collision: collision.cpp
	g++ collision.cpp -Wall -o collision -lX11 -lXext -lm

lineline: lineline.cpp
	g++ lineline.cpp -Wall -o lineline -lX11 -lXext -lm

orbit: orbit.cpp
	g++ orbit.cpp -Wall -o orbit -lX11 -lXext -lm

clean:
	rm -f collision lineline orbit

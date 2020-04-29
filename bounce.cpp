//Author: Cody Davis && Angela Tante
//description: We are making a pong game based in C++
//that will be converted to local online using Client
//Server lab and the concepts of creating a game we have
//learned from CMPS 4490.
#include <iostream>
#include <unistd.h>
using namespace std;
const int W = 80;
const int H = 20;

class Ball {
public:
  double pos[2];
  double vel[2];

  Ball () {
    pos[0]=W/2;
    pos[1]= H/2;
    vel[0]= vel[1]=0;
  }
};

class Paddle {
public:
  double pos[2];

  Paddle () {
    pos[0]= W;
    pos[1]= H/2;
  }
};

void calculateDir(int W, Ball &b) {
  b.pos[0] += b.vel[0];
  b.pos[1] += b.vel[1];

  // b.pos[0] will eventually be changed to add to score rather than
  // just bouncing
  if (b.pos[0] >= W - 2) {
    b.vel[0] = -b.vel[0];
    b.pos[0] = (W-2); //makes the ball bounce away from the right wall
    b.pos[1] += 3;
  }
  if (b.pos[0] < 1) {
    b.pos[0] = 1;
    b.vel[0] = -b.vel[0];
    b.pos[1] -= 8;
  }
  if (b.pos[1] >= (H-1)) {
    b.vel[1] = -b.vel[1];
    b.pos[1] = H - 2;
  }
  if (b.pos[1] < 2) {
    b.vel[1] = -b.vel[1];
    b.pos[1] = -b.pos[1];
  }
}

void show_arr(char arr[][W], int H, int W) {
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cout << arr[i][j];
    }
    cout << endl;
  }
  cout << endl;
}

void make_gameBoard(char arr[][W]) {
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      arr[i][j] = '.';
      if (i == 0 || i == (H-1)) {
        arr[i][j] = '=';
      }
      if (j == 0 || j == (W-1)) {
        arr[i][j] = '|';
      }
      if (j == (W/2)-1 || j == (W/2)) {
        arr[i][j] = '|';
      }
      if ((j == (W/2)-1 || j == (W/2)) && i == 0) {
        arr[i][j-2] = '[';
        arr[i][j-1] = ']';

        arr[i][j-5] = '[';
        arr[i][j-4] = ']';

        arr[i][j-7] = '[';
        arr[i][j-6] = ']';
      }
    }
  }
}

int main(void) {
  char gameBoard[H][W];
  Ball b;
  bool quit = false;


  b.vel[0] = 3.0;
  do {
    make_gameBoard(gameBoard);

    gameBoard[(int)b.pos[1]][(int)b.pos[0]] = '[';
    gameBoard[(int)b.pos[1]][(int)b.pos[0]+1] = ']';

    show_arr(gameBoard,H,W);
    usleep(100000);
    calculateDir(W, b);

  } while (!quit);

  return 0;
}

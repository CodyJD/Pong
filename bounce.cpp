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
  char marker[1] = {'#'};

  Paddle (char side) {
    if (side == 'L') {
      pos[0]= 1;
      pos[1]= H/2;
    }
    if (side == 'R') {
      pos[0]= W - 1;
      pos[1]= H/2;
    }
  }
};


void calculateDir(int W, Ball &b, Paddle &leftPaddle) {
  b.pos[0] += b.vel[0];
  b.pos[1] += b.vel[1];

  // b.pos[0] will eventually be changed to add to score rather than
  // just bouncing
  if (b.pos[0] >= W - 2) {
    b.vel[0] = -b.vel[0];
    b.pos[0] = (W-3); //makes the ball bounce away from the right wall
    // b.pos[1] += 3;
  }
  if ((b.pos[0] < 1) || (leftPaddle.pos[0] + 1 == b.pos[0])) {
    b.pos[0] = 1;
    b.vel[0] = -b.vel[0];
    //b.pos[1] -= 8;
  }
  if (b.pos[1] >= (H-1)) {
    b.vel[1] = -b.vel[1];
    b.pos[1] = H - 2;
  }
  if (b.pos[1] < 2) {
    b.vel[1] = -b.vel[1];
    b.pos[1] = 1;
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
      //fill character for board
      arr[i][j] = '.';

      //border
      if (i == 0 || i == (H-1)) {
          arr[i][j] = '=';

      }
      //the divider left and right of middle
      if (j == 0 || j == (W-1)) {
        arr[i][j] = '|';
      }
      if (j == ((W/2)-1) || j == (W/2)) {
        arr[i][j] = '|';
      }
      ///////scoreboard/////////
      if (j == W - 1 && i == 0) {
        arr[i][j-44] = 'S';
        arr[i][j-43] = 'C';
        arr[i][j-42] = 'O';
        arr[i][j-41] = 'R';
        arr[i][j-40] = 'E';
        arr[i][j-39] = 'B';
        arr[i][j-38] = 'O';
        arr[i][j-37] = 'A';
        arr[i][j-36] = 'R';
        arr[i][j-35] = 'D';
      }
      if (j == W - 1 && i == 1) {
        //left side score board (Left to right on board top to bottom here)
        arr[i][j-50] = '[';
        arr[i][j-49] = ' ';
        arr[i][j-48] = ']';

        arr[i][j-47] = '[';
        arr[i][j-46] = ' ';
        arr[i][j-45] = ']';

        arr[i][j-44] = '[';
        arr[i][j-43] = ' ';
        arr[i][j-42] = ']';
        //right side score scor eb oard
        arr[i][j-37] = '[';
        arr[i][j-36] = ' ';
        arr[i][j-35] = ']';

        arr[i][j-34] = '[';
        arr[i][j-33] = ' ';
        arr[i][j-32] = ']';

        arr[i][j-31] = '[';
        arr[i][j-30] = ' ';
        arr[i][j-29] = ']';
      }
    }
  }
}

int main(void) {
  char gameBoard[H][W];
  Ball b;
  bool quit = false;
  Paddle leftPaddle('L');

  b.vel[0] = 3.0;
  do {
    make_gameBoard(gameBoard);
    //creating ball and drawing in position
    gameBoard[(int)b.pos[1]][(int)b.pos[0]] = '[';
    gameBoard[(int)b.pos[1]][(int)b.pos[0]+1] = ']';
    //crating paddle and drawing in position
    gameBoard[(int)leftPaddle.pos[1]][(int)leftPaddle.pos[0]] = leftPaddle.marker[0];
    gameBoard[(int)leftPaddle.pos[1]+1][(int)leftPaddle.pos[0]] = leftPaddle.marker[0];
    gameBoard[(int)leftPaddle.pos[1]-1][(int)leftPaddle.pos[0]] = leftPaddle.marker[0];

    show_arr(gameBoard,H,W);
    usleep(100000);
    calculateDir(W, b, leftPaddle);

  } while (!quit);

  return 0;
}

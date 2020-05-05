//Author: Cody Davis && Angela Tante
//description: We are making a pong game based in C++
//that will be converted to local online using Client
//Server lab and the concepts of creating a game we have
//learned from CMPS 4490.

//TODO LIST
// [x] fix broken collision system
// Impelment score system
// complete kbhit with keyboard inputs
// start converting to online gameplay



#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <termios.h>

using namespace std;
const int W = 80;
const int H = 20;

int rightCount(0), leftCount(0);
bool rightScore(false), leftScore(false);

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
  char marker[1];

  Paddle (char side) {
    if (side == 'L') {
      marker[0] = ']';
      pos[0]= 1;
      pos[1]= H/2;
    }
    if (side == 'R') {
      marker[0] = '[';
      pos[0]= W - 2;
      pos[1]= H/2+2;
    }
  }
};

void rightPaddleMovement(Paddle &rightPaddle, char &move) {
  move = getchar();
  if(move == 105) {
    rightPaddle.pos[0] += 1;
  }

}

// All positions are based off of the leftmost part of the ball
void collision(int W, Ball &b, Paddle &rightPaddle, Paddle &leftPaddle) {
  b.pos[0] += b.vel[0];
  b.pos[1] += b.vel[1];

  // b.pos[0] will eventually be changed to add to score rather than

  // collides right wall
  if (b.pos[0] >= W - 2) {
    b.pos[0] = (W/2) -1;
    b.pos[1] = H/2;
    b.vel[0] = b.vel[1] = 0;
    //press enter then yeet the ball
  }
  //collides left wall
  if (b.pos[0] < 1) {
    b.pos[0] = (W/2)-1;
    b.pos[1] = H/2;
    b.vel[0] = b.vel[1] = 0;
    // score implementation
    rightScore = true;
    rightCount++;
  }
  //top board colission
  if (b.pos[1] < 1) {
    b.vel[1] = -b.vel[1];
    b.pos[1] += 1;
  }
  //bottom board collision
  if (b.pos[1] >= (H-1)) {
    b.vel[1] = -b.vel[1];
    b.pos[1] = H - 2;
  }
////////paddle collission////////

  // collision with right paddle

  //top of right paddle
  if ((b.pos[0] >= rightPaddle.pos[0] - 1) && ((rightPaddle.pos[1] - 1) == b.pos[1])) {
    b.vel[0] = -b.vel[0];
    b.pos[0] -= 2;
    b.vel[0] = 2;
    b.pos[1] -= 1;
    b.vel[1] = 1;
    b.vel[1] = -b.vel[1];
  }

  // middle of right paddle
  if ((b.pos[0] >= rightPaddle.pos[0] - 1) && (rightPaddle.pos[1] == b.pos[1])) {
    b.vel[0] = -b.vel[0];
    b.pos[0] -= 2;
    b.vel[1] = 0;
  }

  //bottom of right Paddle
  if ((b.pos[0] >= rightPaddle.pos[0] - 1) && ((rightPaddle.pos[1] + 1) >= b.pos[1])) {
    b.vel[0] = -b.vel[0];
    b.pos[0] -= 2;
    b.vel[0] = 2;
    b.pos[1] += 1;
    b.vel[1] = 1;
  }
////////////////////////////////////////////////////////////////////////////////////////
  //collision with left paddle middle
  // top of left paddle colision
  if ((b.pos[0] <= leftPaddle.pos[0]) && ((leftPaddle.pos[1] - 1) == b.pos[1])) {
    b.vel[0] = -b.vel[0];
    b.pos[0] += 2;
    b.vel[0] = 2;
    b.pos[1] -= 1;
    b.vel[1] = 1;
    b.vel[1] = -b.vel[1];
  }
  // middle of left paddle colission
  if ((b.pos[0] <= leftPaddle.pos[0]) && (leftPaddle.pos[1] == b.pos[1])) {
    b.vel[0] = -b.vel[0];
    b.pos[0] += 2;
    b.vel[1] = 0;
  }
  // bottom of left paddle colission
  if ((b.pos[0] <= leftPaddle.pos[0]) && ((leftPaddle.pos[1] + 1) == b.pos[1])) {
    b.vel[0] = -b.vel[0];
    b.pos[0] += 2;
    b.vel[0] = 2;
    b.pos[1] += 1;
    b.vel[1] = 1;
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
      arr[i][j] = ' ';

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
        //right side score scor|eb|oard
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

// void bitch() {
//   struct termios oldt, newt;
//   int ch;
//   int oldf;
//
//   tcgetattr(STDIN_FILENO, &oldt);
//   newt = oldt;
//   newt.c_lflag &= ~(ICANON | ECHO);
//   tcsetattr(STDIN_FILENO, TCSANOW, &newt);
//   oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
//   fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
//
//   ch = getchar();
//
//   tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
//   fcntl(STDIN_FILENO, F_SETFL, oldf);
//
//   if(ch != EOF)
//   {
//       //ungetc(ch, stdin);
//       return 1;
//   }
//
//   return 0;
// }

int main(void) {
  char gameBoard[H][W];
  Ball b;
  bool quit = false;
  Paddle rightPaddle('R'), leftPaddle('L');
  char move;

  b.vel[0] = 1.0;
  do {
    cout << "b.pos[0]: " << b.pos[0] << "   " << "b.vel[0]: " << b.vel[0] << endl;
    cout << "b.pos[1]: " << b.pos[1] << "   " << "b.vel[1]: " << b.vel[1] << endl;
    make_gameBoard(gameBoard);
    //creating ball and drawing in position
    gameBoard[(int)b.pos[1]][(int)b.pos[0]] = '[';
    gameBoard[(int)b.pos[1]][(int)b.pos[0]+1] = ']';


    //rightPaddleMovement(rightPaddle, move);
    //crating paddle and drawing in position
    gameBoard[(int)rightPaddle.pos[1]][(int)rightPaddle.pos[0]] = rightPaddle.marker[0];
    gameBoard[(int)rightPaddle.pos[1]+1][(int)rightPaddle.pos[0]] = rightPaddle.marker[0];
    gameBoard[(int)rightPaddle.pos[1]-1][(int)rightPaddle.pos[0]] = rightPaddle.marker[0];

    gameBoard[(int)leftPaddle.pos[1]][(int)leftPaddle.pos[0]] = leftPaddle.marker[0];
    gameBoard[(int)leftPaddle.pos[1]+1][(int)leftPaddle.pos[0]] = leftPaddle.marker[0];
    gameBoard[(int)leftPaddle.pos[1]-1][(int)leftPaddle.pos[0]] = leftPaddle.marker[0];

    collision(W, b, rightPaddle, leftPaddle);
    /////////score system//////////
    //rightside
    // int rightScored(0);
    // gameBoard[1][30] = 'x';
    // gameBoard[1][33] = 'x';
    // gameBoard[1][36] = 'x';
    if (rightScore) {
      rightScore = false;
      if (rightCount == 1)
        gameBoard[1][49] = 'x';
      if (rightCount == 2)
        gameBoard[1][46] = 'x';
      if (rightCount == 3)
        gameBoard[1][43] = 'x';

      if (rightCount == 3) {
        // Avengers endgame screen
        quit = false;
      }
    }

    //leftside
    if (leftScore) {
      leftScore = false;
      if (leftCount == 1)
        gameBoard[1][30] = 'x';
      if (leftCount == 2)
        gameBoard[1][33] = 'x';
      if (leftCount == 3)
        gameBoard[1][36] = 'x';

      if (leftCount == 3) {
        // Avengers endgame screen
        quit = false;
      }
    }

    show_arr(gameBoard,H,W);
    usleep(100000);

  } while (!quit);
  // } while (!quit || !bitch());

  return 0;
}
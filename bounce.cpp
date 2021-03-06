//Author: Cody Davis && Angela Tante
//description: We are making a pong game based in C++
//that will be converted to local online using Client
//Server lab and the concepts of creating a game we have
//learned from CMPS 4490.

//TODO LIST
// [x] fixed crazy collision maddness
// [x] Impelment score system
// [x] complete kbhit with keyboard inputs
// [x] stop from getting yeeted off screen
// [] start converting to online gameplay

#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <termios.h>
#include <fcntl.h>
#include "titles.h"

using namespace std;

const int W = 80; //gameboard width
const int H = 20; //gamebard height
int rightCount(0), leftCount(0); //varibales for score
bool rightScore(false), leftScore(false); //varibales for score
bool quit = false; //exit status varibale

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
      pos[1]= H/2;
    }
  }
};

// All positions are based off of the leftmost part of the ball
void collision(int W, Ball &b, Paddle &rightPaddle, Paddle &leftPaddle) {
  b.pos[0] += b.vel[0];
  b.pos[1] += b.vel[1];

  //collides right wall
  //hits right wall and also doesnt hit the paddle
  if ((b.pos[0] >= W - 2)) {
    b.pos[0] = (W/2) - 1;
    b.pos[1] = H/2;
    //setting the respawn velocity to only x
    b.vel[0] = 2;
    b.vel[1] = 0; //change this to test score system
    // b.vel[0] = b.vel[1] = 0; //change this to test score system

    //recentering the paddles after score point
    rightPaddle.pos[1] = H / 2;
    leftPaddle.pos[1] = H / 2;
    // score implementation
    leftScore = true;
    leftCount++;
    //press enter then yeet the ball
  }
  //collides left wall
  //if statements are for making sure hits the left wall and doesnt also hit paddle
  if (b.pos[0] < 1) {
    b.pos[0] = (W/2)-1;
    b.pos[1] = H/2;
    //setting the respawn velocity to only x
    b.vel[0] = 2;
    b.vel[1] = 0; //change this to test score system
    // b.vel[0] = b.vel[1] = 0; //change this to test score system

    //recenter paddles after score point
    rightPaddle.pos[1] = H / 2;
    leftPaddle.pos[1] = H / 2;

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
///////////////////////////paddle collission//////////////////////////////
  // collision with right paddle
  //top of right paddle
  if ((b.pos[0] >= rightPaddle.pos[0] - 2) && ((rightPaddle.pos[1] - 1) == b.pos[1])) {
    b.vel[0] = -2;
    b.vel[1] = -1;

  }
  // middle of right paddle
  if ((b.pos[0] >= rightPaddle.pos[0] - 2) && (rightPaddle.pos[1] == b.pos[1])) {
    b.vel[0] = -2;
    b.vel[1] = 0;
  }
  //bottom of right Paddle
  if ((b.pos[0] >= rightPaddle.pos[0] - 2) && ((rightPaddle.pos[1] + 1) == b.pos[1])) {
    b.vel[0] = -2;
    b.vel[1] = 1;
  }
////////////////////////////////////////////////////////////////////////////////////////
  //collision with left paddle middle
  // top of left paddle colision
  if ((b.pos[0] <= leftPaddle.pos[0] + 1) && ((leftPaddle.pos[1] - 1) == b.pos[1])) {
    b.vel[0] = 2;
    b.vel[1] = -1;
  }
  // middle of left paddle colission
  if ((b.pos[0] <= leftPaddle.pos[0] + 1) && (leftPaddle.pos[1] == b.pos[1])) {
    b.vel[0] = 2;
    b.vel[1] = 0;
  }
  // bottom of left paddle colission
  if ((b.pos[0] <= leftPaddle.pos[0] + 1) && ((leftPaddle.pos[1] + 1) == b.pos[1])) {
    b.vel[0] = 2;
    b.vel[1] = 1;
  }
}

void show_arr(char arr[][W], int H, int W)
{
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cout << arr[i][j];
    }
    cout << endl;
  }
  cout << endl;
}

void make_gameBoard(char arr[][W])
{
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

        //score system logic left side
        if (leftCount == 1){
          arr[i][j-49] = 'x';
          leftScore = false;
        } else if(leftCount == 2){
          arr[i][j-49] = 'x';
          arr[i][j-46] = 'x';
          leftScore = false;
        } else if (leftCount == 3) {
          arr[i][j-49] = 'x';
          arr[i][j-46] = 'x';
          arr[i][j-43] = 'x';
          leftScore = false;
          quit = true;
        }
        //score system logic right side
        if (rightCount == 1) {
          arr[i][j-30] = 'x';
          rightScore = false;
        } else if (rightCount == 2) {
          arr[i][j-30] = 'x';
          arr[i][j-33] = 'x';
          rightScore = false;
        } else if (rightCount == 3) {
          arr[i][j-30] = 'x';
          arr[i][j-33] = 'x';
          arr[i][j-36] = 'x';
          rightScore = false;
          quit = true;
        }
      }
    }
  }
}

int check_keys(char key)
{
	if (key == 27){
		// std::cout << " bye bye" << std::endl;
		return 1;
	}
  if (key == 10) {
    printf("You've pressed enter!\n");
  }
	return 0;
}

int menu(char key)
{
  // enter character
  if (key == 10) {
    return 1;
  }
  if (key == 'h') {
    howToPlay();
  }
  if (key == 'b') {
    // back to start screen
    startScreen();
  }
  if (key == 'c') {
    // credit screen
    credits();
  }
  if (key == 'e') {
    endScreen(false, false);
  }

  return 0;
}


void RestoreKeyboardBlocking(struct termios *initial_settings)
{
	tcsetattr(0, TCSANOW, initial_settings);
}

void SetKeyboardNonBlock(struct termios *initial_settings)
{
    struct termios new_settings;
    tcgetattr(0,initial_settings);

    new_settings = *initial_settings;
    new_settings.c_lflag &= ~ICANON;
    new_settings.c_lflag &= ~ECHO;
    new_settings.c_lflag &= ~ISIG;
    new_settings.c_cc[VMIN] = 0;
    new_settings.c_cc[VTIME] = 0;

    tcsetattr(0, TCSANOW, &new_settings);
}

char getcharAlt()
{
    char buff[1];
    int l = read(STDIN_FILENO,buff,1);
    if (l>0) return buff[0];
    return ( EOF);
}

void rightPaddleMovement(Paddle &rightPaddle, char move)
{
  if(move == 'p') {
    if (rightPaddle.pos[1] >= 3) {
      rightPaddle.pos[1]--;
    }
  } else if(move == 'l') {
    if(rightPaddle.pos[1] <= (H - 4)) {
      rightPaddle.pos[1]++;
    }
  }
}

void leftPaddleMovement(Paddle &leftPaddle, char move)
{
  if(move == 'w') {
    if (leftPaddle.pos[1] >= 3) {
      leftPaddle.pos[1]--;
    }
  } else if(move == 's') {
    if (leftPaddle.pos[1] <= (H - 4)) {
      leftPaddle.pos[1]++;
    }
  }
}

int main(void)
{
  char gameBoard[H][W];
  Ball b;
  Paddle rightPaddle('R'), leftPaddle('L');
  char move = 0;
  char key = 0;
  struct termios term_settings;
  b.vel[0] = -2.0; // initial x velocity for start of game

  SetKeyboardNonBlock(&term_settings);

  // call start screen from titles.cpp
  startScreen();
  while (!menu(key)) {
    key = getcharAlt();

    // escape character if player wants to leave completely
    if (key == 27) {
      RestoreKeyboardBlocking(&term_settings);
      return 0;
    }
  }

  //main gameplay loop
  while (!check_keys(move)) {
    // cout << "b.pos[0]: " << b.pos[0] << "   " << "b.vel[0]: " << b.vel[0] << endl;
    // cout << "b.pos[1]: " << b.pos[1] << "   " << "b.vel[1]: " << b.vel[1] << endl;
    make_gameBoard(gameBoard);
    //creating ball and drawing in position
    gameBoard[(int)b.pos[1]][(int)b.pos[0]] = '[';
    gameBoard[(int)b.pos[1]][(int)b.pos[0]+1] = ']';

    //movement controlls for left and right paddle
    move = getcharAlt();
    if (move == 'p' || move == 'l') {
      rightPaddleMovement(rightPaddle, move);
    }
    if (move == 'w' || move == 's'){
      leftPaddleMovement(leftPaddle, move);
    }

    //crating paddle and drawing in position
    gameBoard[(int)rightPaddle.pos[1]][(int)rightPaddle.pos[0]] = rightPaddle.marker[0];
    gameBoard[(int)rightPaddle.pos[1]+1][(int)rightPaddle.pos[0]] = rightPaddle.marker[0];
    gameBoard[(int)rightPaddle.pos[1]-1][(int)rightPaddle.pos[0]] = rightPaddle.marker[0];

    gameBoard[(int)leftPaddle.pos[1]][(int)leftPaddle.pos[0]] = leftPaddle.marker[0];
    gameBoard[(int)leftPaddle.pos[1]+1][(int)leftPaddle.pos[0]] = leftPaddle.marker[0];
    gameBoard[(int)leftPaddle.pos[1]-1][(int)leftPaddle.pos[0]] = leftPaddle.marker[0];

    collision(W, b, rightPaddle, leftPaddle);
    show_arr(gameBoard,H,W);
    cout << "\n\n";
    usleep(100000);

    if (quit == true) {break;}//logic for game winning "quit" is altered in collission near bottom
  }

  if (leftCount == 3) {
    endScreen(true, false);
  } else if (rightCount == 3) {
    endScreen(false, true);
  } else {
    endScreen(false, false);
  }
  
  RestoreKeyboardBlocking(&term_settings);

  return 0;
}

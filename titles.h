#ifndef TITLES_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define TITLES_H

#include <iostream>
#include <unistd.h>


using namespace std;

void startScreen();
void howToPlay();
void credits();
void endScreen(bool leftPlayer, bool rightPlayer);
void clearScreen();

#endif
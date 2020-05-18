#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include <thread>

static bool enable = false;
bool quit = false;

void getsomething(){
  char move = getchar();
  printf("%c\n", move);
}
void echo ()
{
  // printf("you are in echo\n");
  #ifdef WIN32
      HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
      DWORD mode;
      GetConsoleMode(hStdin, &mode);

      if( !enable )
          mode &= ~ENABLE_ECHO_INPUT;
      else
          mode |= ENABLE_ECHO_INPUT;

      SetConsoleMode(hStdin, mode );

  #else
      struct termios tty;
      tcgetattr(STDIN_FILENO, &tty);
      if( !enable )
          tty.c_lflag &= ~ECHO;
      else
          tty.c_lflag |= ECHO;

      (void) tcsetattr(STDIN_FILENO, TCSANOW, &tty);
  #endif
}
void bitch() {
  printf("bitch\n");
}
void check_keys(int key) {
  if (key == 'w')
    bitch();
  if (key == 27) {
    enable = true;
    echo();
    std::exit(0);
    // quit = true;
  }
  if (key == 'p'){
    quit = true;
  }
}
int kbhit()
{
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);

  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if(ch != EOF)
  {
    echo();
    check_keys(ch);
    ungetc(ch, stdin); //erases the char that from stdin

    return 1;
  }

  return 0;
}

int main(void)
{
  std::thread x(bitch);
  std::thread y(getsomething);
  // I'm not sure why this is a thing but there needs to be two
  // while loops that both have !kbhit()
  while(!quit || !kbhit()){
    while(!kbhit()) {
      // puts("Press a key!");
    }
    // fflush(stdin);
    // std::cout << "testing" << std::endl;
    // std::cout << "testing" << std::endl;
    // std::cout << "testing" << std::endl;
    // std::cout << "testing" << std::endl;
    // std::cout << "testing" << std::endl;
    // std::cout << "testing" << std::endl;
    // std::cout << "testing1" << std::endl;
    // printf("You pressed '%c'!\n", getchar());
    x.join();
    y.join();
    // getsomething();
    // uintptr_t x = _beginthread(bitch, 0, NULL);
    // uintptr_t y = _beginthread(getsomething, 0, NULL);

    // usleep(100000);
  }


  return 0;
}
// keylog.cpp
#include <termios.h>
#include <iostream>
#include "keylog.h"
using namespace std;

static struct termios old, current;

// Getting the keyboard input
char keylog(){
  char ch;

  // Initialize new terminal i/o settings
  tcgetattr(0, &old); // Grab old terminal i/o settings
  current = old; // Make new settings same as old settings
  current.c_lflag &= ~ICANON; // Disable buffered i/o
  current.c_lflag &= ~ECHO; // no echo mode
  tcsetattr(0, TCSANOW, &current); // Use new terminal settings TCSANOW

  // Get the key log
  ch = getchar();

  // Restore old terminal i/o settings
  tcsetattr(0, TCSANOW, &old);

  return ch;
}

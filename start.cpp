#include <iostream>
#include <cstdio> //exit
#include <windows.h> // system
#include <unistd.h> //system
#include <conio.h> //getch

using namespace std;


char start_screen[25][37] = {
  "====================================",
  "                                    ",
  "Score:50             Highscore:1340|",
  "|   -           __                 |",
  "| --          ~( @\\   \\            |",
  "|---   _________]_[__/_>________   |",
  "|     /  ____ \\ <>     |  ____  \\  |",
  "|    =\\_/ __ \\_\\_______|_/ __ \\__D |",
  "|________(__)_____________(__)_____|",
  "|                                  |",
  "|        _______________  ___      |",
  "|       / ____/_  __/__ \\|__ \\     |",
  "|      / / __  / /  __/ /__/ /     |",
  "|     / /_/ / / /  / __// __/      |",
  "|     \\____/ /_/  /____/____/      |",
  "|                                  |",
  "|                                  |",
  "|             START                |",
  "|             GARAGE               |",
  "|             INSTRUCTIONS         |",
  "|             EXIT                 |",
  "|                                  |",
  "|     *use up and down arrow*      |",
  "|     *press enter to select*      |",
  "===================================="
};

void clearStar();
void DetectKey(int &option);

int main()
{
  
  // options: 0 = Start, 1 = Car select, 2 = Instruction, 3 = Exit
  int option = 0;
  while(1){
    system("tput clear");
    // Printing out the screen
    for (int i = 0; i < 25; i++){
      cout << start_screen[i] << endl;
    }

    switch(option){
      case(0):
        start_screen[17][10] = '>';
        start_screen[17][11] = '>';
        start_screen[17][12] = '>';
        break;
      case(1):
        start_screen[18][10] = '>';
        start_screen[18][11] = '>';
        start_screen[18][12] = '>';
        break;
      case(2):
        start_screen[18][10] = '>';
        start_screen[18][11] = '>';
        start_screen[18][12] = '>';
        break;
      case(3):
        start_screen[19][10] = '>';
        start_screen[19][11] = '>';
        start_screen[19][12] = '>';
        break;
      default:
        start_screen[17][10] = '>';
        start_screen[17][11] = '>';
        start_screen[17][12] = '>';
        break;
    }
    system("pause>nul");
    // Check which key is being pressed
    if (GetAsyncKeyState(VK_UP)){
      if (option != 0)
        option--;
      clearStar();
    }
    if (GetAsyncKeyState(VK_DOWN)){
      if (option != 3)
        option++;
      clearStar();
    }
  }
  return 0;
}

void clearStar(){
  start_screen[17][10] = ' ';
  start_screen[17][11] = ' ';
  start_screen[17][12] = ' ';

  start_screen[18][10] = ' ';
  start_screen[18][11] = ' ';
  start_screen[18][12] = ' ';

  start_screen[19][10] = ' ';
  start_screen[19][11] = ' ';
  start_screen[19][12] = ' ';

  start_screen[20][10] = ' ';
  start_screen[20][11] = ' ';
  start_screen[20][12] = ' ';
  

void DetectKey(int &option){
  int key;
  key = getch();

  if (key == 72){
    if (option != 0)
      option--;
    clearStar();
  }
  if (key == 80){
    if (option != 3)
      option++;
    clearStar();
  }
}

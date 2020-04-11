// start.cpp
#include <iostream> //cout, cin
#include <fstream> // ifstream, ofstream
#include <string>  // string
#include <vector>  // vector
#include <cstring> // strcpy
#include "../keylog.h" // keylog

using namespace std;

const int ROW = 25;
const int COL = 37;

void ClearArrow(char screen[ROW][COL]);
void PerformAction(int option);

int main(){
  // Opening the start art graphics design .txt file
  ifstream art;
  art.open("./home/startart.txt");
  if (art.fail()){
    cout << "Fail in art opening" << endl;
    exit(1);
  }

  // Outputing the graphics design into the console
  char screen[ROW][COL]; // screen made out of a 25 by 37 character map
  string str;
  int ind = 0;
  // reading from the startart.txt file
  while (getline(art, str)){
    strcpy(screen[ind], str.c_str()); // converting string into a char array
    ind++;
  }

  // Opening the stat file to see highscore and coins.
  ifstream stat;
  stat.open("./home/stat.txt");
  if (stat.fail()){
    cout << "Fail in stat opening" << endl;
    exit(1);
  }
  // Reading the highscore and coins.
  string highscore, coin;
  stat >> highscore >> coin; // Reading from file to the string variables respectively.
  int highscore_size = highscore.size();
  int coin_size = coin.size();
  // Replacing the empty space on the screen with a highscore value
  for (int i = 0; i < highscore_size; i++){
    screen[1][i + 14] = highscore[i];
  }
  // Replacing the empty space on the screen with a coin value
  for (int i = 0; i < coin_size; i++){
    screen[2][i + 8] = coin[i];
  }


  int option = 1;
  // Selecting the options from the start menu.
  // 1: Start playing, 2: Open garage, 3: View Instructions, 4: Reset Progress, 5: Exit game
  while (true){
    system("clear"); //Clearing console screen.
    // Printing the start art
    for (int i = 0; i < 25; i++){
      cout << screen[i] << endl;
    }

    // Detecting keyboard presses
    char key;
    key = keylog();
    switch (key){
      // w button to navigate up
      case 'w':
        if (option != 1)
          option--;
        ClearArrow(screen);
        screen[15+option][11] = '>';
        break;

      // s button to navigate down
      case 's':
        if (option != 5)
          option++;
        ClearArrow(screen);
        screen[15+option][11] = '>';
        break;

      // enter button to perform actions depending on the option.
      case '\n':
        PerformAction(option);
        break;
    }
  }

  char c;
  c = keylog();
  cout << "you output: " << c << endl;

  art.close();
  stat.close();

  return 0;
}

// Function to clear the arrow on the screen by making column 11 a blank space on rows where there are options. The input of this function is the screen art map.
void ClearArrow(char screen[ROW][COL]){
  for (int i = 16; i < 21; i++){
    screen[i][11] = ' ';
  }
}

// Function that performs action depending on the option selected by user. The input of this function is the option that the user selects.
void PerformAction(int option){
  char confirm;
  switch (option){
    // START
    case 1:
    {
      // Start game
      cout << "Start" << endl;
      exit(1);
      break;
    }

    // GARAGE
    case 2:
    {
      // Open garage
      cout << "GARAGE" << endl;
      exit(1);
      break;
    }

    // Instructions
    case 3:
    {
      // Show Instructions here
      cout << "Press q to go back" << endl;
      confirm = keylog();
      while (confirm != 'q'){
        confirm = keylog();
      }
      break;
    }

    // Reset game data
    case 4:
    {
      cout << "Are you sure you want to reset game data? (y/n)" << endl;
      confirm = keylog();
      if (confirm == 'y'){
        // ERASE DATA
        cout << "Erasing!" << endl;
      }
      if (confirm == 'n'){
        break;
      }
      break;
    }

    // EXIT
    case 5:
    {
      cout << "Are you sure you want to exit? (y/n)" << endl;
      confirm = keylog();
      if (confirm == 'y'){
        exit(1);
      }
      if (confirm == 'n'){
        break;
      }
      break;
    }
  }
}

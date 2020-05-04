// start.cpp
#include <iostream> //cout, cin
#include <fstream> // ifstream, ofstream
#include <string>  // string
#include <vector>  // vector
#include <pthread.h> //pthread
#include <vector> // vector
#include "../keylog.h" // keylog
#include "../linkedlist.h" // ListBuild()
#include "../console/console.h" //connect to console.h program; consoleMain()
#include "garage.h" //connect to garage.h program; garageMain()
#include "difficulty.h" //connect to difficulty.h program; difficultyMain()

using namespace std;

// The number of rows and column of the start art graphics.
const int ROW = 26;
const int COL = 36;

// Global Variables
char CARSHAPEtoConsole; //transfer carshape to console
int speed; //transfer starting speed to console
vector<string> screen; // The start screen graphics


// Function protoypes.
void ReadArt(); // Function to read the start screen art. The input is a the screen map
void ReadStat(); // Function to read highscore and coin. This function also updates the screen map which outputs the highscore and coin. The input is the screen map.
void ClearArrow(); // Function to clear the arrow on the screen by making column 11 a blank space on rows where there are options. The input of this function is the screen art map.
void PerformAction(int selected_option); // Function that performs action depending on the option selected by user. The input of this function is the option that the user selects and the screen map.


// ==================================
// === main function of start.cpp ===
int main(){ //originally start(); should have at least one main()
  ReadArt(); // reading from startart.txt

  // Build a linked list to navigate the options on start.
  Node * head = NULL;
  Node * tail = NULL;
  for (int n = 1; n <= 6; n++){
    ListBuild(head, tail, n); // Build a circular doubly linked list
  }

  Node * current_option = head; // The current option that the user is pointing at.
  int selected_option = current_option -> option; // The value of the option from the structure.
  // Selecting the options from the start menu.
  // 1: Start playing, 2: Open garage, 3: View Instructions, 4: Reset Progress, 5: Exit game
  while (true){
    ReadStat(); // Reading highscore and coin and update to screen.
    system("clear"); //Clearing console screen.
    // Printing the start art.
    for (int i = 0; i < ROW; i++){
      cout << screen[i] << endl;
    }

    // Detecting keyboard presses and perform actions.
    char key;
    key = keylog();
    switch (key){
      // w button to navigate up
      case 'w':
      {
        current_option = current_option -> prev; // Navigate 1 option before the current option.
        selected_option = current_option -> option; // Getting the value of the chosen option.
        ClearArrow(); // Clear the arrow
        screen[15+selected_option][11] = '>'; // Move the arrow up
        break;
      }

      // s button to navigate down
      case 's':
      {
        current_option = current_option -> next; // Navigate 1 option after the current option.
        selected_option = current_option -> option; // Getting the value of the chosen option.
        ClearArrow(); // Clear the arrow
        screen[15+selected_option][11] = '>'; // Move the arrow down
        break;
      }
      // enter button to perform actions depending on the option.
      case '\n':
      {
        PerformAction(selected_option);
        break;
      }
    } // end of switch
  } // end of while loop
  return 0;
}
// ====== END of start function =====
// ==================================

// =============================================================================

//===================================
// ============ Functions ===========

// Function to read the start screen art. The input is a the screen map
void ReadArt(){
  // Opening the start art graphics design .txt file
  ifstream art;
  art.open("Desktop/startart.txt"); //originally ./home/startart.txt
  if (art.fail()){
    cout << "Fail in art opening" << endl;
    exit(1);
  }

  // Storing the graphics design into the screen map
  string str;
  // reading from the startart.txt file
  while (getline(art, str)){
    screen.push_back(str);
  }
  art.close();
}

// Function to read highscore and coin. This function also updates the screen map which outputs the highscore and coin. The input is the screen map.
void ReadStat(){
  // Opening the stat file to see highscore and coins.
  ifstream stat;
  stat.open("Desktop/stat.txt"); //originally ./home/stat.txt
  if (stat.fail()){
    cout << "Fail in stat opening" << endl;
    exit(1);
  }
  // Reading the highscore and coins.
  string highscore, coin;
  stat >> highscore >> coin; // Reading from file to the string variables respectively.
  stat.close();
  int highscore_size = highscore.size();
  int coin_size = coin.size();
  // Clearing the space to output the highscore and coin to the screen.
  for (int i = 14; i < COL - 2; i++){
    screen[1][i] = ' ';
  }
  for (int i = 8; i < COL - 2; i++){
    screen[2][i] = ' ';
  }
  // Replacing the empty space on the screen with a highscore value
  for (int i = 0; i < highscore_size; i++){
    screen[1][i + 14] = highscore[i];
  }
  // Replacing the empty space on the screen with a coin value
  for (int i = 0; i < coin_size; i++){
    screen[2][i + 8] = coin[i];
  }
}

// Function to clear the arrow on the screen by making column 11 a blank space on rows where there are options. The input of this function is the screen art map.
void ClearArrow(){
  for (int i = 16; i < 22; i++){ //21
    screen[i][11] = ' ';
  }
}



// Function that performs action depending on the option selected by user. The input of this function is the option that the user selects and the screen map.
void PerformAction(int selected_option){
  char confirm;
  switch (selected_option){
    case 1:
    {
      //start console game
      consoleMain(CARSHAPEtoConsole, speed); //in another source file console.cpp
      break;
    }

    // GARAGE
    case 2:
    {
      // Open garage.cpp file
      CARSHAPEtoConsole=garageMain();
      break;
    }

    //Difficulty
    case 3:
    {
        speed = difficultyMain();
        break;
    }

    // Instructions
    case 4:
    {
      // Read from instruction.txt file
      ifstream instr;
      instr.open("Desktop/instruction.txt"); //originally ./home/instruction.txt
      vector<string> instruction;
      string str;
      while (getline(instr, str)){
        instruction.push_back(str);
      }
      instr.close();
      // Outputng to screen
      system("clear");
      for (int i = 0; i < ROW; i++){
        cout << instruction[i] << endl;
      }
      // Wait for user input to continue
      confirm = keylog();
      break;
    }

    // Reset game data
    case 5:
    {
      // Printing confirmation message
      system("clear"); //Clearing console screen.
      // Printing the screen
      for (int i = 0; i < ROW -3; i++){
        cout << screen[i] << endl;
      }
      cout << "|  Are you sure you want to reset? |" << endl;
      cout << "|              (y/n)               |" << endl;
      cout << "====================================" << endl;
      // Getting confirmation
      confirm = keylog();
      while (confirm != 'n'){
        if (confirm == 'y'){
          // Reset the highscore and coins.
          ofstream reset;
          reset.open("Desktop/stat.txt"); //originally ./home/stat.txt
          reset << 0 << endl;
          reset << 0;
          reset.close();

          // Reset the acquired cars.
          ofstream resetCar;
          resetCar.open("Desktop/availableCars.txt");
          resetCar << 'A';
          resetCar.close();
          CARSHAPEtoConsole = 'A';
          resetCarData();
          resetDifficultyData();

          break;
        }
        confirm = keylog();
      }
      break;
    }

    // EXIT
    case 6:
    {
      // Printing confirmation message
      system("clear"); //Clearing console screen.
      // Printing the screen
      for (int i = 0; i < ROW -3; i++){
        cout << screen[i] << endl;
      }
      cout << "|  Are you sure you want to exit?  |" << endl;
      cout << "|              (y/n)               |" << endl;
      cout << "====================================" << endl;
      // Getting confirmation
      confirm = keylog();
      while (confirm != 'n'){
        if (confirm == 'y'){
          system("clear");
          exit(1);
        }
        confirm = keylog();
      }
      break;
    }
  }
}

// ======== End of Functions ========
// ===================================

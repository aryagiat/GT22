#include <iostream> //cout, cin
#include <fstream> // ifstream, ofstream
#include <string>  // string
#include <vector>  // vector
#include <cstring> // strcpy
#include "../game_library/keylog.h" // keylog
#include "../game_library/linkedlist.h" // ListBuild()

using namespace std;

// Global Variables
int speedtoMain; //to pass the speed/difficulty wanted to start.cpp
bool firstInitialDifficulty = true; //to check whether the code was firstly opened or not
bool firstOpenD = true;
vector<string> difficultyScreen; // The start screen graphics

void ClearDifficultyArrow(int option){ //clear the preceding arrow mark for every screen refresh
    if (option < 7){
        for (int i = 16; i < 21; i++){
            difficultyScreen[i][14] = ' ';
        }
        difficultyScreen[21][6] = ' ';
    }
}

void ClearDifficultyDot(){ //clear the preceding star mark for every difficulty change
    for (int i = 16; i < 21; i++){
        difficultyScreen[i][15] = ' ';
    }
}

void ReadArtDifficulty(){
  // Opening the difficulty art graphics design .txt file
  ifstream difficultyArt;
  difficultyArt.open("./home/difficultyArt.txt"); //originally ./home/difficultyArt.txt
  if (difficultyArt.fail()){
    cout << "Fail in difficulty art opening" << endl;
    exit(1);
  }

  // Storing the graphics design into the screen map
  string gstr;
  int difficultyArt_index = 0;
  // reading from the difficultyArt.txt file
  while (getline(difficultyArt, gstr)){
    difficultyScreen.push_back(gstr);
    difficultyArt_index++;
  }
  difficultyArt.close();
}

int resetDifficultyData(){
    speedtoMain=100000;
		if (!firstOpenD){
		    ClearDifficultyDot(); // Clear the star
    		difficultyScreen[16][15] = '*'; // put a star beside 'EASY' as the beginning difficulty
    		difficultyScreen[16][14] = '>'; // put an arrow beside 'EASY' as the beginning difficulty
		}
		return speedtoMain;
}

int difficultyMain(){
  // Open difficulty
  // Read from difficulty.txt file
  ReadArtDifficulty(); // reading from difficultyArt.txt
	
	firstOpenD = false; //difficulty.h not firstly opened anymore

  if (firstInitialDifficulty == true){
    difficultyScreen[16][15] = '*'; // put a star beside initial chosen difficulty
    firstInitialDifficulty = false;
  }

  // Build a linked list to navigate the options on difficulyty.
  Node * head = NULL;
  Node * tail = NULL;
  for (int n = 1; n <= 6; n++){
    ListBuild(head, tail, n); // Build a circular doubly linked list
  }
  Node * current_option = head; // The current option that the user is pointing at.
  int selected_option = current_option -> option; // The value of the option from the structure.
  //bool exit = false;
  // Selecting the cars from the difficulty menu.
  while(true){
      system("clear"); //Clearing console screen.
      // Printing the difficulty art.
      for (int i = 0; i < 26; i++){
        cout << difficultyScreen[i] << endl;
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
        ClearDifficultyArrow(selected_option); // Clear the arrow
        if (selected_option == 6){
          difficultyScreen[15+selected_option][6] = '>'; // Move the arrow up
        }
        else{
          difficultyScreen[15+selected_option][14] = '>'; // Move the arrow up
        }
        break;
      }

      // s button to navigate down
      case 's':
      {
        current_option = current_option -> next; // Navigate 1 option after the current option.
        selected_option = current_option -> option; // Getting the value of the chosen option.
        ClearDifficultyArrow(selected_option); // Clear the arrow
        if (selected_option == 6){
          difficultyScreen[15+selected_option][6] = '>'; // Move the arrow down
        }
        else{
          difficultyScreen[15+selected_option][14] = '>'; // Move the arrow down
        }
        break;
      }
      // enter button to perform actions depending on the option.
      case '\n':
        {
          switch (selected_option){
            // Choose starting speed.
            case 1:
                speedtoMain=100000;
                ClearDifficultyDot(); // Clear the star
                difficultyScreen[16][15] = '*'; // put a star beside chosen
                break;
            case 2:
                speedtoMain=10000;
                ClearDifficultyDot();// Clear the star
                difficultyScreen[17][15] = '*'; // put a star beside chosen
                break;
            case 3:
                speedtoMain=1000;
                ClearDifficultyDot();// Clear the star
                difficultyScreen[18][15] = '*'; // put a star beside chosen
                break;
            case 4:
                speedtoMain=100;
                ClearDifficultyDot();// Clear the star
                difficultyScreen[19][15] = '*'; // put a star beside chosen
                break;
            case 5:
                speedtoMain=5;
                ClearDifficultyDot();// Clear the star
                difficultyScreen[20][15] = '*'; // put a star beside chosen
                break;
            case 6:
                ClearDifficultyArrow(1);
                difficultyScreen[16][14] = '>'; // Move the arrow to the top beside 'EASY'
                return speedtoMain;
                //break;
           }
          break;

        }
      } // end of switch
     } // end of while loop
}

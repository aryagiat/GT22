#include <iostream> //cout, cin
#include <fstream> // ifstream, ofstream
#include <string>  // string
#include <vector>  // vector
#include <cstring> // strcpy
#include "../keylog.h" // keylog

using namespace std;

int speedtoMain;
vector<string> difficultyScreen; // The start screen graphics

void ClearDifficultyArrow(int option){
    if (option < 7){
        for (int i = 16; i < 21; i++){
            difficultyScreen[i][14] = ' ';
        }
        difficultyScreen[21][6] = ' ';
    }
}

void ClearDifficultyDot(){
    for (int i = 16; i < 21; i++){
        difficultyScreen[i][15] = ' ';
    }
}

void ReadArtDifficulty(){
  // Opening the difficulty art graphics design .txt file
  ifstream difficultyArt;
  difficultyArt.open("Desktop/difficultyArt.txt"); //originally ./home/difficultyArt.txt
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
    //strcpy(difficultyScreen[difficultyArt_index], gstr.c_str()); // converting string into a char array
    difficultyArt_index++;
  }
  difficultyArt.close();
}


int difficultyMain(){
  // Open difficulty
  // Read from difficulty.txt file
  ReadArtDifficulty(); // reading from difficultyArt.txt

  int option = 1;
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
        if (option != 1)
          option--;
          ClearDifficultyArrow(option); // Clear the arrow
          difficultyScreen[15+option][14] = '>'; // Move the arrow up
          break;
        }

        // s button to navigate down
        case 's':
        {
          if (option < 5){
            option++;
            ClearDifficultyArrow(option); // Clear the arrow
            difficultyScreen[15+option][14] = '>'; // Move the arrow down
          }else if (option == 5){
            option++;
            ClearDifficultyArrow(option); // Clear the arrow
            difficultyScreen[15+option][6] = '>'; // Move the arrow down
          }
          break;
        }
        // enter button to perform actions depending on the option.
        case '\n':
        {
          switch (option){
            // Choose starting speed.
            case 1:
                speedtoMain=100000;
                ClearDifficultyDot(); // Clear the star
                difficultyScreen[16][15] = '*'; // put a star beside chosen
                break;
            case 2:
                speedtoMain=500;
                ClearDifficultyDot();// Clear the star
                difficultyScreen[17][15] = '*'; // put a star beside chosen
                break;
            case 3:
                speedtoMain=100;
                ClearDifficultyDot();// Clear the star
                difficultyScreen[18][15] = '*'; // put a star beside chosen
                break;
            case 4:
                speedtoMain=10;
                ClearDifficultyDot();// Clear the star
                difficultyScreen[19][15] = '*'; // put a star beside chosen
                break;
            case 5:
                speedtoMain=5;
                ClearDifficultyDot();// Clear the star
                difficultyScreen[20][15] = '*'; // put a star beside chosen
                break;
            case 6:
                return speedtoMain;
                break;
           }
          break;

        }
      } // end of switch
     } // end of while loop
}

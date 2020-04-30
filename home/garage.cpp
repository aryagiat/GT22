#include <iostream> //cout, cin
#include <fstream> // ifstream, ofstream
#include <string>  // string
#include <vector>  // vector
#include <cstring> // strcpy


using namespace std;

char CARSHAPEtoMain;

void ClearGarageArrow(char garageScreen[26][37],int option){
    if (option < 7){
        for (int i = 16; i < 21; i++){
            garageScreen[i][14] = ' ';
        }
        garageScreen[21][6] = ' ';
    }
}

void ReadArtGarage(char garageScreen[][37]){
  // Opening the garage art graphics design .txt file
  ifstream garageArt;
  garageArt.open("./home/garageArt.txt"); //originally ./home/garageArt.txt
  if (garageArt.fail()){
    cout << "TFail in art opening" << endl;
    exit(1);
  }

  // Storing the graphics design into the screen map
  string gstr;
  int garageArt_index = 0;
  // reading from the garageArt.txt file
  while (getline(garageArt, gstr)){
    strcpy(garageScreen[garageArt_index], gstr.c_str()); // converting string into a char array
    garageArt_index++;
  }
  garageArt.close();
}


int garageMain(){
  // Open garage
  // Read from garage.txt file
  char garageScreen[26][37]; // screen made out of a 26 by 37 character map
  ReadArtGarage(garageScreen); // reading from garageArt.txt

  int option = 1;
  bool exit = false;
  // Selecting the cars from the garage menu.
  while(exit == false){
      system("clear"); //Clearing console screen.
      // Printing the garage art.
      for (int i = 0; i < 26; i++){
        cout << garageScreen[i] << endl;
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
          ClearGarageArrow(garageScreen,option); // Clear the arrow
          garageScreen[15+option][14] = '>'; // Move the arrow up
          break;
        }

        // s button to navigate down
        case 's':
        {
          if (option < 5){
            option++;
            ClearGarageArrow(garageScreen,option); // Clear the arrow
            garageScreen[15+option][14] = '>'; // Move the arrow down
          }else if (option == 5){
            option++;
            ClearGarageArrow(garageScreen,option); // Clear the arrow
            garageScreen[15+option][6] = '>'; // Move the arrow down
          }
          break;
        }
        // enter button to perform actions depending on the option.
        case '\n':
        {
          switch (option){
            // Choose car.
            case 1:
                CARSHAPEtoMain='A';
                break;
            case 2:
                CARSHAPEtoMain='V';
                break;
            case 3:
                CARSHAPEtoMain='R';
                break;
            case 4:
                CARSHAPEtoMain='O';
                break;
            case 5:
                CARSHAPEtoMain='+';
                break;
            case 6:
                  return CARSHAPEtoMain;
                //exit=true;
                break;
           }
                      break;

        }
      } // end of switch
     } // end of while loop
}

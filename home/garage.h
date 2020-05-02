#include <iostream> //cout, cin
#include <fstream> // ifstream, ofstream
#include <string>  // string
#include <vector>  // vector
#include <cstring> // strcpy
#include "../keylog.h" // keylog

using namespace std;

char CARSHAPEtoMain;
bool firstInitialCar = true;
vector<string> garageScreen; // The garage screen graphics

// Function to read highscore and coin. This function also updates the screen map which outputs the highscore and coin. The input is the screen map.
void ReadStatGarage(){
  // Opening the stat file to see highscore and coins.
  ifstream stat;
  stat.open("./home/stat.txt"); //originally ./home/stat.txt
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
  for (int i = 14; i < 34; i++){
    garageScreen[1][i] = ' ';
  }
  for (int i = 8; i < 34; i++){
    garageScreen[2][i] = ' ';
  }
  // Replacing the empty space on the screen with a highscore value
  for (int i = 0; i < highscore_size; i++){
    garageScreen[1][i + 14] = highscore[i];
  }
  // Replacing the empty space on the screen with a coin value
  for (int i = 0; i < coin_size; i++){
    garageScreen[2][i + 8] = coin[i];
  }
}

void unlockCar(string theUnlockedCar, int score, int coins){
    ifstream iunlockingFile;
    iunlockingFile.open("./home/availableCars.txt"); //originally ./home/availableCars.txt

    int unlockingArray_index = 0;
    string unlockingArray[5], unlockingLine;

    for (int initializeIndex=0; initializeIndex<5; initializeIndex++){ //initialize the unlockingArray[5] to " " per index
        unlockingArray[initializeIndex]=" ";
    }

    if (iunlockingFile.is_open()){
      while (getline(iunlockingFile, unlockingLine)){ //extract available cars
          unlockingArray[unlockingArray_index]=unlockingLine;
          unlockingArray_index++;
        }
      }
    iunlockingFile.close();

    for (int insertCarIndex=0; insertCarIndex<5; insertCarIndex++){ //add theUnlockedCar into unlockingArray[5]
        if (unlockingArray[insertCarIndex]==" "){
            unlockingArray[insertCarIndex]=theUnlockedCar;
            break;
        }
        //break;
    }

    ofstream ounlockingFile;
    ounlockingFile.open("./home/availableCars.txt"); //originally ./home/availableCars.txt

    for (int unlockingIndex=0; unlockingIndex<4; unlockingIndex++){
        if (unlockingArray[unlockingIndex]!=" "){
            ounlockingFile << unlockingArray[unlockingIndex] << endl; //save unlocked cars into empty slot
        }
    }
    if (unlockingArray[4]!=" "){
        ounlockingFile << unlockingArray[4]; //save the last line without adding an unnecessary line
    }
    ounlockingFile.close();

//----------------------resave stats----------------------//
    ofstream coinOutFile;
    coinOutFile.open("./home/stat.txt"); //originally ./home/stat.txt

    coinOutFile << score << endl; //resave stats
    coinOutFile << coins;

    coinOutFile.close();
//----------------------resave stats----------------------//
}

bool unlocked(string carShape){
    ifstream unlockedFile;
    unlockedFile.open("./home/availableCars.txt"); //originally ./home/availableCars.txt

    int unlockedArray_index = 0;
    string unlockedArray[5], unlockedLine;
    if (unlockedFile.is_open()){
      while (getline(unlockedFile, unlockedLine)){ //extract stat to see if car is unlocked or not
          unlockedArray[unlockedArray_index]=unlockedLine;
          unlockedArray_index++;
        }
      }
    unlockedFile.close();

    bool carUnlocked = false;
    for (int counter=0; counter<5; counter++){
        if (unlockedArray[counter] == carShape){
            carUnlocked = true;
        }
    }
    return carUnlocked;
}

void ClearGarageArrow(int option){
    if (option < 7){
        for (int i = 16; i < 21; i++){
            garageScreen[i][14] = ' ';
        }
        garageScreen[21][6] = ' ';
    }
}

void ClearGarageDot(){
    for (int i = 16; i < 21; i++){
        garageScreen[i][16] = ' ';
    }
}

void ReadArtGarage(){
  // Opening the garage art graphics design .txt file
  ifstream garageArt;
  garageArt.open("./home/garageArt.txt"); //originally ./home/garageArt.txt
  if (garageArt.fail()){
    cout << "Fail in garage art opening" << endl;
    exit(1);
  }


  // Storing the graphics design into the screen map
  string gstr;
  int garageArt_index = 0;
  // reading from the garageArt.txt file
  while (getline(garageArt, gstr)){
    garageScreen.push_back(gstr);
    //strcpy(garageScreen[garageArt_index], gstr.c_str()); // converting string into a char array
    garageArt_index++;
  }
  garageArt.close();
}

void lockAndPriceApply(){
    string theCar;
    char priceArray[4][6] = {"(20c)", "(50c)", "(60c)", "(70c)"};

    for (int lockCounter=17; lockCounter<21; lockCounter++){
        theCar = garageScreen[lockCounter][17];
        if (not unlocked(theCar)){
            garageScreen[lockCounter][19] = 'x';
        }else{
            garageScreen[lockCounter][19] = ' ';
        }
    }

    for (int costCounter=17; costCounter<21; costCounter++){
        theCar = garageScreen[costCounter][17];
        if (not unlocked(theCar)){
            for (int priceChar=0; priceChar<5; priceChar++){
                garageScreen[costCounter][21+priceChar] = priceArray[costCounter-17][priceChar];
            }
        }else{
            for (int priceChar=0; priceChar<5; priceChar++){
                garageScreen[costCounter][21+priceChar] = ' ';
            }
        }
    }

}


int garageMain(){
  // Open garage
  // Read from garage.txt file
  ReadArtGarage(); // reading from garageArt.txt

  if (firstInitialCar == true){
    garageScreen[16][16] = '*'; // put a star beside initial chosen car
    firstInitialCar = false;
  }


  ifstream coinFile;
  coinFile.open("./home/stat.txt"); //originally ./home/stat.txt

  int score, coins;
  coinFile >> score >> coins;

  coinFile.close(); //close coinFile

  int option = 1;
  //bool exit = false;
  // Selecting the cars from the garage menu.
  while(true){
      ReadStatGarage(); // reading the highscore and coin
      system("clear"); //Clearing console screen.
      lockAndPriceApply(); //applying locks
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
          ClearGarageArrow(option); // Clear the arrow
          garageScreen[15+option][14] = '>'; // Move the arrow up
          break;
        }

        // s button to navigate down
        case 's':
        {
          if (option < 5){
            option++;
            ClearGarageArrow(option); // Clear the arrow
            garageScreen[15+option][14] = '>'; // Move the arrow down
          }else if (option == 5){
            option++;
            ClearGarageArrow(option); // Clear the arrow
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
                ClearGarageDot(); // Clear the star
                garageScreen[16][16] = '*'; // put a star beside chosen
                break;
            case 2:
                  if (unlocked("V") == true){
                      CARSHAPEtoMain='V';
                      ClearGarageDot();// Clear the star
                      garageScreen[17][16] = '*'; // put a star beside chosen
                  }else if (coins >= 20 and unlocked("V") == false){
                      CARSHAPEtoMain='V';
                      ClearGarageDot();// Clear the star
                      garageScreen[17][16] = '*'; // put a star beside chosen

                      coins -= 20; //subtract coins from car price
                      unlockCar("V", score, coins);
                  }
                break;
            case 3:
                if (unlocked("H") == true){
                      CARSHAPEtoMain='H';
                      ClearGarageDot();// Clear the star
                      garageScreen[18][16] = '*'; // put a star beside chosen
                  }else if (coins >= 50 and unlocked("H") == false){
                      CARSHAPEtoMain='H';
                      ClearGarageDot();// Clear the star
                      garageScreen[18][16] = '*'; // put a star beside chosen

                      coins -= 50; //subtract coins from car price
                      unlockCar("H", score, coins);
                  }
                break;
            case 4:
                if (unlocked("&") == true){
                      CARSHAPEtoMain='&';
                      ClearGarageDot();// Clear the star
                      garageScreen[19][16] = '*'; // put a star beside chosen
                  }else if (coins >= 60 and unlocked("&") == false){
                      CARSHAPEtoMain='&';
                      ClearGarageDot();// Clear the star
                      garageScreen[19][16] = '*'; // put a star beside chosen

                      coins -= 60; //subtract coins from car price
                      unlockCar("&", score, coins);
                  }
                break;
            case 5:
                if (unlocked("+") == true){
                      CARSHAPEtoMain='+';
                      ClearGarageDot();// Clear the star
                      garageScreen[20][16] = '*'; // put a star beside chosen
                  }else if (coins >= 70 and unlocked("+") == false){
                      CARSHAPEtoMain='+';
                      ClearGarageDot();// Clear the star
                      garageScreen[20][16] = '*'; // put a star beside chosen

                      coins -= 70; //subtract coins from car price
                      unlockCar("+", score, coins);
                  }
                break;
            case 6:
                return CARSHAPEtoMain;
                break;
           }
          break;

        }
      } // end of switch
     } // end of while loop
}

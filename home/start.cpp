// start.cpp
#include <iostream> //cout, cin
#include <fstream> // ifstream, ofstream
#include <string>  // string
#include <vector>  // vector
#include <cstring> // strcpy
#include "../keylog.h" // keylog

using namespace std;


int main(){
  // Opening the start art graphics design .txt file
  ifstream art;
  art.open("./home/startart.txt");
  if (art.fail()){
    cout << "Fail in art opening" << endl;
    exit(1);
  }

  // Outputing the graphics design into the console
  char screen[25][37]; // screen made out of a 25 by 37 character map
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


  for (int i = 0; i < 25; i++){
    cout << screen[i] << endl;
  }
  char c;
  c = keylog();
  cout << "you output: " << c << endl;

  art.close();
  stat.close();

  return 0;
}

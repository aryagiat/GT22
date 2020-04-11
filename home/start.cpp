#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include "../keylog.h"

using namespace std;

int main(){
  ifstream fin;
  fin.open("./home/startart.txt");
  if (fin.fail()){
    cout << "Fail in File opening" << endl;
    exit(1);
  }
  char screen[25][37];
  string str;
  int i = 0;
  while (getline(fin, str)){
    strcpy(screen[i], str.c_str());
    i++;
  }
  for (int i = 0; i < 25; i++){
    cout << screen[i] << endl;
  }
  char c;
  c = keylog();
  cout << "you output: " << c << endl;

}


#include <iostream>
#include "keylog.h"
#include "../home/start.h" //originally ./home/start.h

using namespace std;

int main(){
  while (true){
    start();
    cout << "MAIN" << endl;
    char key = keylog();
  }

  return 0;
}

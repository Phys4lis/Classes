#include <iostream>
#include <vector>
#include <cstring>
#include "videogames.h"

int validInput();

using namespace std;

int main() {
  vector<parent*> storage;
  // Add Function
  if (validInput() == 1) {
    // prompt for which type of media to add
  }
  // Search Function
  else if (validInput() == 2) {

  }
  // Delete function
  else if (validInput() == 3) {

  }
}

int validInput() {
  cout << "What would you like to do (ADD/SEARCH/DELETE)?" << endl;
  bool looping = true;
  while (looping = true) {
    char input[10];
    cin.get(input, 10);
    cin.get();
    if ((strcmp(input, "add") == 0) || (strcmp(input, "ADD") == 0)) {
      return 1;
    }
    else if ((strcmp(input, "search") == 0) || (strcmp(input, "SEARCH") == 0)){
      return 2;
    }
    else if ((strcmp(input, "delete") == 0) || (strcmp(input, "DELETE") == 0)){
      return 3;
    }
    else {
      cout << "Please  a a enter a valid input" << endl;
      continue;
    }
  }
  return -1;
}



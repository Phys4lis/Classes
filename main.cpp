#include <iostream>
#include <vector>
#include <cstring>
#include "parent.h"
#include "videogames.h"

int validInput();
int validMedia();
void add(parent* &newparent, vector<parent*> storage);

using namespace std;

int main() {
  vector<parent*> storage;
  // Add Function
  if (validInput() == 1) {
    parent* newparent = new parent();
    if (validMedia() == 1) {
      videogames* vg = new videogames();
    }
    else if (validMedia() == 2) {

    }
    else if (validMedia() == 3) {

    }
  }
  // Search Function
  else if (validInput() == 2) {

  }
  // Delete function
  else if (validInput() == 3) {

  }
}

int validInput() {
  cout << "What do you like to do (ADD/SEARCH/DELETE)?" << endl;
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
      cout << "Please enter a valid input" << endl;
      continue;
    }
  }
  return -1;
}

int validMedia() {
  cout << "What media would you like to add (Video Games/Music/Movies)?" << endl;
  bool looping = true;
  while (looping = true) {
    char input[15];
    cin.get(input, 15);
    cin.get();
    if ((strcmp(input, "video games") == 0) || (strcmp(input, "Video Games") == 0)) {
      return 1;
    }
    else if ((strcmp(input, "music") == 0) || (strcmp(input, "Music") == 0)){
      return 2;
    }
    else if ((strcmp(input, "movies") == 0) || (strcmp(input, "Movies") == 0)){
      return 3;
    }
    else {
      cout << "Please enter a valid media" << endl;
      continue;
    }
  }
  return -1;
}

void add(parent* &newparent, vector<parent*> storage) {

}

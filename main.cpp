#include <iostream>
#include <vector>
#include <cstring>
#include "parent.h"
#include "videogames.h"

int validInput();
int validMedia();
void search(vector<parent*> storage);

using namespace std;

int main() {
  vector<parent*> storage;
  // Add Function
  bool running = true;
  while (running == true) {
    if (validInput() == 1) {
      parent* newparent = new parent();
      if (validMedia() == 1) {
	videogames* vg = new videogames();
	storage.push_back(vg);
      }
      else if (validMedia() == 2) {
	
      }
      else if (validMedia() == 3) {
	
      }
    }
    // Search Function
    else if (validInput() == 2) {
      search(storage);
    }
    // Delete function
    else if (validInput() == 3) {

    }
  }
}

int validInput() {
  cout << "What do you want to do (ADD/SEARCH/DELETE)?" << endl;
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


void search(vector<parent*> storage) {
  cout << "Do you want to search by year or by title?" << endl;
  char input[20];
  cin.get(input, 20);
  cin.get();
  if (strcmp(input, "year") == 0) {
    cout << "Please enter the year of the media." << endl;
    int intInput;
    cin >> intInput;
    cin.get();
    for (vector<parent*>::iterator iter = storage.begin(); iter != storage.end(); iter++) {
      if (intInput == (*iter)->year) {
	cout << (*iter)->year;
      }
    }
  }
  else if (strcmp(input, "title") == 0) {
    
  }
}

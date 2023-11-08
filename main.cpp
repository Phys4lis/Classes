#include <iostream>
#include <vector>
#include <cstring>
#include "parent.h"
#include "videogames.h"
#include "music.h"
#include "movies.h"

int validInput();
int validMedia();
void search(vector<parent*> storage);
void deleteMedia(vector<parent*> storage);

using namespace std;

int main() {
  vector<parent*> storage;
  // Add Function
  bool running = true;
  while (running == true) {
    int option = validInput();
    if (option == 1) {
      // parent* newparent = new parent();
      int whichMedia = validMedia();
      if (whichMedia == 1) {
	videogames* vg = new videogames();
	storage.push_back(vg);
      }
      else if (whichMedia == 2) {
	music* msc = new music();
	storage.push_back(msc);
      }
      else if (whichMedia == 3) {
	movies* mvs = new movies();
	storage.push_back(mvs);
      }
    }
    // Search Function
    else if (option == 2) {
      search(storage);
    }
    // Delete function
    else if (option == 3) {
      deleteMedia(storage);
    }
    else if (option == 4) {
      running = false;
    }
  }
}

int validInput() {
  cout << "What do you want to do (ADD/SEARCH/DELETE/QUIT)?" << endl;
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
    else if ((strcmp(input, "quit") == 0) || (strcmp(input, "QUIT") == 0)){
      return 4;
    }
    else {
      cout << "Please enter a valid input." << endl;
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
	if (strcmp((*iter)->type, "videogame") == 0) {
	  (*iter)->printVideoGames();
	}
	else if (strcmp((*iter)->type, "music") == 0) {
	  (*iter)->printMusic();
	}
	else if (strcmp((*iter)->type, "movie") == 0) {
	  (*iter)->printMovies();
	}
      }
    }
  }
  else if (strcmp(input, "title") == 0) {
    cout << "Please enter the title of the media." << endl;
    char input[50];
    cin.get(input, 50);
    cin.get();
    for (vector<parent*>::iterator iter = storage.begin(); iter != storage.end(); iter++) {
      if (strcmp((*iter)->title, input) == 0) {
	if (strcmp((*iter)->type, "videogame") == 0) {
	  (*iter)->printVideoGames();
	}
	else if (strcmp((*iter)->type, "music") == 0) {
	  (*iter)->printMusic();
	}
	else if (strcmp((*iter)->type, "movie") == 0) {
	  (*iter)->printMovies();
	}
      }
    }
  }
}

void deleteMedia(vector<parent*> storage) {
  cout << "Do you want to delete by year or by title?" << endl;
  char input[50];
  cin.get(input, 50);
  cin.get();
  if (strcmp(input, "year") == 0) {
    cout << "Please enter the year of the media." << endl;
    int intInput;
    cin >> intInput;
    cin.get();
    for (vector<parent*>::iterator iter = storage.begin(); iter != storage.end(); iter++) {
      if (intInput == (*iter)->year) {
	if (strcmp((*iter)->type, "videogame") == 0) {
	  (*iter)->printVideoGames();
	}
	else if (strcmp((*iter)->type, "music") == 0) {
	  (*iter)->printMusic();
	}
	else if (strcmp((*iter)->type, "movie") == 0) {
	  (*iter)->printMovies();
	}
      }
    }
    cout << "Are you sure you want to delete these items? (y/n)" << endl;
    char yesNo;
    cin >> yesNo;
    cin.get();
    if (yesNo == 'y' || yesNo == 'Y') {
      for (vector<parent*>::iterator iter = storage.begin(); iter != storage.end(); iter++) {
	if (intInput == (*iter)->year) {
	  delete *iter;
	  storage.erase(iter);
	}
      }
    }
  }
  

  
  else if (strcmp(input, "title") == 0) {
    cout << "Please enter the title of the media." << endl;
    char input[50];
    cin.get(input, 50);
    cin.get();
    for (vector<parent*>::iterator iter = storage.begin(); iter != storage.end(); iter++) {
      if (strcmp((*iter)->title, input) == 0) {
	if (strcmp((*iter)->type, "videogame") == 0) {
	  (*iter)->printVideoGames();
	}
	else if (strcmp((*iter)->type, "music") == 0) {
	  (*iter)->printMusic();
	}
	else if (strcmp((*iter)->type, "movie") == 0) {
	  (*iter)->printMovies();
	}
      }
    }
    cout << "Are you sure you want to delete these items? (y/n)" << endl;
    char yesNo;
    cin >> yesNo;
    cin.get();
    if (yesNo == 'y' || yesNo == 'Y') {
      for (vector<parent*>::iterator iter = storage.begin(); iter != storage.end(); iter++) {
        if (strcmp((*iter)->title, input) == 0) {
	  delete *iter;
	  storage.erase(iter);
	}
      } 
    }
  }
}


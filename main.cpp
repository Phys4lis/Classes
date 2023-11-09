/* This program allows user to add media (video games, music, or movie) and search or delete media by listing the year or title of the media they want to search/delete.
 * Date: 11/8/23
 * Author: Roger Li
 */

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
void deleteMedia(vector<parent*> &storage);

using namespace std;

int main() {
  vector<parent*> storage;
  // Add Function
  bool running = true;
  while (running == true) {
    int option = validInput();
    if (option == 1) {
      int whichMedia = validMedia();
      // Add a video game
      if (whichMedia == 1) {
	videogames* vg = new videogames();
	storage.push_back(vg);
      }
      // Add music
      else if (whichMedia == 2) {
	music* msc = new music();
	storage.push_back(msc);
      }
      // Add a movie
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

// Checks for valid input from the user
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

// Checks for a valid media input from the user
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

// Search for a specific item through a year or title
void search(vector<parent*> storage) {
  cout << "Do you want to search by year or by title?" << endl;
  char input[20];
  cin.get(input, 20);
  cin.get();
  // Search using the item's year
  if (strcmp(input, "year") == 0) {
    cout << "Please enter the year of the media." << endl;
    int intInput;
    cin >> intInput;
    cin.get();
    int amount = 0;
    // Go through all media, print the ones that match the year
    for (vector<parent*>::iterator iter = storage.begin(); iter != storage.end(); iter++) {
      if (intInput == (*iter)->year) {
	amount++;
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
    if (amount == 0) {
      cout << "There is no media with this year!" << endl;
    }
  }
  // Search using the item's title
  else if (strcmp(input, "title") == 0) {
    cout << "Please enter the title of the media." << endl;
    char input[50];
    cin.get(input, 50);
    cin.get();
    int amount2 = 0;
    // Go through all media, print the ones that match the title
    for (vector<parent*>::iterator iter = storage.begin(); iter != storage.end(); iter++) {
      if (strcmp((*iter)->title, input) == 0) {
	amount2++;
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
    if (amount2 == 0) {
      cout << "There is no media with this title!" << endl;
    }
  }
}

// Delete a specific item using the item's year or title
void deleteMedia(vector<parent*> &storage) {
  cout << "Do you want to delete by year or by title?" << endl;
  char input[50];
  cin.get(input, 50);
  cin.get();
  // Delete with year
  if (strcmp(input, "year") == 0) {
    cout << "Please enter the year of the media." << endl;
    int intInput;
    cin >> intInput;
    cin.get();
    int amount = 0;
    // Go through all media, print one-by-one the media that match the year
    for (vector<parent*>::iterator iter = storage.begin(); iter != storage.end(); iter++) {
      if (intInput == (*iter)->year) {
	amount++;
	if (strcmp((*iter)->type, "videogame") == 0) {
	  (*iter)->printVideoGames();
	}
	else if (strcmp((*iter)->type, "music") == 0) {
	  (*iter)->printMusic();
	}
	else if (strcmp((*iter)->type, "movie") == 0) {
	  (*iter)->printMovies();
	}
	// Verify that the user wishes to delete the media
	if (amount != 0) {
	  cout << "Are you sure you want to delete this item? (y/n)" << endl;
	}
	
	char yesNo;
	cin >> yesNo;
	cin.get();
	// Delete the item
	if (yesNo == 'y' || yesNo == 'Y') {
	  delete *iter;
	  storage.erase(iter);
	  cout << "The item has been successfully removed." << endl << endl;
	  return;
        }
	else if (yesNo == 'n' || yesNo == 'N') {
	    
	}
      }
      
    }
    if (amount == 0) {
       cout << "There are no items to delete in this year!" << endl;
       return;
    }
  }
  

  // Delete with title
  else if (strcmp(input, "title") == 0) {
    cout << "Please enter the title of the media." << endl;
    char inputTitle[50];
    cin.get(inputTitle, 50);
    cin.get();
    int amount2 = 0;
    // Go through all media, print one-by-one the media that match the title
    for (vector<parent*>::iterator iter = storage.begin(); iter != storage.end(); iter++) {
      if (strcmp((*iter)->title, inputTitle) == 0) {
	amount2++;
	if (strcmp((*iter)->type, "videogame") == 0) {
	  (*iter)->printVideoGames();
	}
	else if (strcmp((*iter)->type, "music") == 0) {
	  (*iter)->printMusic();
	}
	else if (strcmp((*iter)->type, "movie") == 0) {
	  (*iter)->printMovies();
	}
	// Verify that the user wishes to delete the item
	if (amount2 != 0) {
	  cout << "Are you sure you want to delete this item? (y/n)" << endl;
	}
	
	char yesNo;
	cin >> yesNo;
	cin.get();
	// Delete the item
	if (yesNo == 'y' || yesNo == 'Y') {
	  delete *iter;
	  storage.erase(iter);
	  cout << "The item has been successfully removed." << endl << endl;
	  return;
        }
	else if (yesNo == 'n' || yesNo == 'N') {
	    
	}
      }
      
    }
    if (amount2 == 0) {
       cout << "There are no items to delete with this title!" << endl;
       return;
    }
  }
}


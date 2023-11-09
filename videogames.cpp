#include <iostream>
#include "videogames.h"
#include <cstring>
using namespace std;

videogames::videogames() {
  // Change type to video game
  strcpy(type, "videogame");
  // Prompt user for information about the video game
  cout << "Please enter a title." << endl;
  char input1[50];
  cin.get(input1, 50);
  cin.get();
  strcpy(title, input1);
  cout << "Please enter a year." << endl;
  int intInput2;
  cin >> intInput2;
  cin.get();
  year = intInput2;
  cout << "Please enter a publisher." << endl;
  char input3[50];
  cin.get(input3, 50);
  cin.get();
  strcpy(publisher, input3);
  cout << "Please enter a rating." << endl;
  int intInput4;
  cin >> intInput4;
  cin.get();
  rating = intInput4;
}

// Video game functions
char* videogames::getPublisher() {
  return publisher;
}

int videogames::getRating() {
  return rating;
}

void videogames::printVideoGames() {
  cout << "Video game - " << "Title: " << getTitle() << ", " << "Year: " << getYear() << ", " << "Publisher: " << getPublisher() << ", " << "Rating: " << getRating() << endl;
}

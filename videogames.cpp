#include <iostream>
#include "videogames.h"
#include <cstring>
using namespace std;

videogames::videogames() {
  cout << "Please enter a title" << endl;
  char input1[20];
  cin.get(input1, 20);
  cin.get();
  strcpy(title, input1);
  cout << "Please enter a year" << endl;
  int intInput2;
  cin >> intInput2;
  cin.get();
  year = intInput2;
  cout << "Please enter a publisher" << endl;
  char input3[20];
  cin.get(input3, 20);
  cin.get();
  strcpy(publisher, input3);
  cout << "Please enter a rating" << endl;
  int intInput4;
  cin >> intInput4;
  cin.get();
  rating = intInput4;
}

int videogames::getPublisher() {
  return 0;
}

int videogames::getRating() {
  return rating;
}



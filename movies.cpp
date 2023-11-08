#include <iostream>
#include "movies.h"
#include <cstring>
using namespace std;

movies::movies() {
  strcpy(type, "movie");
  cout << "Please enter a title." << endl;
  char input1[50];
  cin.get(input1, 50);
  cin.get();
  strcpy(title, input1);
  cout << "Please enter a year" << endl;
  int intInput2;
  cin >> intInput2;
  cin.get();
  year = intInput2;
  cout << "Please enter a director." << endl;
  char input3[50];
  cin.get(input3, 50);
  cin.get();
  strcpy(director, input3);
  cout << "Please enter a duration." << endl;
  char input4[50];
  cin.get(input4, 50);
  cin.get();
  strcpy(duration, input4);
  cout << "Please enter a rating." << endl;
  int intInput5;
  cin >> intInput5;
  cin.get();
  rating = intInput5;
}

char* movies::getDirector() {
  return director;
}

char* movies::getDuration() {
  return duration;
}

int movies::getRating() {
  return rating;
}

void movies::printMovies() {
  cout << "Movie - " << "Title: " << getTitle() << ", " << "Year: " << getYear() << ", " << "Director: " << getDirector() << ", " << "Duration: " << getDuration() << ", " << "Rating: " << getRating() << endl;
}



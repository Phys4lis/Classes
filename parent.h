#ifndef PARENT_H
#define PARENT_H

#include <iostream>
using namespace std;

class parent {
 public:
  parent();
  // Parent variables used by children
  char title[50];
  int year;
  char type[20];
  char* getTitle();
  int getYear();

  // Parent functions
  virtual void printVideoGames();
  virtual void printMusic();
  virtual void printMovies();

  // Destructor
  virtual ~parent();
}; 

#endif

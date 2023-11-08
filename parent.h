#ifndef PARENT_H
#define PARENT_H

#include <iostream>
using namespace std;

class parent {
 public:
  parent();
  char title[50];
  int year;
  char type[20];
  char* getTitle();
  int getYear();

  virtual void printVideoGames();
  virtual void printMusic();
  virtual void printMovies();
  
  virtual ~parent();
}; 

#endif

#include <iostream>
#include "parent.h"
using namespace std;

class movies : public parent {
 public:
  movies();
  // Variables and functions used in movies.cpp
  char director[50];
  char duration[50];
  int rating;
  char* getDirector();
  char* getDuration();
  int getRating();
  void printMovies();
};

#include <iostream>
#include "parent.h"
using namespace std;

class movies : public parent {
 public:
  movies();
  char director[50];
  char duration[50];
  int rating;
  char* getDirector();
  char* getDuration();
  int getRating();
  void printMovies();
};

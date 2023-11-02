#include <iostream>
#include "parent.h"
using namespace std;

class videogames : public parent {
 public:
  videogames();
  char publisher[20];
  int rating;
  int getPublisher();
  int getRating();
};

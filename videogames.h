#include <iostream>
#include "parent.h"
using namespace std;

class videogames : public parent {
 public:
  videogames();
  char publisher[50];
  int rating;
  char* getPublisher();
  int getRating();
  void printVideoGames();
};

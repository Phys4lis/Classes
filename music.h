#include <iostream>
#include "parent.h"
using namespace std;

class music : public parent {
 public:
  music();
  char publisher[20];
  int rating;
  int getPublisher();
  int getRating();
};






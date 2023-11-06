#include <iostream>
#include "parent.h"
using namespace std;

class movies : public parent {
 public:
  movies();
  char artist[20];
  int duration;
  char publisher[20];
};

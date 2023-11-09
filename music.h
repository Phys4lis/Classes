#include <iostream>
#include "parent.h"
using namespace std;

class music : public parent {
 public:
  music();
  // Variables and functions used in music.cpp
  char publisher[50];
  char duration[50];
  char* getPublisher();
  char* getDuration();
  void printMusic();
};

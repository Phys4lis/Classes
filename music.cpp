#include <iostream>
#include "music.h"
#include <cstring>
using namespace std;

music::music() {
  strcpy(type, "music");
  cout << "Please enter a title." << endl;
  char input1[50];
  cin.get(input1, 50);
  cin.get();
  strcpy(title, input1);
  cout << "Please enter a year." << endl;
  int intInput2;
  cin >> intInput2;
  cin.get();
  year = intInput2;
  cout << "Please enter a publisher." << endl;
  char input3[50];
  cin.get(input3, 50);
  cin.get();
  strcpy(publisher, input3);
  cout << "Please enter a duration." << endl;
  char input4[50];
  cin.get(input4, 50);
  cin.get();
  strcpy(duration, input4);
}

char* music::getPublisher() {
  return publisher;
}

char* music::getDuration() {
  return duration;
}

void music::printMusic() {
  cout << "Music - " << "Title: " << getTitle() << ", " << "Year: " << getYear() << ", " << "Publisher: " << getPublisher() << ", " << "Duration: " << getDuration() << endl;
}

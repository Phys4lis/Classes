#include <iostream>
#include "parent.h"
#include "videogames.h"
#include "music.h"
#include "movies.h"

using namespace std;

parent::parent() {
  
}

// Parent functions
char* parent::getTitle() {
  return title;
}

int parent::getYear() {
  return year;
}

void parent::printVideoGames() {

}

void parent::printMusic() {

}

void parent::printMovies() {

}

parent::~parent() {

}

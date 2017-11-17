#include "game.h"
#include <iostream>
#include <cstring>

using namespace std;

Game::Game(char* _publisher, char* _rating, char* _title, char* _year):Media() {
  publisher = new char[80];
  rating = new char[80];
  strcpy(publisher, _publisher);
  strcpy(rating, _rating);
  strcpy(title, _title);
  strcpy(year, _year);
  id = 1;
}

Game::~Game() {
  delete [] publisher;
  delete [] rating;
}

char* Game::getPublisher() {
  return publisher;
}

char* Game::getRating() {
  return rating;
}

void Game::print() {
  cout << "(Video Game) Title: " << title << " | Year: " << year << " | Publisher: " << publisher << " | Rating: " << rating << endl;
}

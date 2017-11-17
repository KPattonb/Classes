#include "movie.h"
#include <iostream>
#include <cstring>

using namespace std;

Movie::Movie(char* _director, char* _duration, char* _rating, char* _title, char* _year):Media() {
  director = new char[80];
  duration = new char[80];
  rating = new char[80];
  strcpy(director, _director);
  strcpy(duration, _duration);
  strcpy(rating, _rating);
  strcpy(title, _title);
  strcpy(year, _year);
  id = 3;
}


Movie::~Movie() {
  delete [] director;
  delete [] duration;
  delete [] rating;
}

char* Movie::getDirector() {
  return director;
}

char* Movie::getDuration() {
  return duration;
}

char* Movie::getRating() {
  return rating;
}

void Movie::print() {
  cout << "(Movie) Title: " << title << " | Director: " << director << " | Year: " << year << " | Duration: " << duration << " | Rating: " << rating << endl;
}

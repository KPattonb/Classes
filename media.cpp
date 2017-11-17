#include "media.h"
#include <iostream>
#include <cstring>

using namespace std;

Media::Media() {
  title = new char[80];
  year = new char[5];
  id = 0;
}

Media::~Media() {
  delete [] title;
  delete [] year;
}

char* Media::getTitle() {
  return title;
}

char* Media::getYear() {
  return year;
}

int Media::getID() {
  return id;
}

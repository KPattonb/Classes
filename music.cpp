#include "music.h"
#include <iostream>
#include <cstring>

using namespace std;

Music::Music(char* _artist, char* _duration, char* _publisher, char* _title, char* _year):Media() {
  artist = new char[80];
  duration = new char[80];
  publisher = new char[80];
  strcpy(artist, _artist);
  strcpy(duration, _duration);
  strcpy(publisher, _publisher);
  strcpy(title, _title);
  strcpy(year, _year);
  id = 2;
}

Music::~Music() {
  delete [] artist;
  delete [] publisher;
  delete [] duration;
}

char* Music::getArtist() {
  return artist;
}

char* Music::getDuration() {
  return duration;
}

char* Music::getPublisher() {
  return publisher;
}

void Music::print() {
  cout << "(Music) Title: " << title << " | Artist: " << artist << " | Year: " << year << " | Duration: " << duration << " | Publisher: " << publisher << endl;
}

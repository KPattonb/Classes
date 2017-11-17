#include "media.h"
#ifndef MOVIE_H
#define MOVIE_H

class Movie : public Media {
 private:
  char* director;
  char* duration;
  char* rating;

 public:
  Movie(char* _director, char* _duration, char* _rating, char* _title, char* _year);
  ~Movie();

  char* getDirector();
  char* getDuration();
  char* getRating();

  void print();
};

#endif

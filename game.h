#include "media.h"
#ifndef GAME_H
#define GAME_H

class Game : public Media {
 private:
  char* publisher;
  char* rating;

 public:
  Game(char* _publisher, char* _rating, char* _title, char* _year);
  ~Game();

  char* getPublisher();
  char* getRating();

  void print();
};

#endif

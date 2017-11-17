#include "media.h"
#ifndef MUSIC_H
#define MUSIC_H

class Music : public Media {
 private:
  char* artist;
  char* duration;
  char* publisher;
  
 public:
  Music(char* _artist, char* _duration, char* _publisher, char* _title, char* _year);
  ~Music();

  char* getArtist();
  char* getDuration();
  char* getPublisher();

  void print();
};

#endif

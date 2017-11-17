#ifndef MEDIA_H
#define MEDIA_H

class Media {
 protected:
  char* title;
  char* year;
  int id;
 public:
  Media();
  ~Media();

  char* getTitle();  char* getYear();
  int getID();

};

#endif


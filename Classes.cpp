//Classes
//Allows user to enter different types of media into a database and retrieve/delete them
//Author: Kian Patton
//Date: November 16, 2017
#include <iostream>
#include <vector>
#include <cstring>
#include "media.h"
#include "game.h"
#include "music.h"
#include "movie.h"

using namespace std;

void addMedia(vector<Media*>* datab) {
  char title[80];
  char year[5];
  char type;

  cout << "Enter the title." << endl;
  cin.getline(title, 80);

  for (int i = 0; i < strlen(title); i++) {
    title[i] = toupper(title[i]);
  }

  cout << "Enter the year when it was released." << endl;
  cin.getline(year, 5);

  cout << "Enter 'g' if it is a video game, 'm' if it is music, or 'f' if it is a film." << endl;
  cin >> type;
  cin.ignore();

  if (type = 'g') {
    char publisher[80];
    char rating[80];

    cout << "Enter the publisher." << endl;
    cin.getline(publisher, 80);
    cout << "Enter the rating." << endl;
    cin.getline(rating, 80);

    Game* game = new Game(rating, publisher, year, title);
    datab->push_back(game);

    cout << title << " added." << endl;
  }
  else if (type = 'm') {
    char artist[80];
    char duration[80];
    char publisher[80];

    cout << "Enter the artist." << endl;
    cin.getline(artist, 80);
    cout << "Enter the song duration." << endl;
    cin.getline(duration, 80);
    cout << "Enter the publisher." << endl;
    cin.getline(publisher, 80);

    Music* music = new Music(artist, duration, publisher, title, year);
    datab->push_back(music);

    cout << title << " added." << endl;
  }
  else if (type = 'f') {
    char director[80];
    char duration[80];
    char rating[80];

    cout << "Enter the director." << endl;
    cin.getline(director, 80);
    cout << "Enter the duration." << endl;
    cin.getline(duration, 80);
    cout << "Enter the rating." << endl;
    cin.getline(rating, 80);

    Movie* movie = new Movie(director, duration, rating, title, year);
    datab->push_back(movie);

    cout << title << " added." << endl;
  }
}

void searchMedia(vector<Media*> datab) {
  char type;

  cout << "Enter 't' to search by title or 'y' to search by year." << endl;
  cin >> type;
  cin.ignore();

  if (type == 't') {
    char title[80];

    cout << "Enter the title." << endl;
    cin.getline(title, 80);

    for (int i = 0; i < strlen(title); i++) {
      title[i] = toupper(title[i]);
    }

    cout << "Search results: " << endl;

    for (int i = 0; i < datab.size(); i++) {
      if (strcmp(title, datab[i]->getTitle()) == 0) {
	if (datab[i]->getID() == 1) {
	  ((Game*) datab[i])->print();
	}
	if (datab[i]->getID() == 2) {
	  ((Music*) datab[i])->print();
	}
	if (datab[i]->getID() == 3) {
	  ((Movie*) datab[i])->print();
	}
      }
    }
  }
  else if (type == 'y') {
    char year[5];

    cout << "Enter the year it was released." << endl;
    cin.getline(year, 5);

    cout << "Search results: " << endl;

    for (int i = 0; i < datab.size(); i++) {
      if (strcmp(year, datab[i]->getTitle()) == 0) {
	if (datab[i]->getID() == 1) {
	  ((Game*) datab[i])->print();
	}
	if (datab[i]->getID() == 2) {
	  ((Music*) datab[i])->print();
	}
	if (datab[i]->getID() == 3) {
	  ((Movie*) datab[i])->print();
	}
      }
    }
  }
}

void deleteMedia(vector<Media*> datab) {
  char type;
  char confirm;

  cout << "Enter 't' to delete by title or 'y' to delete by year." << endl;
  cin >> type;
  cin.ignore();

  if (type == 't') {
    char title[80];

    cout << "Enter the title," << endl;
    cin.getline(title, 80);

    for (int i = 0; i < strlen(title); i++) {
      title[i] = toupper(title[i]);
    }

    cout << "Are you sure you would like to delete this item? y or n?" << endl;
    cin >> confirm;

    if (confirm == 'y') {
      for (int i = 0; i < datab.size(); i++) {
	if (strcmp(title, datab[i]->getTitle()) == 0) {
	  if (datab[i]->getID() == 1) {
	    delete ((Game*) datab[i]);
	    datab.erase(datab.begin() + i);
	  }
	  if (datab[i]->getID() == 2) {
	    delete ((Music*) datab[i]);
	    datab.erase(datab.begin() + i);
	  }
	  if (datab[i]->getID() == 3) {
	    delete ((Movie*) datab[i]);
	    datab.erase(datab.begin() + i);
	  }
	}
      }
    }
  }
  else if (type == 'y') {
    char year[5];

    cout << "Enter the year it was released." << endl;
    cin.getline(year, 5);

    cout << "Are you sure you would like to delete this item? y or n?: " << endl;
    cin >> confirm;
    cin.ignore();

    if (confirm == 'y') {
      for (int i = 0; i < datab.size(); i++) {
	if (strcmp(year, datab[i]->getTitle()) == 0) {
	  if (datab[i]->getID() == 1) {
	    delete ((Game*) datab[i]);
	    datab.erase(datab.begin() + i);
	  }
	  if (datab[i]->getID() == 2) {
	    delete ((Music*) datab[i]);
	    datab.erase(datab.begin() + i);
	  }
	  if (datab[i]->getID() == 3) {
	    delete ((Movie*) datab[i]);
	    datab.erase(datab.begin() + i);
	  }
	}
      }
    }
  }
}

int main() {

  vector<Media*> datab;
  vector<Media*>* databpr = &datab;
  char input;

  while (input != 'q') {
    cout << "Enter 'a' to add media, 's' to search the database, 'd' to delete media, or 'q' to quit the program." << endl;
    cin >> input;
    cin.ignore();

    if (input == 'a') {
      addMedia(databpr);
    }
    else if (input == 's') {
      searchMedia(datab);
    }
    else if (input == 'd') {
      deleteMedia(datab);
    }
    else {
      return 0;
    }
  }
}

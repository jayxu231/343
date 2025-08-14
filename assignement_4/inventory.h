#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include "genreCatalog.h"
#include "movie.h"

using namespace std;

class Inventory {
private:
    GenreCatalog comedies;
    GenreCatalog dramas;
    GenreCatalog classics;
public:
    Inventory() = default;
    ~Inventory();
    void addMovie(Movie * movie);
    Movie * findMovie(const string &key);
    bool borrowMovie(const string &key);
    bool returnMovie(const string &key);
    void printAll() const; 
};

#endif
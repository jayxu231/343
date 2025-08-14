#ifndef COMEDY_H
#define COMEDY_H

#include "movie.h"
using namespace std; 

class Comedy : public Movie {
private:
    int year;

public:
    string key() const override;
};

#endif

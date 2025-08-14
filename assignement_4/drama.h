#ifndef DRAMA_H
#define DRAMA_H

#include "movie.h"
using namespace std; 

class Drama : public Movie {
public:
    string key() const override;
};

#endif

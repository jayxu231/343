#ifndef CLASSIC_H
#define CLASSIC_H

#include "movie.h"

using namespace std;

class Classic : public Movie {
private:
    string majorActor;
    int month;
    int year;

public:
    string key() const override;
};

#endif

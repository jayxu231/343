#ifndef MOVIE_H
#define MOVIE_H

#include <string>
using namespace std;

class Movie {
protected:
    int stock;
    string director;
    string title;

public:
    virtual ~Movie() {}
    virtual string key() const = 0;
    virtual string display() const;
    bool borrow();
    bool returnMovie();
};

#endif

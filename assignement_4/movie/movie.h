#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <typeinfo>
using namespace std;

class Movie {
protected:
    int stock;
    string director;
    string title;
    int year;

public:  


    virtual ~Movie() {}
    virtual string key() const = 0;
    virtual string describe() const = 0;
    virtual string display() const = 0;

    int getStock();

    bool increaseStock(int s);
    bool borrow();
    bool returnMovie();
};

#endif

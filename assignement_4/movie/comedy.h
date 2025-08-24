#ifndef COMEDY_H
#define COMEDY_H

#include "movie.h"
using namespace std; 

class Comedy : public Movie {
private:


public:
    Comedy();
    Comedy(int s, string d, string t, int y);
    bool operator==(const Comedy &other) const;
    bool operator<(const Comedy &other) const;
    
    string getTitle() const;
    int getYear() const;
    string key() const override;
    string describe() const override;
    string display() const override;
};

#endif

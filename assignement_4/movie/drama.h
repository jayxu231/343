#ifndef DRAMA_H
#define DRAMA_H

#include "movie.h"
using namespace std; 

class Drama : public Movie {
public:
    Drama();
    Drama(int s , string d, string t, int y);
    bool operator==(const Drama &other) const;
    bool operator<(const Drama &other) const;
    
    string getTitle() const;
    int getYear() const;
    string key() const override;
    string describe() const override;
    string display() const override;
};

#endif

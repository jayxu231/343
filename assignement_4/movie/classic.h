#ifndef CLASSIC_H
#define CLASSIC_H

#include "movie.h"

using namespace std;

class Classic : public Movie {
private:
    string majorActor;
    int month;


public:
    Classic();
    Classic(int s, const string &d, const string &t, int y, int m, const string &a);
    bool operator==(const Classic &other) const;
    bool operator<(const Classic &other) const;
    
    string key() const override;
    string describe() const override;
    string display() const override;
    // getters
    int getMonth() const;
    int getYear() const;
    string getTitle() const;
    string getActor() const;

};

#endif

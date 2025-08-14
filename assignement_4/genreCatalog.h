#ifndef GENRECATALOG_H
#define GENRECATALOG_H

#include "movie.h"

class GenreCatalog {
private:
    struct Movienode {
        Movie * movie;
        Movienode * left;
        Movienode * right;
        Movienode(Movie *m);
    };
    Movienode * root; 

    void insertHelper(Movienode * n, Movie* m);
    void inOrderHelper(Movienode * n) const;
    void destroyTree(Movienode * n);

public:
    GenreCatalog();
    ~GenreCatalog();

    void insert(Movie * movie);
    Movie find(const string &key) const;
    void inOrderPrint() const; 

};
#endif
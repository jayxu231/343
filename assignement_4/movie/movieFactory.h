#ifndef MOVIE_FACTORY_H
#define MOVIE_FACTORY_H

#include "movie.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"
#include <string>

class MovieFactory {
public:
    static Movie * createFromLine(const std::string& line);
};

#endif

#ifndef MOVIE_FACTORY_H
#define MOVIE_FACTORY_H

#include <string>
#include "movie.h"

class MovieFactory {
public:
    Movie * createFromLine(const std::string& line) const;
};

#endif

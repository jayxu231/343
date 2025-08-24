#include "borrow.h"
#include "movie.h"

std::string Borrow::describe() const {
    if (movie) {
        return "Borrowed: " + movie->describe();
    }
    return "Borrowed: <null movie>";
}

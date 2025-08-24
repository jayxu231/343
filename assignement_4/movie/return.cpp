#include "return.h"
#include "movie.h"

std::string Return::describe() const {
    if (movie) {
        return "Returned: " + movie->describe();
    }
    return "Returned: <null movie>";
}

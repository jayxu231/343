#ifndef INVENTORY_H
#define INVENTORY_H

#include <map>
#include <string>
#include "movie.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"

class Inventory {
private:
    // Keys must match each genre's sorting rule:
    //  - Comedy:  Title|Year
    //  - Drama:   Director|Title
    //  - Classic: Year|Month|Actor
    // Each genre gets its own ordered map, keyed by Movie::key()
    std::map<std::string, Movie *> comedies; // Comedy: Title|Year
    std::map<std::string, Movie *> dramas;   // Drama:  Director|Title
    std::map<std::string, Movie *> classics; // Classic: Year|Month|Actor

public:
    Inventory() = default;
    ~Inventory();

    // Add a movie to the correct genre map. If key already exists, merge stock.
    void addMovie(Movie * movie);

    // Find by key across all genres (returns first match or nullptr).
    Movie * findMovie(const std::string &key);
    
    // Borrow/return by key (searches all genres). Returns false on error.
    bool borrowMovie(const std::string &key);
    bool returnMovie(const std::string &key);

    // Print inventory: Comedies, then Dramas, then Classics (each already ordered by map key)
    void printAll() const;

    // (Optional) Genre-specific find helpers if you prefer tighter control:
    Movie * findComedy(const std::string &key);
    Movie * findDrama (const std::string &key);
    Movie * findClassic(const std::string &key);

private:
    // Internal helpers to choose the right map based on dynamic type
    static std::map<std::string, Movie*>& mapFor(Movie * m,
                                                 std::map<std::string, Movie*> &com,
                                                 std::map<std::string, Movie*> &dra,
                                                 std::map<std::string, Movie*> &cla);

    // Search order: comedies -> dramas -> classics
    Movie * findInAll(const std::string &key);
};

#endif

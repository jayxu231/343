#include "inventory.h"
#include <iostream>

using namespace std;

Inventory::~Inventory() {
    for (auto &temp : comedies) delete temp.second;
    for (auto &temp : dramas)   delete temp.second;
    for (auto &temp : classics) delete temp.second;
    comedies.clear();
    dramas.clear();
    classics.clear();
}
void Inventory::addMovie(Movie * movie) {
    if(!movie) { 
        return;
    }
    map<std::string, Movie*>& genreMap = mapFor(movie, comedies, dramas, classics);

    std::string key = movie->key();

    // Check if it already exists
    auto it = genreMap.find(key);
    if (it != genreMap.end()) {
        // Merge stock instead of adding a duplicate
        it->second->increaseStock(movie->getStock());
        delete movie; // discard the new object, keep existing
    } else {
        // Insert as new
        genreMap[key] = movie;
    }
}
Movie * Inventory::findMovie(const string &key) {
    return findInAll(key);
}
bool Inventory::borrowMovie(const string &key) {
    Movie * m = findInAll(key);
    if (!m) return false;
    return m->borrow();
}
bool Inventory::returnMovie(const string &key) {
    Movie* m = findInAll(key);
    if (!m) return false;
    return m->returnMovie();
}
void Inventory::printAll() const {
    cout << "Comedies:\n";
    for (const auto& kv : comedies) {
        cout << kv.second->display() << "\n";
    }

    cout << "Dramas:\n";
    for (const auto& kv : dramas) {
        cout << kv.second->display() << "\n";
    }

    cout << "Classics:\n";
    for (const auto& kv : classics) {
        cout << kv.second->display() << "\n";
    }
}
Movie * Inventory::findComedy(const std::string& key) {
    auto it = comedies.find(key);
    return (it == comedies.end()) ? nullptr : it->second;
}

Movie * Inventory::findDrama(const std::string& key) {
    auto it = dramas.find(key);
    return (it == dramas.end()) ? nullptr : it->second;
}

Movie * Inventory::findClassic(const std::string& key) {
    auto it = classics.find(key);
    return (it == classics.end()) ? nullptr : it->second;
}
Movie * Inventory::findInAll(const std::string& key) {
    if (auto* m = findComedy(key))  return m;
    if (auto* m = findDrama(key))   return m;
    if (auto* m = findClassic(key)) return m;
    return nullptr;
}


map<string, Movie *>& Inventory::mapFor(Movie* m, map<string, Movie*> &com, map<string, Movie*> &dra,map<string, Movie*> &cla) {
    if (dynamic_cast<Comedy*>(m)) return com; 
    if (dynamic_cast<Drama*>(m))  return dra;  
    if (dynamic_cast<Classic*>(m)) return cla;  
    throw runtime_error("Unknown movie type");
}
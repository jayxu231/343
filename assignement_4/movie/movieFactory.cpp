#include "movieFactory.h"
#include <sstream>
#include <iostream>

using namespace std;
// Helper to trim whitespace
static std::string trim(const string& s) {
    size_t b = 0, e = s.size();
    while (b < e && isspace((unsigned char)s[b])) ++b;
    while (e > b && isspace((unsigned char)s[e - 1])) --e;
    return s.substr(b, e - b);
}

Movie* MovieFactory::createFromLine(const string& line) {
    if (line.empty()) return nullptr;

    istringstream ss(line);
    char genre;
    ss >> genre;   // F, D, or C
    if (ss.peek() == ',') ss.get(); // eat comma if present

    int stock, year, month;
    string director, title, first, last;

    switch (genre) {
    case 'F': {
        // Format: F, stock, director, title, year
        char comma;
        ss >> stock >> comma;
        getline(ss, director, ',');
        getline(ss, title, ',');
        ss >> year;

        director = trim(director);
        title    = trim(title);

        return new Comedy(stock, director, title, year);
    }
    case 'D': {
        // Format: D, stock, director, title, year
        char comma;
        ss >> stock >> comma;
        getline(ss, director, ',');
        getline(ss, title, ',');
        ss >> year;

        director = trim(director);
        title    = trim(title);

        return new Drama(stock, director, title, year);
    }
    case 'C': {
        // Format: C, stock, director, title, first last month year
        char comma;
        ss >> stock >> comma;
        getline(ss, director, ',');
        getline(ss, title, ',');
        ss >> first >> last >> month >> year;

        director = trim(director);
        title    = trim(title);
        string actor = first + " " + last;

        return new Classic(stock, director, title, year, month, actor);
    }
    default:
        cerr << "MovieFactory: invalid genre code in line: " << line << "\n";
        return nullptr;
    }
}

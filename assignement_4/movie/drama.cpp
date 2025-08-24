#include "drama.h"

using namespace std;

Drama::Drama() {
    stock = 0;
    title = "null";
    director = "null";
    year = 0;
}
Drama::Drama(int s , string d, string t, int y) {
    stock = s;
    director = d;
    title = t;
    year = y;
}
bool Drama::operator==(const Drama &other) const {
    return (title == other.getTitle()) && (year == other.getYear());
}
bool Drama::operator<(const Drama& other) const {
    if (title != other.getTitle()) {
        return title < other.getTitle();
    }
    return year < other.getYear();
}
string Drama::getTitle() const {
    return title;
}
int Drama::getYear() const {
    return year;
}
string Drama::key() const {
    return director + "|" + title;
}
string Drama::display() const {
    return "Stock: " + to_string(stock) +
           " | Drama | Dir: " + director + " | " +
           title + " | " + to_string(year) + " \n";
}
string Drama::describe() const {
    return title + " (" + std::to_string(year) + ") by " + director;
}

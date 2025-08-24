#include "comedy.h"

using namespace std;

Comedy::Comedy() {
    stock = 0;
    title = "null";
    director = "null";
    year = 0;
}
Comedy::Comedy(int s , string d, string t, int y) {
    stock = s;
    director = d;
    title = t;
    year = y;
}
bool Comedy::operator==(const Comedy &other) const {
    return (title == other.getTitle()) && (year == other.getYear());
}
bool Comedy::operator<(const Comedy& other) const {
    if (title != other.getTitle()) {
        return title < other.getTitle();
    }
    return year < other.getYear();
}
string Comedy::getTitle() const {
    return title;
}
int Comedy::getYear() const {
    return year;
}
string Comedy::key() const {
    return title + "|" + to_string(year);
}
string Comedy::display() const {
    return "Stock: " + to_string(stock) +
           " | Comedy | " + title + " | " +
           to_string(year) + " | Dir: " + director + " \n";
}
string Comedy::describe() const {
    return title + " (" + std::to_string(year) + ")";
}
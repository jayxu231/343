#include "classic.h"

using namespace std;

Classic::Classic(int s, const string &d, const string &t, int y, int m, const string &a){
    stock = s;
    director = d;
    title = t;
    year = y;
    month = m;
    majorActor = a;
}
Classic::Classic() {
    stock = 0;
    director = "null";
    title = "null";
    year = 0;
    month = 0;
    majorActor = "null";
}
bool Classic::operator==(const Classic &other) const  {
    return (other.getTitle() == getTitle()) && (other.getActor() == getActor()) && (other.getMonth() == getMonth()) && (other.getYear() == getYear());
    
}

bool Classic::operator<(const Classic &other) const {
    if (year == other.getYear()) {
        if (month == other.getMonth()) {
            return majorActor < other.getActor();  
        } else {
            return month < other.getMonth();
        }
    }
    return year < other.getYear();
}
int Classic::getMonth() const {
    return month;
}
int Classic::getYear() const {
    return year;
}
string Classic::getTitle() const {
    return title;
}
string Classic::getActor() const {
    return majorActor;
}

string Classic::describe() const {
    return title + " " + majorActor + " " + to_string(month) 
           + " " + to_string(year);
}
string Classic::display() const {
    return "Stock: " + to_string(stock) + " | Classic | " + title + " | " + 
    majorActor + " | " + to_string(month) + "/" + to_string(year) + " | Dir: " + 
    director + " \n";
}
string Classic::key() const {
    return to_string(year) + "|" + to_string(month) + "|" + majorActor;
}
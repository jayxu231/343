
#include "movie.h"
#include <iostream>

using namespace std;

bool Movie::borrow() {
    if (stock > 0) {
        stock--;
        return true;
    } else {
        cout << "Error: Movie out of stock: " << title << endl;
        return false;
    }
}
int Movie::getStock() {
    return stock;
}
bool Movie::returnMovie() { 
    stock++;
    return true;
}
bool Movie::increaseStock(int s) {
    stock += s;
    return true;
}
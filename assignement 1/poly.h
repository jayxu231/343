#ifndef POLY_H
#define POLY_H

#include <iostream>

class Poly {
private:
// use an array not a vector for this assignement
// size of the array will change in runtime, learn how to do that 
    int *coefficient;
    int size;
public:
    Poly();
    Poly(int c, int s);
    ~Poly();

    Poly operator+(const Poly &other);
    Poly operator-(const Poly &other);
    Poly operator*(const Poly &other);

    Poly operator=(const Poly &other);

    Poly operator+=(const Poly &other);
    Poly operator-=(const Poly &other);
    Poly operator*=(const Poly &other);


    int getCoeff(int s);
    void setCoeff(int c, int s);
    void print() const;


}


#endif
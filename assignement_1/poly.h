// ---------------------------------- poly.h ------------------------------------
// Jayden Sastradi, CSS343
// Date Created: ...
// Last Modified: ...
// -----------------------------------------------------------------------------
// Purpose: Defines the Poly class for implementation.
// -----------------------------------------------------------------------------

#ifndef POLY_H
#define POLY_H

#include <iostream>

class Poly {
private:

    int *coefficient;
    int size;
public:
    Poly();
    Poly(int e);
    Poly(int c, int e);
    Poly(const Poly &other);
    ~Poly();

    Poly operator+(const Poly &other);
    Poly operator-(const Poly &other);
    Poly operator*(const Poly &other);

    Poly& operator=(const Poly &other);

    Poly& operator+=(const Poly &other);
    Poly& operator-=(const Poly &other);
    Poly& operator*=(const Poly &other);

    friend std::istream& operator>>(std::istream& in, Poly& poly);
    friend std::ostream& operator<<(std::ostream& out, const Poly& poly);
// helper function to create a bigger array when needed
    void setArr(int e);
// helper function to get the coefficient of the exponent
    int getCoeff(int e) const;
    void setCoeff(int c, int e);



};


#endif
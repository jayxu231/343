// ---------------------------------- poly.h ------------------------------------
// Jayden Sastradi, CSS343
// Date Created: 6/25/2025
// Last Modified: 7/1/2025
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
    bool operator==(const Poly& other) const;
    bool operator!=(const Poly& other) const;
    
    Poly& operator+=(const Poly &other);
    Poly& operator-=(const Poly &other);
    Poly& operator*=(const Poly &other);

    friend std::istream& operator>>(std::istream& in, Poly& poly);
    friend std::ostream& operator<<(std::ostream& out, const Poly& poly);
    void setArr(int e);
    int getCoeff(int e) const;
    void setCoeff(int c, int e);



};


#endif
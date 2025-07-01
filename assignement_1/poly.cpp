// ---------------------------------- poly.cpp ----------------------------------
// Jayden Sastradi, CSS343
// Date Created: 6/25/2025
// Last Modified: 6/26/2025
// -----------------------------------------------------------------------------
// Purpose: Implements the Poly class for polynomial arithmetic including operator
// overloading for +, -, *, assignment, and stream I/O. Also includes dynamic memory
// management, resizing, and deep copying.
// -----------------------------------------------------------------------------

#include "poly.h"

// ------------------------------ Constructor: Poly() ------------------------------
// Default constructor initializing the polynomial to 0x^0.
// ----------------------------------------------------------------------------------
Poly::Poly() {
    size = 0;
    coefficient = nullptr;
    setArr(1);
    coefficient[0] = 0;
}

// ---------------------------- Constructor: Poly(int) -----------------------------
// Initializes polynomial to a constant c.
// ----------------------------------------------------------------------------------
Poly::Poly(int c) {
    size = 0;
    coefficient = nullptr;
    setArr(1);
    coefficient[0] = c;
}

// ------------------------ Constructor: Poly(int c, int e) ------------------------
// Initializes polynomial with coefficient c at exponent e.
// ----------------------------------------------------------------------------------
Poly::Poly(int c, int e) {
    size = 0;
    coefficient = nullptr;
    setArr(e + 1);
    coefficient[e] = c;
}

// ------------------------------ Copy Constructor -------------------------------
// Performs deep copy of another Poly object.
// ----------------------------------------------------------------------------------
Poly::Poly(const Poly& other) {
    size = 0;
    coefficient = nullptr;
    setArr(other.size);
    for (int i = 0; i < size; i++) {
        coefficient[i] = other.coefficient[i];
    }
}

// ----------------------------- Destructor: ~Poly() -----------------------------
// Frees dynamically allocated memory.
// ----------------------------------------------------------------------------------
Poly::~Poly() {
    delete[] coefficient;
    coefficient = nullptr;
}

// ---------------------------- operator+ (Addition) -----------------------------
// Returns a new Poly object that is the sum of this and another.
// ----------------------------------------------------------------------------------
Poly Poly::operator+(const Poly& other) {
    int maxSize = (size > other.size) ? size : other.size;
    Poly result;
    result.setArr(maxSize);
    for (int i = 0; i < maxSize; i++) {
        int a = (i < size) ? coefficient[i] : 0;
        int b = (i < other.size) ? other.coefficient[i] : 0;
        result.coefficient[i] = a + b;
    }
    return result;
}

// ---------------------------- operator- (Subtraction) --------------------------
// Returns a new Poly object that is the difference of this and another.
// ----------------------------------------------------------------------------------
Poly Poly::operator-(const Poly& other) {
    int maxSize = (size > other.size) ? size : other.size;
    Poly result;
    result.setArr(maxSize);
    for (int i = 0; i < maxSize; i++) {
        int a = (i < size) ? coefficient[i] : 0;
        int b = (i < other.size) ? other.coefficient[i] : 0;
        result.coefficient[i] = a - b;
    }
    return result;
}

// --------------------------- operator* (Multiplication) ------------------------
// Returns a new Poly object that is the product of this and another.
// ----------------------------------------------------------------------------------
Poly Poly::operator*(const Poly& other) {
    int maxSize = size + other.size - 1;
    Poly result;
    result.setArr(maxSize);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < other.size; j++) {
            result.coefficient[i + j] += coefficient[i] * other.coefficient[j];
        }
    }
    return result;
}

// ------------------------ operator= (Assignment Operator) ----------------------
// Assigns another Poly object to this one (deep copy).
// ----------------------------------------------------------------------------------
Poly& Poly::operator=(const Poly& other) {
    if (this != &other) {
        delete[] coefficient;
        coefficient = nullptr;
        setArr(other.size);
        for (int i = 0; i < other.size; i++) {
            coefficient[i] = other.coefficient[i];
        }
    }
    return *this;
}

// ---------------------- operator+= (Compound Addition) ------------------------
// Adds another Poly to this one in place.
// ----------------------------------------------------------------------------------
Poly& Poly::operator+=(const Poly& other) {
    if (size < other.size) {
        setArr(other.size);
    }
    for (int i = 0; i < other.size; ++i) {
        coefficient[i] += other.coefficient[i];
    }
    return *this;
}

// ---------------------- operator-= (Compound Subtraction) ---------------------
// Subtracts another Poly from this one in place.
// ----------------------------------------------------------------------------------
Poly& Poly::operator-=(const Poly& other) {
    if (size < other.size) {
        setArr(other.size);
    }
    for (int i = 0; i < other.size; ++i) {
        coefficient[i] -= other.coefficient[i];
    }
    return *this;
}

// ---------------------- operator*= (Compound Multiplication) ------------------
// Multiplies another Poly with this one in place.
// ----------------------------------------------------------------------------------
Poly& Poly::operator*=(const Poly& other) {
    int newSize = size + other.size - 1;
    int * newCoeff = new int[newSize]{};

    for(int i = 0; i < size; i ++){
        for(int j = 0; j < other.size; j++){
            newCoeff[i + j] += coefficient[i] * other.coefficient[j];
        }
    }

    delete [] coefficient;

    coefficient = newCoeff;
    size = newSize;

    return *this;
}

// ---------------------- operator== (Equality Check) ------------------
// Checks if two Polys are equal to each other.
// ----------------------------------------------------------------------------------
bool Poly::operator==(const Poly& other) const {
    int maxSize = (size > other.size) ? size : other.size;
    for (int i = 0; i < maxSize; ++i) {
        int a = (i < size) ? coefficient[i] : 0;
        int b = (i < other.size) ? other.coefficient[i] : 0;
        if (a != b) {
            return false;
        }
    }
    return true;
}
// ---------------------- operator!= (Equality Check) ------------------
// Checks if two Polys are not equal to each other.
// ----------------------------------------------------------------------------------
bool Poly::operator!=(const Poly& other) const {
    return !(*this == other);
}

// -------------------------- operator>> (Input Stream) --------------------------
// Reads terms (coefficient and exponent pairs) into the Poly.
// (To be implemented)
// ----------------------------------------------------------------------------------
std::istream& operator>>(std::istream& in, Poly& poly) {
    int coeff, exp;
    while (true) {
        in >> coeff >> exp;
        if (coeff == -1 && exp == -1) break;
        poly.setCoeff(coeff, exp);
    }
    return in;
}

// -------------------------- operator<< (Output Stream) -------------------------
// Outputs the polynomial in standard form.
// (To be implemented)
// ----------------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& out, const Poly& poly) {
    bool printed = false;
    for (int i = poly.size - 1; i >= 0; --i) {
        int coeff = poly.getCoeff(i);
        if (coeff != 0) {
            if (printed) {
                out << (coeff > 0 ? " +" : " -");
            } else {
                out << (coeff > 0 ? "+" : "-");
            }

            if (std::abs(coeff) != 1 || i == 0) {
                out << abs(coeff);
            }

            if (i > 0) {
                out << "x";
                if (i > 1) {
                    out << "^" << i;
                }
            }

            printed = true;
        }
    }

    if (!printed) {
        out << " 0";
    }

    return out;
}

// ------------------------------ setArr ----------------------------------------
// Dynamically resizes the coefficient array and preserves data.
// ----------------------------------------------------------------------------------
void Poly::setArr(int s) {
    if (s <= size) {
        return;
    }
    if (coefficient == nullptr) {
        coefficient = new int[s]{};
    } else {
        int* temp = coefficient;
        coefficient = new int[s]{};
        for (int i = 0; i < size; i++) {
            coefficient[i] = temp[i];
        }
        delete[] temp;
    }
    size = s;
}
// ------------------------------ setCoeff ----------------------------------------
// set the Coefficient for the power
// ----------------------------------------------------------------------------------
void Poly::setCoeff(int c, int e) {
    if(e < 0) {
        return;
    } 
    if(e >= size) {
        setArr(e + 1);

    }
    coefficient[e] = c;
}
// ------------------------------ getoeff ----------------------------------------
// set the Coefficient for the power
// ----------------------------------------------------------------------------------

int Poly::getCoeff(int e) const {
    if(e < 0 || e >= size) { 
        return 0;
    } else {
        return coefficient[e];
    }
}
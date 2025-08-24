#ifndef BORROW_H
#define BORROW_H

#include "transaction.h"

class Borrow : public Transaction {
public:
    Borrow(Movie* moviePtr, const std::string& date = "")
        : Transaction('B', moviePtr, date) {}

    std::string describe() const override;
};

#endif

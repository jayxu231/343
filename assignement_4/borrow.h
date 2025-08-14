#ifndef BORROW_H
#define BORROW_H

#include "transaction.h"

class Borrow : public Transaction {
public:
    std::string describe() const override;
};

#endif

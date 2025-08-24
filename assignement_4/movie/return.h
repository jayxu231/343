#ifndef RETURN_H
#define RETURN_H

#include "transaction.h"

class Return : public Transaction {
public:
    Return(Movie* moviePtr, const std::string& date = "")
        : Transaction('R', moviePtr, date) {}

    std::string describe() const override;
};

#endif

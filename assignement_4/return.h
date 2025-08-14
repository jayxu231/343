#ifndef RETURN_H
#define RETURN_H

#include "transaction.h"

class Return : public Transaction {
public:
    std::string describe() const override;
};

#endif

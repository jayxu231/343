#ifndef HISTORY_QUERY_H
#define HISTORY_QUERY_H

#include "transaction.h"

using namespace std;

class HistoryQuery : public Transaction {
public:
    string describe() const override;
};

#endif

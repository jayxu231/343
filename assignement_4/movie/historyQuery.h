// historyQuery.h
#ifndef HISTORYQUERY_H
#define HISTORYQUERY_H

#include "transaction.h"

class HistoryQuery : public Transaction {
public:
    HistoryQuery(const std::string& date = "")
        : Transaction('H', nullptr, date) {}
    std::string describe() const override {
        return "History requested";
    }
};

#endif

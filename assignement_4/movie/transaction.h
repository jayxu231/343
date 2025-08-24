#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "movie.h"

class Transaction {
public:
    Transaction(char actionType, Movie* moviePtr, const std::string& date);
    virtual ~Transaction() = default;

    char getActionType() const;                 
    Movie* getMovie() const;                    
    std::string getDate() const;               

    std::string getActionDescription() const;

    virtual std::string describe() const = 0;  

protected:
    char actionType;    // 'B' for Borrow, 'R' for Return, etc.
    Movie* movie;       // null for H/I
    std::string date;   // optional
};

#endif

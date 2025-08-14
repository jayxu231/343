#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "movie.h"  

using namespace std;

class Transaction {
public:
    // Constructor
    Transaction(char actionType, Movie* moviePtr, const std::string& date);

    // Getters
    char getActionType() const;                
    Movie* getMovie() const;                   
    string getDate() const;              

    // Utility: returns "Borrowed" or "Returned"
    string getActionDescription() const;

private:
    char actionType;   
    Movie* movie;       
    string date;   
};

#endif
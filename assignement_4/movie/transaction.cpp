#include "transaction.h"

Transaction::Transaction(char actionType, Movie* moviePtr, const std::string& date)
    : actionType(actionType), movie(moviePtr), date(date) {}

char Transaction::getActionType() const {
    return actionType;
}

Movie* Transaction::getMovie() const {
    return movie;
}

std::string Transaction::getDate() const {
    return date;
}

std::string Transaction::getActionDescription() const {
    if (actionType == 'B') return "Borrowed";
    if (actionType == 'R') return "Returned";
    return "Unknown Action";
}

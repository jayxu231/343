#ifndef STORE_H
#define STORE_H

#include <string>
#include <istream>
#include "inventory.h"
#include "history.h"


#include "customerDirectory.h"
/*
#include "borrow.h"
#include "return.h"
*/

class Store {
public:
    Store() = default;

    // Bulk loaders
    void loadMovies(const std::string& filename); //done
    void loadCustomers(const std::string& filename);
/*
    // Process a commands file containing B/R/H/I lines
    void processCommands(const std::string& filename);
*/
    // Convenience (direct calls, optional)
    void printInventory() const;
    void printHistory(int customerId) const;



private:
    Inventory inventory;
    CustomerDirectory customers;

    // ---------- small helpers ----------
    static std::string trim(std::string s);
    static bool readLine(std::istream& in, std::string& line);

    // Build EXACT keys that match Movie::key() in each subclass
    static bool buildComedyKey (const std::string& rest, std::string& outKey); // Title|Year
    static bool buildDramaKey  (const std::string& rest, std::string& outKey); // Director|Title
    static bool buildClassicKey(std::istream& ss, std::string& outKey);        // Year|Month|Actor

    // ---------- command handlers ----------
    bool handleBorrow (std::istream& ss);
    bool handleReturn (std::istream& ss);
    bool handleHistory(std::istream& ss);
    bool handleInventory();
};

#endif // STORE_H

#include "store.h"
#include <iostream>
#include "store.h"
#include <iostream>
#include "customer.h"
#include "customerDirectory.h"
#include "hashTable.h"
#include "borrow.h"
#include "return.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"


int main() {
    Store store;

    std::cout << "=== Loading movies from data4movies.txt ===\n";
    store.loadMovies("data4movies.txt");

    std::cout << "\n=== Inventory after load ===\n";
    store.printInventory();

        Store s;

    std::cout << "=== Loading customers from data4customers.txt ===\n";
    s.loadCustomers("data4customers.txt");

    // Optional sanity checks (pick IDs that exist in your file)
    std::cout << "\n=== Sample history lookups ===\n";
    s.printHistory(1001);   // will print empty if no transactions yet
    s.printHistory(1002);
        std::cout << "=== TEST: Customer & Directory with Movies ===\n";

    // 1) Create customers
    Customer* c1 = new Customer(1001, "Alice", "Johnson");
    Customer* c2 = new Customer(1002, "Bob",   "Nguyen");

    // 2) Put them into directory
    CustomerDirectory dir;
    dir.put(c1);
    dir.put(c2);

    // 3) Create some real movies
    Movie* m1 = new Comedy(5, "Chuck Russell", "The Mask", 1994);
    Movie* m2 = new Drama(2, "Christopher Nolan", "Inception", 2010);

    // 4) Record transactions
    c1->record(new Borrow(m1));
    c1->record(new Return(m1));
    c2->record(new Borrow(m2));

    // 5) Print their histories
    std::cout << "\n--- History for Alice ---\n";
    c1->printHistory();

    std::cout << "\n--- History for Bob ---\n";
    c2->printHistory();

    // 6) Print directory contents
    std::cout << "\n--- Directory printAll() ---\n";
    dir.printAll();

    return 0;
    return 0;
}

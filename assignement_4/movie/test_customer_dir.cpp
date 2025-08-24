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
}

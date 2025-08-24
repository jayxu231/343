// test_customer_dir.cpp
#include <iostream>
#include "customer.h"
#include "customerDirectory.h"
#include "hashTable.h"
#include "transaction.h"

// --- Minimal test transaction so we don't need Movie objects ---
class TestTransaction : public Transaction {
public:
    explicit TestTransaction(const std::string& label)
        : Transaction('T', /*movie*/nullptr, /*date*/""), label_(label) {}

    std::string describe() const override { return label_; }

private:
    std::string label_;
};

static void check(bool cond, const char* msg) {
    if (!cond) { std::cerr << "[FAIL] " << msg << "\n"; std::exit(1); }
    std::cout << "[OK] " << msg << "\n";
}

int main() {
    // 1) Create some customers
    Customer* c1 = new Customer(1001, "Alice", "Johnson");
    Customer* c2 = new Customer(1002, "Bob",   "Nguyen");
    Customer* c3 = new Customer(1003, "Cara",  "Lopez");

    // 2) Put them in the directory
    CustomerDirectory dir;
    dir.put(c1);
    dir.put(c2);
    dir.put(c3);

    // 3) Basic lookups
    check(dir.has(1001), "has(1001) true");
    check(dir.has(1002), "has(1002) true");
    check(!dir.has(9999), "has(9999) false");

    Customer* got = dir.get(1002);
    check(got != nullptr, "get(1002) non-null");
    check(got->getName() == std::string("Bob Nguyen"), "get(1002) name matches");

    // 4) Record some transactions on customers (history test)
    c1->record(new TestTransaction("Borrowed: TEST-ITEM-1"));
    c1->record(new TestTransaction("Returned: TEST-ITEM-1"));
    c2->record(new TestTransaction("Borrowed: TEST-ITEM-2"));

    std::cout << "\n--- History for 1001 ---\n";
    c1->printHistory();   // should show Returned… then Borrowed… (latest first)

    std::cout << "\n--- History for 1002 ---\n";
    c2->printHistory();   // one entry

    std::cout << "\n--- History for 1003 (empty) ---\n";
    c3->printHistory();   // should show "(no transactions)"

    // 5) Optional: print all customers (works only if you implemented CustomerDirectory::printAll)
    std::cout << "\n--- Directory printAll() ---\n";
    dir.printAll();

    std::cout << "\nAll Customer/Directory tests passed!\n";
    return 0;
}

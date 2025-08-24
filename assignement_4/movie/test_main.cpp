#include <iostream>
#include <cassert>
#include "inventory.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"

using std::cout;
using std::endl;

// --- Small helper to check expectations ---
static void check(bool cond, const char* msg) {
    if (!cond) { std::cerr << "[FAIL] " << msg << "\n"; std::exit(1); }
    std::cout << "[OK] " << msg << "\n";
}

int main() {
    Inventory inv;

    // === 1) Create a few movies ===
    // Adjust constructors to match your actual movie ctors
    // Convention used here: (stock, director, title, year [, month, actor])
    Movie* f1  = new Comedy(5, "Chuck Russell", "The Mask", 1994);
    Movie* f1b = new Comedy(3, "Chuck Russell", "The Mask", 1994); // duplicate key → merges stock
    Movie* d1  = new Drama(2, "Christopher Nolan", "Inception", 2010);
    Movie* c1  = new Classic(4, "Michael Curtiz", "Casablanca", 1942, 11, "Humphrey Bogart");
    Movie* c2  = new Classic(1, "Michael Curtiz", "Casablanca", 1942, 11, "Ingrid Bergman"); // different actor → distinct key

    // === 2) Add to inventory, including a duplicate (merge test) ===
    inv.addMovie(f1);   // The Mask (5)
    inv.addMovie(f1b);  // duplicate key: The Mask (add 3 → expect 8 total)
    inv.addMovie(d1);   // Inception (2)
    inv.addMovie(c1);   // Casablanca (Bogart) (4)
    inv.addMovie(c2);   // Casablanca (Bergman) (1) – different classic by key

    // Optional: print to visually inspect ordering
    cout << "\n=== INVENTORY AFTER ADD ===\n";
    inv.printAll();

    // === 3) Find by genre+key and verify merged stock ===
    // Keys must match your key() implementations:
    // Comedy:  Title|Year
    // Drama:   Director|Title
    // Classic: Year|Month|Actor
    {
        Movie* mf = inv.findComedy("The Mask|1994");
        check(mf != nullptr, "findComedy: The Mask present after add");
        // need getStock() method on Movie or Comedy
        check(mf->getStock() == 8, "merge stock on duplicate Comedy (5+3=8)");

        Movie* md = inv.findDrama("Christopher Nolan|Inception");
        check(md && md->getStock() == 2, "Drama present with correct stock");

        Movie* mcBogart = inv.findClassic("1942|11|Humphrey Bogart");
        Movie* mcBerg   = inv.findClassic("1942|11|Ingrid Bergman");
        check(mcBogart && mcBogart->getStock() == 4, "Classic (Bogart) present");
        check(mcBerg   && mcBerg->getStock()   == 1, "Classic (Bergman) present");
    }

    // === 4) Borrow path ===
    {
        bool ok = inv.borrowMovie("The Mask|1994"); // should succeed (8→7)
        check(ok, "borrow Movie (Comedy) succeeds when in stock");

        Movie* mf = inv.findComedy("The Mask|1994");
        check(mf && mf->getStock() == 7, "stock decremented after borrow");

        // borrow Drama twice (2→1→0), third should fail
        check(inv.borrowMovie("Christopher Nolan|Inception"), "borrow Drama #1 ok");
        check(inv.borrowMovie("Christopher Nolan|Inception"), "borrow Drama #2 ok");
        check(!inv.borrowMovie("Christopher Nolan|Inception"), "borrow Drama #3 fails (out of stock)");
    }

    // === 5) Return path ===
    {
        bool ok = inv.returnMovie("Christopher Nolan|Inception"); // (0→1)
        check(ok, "return Drama succeeds");
        Movie* md = inv.findDrama("Christopher Nolan|Inception");
        check(md && md->getStock() == 1, "stock incremented after return");
    }

    // === 6) Negative lookup test ===
    {
        Movie* none = inv.findComedy("Nonexistent|2000");
        check(none == nullptr, "find on nonexistent key returns nullptr");
        check(!inv.borrowMovie("Nonexistent|2000"), "borrow nonexistent key fails");
        check(!inv.returnMovie("Nonexistent|2000"), "return nonexistent key fails");
    }

    cout << "\nAll inventory tests passed!\n";
    return 0;
}

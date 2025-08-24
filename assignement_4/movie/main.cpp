#include "store.h"
#include <iostream>

int main() {
    Store store;

    std::cout << "=== Loading movies from data4movies.txt ===\n";
    store.loadMovies("data4movies.txt");

    std::cout << "\n=== Inventory after load ===\n";
    store.printInventory();

    return 0;
}

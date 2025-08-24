#include "customerDirectory.h"
#include "customer.h"
#include <iostream>

void CustomerDirectory::put(Customer* c) {
    if (c) table.put(c);
}

Customer* CustomerDirectory::get(int id) const {
    return table.get(id);
}

bool CustomerDirectory::has(int id) const {
    return table.has(id);
}

void CustomerDirectory::printAll() const {
    auto all = table.collectValues();
    if (all.empty()) {
        std::cout << "(no customers)\n";
        return;
    }
    for (const auto* c : all) {
        if (!c) continue;
        std::cout << "ID " << c->getId() << " : " << c->getName() << "\n";
    }
}

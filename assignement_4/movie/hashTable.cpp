#include "hashTable.h"
#include "customer.h"

#include <vector>

HashTable::HashTable(int size)
    : capacity(size > 0 ? size : 101),
      count(0),
      buckets(static_cast<size_t>(capacity)) {}

int HashTable::hashFunction(int key) const {
    int h = key % capacity;
    return (h < 0) ? (h + capacity) : h;
}

void HashTable::put(Customer* c) {
    if (!c) return;
    const int key = c->getId();

    // Simple grow at ~70% load
    if (count * 10 >= capacity * 7) {
        rehash(capacity * 2 + 1);
    }

    int idx = hashFunction(key);

    for (int i = 0; i < capacity; ++i) {
        int probe = (idx + i) % capacity;
        Entry& e = buckets[probe];

        if (!e.occupied) {
            // empty slot: insert new
            e.key = key;
            e.value = c;
            e.occupied = true;
            ++count;
            return;
        }
        if (e.key == key && e.occupied) {
            // replace existing
            e.value = c;
            return;
        }
        // else keep probing
    }

    // Fallback (shouldn’t happen if rehash works)
    buckets[0].key = key;
    buckets[0].value = c;
    if (!buckets[0].occupied) { buckets[0].occupied = true; ++count; }
}

Customer* HashTable::get(int id) const {
    int idx = hashFunction(id);

    for (int i = 0; i < capacity; ++i) {
        int probe = (idx + i) % capacity;
        const Entry& e = buckets[probe];

        if (!e.occupied) {
            // hit a never-used slot → not present
            return nullptr;
        }
        if (e.key == id) {
            return e.value;
        }
        // else continue probing
    }
    return nullptr;
}

bool HashTable::has(int id) const {
    return get(id) != nullptr;
}

std::vector<Customer*> HashTable::collectValues() const {
    std::vector<Customer*> out;
    out.reserve(static_cast<size_t>(count));
    for (const auto& e : buckets) {
        if (e.occupied && e.value) {
            out.push_back(e.value);
        }
    }
    return out;
}

void HashTable::rehash(int newCapacity) {
    std::vector<Entry> old = std::move(buckets);
    capacity = (newCapacity > 0 ? newCapacity : capacity * 2 + 1);
    buckets.assign(static_cast<size_t>(capacity), Entry{});
    count = 0;

    for (const auto& e : old) {
        if (e.occupied && e.value) {
            // Reinsert
            int idx = hashFunction(e.key);
            for (int i = 0; i < capacity; ++i) {
                int probe = (idx + i) % capacity;
                Entry& slot = buckets[probe];
                if (!slot.occupied) {
                    slot.key = e.key;
                    slot.value = e.value;
                    slot.occupied = true;
                    ++count;
                    break;
                }
                if (slot.key == e.key) {
                    slot.value = e.value; // replace
                    break;
                }
            }
        }
    }
}

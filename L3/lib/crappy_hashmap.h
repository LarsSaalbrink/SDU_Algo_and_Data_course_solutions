#include <vector>
#include <optional>
#include <stdexcept>

enum class EntryState { Available, Occupied, Deleted };

template <typename ValueType>
class HashMap {
private:
    struct Entry {
        ValueType value;
        EntryState state;

        Entry() : state(EntryState::Available) {}
    };

    std::vector<Entry> table;

    size_t quadratic_probe(size_t index_start) const {
        size_t i = 1;
        size_t index = index_start + i;

        while (table[index].state == EntryState::Occupied) {
            ++i;
            index = (index_start + i * i) % table.size();
        }
        return index;
    }

    // Member hashing function
    size_t hash(const ValueType& value) const {
        return value % table.size();
    }

public:
    HashMap(size_t initialSize) {
        table.resize(initialSize);
    }

    void insert(const ValueType& value) {
        // If table is completely full, throw error
        if (table_full()) {
            throw std::runtime_error("Table is full.");
        }
        // if (size >= table.size() / 2) {
        //     rehash(); // Rehash if load factor is greater than 0.5
        // }

        size_t index = hash(value);

        if (table[index].state == EntryState::Occupied) {
            index = quadratic_probe(index);
        }

        // Insert new entry
        table[index].value = value;
        table[index].state = EntryState::Occupied;
    }

    std::vector<ValueType> get_all() const {
        std::vector<ValueType> values;

        for (const auto& entry : table) {
            if (entry.state == EntryState::Occupied) {
                values.push_back(entry.value);
            }
            else if (entry.state == EntryState::Deleted) {
                values.push_back(-1);
            }
            else {
                values.push_back(0);
            }
        }

        return values;
    }

    // Remove
    void remove(size_t index) {
        if (index >= table.size()) {
            throw std::runtime_error("Index out of bounds.");
        }

        table[index].state = EntryState::Deleted;
    }

    void rehash() {
        size_t newSize = table.size() * 2;
        std::vector<Entry> newTable(newSize);

        for (const auto& entry : table) {
            if (entry.state == EntryState::Occupied) {
                size_t index = 0;
                size_t i = 0;

                if (newTable[index].state == EntryState::Occupied) {
                    index = quadratic_probe(index);
                }

                newTable[index] = entry;
            }
        }

        table = std::move(newTable);
    }

    bool table_full(){
        for (const auto& entry : table) {
            if (entry.state == EntryState::Available) {
                return false;
            }
        }
        return true;
    }

    size_t getSize() const {
        return table.size();
    }
};
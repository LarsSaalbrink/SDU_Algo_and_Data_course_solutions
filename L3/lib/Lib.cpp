#include "Lib.h"
#include <iostream>
#include <vector>
#include <optional>

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

void task0_1()
{
    std::cout << "\n\n---------- Task 0.1 ----------" << std::endl;

    #define VAR_TYPE int
    HashMap<VAR_TYPE> hashmap(16);

    std::cout << "5 Elements hashing to position 2" << std::endl;
    hashmap.insert(2);
    hashmap.insert(18);
    hashmap.insert(34);
    hashmap.insert(50);
    hashmap.insert(66);

    std::cout << "Size of hashmap: " << hashmap.getSize() << std::endl;
    std::vector<VAR_TYPE> values = hashmap.get_all();
    for (size_t i = 0; i < values.size(); i++)
    {
        std::cout << "Index: " << i << " Value: " << values[i] << std::endl;
    }
}
void task0_2()
{
    std::cout << "\n\n---------- Task 0.2 ----------" << std::endl;

    #define VAR_TYPE int
    HashMap<VAR_TYPE> hashmap(11);

    std::cout << "6 Elements hashing to position 2" << std::endl;
    hashmap.insert(2);
    hashmap.insert(13);
    hashmap.insert(24);
    hashmap.insert(35);
    hashmap.insert(46);
    hashmap.insert(57);

    std::cout << "Size of hashmap: " << hashmap.getSize() << std::endl;
    std::vector<VAR_TYPE> values = hashmap.get_all();
    for (size_t i = 0; i < values.size(); i++)
    {
        std::cout << "Index: " << i << " Value: " << values[i] << std::endl;
    }
}
void task0_3(){
    std::cout << "\n\n---------- Task 0.3 ----------" << std::endl;
    std::cout << "Either requires a dummy element at the deleted pos, a flag system or a rehashing of the table" << std::endl;
}


void task1(){
    std::cout << "\n\n---------- Task 1 ----------" << std::endl;

    #define VAR_TYPE int
    HashMap<VAR_TYPE> hashmap(11);

    hashmap.insert(22);
    hashmap.insert(5);
    hashmap.insert(16);
    hashmap.insert(27);

    std::cout << "Size of hashmap: " << hashmap.getSize() << std::endl;
    std::vector<VAR_TYPE> values = hashmap.get_all();
    for (size_t i = 0; i < values.size(); i++)
    {
        std::cout << "Index: " << i << " Value: " << values[i] << std::endl;
    }

    std::cout << "Order was correct!\n" << std::endl;

    hashmap.insert(1);
    hashmap.insert(12);
    hashmap.insert(23);
    hashmap.insert(23);
    hashmap.insert(12345678);

    std::cout << "Size of hashmap: " << hashmap.getSize() << std::endl;
    values = hashmap.get_all();
    for (size_t i = 0; i < values.size(); i++)
    {
        std::cout << "Index: " << i << " Value: " << values[i] << std::endl;
    }
}
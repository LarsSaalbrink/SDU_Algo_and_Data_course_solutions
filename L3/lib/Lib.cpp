#include "Lib.h"
#include "crappy_hashmap.h"
#include "balls.h"

#include <iostream>
#include <optional>
#include <vector>

void task0_1() {
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
    for (size_t i = 0; i < values.size(); i++) {
        std::cout << "Index: " << i << " Value: " << values[i] << std::endl;
    }
}
void task0_2() {
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
    for (size_t i = 0; i < values.size(); i++) {
        std::cout << "Index: " << i << " Value: " << values[i] << std::endl;
    }
}
void task0_3() {
    std::cout << "\n\n---------- Task 0.3 ----------" << std::endl;
    std::cout << "Either requires a dummy element at the deleted pos, a flag "
                 "system or a rehashing of the table"
              << std::endl;
}

void task1() {
    std::cout << "\n\n---------- Task 1 ----------" << std::endl;

#define VAR_TYPE int
    HashMap<VAR_TYPE> hashmap(11);

    hashmap.insert(22);
    hashmap.insert(5);
    hashmap.insert(16);
    hashmap.insert(27);

    std::cout << "Size of hashmap: " << hashmap.getSize() << std::endl;
    std::vector<VAR_TYPE> values = hashmap.get_all();
    for (size_t i = 0; i < values.size(); i++) {
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
    for (size_t i = 0; i < values.size(); i++) {
        std::cout << "Index: " << i << " Value: " << values[i] << std::endl;
    }
}

void task2() {
    std::cout << "\n\n---------- Task 2 ----------" << std::endl;

    std::cout << "Random fill strategy" << std::endl;
    std::cout << "10007 bins, 10007 balls, 1000 runs" << std::endl;
    ball_experiment_run(10007, 10007, 1000, fill_bins_random);
    std::cout << "32749 bins, 32749 balls, 1000 runs" << std::endl;
    ball_experiment_run(32749, 32749, 1000, fill_bins_random);
    // ball_experiment_run(655210, 655210, 1000, fill_bins_random);  //Yields 1,
    // 8

    std::cout << "\nPower of two choices fill strategy" << std::endl;
    std::cout << "10007 bins, 10007 balls, 1000 runs" << std::endl;
    ball_experiment_run(10007, 10007, 1000, fill_bins_potc);
    std::cout << "32749 bins, 32749 balls, 1000 runs" << std::endl;
    ball_experiment_run(32749, 32749, 1000, fill_bins_potc);
}

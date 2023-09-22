#include "Lib.h"
#include "crappy_hashmap.h"

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

// Balls & bins
void fill_bins_random(std::vector<size_t> &bins, size_t balls) {
    // Clear all bins
    for (size_t i = 0; i < bins.size(); i++) {
        bins[i] = 0;
    }

    // Fill bins randomly
    for (size_t i = 0; i < balls; i++) {
        size_t bin = rand() % bins.size();
        bins[bin]++;
    }
}
size_t average_of_bins(std::vector<size_t> &bins) {
    int sum = 0;
    for (size_t i = 0; i < bins.size(); i++) {
        sum += bins[i];
    }
    return sum / bins.size();
}
size_t max_of_bins(std::vector<size_t> &bins) {
    size_t max = 0;
    for (size_t i = 0; i < bins.size(); i++) {
        if (bins[i] > max) {
            max = bins[i];
        }
    }
    return max;
}

void ball_experiment_run(size_t num_bins, size_t num_balls, size_t number_of_runs) {
    size_t balls = num_bins;
    std::vector<size_t> bins(num_balls, 0);

    // Calculate "average" and "max" average value across NUM_OF_RUNS runs
    std::vector<size_t> averages(number_of_runs, 0);
    std::vector<size_t> maxes(number_of_runs, 0);
    for (size_t i = 0; i < number_of_runs; i++) {
        fill_bins_random(bins, balls);
        averages[i] = average_of_bins(bins);
        maxes[i] = max_of_bins(bins);
    }

    size_t experiment_average = 0;
    size_t experiment_max = 0;
    for (size_t i = 0; i < number_of_runs; i++) {
        experiment_average += averages[i];
        experiment_max += maxes[i];
    }
    experiment_average /= number_of_runs;
    experiment_max /= number_of_runs;

    std::cout << "Average amount of balls in a bin across " << number_of_runs
              << " experiments: " << experiment_average << std::endl;
    std::cout << "Largest amount of balls in a bin on average across "
              << number_of_runs << " experiments: " << experiment_max << std::endl;
}

void task2() {
    std::cout << "\n\n---------- Task 2 ----------" << std::endl;

    ball_experiment_run(10007, 10007, 1000);
    ball_experiment_run(32749, 32749, 1000);
    // ball_experiment_run(655210, 655210, 1000);  //Yields 1, 8
}

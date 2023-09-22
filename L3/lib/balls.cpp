#include "balls.h"

#include <iostream>

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
void fill_bins_potc(std::vector<size_t> &bins, size_t balls) {
    // Clear all bins
    for (size_t i = 0; i < bins.size(); i++) {
        bins[i] = 0;
    }

    // Fill bins according to power of two choices algorithm
    for (size_t i = 0; i < balls; i++) {
        size_t bin1 = rand() % bins.size();
        size_t bin2 = rand() % bins.size();
        if (bins[bin1] < bins[bin2]) {
            bins[bin1]++;
        } else {
            bins[bin2]++;
        }
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

void ball_experiment_run(size_t num_bins, size_t num_balls,
                         size_t number_of_runs,
                         void (*bin_fill_strategy)(std::vector<size_t> &,
                                                   size_t)) {
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
              << number_of_runs << " experiments: " << experiment_max
              << std::endl;
}
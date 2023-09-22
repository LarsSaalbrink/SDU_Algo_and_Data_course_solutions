#include <vector>
#include <cstddef>

void fill_bins_random(std::vector<size_t> &bins, size_t balls);
void fill_bins_potc(std::vector<size_t> &bins, size_t balls);

void ball_experiment_run(size_t num_bins, size_t num_balls,
                         size_t number_of_runs,
                         void (*bin_fill_strategy)(std::vector<size_t> &,
                                                   size_t));
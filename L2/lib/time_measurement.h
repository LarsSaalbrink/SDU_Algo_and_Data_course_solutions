#ifndef TIME_MEASUREMENT_H
#define TIME_MEASUREMENT_H

#include <chrono>
#include <iostream>
#include <vector>

extern std::vector<std::vector<double>> execution_times;

// Function to measure execution time of
// function with variable amount of arguments
// and a return value
template <typename Func, typename... Args>
auto measure_execution_time(Func func, Args &&...args) {
    auto start = std::chrono::high_resolution_clock::now();
    auto result = func(std::forward<Args>(args)...); // Call the function
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;

    std::cout << "Execution time: " << duration.count() << " seconds"
              << std::endl;

    execution_times.back().push_back(duration.count());

    return result;
}

// Function to measure execution time of
// function with variable amount of arguments
// and no return value
template <typename Func, typename... Args>
void measure_execution_time_no_ret(Func func, Args &&...args) {
    auto start = std::chrono::high_resolution_clock::now();
    func(std::forward<Args>(args)...); // Call the function
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;

    std::cout << "Execution time: " << duration.count() << " seconds"
              << std::endl;

    execution_times.back().push_back(duration.count());
}

#endif // TIME_MEASUREMENT_H

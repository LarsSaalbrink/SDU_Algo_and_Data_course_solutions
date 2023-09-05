#ifndef TIME_MEASUREMENT_H
#define TIME_MEASUREMENT_H

#include <chrono>

// Function to measure execution time of
// function with variable amount of arguments
template <typename Func, typename... Args>
void measureExecutionTime(Func func, Args &&...args) {
  auto start = std::chrono::high_resolution_clock::now();
  func(std::forward<Args>(args)...); // Call the function
  auto end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> duration = end - start;

  std::cout << "Execution time: " << duration.count() << " seconds"
            << std::endl;
}

#endif // TIME_MEASUREMENT_H

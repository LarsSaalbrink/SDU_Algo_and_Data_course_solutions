#include <iostream>

#include "Lib.h"
#include "time_measurement.h"

// Example function to be measured
void exampleFunction(int arg, int a, double b, const std::string &c) {
    std::cout << "a: " << a << ", b: " << b << ", c: " << c << std::endl;
    double n = 0;
    for (int i = 0; i < arg; ++i) {
        n++;
    }
}

int main() {
    measureExecutionTime(exampleFunction, 100000000, 42, 3.14, "Hello");

    return 0;
}

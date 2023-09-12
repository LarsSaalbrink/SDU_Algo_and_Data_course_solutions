#include <iostream>

#include "Lib.h"
#include "time_measurement.h"

#include "Matplotlibcpp.h"
#include <chrono>
#include <vector>
namespace mpl = matplotlibcpp;

std::vector<std::vector<double>> execution_times;

void plotVector(std::vector<double> data, std::string title) {
    // Plot red line
    mpl::plot(data, "r-");

    // Title
    mpl::title(title);

    // No x axis labels
    std::vector<std::string> xticks;
    std::vector<int> xticksPos;
    mpl::xticks(xticksPos, xticks);

    // y axis label
    mpl::ylabel("Seconds");

    // Show plot
    mpl::show();
}

void plot_testresult(std::string title) {
    plotVector(execution_times.back(), title);
}

int main() {
    test1();
    test3();
    test2();

    return 0;
}

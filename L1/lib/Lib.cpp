#include "Lib.h"
#include "time_measurement.h"

#include <iostream>

/* 1
 * int sum(int n);
 * Returns the sum of the first n natural numbers.
 */
int sum(int n) { // Should be unsigned int
    if (n == 0) {
        return 0;
    }
    return n + sum(n - 1);
}
void test1() {
    execution_times.push_back(std::vector<double>());

    std::cout << "\n---Test 1: sum()---" << std::endl;
    auto output = measure_execution_time(sum, 0);
    std::cout << "sum(0) = " << output << std::endl << std::endl;

    output = measure_execution_time(sum, 1000);
    std::cout << "sum(1000) = " << output << std::endl << std::endl;

    output = measure_execution_time(sum, 2000);
    std::cout << "sum(2000) = " << output << std::endl << std::endl;

    output = measure_execution_time(sum, 3000);
    std::cout << "sum(3000) = " << output << std::endl << std::endl;

    output = measure_execution_time(sum, 4000);
    std::cout << "sum(4000) = " << output << std::endl << std::endl;

    output = measure_execution_time(sum, 5000);
    std::cout << "sum(5000) = " << output << std::endl << std::endl;

    output = measure_execution_time(sum, 6000);
    std::cout << "sum(6000) = " << output << std::endl << std::endl;

    output = measure_execution_time(sum, 7000);
    std::cout << "sum(7000) = " << output << std::endl << std::endl;

    output = measure_execution_time(sum, 8000);
    std::cout << "sum(8000) = " << output << std::endl << std::endl;

    output = measure_execution_time(sum, 9000);
    std::cout << "sum(9000) = " << output << std::endl << std::endl;

    output = measure_execution_time(sum, 10000);
    std::cout << "sum(10000) = " << output << std::endl << std::endl;
}

/* 2
 * int evenSquareSum(int n);
 * Returns the sum of the first n even numbers' squares.
 */
int evenSquareSum(int n) { // Should be unsigned int
    if (n == 0) {
        return 0;
    }
    return 2 * n * 2 * n + evenSquareSum(n - 1);
}
void test2() {
    std::cout << "\n---Test 2: evenSquareSum()---" << std::endl;
    auto output = measure_execution_time(evenSquareSum, 0);
    std::cout << "evenSquareSum(0) = " << output << std::endl << std::endl;

    output = measure_execution_time(evenSquareSum, 1);
    std::cout << "evenSquareSum(1) = " << output << std::endl << std::endl;

    output = measure_execution_time(evenSquareSum, 42);
    std::cout << "evenSquareSum(42) = " << output << std::endl << std::endl;

    output = measure_execution_time(evenSquareSum, 1000);
    std::cout << "evenSquareSum(10000) = " << output << std::endl << std::endl;
}

/* 3
 * int fib(int n);
 * Returns the nth Fibonacci number.
 */
// https://en.wikipedia.org/wiki/Fibonacci_sequence
int fib(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}
void test3() {
    std::cout << "\n---Test 3: fib()---" << std::endl;
    auto output = measure_execution_time(fib, 0);
    std::cout << "fib(0) = " << output << std::endl << std::endl;

    output = measure_execution_time(fib, 1);
    std::cout << "fib(1) = " << output << std::endl << std::endl;

    output = measure_execution_time(fib, 2);
    std::cout << "fib(2) = " << output << std::endl << std::endl;

    output = measure_execution_time(fib, 3);
    std::cout << "fib(3) = " << output << std::endl << std::endl;

    output = measure_execution_time(fib, 42);
    std::cout << "fib(42) = " << output << std::endl << std::endl;
}

/* 4
 * bool linear(string s, char c, int l)
 * Returns true if string s with length l containes char c,
 * otherwise false.
 */
bool linear(std::string s, char c, int l) {
    if (l == 0) {
        return false;
    }
    if (s[l - 1] == c) {
        return true;
    }
    return linear(s, c, l - 1);
}
void test4() {
    std::cout << "\n---Test 4: linear()---" << std::endl;
    std::string s = "Hello World!";
    auto output = measure_execution_time(linear, s, 'o', s.length());

    std::cout << "linear(\"" << s << "\", 'o', " << s.length()
              << ") = " << (output ? "true" : "false") << std::endl
              << std::endl;

    output = measure_execution_time(linear, s, 'x', s.length());
    std::cout << "linear(\"" << s << "\", 'x', " << s.length()
              << ") = " << (output ? "true" : "false") << std::endl
              << std::endl;
}

/* 5
 * bool binarySearch(int arr[], int value)
 * Returns true if value is in arr, otherwise false.
 * The elements are sorted
 */
bool binarySearch(int arr[], int value) {
    // Static variables as function template does not include left & right
    static int left = 0;
    static int right = -1;

    if (right == -1) {  // Initialize right
        right = sizeof(arr);
    }

    if (left > right) {
        // Reset left and right for the next search
        left = 0;
        right = -1;
        return false; // Element not found
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == value) {
        // Reset left and right for the next search
        left = 0;
        right = -1;
        return true; // Element found
    } else if (arr[mid] > value) {
        // Search the left half
        right = mid - 1;
    } else {
        // Search the right half
        left = mid + 1;
    }

    return binarySearch(arr, value);
}
void test5() {
    std::cout << "\n---Test 5: binarySearch()---" << std::endl;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    auto output = measure_execution_time(binarySearch, arr, 7);
    std::cout << "binarySearch([1, 2, 3, 4, 5, 6, 7, 8], 5) = "
              << (output ? "true" : "false") << std::endl
              << std::endl;

    output = measure_execution_time(binarySearch, arr, 9);
    std::cout << "binarySearch([1, 2, 3, 4, 5, 6, 7, 8], 9) = "
              << (output ? "true" : "false") << std::endl
              << std::endl;
}
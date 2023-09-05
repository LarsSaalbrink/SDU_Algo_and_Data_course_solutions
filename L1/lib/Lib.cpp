#include "Lib.h"
#include "time_measurement.h"

#include <iostream>

using namespace std;

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
    cout << "\n---Test 1: sum()---" << endl;
    auto output = measure_execution_time(sum, 0);
    cout << "sum(0) = " << output << endl << endl;

    output = measure_execution_time(sum, 1);
    cout << "sum(1) = " << output << endl << endl;

    output = measure_execution_time(sum, 42);
    cout << "sum(42) = " << output << endl << endl;

    output = measure_execution_time(sum, 100000);
    cout << "sum(10000) = " << output << endl << endl;
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
    cout << "\n---Test 2: evenSquareSum()---" << endl;
    auto output = measure_execution_time(evenSquareSum, 0);
    cout << "evenSquareSum(0) = " << output << endl << endl;

    output = measure_execution_time(evenSquareSum, 1);
    cout << "evenSquareSum(1) = " << output << endl << endl;

    output = measure_execution_time(evenSquareSum, 42);
    cout << "evenSquareSum(42) = " << output << endl << endl;

    output = measure_execution_time(evenSquareSum, 1000);
    cout << "evenSquareSum(10000) = " << output << endl << endl;
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
    cout << "\n---Test 3: fib()---" << endl;
    auto output = measure_execution_time(fib, 0);
    cout << "fib(0) = " << output << endl << endl;

    output = measure_execution_time(fib, 1);
    cout << "fib(1) = " << output << endl << endl;

    output = measure_execution_time(fib, 42);
    cout << "fib(42) = " << output << endl << endl;
}

/* 4
 * bool linear(string s, char c, int l)
 * Returns true if string s with length l containes char c,
 * otherwise false.
 */
bool linear(string s, char c, int l) {
    if (l == 0) {
        return false;
    }
    if (s[l - 1] == c) {
        return true;
    }
    return linear(s, c, l - 1);
}
void test4() {
    cout << "\n---Test 4: linear()---" << endl;
    string s = "Hello World!";
    auto output = measure_execution_time(linear, s, 'o', s.length());

    cout << "linear(\"" << s << "\", 'o', " << s.length()
         << ") = " << (output ? "true" : "false") << endl
         << endl;

    output = measure_execution_time(linear, s, 'x', s.length());
    cout << "linear(\"" << s << "\", 'x', " << s.length()
         << ") = " << (output ? "true" : "false") << endl
         << endl;
}

/* 5
 * bool binarySearch(int arr[], int value)
 * Returns true if value is in arr, otherwise false.
 * The elements are sorted
 */
bool binarySearch(int arr[], int value) {
    int begin = 0;
    int mid = 0;
    int end = sizeof(arr);

    while (begin <= end) {
        mid = (begin + end) / 2;
        if (arr[mid] < value)
            begin = mid + 1;
        else if (arr[mid] > value)
            end = mid - 1;
        else
            return true;
    }
    return false;
}
void test5() {
    cout << "\n---Test 5: binarySearch()---" << endl;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    auto output = measure_execution_time(binarySearch, arr, 5);
    cout << "binarySearch([1, 2, 3, 4, 5, 6, 7, 8], 5) = "
         << (output ? "true" : "false") << endl
         << endl;

    output = measure_execution_time(binarySearch, arr, 9);
    cout << "binarySearch([1, 2, 3, 4, 5, 6, 7, 8], 9) = "
         << (output ? "true" : "false") << endl
         << endl;
}
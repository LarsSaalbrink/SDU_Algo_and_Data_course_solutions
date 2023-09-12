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
// int fib(int n) {
//     if (n == 0 || n == 1) {
//         return n;
//     }
//     return fib(n - 1) + fib(n - 2);
// }

// Recursive Fibonacci function with memoization
// test3 shows that this is roughly 1000000 times faster for call fib(42)
// Integer overflow occurs at fib(93)
// uint64_t fib(uint64_t n) {
//     static uint64_t memo[100] = {0};
//     if (n == 0 || n == 1) {
//         return n;
//     }
//     if (memo[n] != 0) {
//         return memo[n];
//     }
//     memo[n] = fib(n - 1) + fib(n - 2);
//     return memo[n];
// }

// Recursive Fibonacci function with memoization & larger type
void fib(mpz_t result, unsigned long n) {
    static mpz_t memo[100000];
    static int initialized = 0;

    if (!initialized) {
        for (int i = 0; i < 1000; i++) {
            mpz_init(memo[i]);
        }
        initialized = 1;
    }

    if (n == 0 || n == 1) {
        mpz_set_ui(result, n);
        return;
    }

    if (mpz_cmp_ui(memo[n], 0) != 0) {
        mpz_set(result, memo[n]);
        return;
    }

    mpz_t temp1, temp2;
    mpz_init(temp1);
    mpz_init(temp2);

    fib(temp1, n - 1);
    fib(temp2, n - 2);

    mpz_add(result, temp1, temp2);

    mpz_set(memo[n], result);

    mpz_clear(temp1);
    mpz_clear(temp2);
}
void test3() {
    std::cout << "\n---Test 3: fib()---" << std::endl;
    mpz_t result;
    mpz_init(result);

    uint64_t num = 0;
    measure_execution_time_no_ret(fib, result, num);
    gmp_printf("Fib(%lu) = %Zd\n\n", num, result);

    num = 1;
    measure_execution_time_no_ret(fib, result, num);
    gmp_printf("Fib(%lu) = %Zd\n\n", num, result);

    num = 2;
    measure_execution_time_no_ret(fib, result, num);
    gmp_printf("Fib(%lu) = %Zd\n\n", num, result);

    num = 4;
    measure_execution_time_no_ret(fib, result, num);
    gmp_printf("Fib(%lu) = %Zd\n\n", num, result);

    num = 42;
    measure_execution_time_no_ret(fib, result, num);
    gmp_printf("Fib(%lu) = %Zd\n\n", num, result);

    num = 93;
    measure_execution_time_no_ret(fib, result, num);
    gmp_printf("Fib(%lu) = %Zd\n\n", num, result);

    num = 100;
    measure_execution_time_no_ret(fib, result, num);
    gmp_printf("Fib(%lu) = %Zd\n\n", num, result);

    num = 1000;
    measure_execution_time_no_ret(fib, result, num);
    gmp_printf("Fib(%lu) = %Zd\n\n", num, result);

    num = 5000;
    measure_execution_time_no_ret(fib, result, num);
    gmp_printf("Fib(%lu) = %Zd\n\n", num, result);

    num = 92000;
    measure_execution_time_no_ret(fib, result, num);
    gmp_printf("Fib(%lu) = %Zd\n\n", num, result);

    // Count digits of output
    int digits = 0;
    mpz_t temp;
    mpz_init(temp);
    mpz_set(temp, result);
    while (mpz_cmp_ui(temp, 0) != 0) {
        mpz_tdiv_q_ui(temp, temp, 10);
        digits++;
    }
    mpz_clear(temp);
    std::cout << "Last fibonacci number has " << digits << " digits."
              << std::endl
              << std::endl;
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
    // Static variables as function protoype does not include left & right
    static int left = 0;
    static int right = -1;

    if (right == -1) { // Initialize right
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
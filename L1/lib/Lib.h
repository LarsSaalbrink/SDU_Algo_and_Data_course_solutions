#ifndef LIB_H
#define LIB_H

#include <gmp.h>
#include <string>

int sum(int n);
void test1();

int evenSquareSum(int n);
void test2();

// int fib(int n);
// uint64_t fib(uint64_t n);
void fib(mpz_t result, uint64_t n);
void test3();

bool linear(std::string s, char c, int l);
void test4();

bool binarySearch(int arr[], int value);
void test5();

#endif // LIB_H

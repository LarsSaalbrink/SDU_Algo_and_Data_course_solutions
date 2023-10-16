#include "Lib.h"
#include "is_sum_present.h"
#include "anagram_check.h"

#include <iostream>

void task1(){
    std::cout << "\n\n---------- Task 1 ----------" << std::endl;
    std::cout << "Quadratic algorithm:" << std::endl;
    std::vector<int> table = {1, 2, 3, 4, 5};
    std::cout << "Sum is " << (is_sum_present_quadratic(table, 5) ? "present" : "not present") << std::endl;

    table = {1, 2, 3, 5, 9};
    std::cout << "Sum is " << (is_sum_present_quadratic(table, 7) ? "present" : "not present") << std::endl;

    table = {1, 2, 3, 4, 5};
    std::cout << "Sum is " << (is_sum_present_quadratic(table, 50) ? "present" : "not present") << std::endl;

    table = {};
    std::cout << "Sum is " << (is_sum_present_quadratic(table, 5) ? "present" : "not present") << std::endl;

    std::cout << "Linear algorithm:" << std::endl;
    table = {1, 2, 3, 4, 5};
    std::cout << "Sum is " << (is_sum_present_linear(table, 5) ? "present" : "not present") << std::endl;

    table = {1, 2, 3, 5, 9};
    std::cout << "Sum is " << (is_sum_present_linear(table, 7) ? "present" : "not present") << std::endl;

    table = {1, 2, 3, 4, 5};
    std::cout << "Sum is " << (is_sum_present_linear(table, 50) ? "present" : "not present") << std::endl;

    table = {};
    std::cout << "Sum is " << (is_sum_present_linear(table, 5) ? "present" : "not present") << std::endl;
}

void task2(){
    std::cout << "\n\n---------- Task 2 ----------" << std::endl;
    std::cout << "Anagram check:" << std::endl;
    std::cout << "'anagram & nagaram' -> " << (are_anagrams("anagram", "nagaram") ? "true" : "false") << std::endl;
    std::cout << "'stale & steal' -> " << (are_anagrams("stale", "steal") ? "true" : "false") << std::endl;
    std::cout << "'yeehaw & cowboy' -> " << (are_anagrams("yeehaw", "cowboy") ? "true" : "false") << std::endl;
    std::cout << "'@3608==D' & 'D==@8630' -> " << (are_anagrams("@3608==D", "D==@8630") ? "true" : "false") << std::endl;
    std::cout << "'\u03B8\u00B0' & '\u03BC\u00B0' -> " << (are_anagrams("\u03B8\u00B0", "\u03BC\u00B0") ? "true" : "false") << std::endl;
}

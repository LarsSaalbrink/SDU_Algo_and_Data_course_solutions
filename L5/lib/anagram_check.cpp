#include "anagram_check.h"
#include <map>

bool are_anagrams(std::string s1, std::string s2){
    if(s1.length() != s2.length()){
        return false;
    }
    
    // Map to support arbitrary characters
    std::map<char, int> char_count;

    // Count characters in s1
    for(int i = 0; i < s1.length(); i++){
        char_count[s1[i]]++;
    }
    for(int i = 0; i < s2.length(); i++){
        char_count[s2[i]]--;
    }
    // Check if all characters are present in equal amounts
    for(auto it = char_count.begin(); it != char_count.end(); it++){
        if(it->second != 0){
            return false;
        }
    }
    return true;
}
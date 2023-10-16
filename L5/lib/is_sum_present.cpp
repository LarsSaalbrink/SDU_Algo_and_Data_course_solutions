#include "is_sum_present.h"

bool is_sum_present_quadratic(std::vector<int>& table, int X) {
    for(int i = 0; i < table.size(); i++){
        for(int j = 0; j < table.size(); j++){
            if(table[i] + table[j] == X){
                return true;
            }
        }
    }
    return false;
}

bool is_sum_present_linear(std::vector<int>& table, int X) {
    // Table is presorted, two pointers method is applicable
    int i = 0;
    int j = table.size() - 1;
    while(i < j){
        if(table[i] + table[j] == X){
            return true;
        }
        else if(table[i] + table[j] < X){  // Too small, use larger lower term
            i++;
        }
        else{  //Too large, use smaller upper term
            j--;
        }
    }
    return false;
}
#pragma once
#include <vector>

using namespace std;

#ifndef LABA5_2026_GFG_H
#define LABA5_2026_GFG_H


template<typename T>
int contains(const T target_el, const T *arr, const size_t arr_size) {
    for (int i = 0; i < arr_size; i++) {
        if (arr[i] == target_el) return i;
    }

    return -1;
}


#endif //LABA5_2026_GFG_H

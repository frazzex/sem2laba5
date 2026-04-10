#pragma once
#include <vector>

using namespace std;

#ifndef LABA5_2026_GFG_H
#define LABA5_2026_GFG_H


template<typename T>
bool contains(const T desired_el, const T *arr, const size_t arr_size) {
    for (int i = 0; i < arr_size; i++) {
        if (arr[i] == desired_el) return true;
    }

    return false;
}


#endif //LABA5_2026_GFG_H

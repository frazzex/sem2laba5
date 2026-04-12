#ifndef LABA5_2026_UTILS_H
#define LABA5_2026_UTILS_H

#pragma once
#include <iostream>

#include "../task1/utils.h"

using namespace std;


template<typename T>
bool change(T first_el, T second_el, T *arr, size_t arr_size) {
    T temp;
    const int first_el_index = contains(first_el, arr, arr_size);
    const int second_el_index = contains(second_el, arr, arr_size);

    if (first_el_index == -1 || second_el_index == -1) {
        cout << "Одного из элементов нет в массиве! Проверьте вводные данные!\n";
        return false;
    }

    if (first_el_index != second_el_index) {
        temp = arr[first_el_index];
        arr[first_el_index] = arr[second_el_index];
        arr[second_el_index] = temp;
    }

    cout << "Два элемента массива были успешно поменяны местами!\n";
    return true;
}

template<typename T>
void print_array(const T *arr, const size_t arr_size) {
    for (int i = 0; i < arr_size; i++) cout << arr[i] << " ";
    cout << endl;
}


#endif //LABA5_2026_UTILS_H

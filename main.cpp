#include <iostream>
#include <string>

#include "task1/utils.h"
#include "task2/utils.h"

using namespace std;

void task1() {
    int arr[] = {1, 3, 2, 4, 5, 6, 7, 9, 15, 19};
    size_t arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Массив: ";
    print_array(arr, arr_size);

    cout << "Число 5 входит в массив? Ответ: " << (contains(5, arr, arr_size) ? "Да" : "Нет") << endl;
    cout << "Число 10 входит в массив? Ответ: " << (contains(10, arr, arr_size) ? "Да" : "Нет") << endl;
    cout << "Число 19 входит в массив? Ответ: " << (contains(19, arr, arr_size) ? "Да" : "Нет") << endl;
    cout << "Число 18 входит в массив? Ответ: " << (contains(18, arr, arr_size) ? "Да" : "Нет") << endl;
}

void task2() {
    int arr[] = {1, 10, 8, 14, 26, 19};
    size_t arr_size = sizeof(arr) / sizeof(arr[0]);
    int first_el = 1, second_el = 10;

    cout << "Массив: ";
    print_array(arr, arr_size);

    if (change(first_el, second_el, arr, arr_size)) {
        cout << "Массив после перестановки чисел " << first_el << " и " << second_el << ": ";
        print_array(arr, arr_size);
    }
}

int main() {
    system("chcp 65001");
    setlocale(LC_ALL, "ru");

    task2();

    return 0;
}

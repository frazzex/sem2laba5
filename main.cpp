#include <iostream>

#include "task1/utils.h"

using namespace std;

void task1() {
    int arr[] = {1, 3, 2, 4, 5, 6, 7, 9, 15, 19};
    size_t arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Массив: " << endl;
    for (int i = 0; i < arr_size; i++) cout << arr[i] << " ";
    cout << endl << endl;

    cout << "Число 5 входит в массив? Ответ: " << (contains(5, arr, arr_size) ? "Да" : "Нет") << endl;
    cout << "Число 10 входит в массив? Ответ: " << (contains(10, arr, arr_size) ? "Да" : "Нет") << endl;
    cout << "Число 19 входит в массив? Ответ: " << (contains(19, arr, arr_size) ? "Да" : "Нет") << endl;
    cout << "Число 18 входит в массив? Ответ: " << (contains(18, arr, arr_size) ? "Да" : "Нет") << endl;
}

int main() {
    system("chcp 65001");
    setlocale(LC_ALL, "ru");

    task1();

    return 0;
}

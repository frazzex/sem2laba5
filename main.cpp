#include <iostream>
#include <ostream>

#include <string>
#include <ctime>
#include <cstdlib>

#include "task1/utils.h"
#include "task2/utils.h"
#include "task3/Matrix.h"
#include "task4/Polynomial.h"
#include "task4/Rational.h"

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

void task3() {
    Matrix<int> matrix1(3, 3);
    Matrix<int> matrix2(3, 3);
    Matrix<int> matrix3{};
    cout << "Матрица 1:" << endl << matrix1 << endl << endl;
    cout << "Матрица 2:" << endl << matrix2 << endl << endl;
    cin >> matrix3;
    cout << "Матрица 3 (введенная самостоятельно):" << endl << matrix3 << endl << endl;
    Matrix<int> matrix4 = matrix1 + matrix2;
    cout << "Сложение матриц 1 и 2:" << endl << matrix4 << endl << endl;
    Matrix<int> matrix5 = matrix1 * matrix2;
    cout << "Перемножение матриц 1 и 2:" << endl << matrix5 << endl << endl;
}

void task4() {
    Polynomial poly1 (vector {5, 6});
    Polynomial poly2 (vector {2, 3, 4});
    cout << "------ INT многочлен ------" << endl;
    cout << "Первый многочлен: " << poly1 << endl;
    cout << "Второй многочлен: " << poly2 << endl << endl;

    cout << "Оператор + : " << (poly1 + poly2) << endl;
    cout << "Оператор - : " << (poly1 - poly2) << endl;
    cout << "Оператор * : " << (poly1 * poly2) << endl << endl;

    poly1 += poly2;
    cout << "Оператор += : " << (poly1) << endl;
    poly1 -= poly2;
    cout << "Оператор -= : " << (poly1) << endl;
    poly1 *= poly2;
    cout << "Оператор *= : " << (poly1) << endl << endl;

    cout << "Оператор + со скаляром 5 : " << (poly1 + 5) << endl;
    cout << "Оператор - со скаляром 5 : " << (poly1 - 5) << endl;
    cout << "Оператор * со скаляром 5 : " << (poly1 * 5) << endl << endl;

    poly1 += 4;
    cout << "Оператор += со скаляром 4: " << (poly1) << endl;

    poly1 -= 4;
    cout << "Оператор -= со скаляром 4: " << (poly1) << endl;

    poly1 *= 4;
    cout << "Оператор *= со скаляром 4: " << (poly1) << endl;




}

int main() {
    srand(time(NULL));
    system("chcp 65001");
    setlocale(LC_ALL, "ru");

    task4();

    return 0;
}

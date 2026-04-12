#ifndef LABA5_2026_MATRIX_H
#define LABA5_2026_MATRIX_H

#pragma once
#include <vector>
#include <string>
#include <ostream>
#include <istream>

using namespace std;


template<typename T>
class Matrix {
    vector<vector<T> > vec;
    int DEFAULT_SIZE = 5;

public:
    Matrix() {
        this->vec.resize(this->DEFAULT_SIZE, vector<T>(this->DEFAULT_SIZE));
        for (auto &line: this->vec) for (auto &el: line) el = 65 + rand() % (123 - 65);
    }

    Matrix(int rows, int cols) {
        this->vec.resize(rows, vector<T>(cols));
        for (auto &line: this->vec) for (auto &el: line) el = 65 + rand() % (123 - 65);
    }

    ~Matrix() {
    }

    friend ostream &operator<<(ostream &os, Matrix &matrix) {
        for (auto line: matrix.vec) {
            for (auto el: line) {
                os << el << "\t";
            }
            os << endl;
        }
        return os;
    }

    friend istream &operator>>(istream &is, Matrix &matrix) {
        int rows, cols;

        is >> rows >> cols;

        if (is.good()) {
            matrix = Matrix(rows, cols);
        }

        return is;
    }

    T get(int row, int col) {
        return this->vec[row][col];
    }

    bool set(int row, int col, T value) {
        this->vec[row][col] = value;
        return true;
    }

    Matrix operator+(const Matrix &other) {
        if (this->vec.size() != other.vec.size()
            || this->vec.size() != other.vec[0].size()
            || this->vec.empty()
            || other.vec.empty()) {
            throw invalid_argument("Для сложения матрицы должны быть одинаковых размеров!");
        }

        int rows = this->vec.size();
        int cols = this->vec[0].size();

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.vec[i][j] = this->vec[i][j] + other.vec[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix &other) const {
        if (this->vec.empty() || other.vec.empty()) {
            throw invalid_argument("Матрицы не могут быть пустыми для умножения!");
        }

        if (this->vec[0].size() != other.vec.size()) {
            throw invalid_argument("Количество столбцов первой матрицы должно быть равно количеству строк второй!");
        }

        int rows = this->vec.size();
        int cols = other.vec[0].size();
        int inner = this->vec[0].size();

        Matrix result(rows, cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.vec[i][j] = T{};

                for (int k = 0; k < inner; ++k) {
                    result.vec[i][j] = result.vec[i][j] + this->vec[i][k] * other.vec[k][j];
                }
            }
        }

        return result;
    }
};


#endif //LABA5_2026_MATRIX_H

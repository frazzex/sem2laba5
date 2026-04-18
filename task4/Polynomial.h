#ifndef LABA5_2026_POLYNOMIAL_H
#define LABA5_2026_POLYNOMIAL_H

#include <vector>
#include <iostream>

using namespace std;


template<typename T>
class Polynomial {
    vector<T> coeffs;

public:
    Polynomial(vector<T> coefficients) {
        this->coeffs = coefficients;
    }

    Polynomial(T coefficient) {
        this->coeffs.emplace_back(coefficient);
    }

    bool operator==(const Polynomial &other) const {
        if (this->coeffs.size() != other.coeffs.size()) return false;

        for (int i = 0; i < this->coeffs.size(); ++i) {
            if (this->coeffs[i] != other.coeffs[i]) return false;
        }

        return true;
    }

    bool operator!=(const Polynomial &other) const {
        return !(*this == other);
    }

    bool operator==(const T &scalar) const {
        return this->coeffs.size() == 1 && this->coeffs[0] == scalar;
    }

    bool operator!=(const T &scalar) const {
        return !(*this == scalar);
    }

    Polynomial operator+(const Polynomial &other) const {
        size_t max_size = max(this->coeffs.size(), other.coeffs.size());

        vector<T> new_coeffs(max_size, T{0});

        for (size_t i = 0; i < this->coeffs.size(); i++) {
            new_coeffs[i] = this->coeffs[i];
        }

        for (size_t i = 0; i < other.coeffs.size(); i++) {
            new_coeffs[i] += other.coeffs[i];
        }

        return Polynomial(new_coeffs);
    }

    Polynomial operator-(const Polynomial &other) const {
        size_t max_size = max(this->coeffs.size(), other.coeffs.size());

        vector<T> new_coeffs(max_size, T{0});

        for (size_t i = 0; i < this->coeffs.size(); i++) {
            new_coeffs[i] = this->coeffs[i];
        }

        for (size_t i = 0; i < other.coeffs.size(); i++) {
            new_coeffs[i] -= other.coeffs[i];
        }

        return Polynomial(new_coeffs);
    }

    Polynomial operator*(const Polynomial &other) const {
        if (coeffs.empty() || other.coeffs.empty()) {
            return Polynomial(T{0});
        }

        size_t result_size = coeffs.size() + other.coeffs.size() - 1;
        std::vector<T> new_coeffs(result_size, T{0});

        for (size_t i = 0; i < coeffs.size(); ++i) {
            for (size_t j = 0; j < other.coeffs.size(); ++j) {
                new_coeffs[i + j] += coeffs[i] * other.coeffs[j];
            }
        }

        return Polynomial(new_coeffs);
    }

    Polynomial &operator+=(const Polynomial &other) {
        *this = *this + other;
        return *this;
    }

    Polynomial &operator-=(const Polynomial &other) {
        *this = *this - other;
        return *this;
    }

    Polynomial operator *=(const Polynomial &other) {
        *this = *this * other;
        return *this;
    }

    Polynomial operator+(const T &scalar) {
        return *this + Polynomial(scalar);
    }

    Polynomial operator-(const T &scalar) {
        return Polynomial(*this - Polynomial(scalar));
    }

    Polynomial operator*(const T &scalar) {
        return Polynomial(*this * Polynomial(scalar));
    }

    Polynomial &operator+=(const T &scalar) {
        *this = *this + Polynomial(scalar);
        return *this;
    }

    Polynomial &operator-=(const T &scalar) {
        *this = *this - Polynomial(scalar);
        return *this;
    }

    Polynomial &operator*=(const T &scalar) {
        *this = *this * Polynomial(scalar);
        return *this;
    }

    friend ostream &operator<<(ostream &os, const Polynomial<T> &polynomial) {
        for (int i = polynomial.coeffs.size(); i != 0; --i) {
            os << polynomial.coeffs[i - 1] << " ";
        }
        return os;
    }

    T operator[](int index) const {
        if (index >= this->coeffs.size()) return T{};
        return this->coeffs[index];
    }

    T operator()(const T &x) const {
        if (this->coeffs.empty()) return T{};

        T result = this->coeffs.back();

        for (int i = this->coeffs.size() - 2; i >= 0; --i) {
            result = result * x + coeffs[i];
        }

        return result;
    }

    int degree() {
        return this->coeffs.size();
    }
};

template<typename T>
bool operator==(const T &scalar, const Polynomial<T> &polynomial) {
    return polynomial == scalar;
}

template<typename T>
bool operator!=(const T &scalar, const Polynomial<T> &polynomial) {
    return polynomial != scalar;
}

#endif //LABA5_2026_POLYNOMIAL_H

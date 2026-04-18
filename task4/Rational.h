#pragma once
#include <ostream>

#ifndef LABA4_2026_RATIONAL_H
#define LABA4_2026_RATIONAL_H


class Rational {
    int nominator, denominator;

    void normalize();

public:
    Rational();

    Rational(int nominator, int denominator);

    [[nodiscard]] int Numerator() const;

    [[nodiscard]] int Denominator() const;

    Rational operator+(const Rational &other) const;

    Rational operator-(const Rational &other) const;

    Rational operator*(const Rational &other) const;

    Rational operator/(const Rational &other) const;

    Rational operator+(int num) const;

    Rational operator-(int num) const;

    Rational operator*(int num) const;

    Rational operator/(int num) const;

    Rational operator+=(const Rational &other);

    Rational operator-=(const Rational &other);

    Rational operator*=(const Rational &other);

    Rational operator/=(const Rational &other);

    Rational operator+() const;

    Rational operator-() const;

    bool operator==(const Rational &other) const;

    bool operator!=(const Rational &other) const;

    friend std::ostream &operator <<(std::ostream &os, const Rational &rational);
};


#endif //LABA4_2026_RATIONAL_H

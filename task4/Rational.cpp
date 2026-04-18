#include "Rational.h"

#include <numeric>

using namespace std;

Rational::Rational() {
    this->nominator = 0;
    this->denominator = 1;
}

Rational::Rational(const int nominator, const int denominator) {
    this->nominator = nominator;
    this->denominator = denominator;
    this->normalize();
}

int Rational::Numerator() const {
    return this->nominator;
}

int Rational::Denominator() const {
    return this->denominator;
}

/*
Бинарные операторы
*/

Rational Rational::operator+(const Rational &other) const {
    int new_nominator = this->nominator * other.denominator + this->denominator * other.nominator;
    int new_denominator = this->denominator * other.denominator;
    return {new_nominator, new_denominator};
}

Rational Rational::operator-(const Rational &other) const {
    int new_nominator = this->nominator * other.denominator - this->denominator * other.nominator;
    int new_denominator = this->denominator * other.denominator;
    return {new_nominator, new_denominator};
}

Rational Rational::operator*(const Rational &other) const {
    return {
        this->nominator * other.nominator,
        this->denominator * other.denominator
    };
}

Rational Rational::operator/(const Rational &other) const {
    return {
        this->nominator * other.denominator,
        this->denominator * other.nominator
    };
}

/*
Бинарные операторы int-ов
*/

Rational Rational::operator+(int const num) const {
    return *this + Rational(num, 1);
}

Rational Rational::operator-(int const num) const {
    return *this - Rational(num, 1);
}

Rational Rational::operator*(int const num) const {
    return *this * Rational(num, 1);
}

Rational Rational::operator/(int const num) const {
    return *this / Rational(num, 1);
}

/*
Составные операторы (+=, -=, *=, /=)
*/

Rational Rational::operator+=(Rational const &other) {
    *this = *this + other;
    return *this;
}

Rational Rational::operator-=(const Rational &other) {
    *this = *this - other;
    return *this;
}

Rational Rational::operator*=(const Rational &other) {
    *this = *this * other;
    return *this;
}

Rational Rational::operator/=(const Rational &other) {
    *this = *this / other;
    return *this;
}

Rational Rational::operator+() const {
    return *this;
}

Rational Rational::operator-() const {
    return {-nominator, denominator};
}

bool Rational::operator==(const Rational &other) const {
    return this->nominator * other.denominator == this->denominator * other.nominator;
}

bool Rational::operator!=(const Rational &other) const {
    return this->nominator * other.denominator != this->denominator * other.nominator;
}

std::ostream &operator<<(std::ostream &os, const Rational &rational) {
    return os << to_string(rational.Numerator()) + "/" + to_string(rational.Denominator());
}


void Rational::normalize() {
    if (this->denominator == 0) {
        this->nominator = 0;
        this->denominator = 1;
        return;
    }

    if (this->denominator < 0) {
        this->nominator = -this->nominator;
        this->denominator = -this->denominator;
    }

    const int max_common_devisor = gcd(abs(this->nominator), this->denominator);
    this->nominator /= max_common_devisor;
    this->denominator /= max_common_devisor;
}

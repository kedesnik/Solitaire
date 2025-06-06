#include "pair.h"
#include <iostream>

using namespace std;

// Реализация методов
Pair::Pair() : first(0), second(0.0) {}

Pair::Pair(int f, double s) : first(f), second(s) {}

Pair::Pair(const Pair& p) : first(p.first), second(p.second) {}

void Pair::setFirst(int f) { first = f; }
void Pair::setSecond(double s) { second = s; }
int Pair::getFirst() const { return first; }
double Pair::getSecond() const { return second; }

bool Pair::operator>(const Pair& p) const {
    return (first > p.first) || (first == p.first && second > p.second);
}

bool Pair::operator<(const Pair& p) const {
    return (first < p.first) || (first == p.first && second < p.second);
}

bool Pair::operator==(const Pair& p) const {
    return first == p.first && second == p.second;
}

bool Pair::operator!=(const Pair& p) const {
    return !(*this == p);
}

bool Pair::operator>=(const Pair& p) const {
    return !(*this < p);
}

bool Pair::operator<=(const Pair& p) const {
    return !(*this > p);
}

void Pair::print() const {
    cout << "(" << first << ", " << second << ")";
}

// Реализация методов
void Fraction::setWhole(int w) { setFirst(w); }
void Fraction::setFractional(double f) { setSecond(f); }
int Fraction::getWhole() const { return getFirst(); }
double Fraction::getFractional() const { return getSecond(); }

void Fraction::print() const {
    cout << getWhole() << "." << getFractional() *10;
}

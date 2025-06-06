#ifndef PAIR_H
#define PAIR_H

#include <iostream>

using namespace std;

class Pair {
protected:
    int first;
    double second;

public:
    // ������������
    Pair();
    Pair(int f, double s);
    Pair(const Pair& p);

    // ������ �������
    void setFirst(int f);
    void setSecond(double s);
    int getFirst() const;
    double getSecond() const;

    // ��������� ���������
    bool operator>(const Pair& p) const;
    bool operator<(const Pair& p) const;
    bool operator==(const Pair& p) const;
    bool operator!=(const Pair& p) const;
    bool operator>=(const Pair& p) const;
    bool operator<=(const Pair& p) const;

    void print() const;
};

class Fraction : public Pair {
public:
    Fraction() : Pair() {}
    Fraction(int f, double s) : Pair(f, s) {}
    Fraction(const Fraction& f) : Pair(f) {}

    // ������ �������
    void setWhole(int w);
    void setFractional(double f);
    int getWhole() const;
    double getFractional() const;

    void print() const;
};

void task4();

#endif

#ifndef WALLET_H
#define WALLET_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdexcept>
#include <string>

using namespace std;

#define EPS 0.000000001

class Wallet {
private:
    int p5000, p2000, p1000, p500, p200, p100, p50, p10, p5, p2, p1;
    int p05, p01, p005, p001;

public:
    Wallet();
    Wallet(int _5000, int _2000, int _1000, int _500, int _200, int _100,
          int _50, int _10, int _5, int _2, int _1,
          int _05, int _01, int _005, int _001);
    Wallet(const Wallet& other);

    int get5000() const { return p5000; }
    int get2000() const { return p2000; }
    int get1000() const { return p1000; }
    int get500() const { return p500; }
    int get200() const { return p200; }
    int get100() const { return p100; }
    int get50() const { return p50; }
    int get10() const { return p10; }
    int get5() const { return p5; }
    int get2() const { return p2; }
    int get1() const { return p1; }
    int get05() const { return p05; }
    int get01() const { return p01; }
    int get005() const { return p005; }
    int get001() const { return p001; }

    double total() const;
    Wallet operator+(const Wallet& other) const;
    Wallet operator-(const Wallet& other) const;
    double operator/(const Wallet& other) const;

    bool operator==(const Wallet& other) const;
    bool operator!=(const Wallet& other) const;
    bool operator>(const Wallet& other) const;
    bool operator<(const Wallet& other) const;

    string toString() const;

    friend ostream& operator<<(ostream& os, const Wallet& wallet);
    friend istream& operator>>(istream& is, Wallet& wallet);
};

#endif

#ifndef MY_COMPLEX_H
#define MY_COMPLEX_H

#include <iostream>
#include <sstream>
#include <cmath>
#include <string>

using namespace std;

#define EPS 0.000000001

class my_complex {
    double Re, Im;

public:
    my_complex();
    my_complex(double a, double b = 0);
    my_complex(my_complex& X);
    my_complex(const my_complex& X);

    // Деструктор
    ~my_complex() {}

    // Сеттеры и геттеры
    void setRe(double x);
    void setIm(double x);
    double getRe();
    double getIm();

     // Дружественные функции
    friend void print_complex(my_complex A);
    friend my_complex operator+(my_complex A, my_complex B);
    friend bool operator==(const my_complex A, const my_complex B);
    friend ostream& operator<<(std::ostream& out, my_complex& X);
    friend ostream& operator<<(ostream& out, const my_complex& X);
    //по заданию
    friend my_complex operator-(my_complex A, my_complex B);
    friend my_complex operator*(my_complex A, my_complex B);
    friend my_complex operator/(my_complex A, my_complex B);
    friend bool operator!=(const my_complex A, const my_complex B);
    // Методы класса
    double modul();
    string trigonom();

     // Перегрузка операций
    my_complex& operator =(const my_complex& A);
    string toString();
};

void task1();


#endif

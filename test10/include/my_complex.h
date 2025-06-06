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

    // ����������
    ~my_complex() {}

    // ������� � �������
    void setRe(double x);
    void setIm(double x);
    double getRe();
    double getIm();

     // ������������� �������
    friend void print_complex(my_complex A);
    friend my_complex operator+(my_complex A, my_complex B);
    friend bool operator==(const my_complex A, const my_complex B);
    friend ostream& operator<<(std::ostream& out, my_complex& X);
    friend ostream& operator<<(ostream& out, const my_complex& X);
    //�� �������
    friend my_complex operator-(my_complex A, my_complex B);
    friend my_complex operator*(my_complex A, my_complex B);
    friend my_complex operator/(my_complex A, my_complex B);
    friend bool operator!=(const my_complex A, const my_complex B);
    // ������ ������
    double modul();
    string trigonom();

     // ���������� ��������
    my_complex& operator =(const my_complex& A);
    string toString();
};

void task1();


#endif

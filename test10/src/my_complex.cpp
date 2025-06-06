#include "my_complex.h"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

//Конструкторы
my_complex::my_complex() {
    Re = 0;
    Im = 0;
}
my_complex::my_complex(double a, double b) {
    Re = a;
    Im = b;
}
my_complex::my_complex(my_complex& X) {
    Re = X.Re;
    Im = X.Im;
}
my_complex::my_complex(const my_complex& X) {
    Re = X.Re;
    Im = X.Im;
}

// сеттеры и гееттры
void my_complex::setRe(double x) { Re = x; }
void my_complex::setIm(double x) { Im = x; }
double my_complex::getRe() { return Re; }
double my_complex::getIm() { return Im; }


//Методы класса
// Вычисление модуля комплексного числа
double my_complex::modul() {
    return sqrt(Re * Re + Im * Im);
}

// Представление в тригонометрической форме
string my_complex::trigonom() {
    double r = modul();
    double phi = atan2(Im, Re);

    // Формирование строки вида "r(cos(phi) + i*sin(phi))"
    string result = to_string(r) + "(cos(" + to_string(phi) + ") + i*sin(" + to_string(phi) + "))";
    return result;
}

// Функция преобразования в строку
string my_complex::toString() {
    ostringstream ss;
    if (abs(Im) < EPS) {
        ss << Re;
        return ss.str();
    }
    if (Im > 0)
        ss << Re << "+" << Im << "i";
    else
        ss << Re << Im << "i";
    return ss.str();
}
// Оператор присваивания
my_complex& my_complex::operator=(const my_complex& A) {
    if (&A == this)
        return *this;
    this->Re = A.Re;
    this->Im = A.Im;
    return *this;
}

// Вывод комплексного числа в традиционном формате
void print_complex(my_complex A) {
    cout << A.Re;
    if (A.Im < 0)
        cout << A.Im << "i" << endl;
    else
        cout << "+" << A.Im << "i" << endl;
}
my_complex operator+(my_complex A, my_complex B) {
    my_complex C;
    C.Re = A.Re + B.Re;
    C.Im = A.Im + B.Im;
    return C;
}
my_complex operator-(my_complex A, my_complex B) {
    return my_complex(A.Re - B.Re, A.Im - B.Im);

}
// Оператор умножения (по формуле)
my_complex operator*(my_complex A, my_complex B) {
    return my_complex(
        A.Re * B.Re - A.Im * B.Im,
        A.Re * B.Im + A.Im * B.Re
    );
}
// Оператор деления (по формуле)
my_complex operator/(my_complex A, my_complex B) {
    double d = B.Re * B.Re + B.Im * B.Im;
    return my_complex(
        (A.Re * B.Re + A.Im * B.Im) / d,
        (A.Im * B.Re - A.Re * B.Im) / d
    );
}
// Операторы сравнения
bool operator ==(const my_complex A, const my_complex B) {
    if (abs(A.Re - B.Re) < EPS && abs(A.Im - B.Im) < EPS)
        return true;
    return false;
}
bool operator!=(const my_complex A, const my_complex B) {
    return !(A == B);
}
// Операторы вывода в поток
ostream& operator<<(std::ostream& out, my_complex& X) {
    out << X.toString();
    return out;
}
ostream& operator<<(ostream& out, const my_complex& X) {
    if (abs(X.Im) < EPS) {
        out << X.Re;
    }
    else if (X.Im > 0) {
        out << X.Re << "+" << X.Im << "i";
    }
    else {
        out << X.Re << X.Im << "i";
    }
    return out;
}

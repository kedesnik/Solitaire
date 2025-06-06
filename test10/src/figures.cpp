#include "figures.h"

using namespace std;

figure::figure(double a, double b) { x = a; y = b; }
double figure::area() { return 0; }

rectangle::rectangle(double a, double b) : figure(a, b) {}
double rectangle::area() { return x * y; }

circle::circle(double a) : figure(a) {}
double circle::area() { return 3.1416 * x * x; }

triangle::triangle(double a, double b, double c) : figure(a, b) {
    // 1. Все стороны должны быть положительными
    // 2. Должно выполняться неравенство треугольника для всех комбинаций
    if (a > 0 && b > 0 && c > 0 &&
        (a + b > c) && (a + c > b) && (b + c > a)) {
        z = c;
    }
    else {
        cout << "Ошибка: стороны (" << a << ", " << b << ", " << c
     << ") не могут образовать треугольник!" << endl;
        x = y = z = 0;
    }
}

double triangle::area() {
    if (x <= 0 || y <= 0 || z <= 0) return 0;

    double p = (x + y + z) / 2;
    return sqrt(p * (p - x) * (p - y) * (p - z));
}

#include "triangle.h"
#include <iostream>
#include <iomanip>

using namespace std;

Triangle::Triangle(double sideA, double sideB, double sideC)
    : a(sideA), b(sideB), c(sideC) {
    if (!isValid()) {
        throw TriangleE("Некорректные стороны треугольника");
    }
}

double Triangle::circumradius() const {
    double p = (a + b + c) / 2.0;
    double area = sqrt(p * (p - a) * (p - b) * (p - c));
    return (a * b * c) / (4.0 * area);// Формула радиуса
}
void testTriangle(double a, double b, double c) {
    try {
        Triangle t(a, b, c);
        double radius = t.circumradius();
        cout << "Треугольник " << a << ", " << b << ", " << c
             << " имеет радиус описанной окружности: " << fixed << setprecision(2)
             << radius << endl;
    }//как специфичное исключение
    catch (const TriangleE& e) {
        cerr << "Ошибка: " << e.what() << " - стороны "
             << a << ", " << b << ", " << c << endl;
    }
}

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <stdexcept>
#include <string>
#include <cmath>

using namespace std;
// для ошибок, которые можно обнаружить только во время выполнения программы
class TriangleE : public runtime_error {
public:
    explicit TriangleE(const string& message)
        : runtime_error(message) {}
};

class Triangle {
private:
    double a, b, c;

    bool isValid() const {
        return (a + b > c) && (a + c > b) && (b + c > a) &&
               (a > 0) && (b > 0) && (c > 0);
    }
public:
    Triangle(double sideA, double sideB, double sideC);
    double circumradius() const;
};

void testTriangle(double a, double b, double c);
void task5();

#endif

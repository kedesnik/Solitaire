#ifndef FIGURES_H
#define FIGURES_H

#include <iostream>
#include <cmath>

class figure {
protected:
    double x, y;
public:
    figure(double a = 0, double b = 0);
    virtual double area();
};

class rectangle : public figure {
public:
    rectangle(double a, double b);
    double area();
};

class circle : public figure {
public:
    circle(double a);
    double area();
};

class triangle : public figure {
private:
    double z;
public:
    triangle(double a, double b, double c);
    double area();
};

void task3();

#endif

#include "my_complex.h"
#include "figures.h"
#include "wallet.h"
#include "pair.h"
#include "triangle.h"
#include <iostream>
#include <locale.h>

using namespace std;

void menu();
void task1();
void task2();
void task3();
void task4();
void task5();


int main() {
    cout << "0 - Exit" << endl;
    cout << "1 - Complex numbers" << endl;
    cout << "2 - Wallet" << endl;
    cout << "3 - Figures" << endl;
    cout << "4 - Pair and fraction" << endl;
    cout << "5 - Radius opisannoi ocrugnosti" << endl;

    setlocale(LC_ALL, "");
    menu();
    return 0;
}

void menu() {
    int n = 1;

    while (n != 0) {
        cout << "\nVibirete: ";
        cin >> n;

        switch(n) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 4:
                task4();
                break;
            case 5:
                task5();
                break;
            case 0:
                cout << "Exiting program..." << endl;
                return;
            default:
                cout << "No such task!" << endl;
                break;
        }
    }
}
void task1() {
    my_complex A, B(4, -3), C(5), D(B);
    print_complex(A);

    A.setRe(2);
    A.setIm(3);
    cout << A << endl;

    print_complex(B);
    print_complex(C);
    print_complex(D);

    my_complex P = B + C;
    print_complex(P);

    if (C == D) cout << "Yes" << endl;
    else cout << "No" << endl;
    cout << endl;

    my_complex X(1, 4), Y(2, -1);

    cout << "X: "; print_complex(X);
    cout << "Y: "; print_complex(Y);

    cout << "X - Y: " << (X - Y) << endl;
    cout << "X * Y: " << (X * Y) << endl;
    cout << "X / Y: " << (X / Y) << endl;

    cout << "X != Y? ";
    if (X != Y) cout << "Yes" << endl;

    cout << "|X| = " << X.modul() << endl;
    cout << "trigonometric forma X: " << X.trigonom() << endl;
}
void task2() {
    try {
        // Создаем первый кошелек с фиксированными значениями
        Wallet wallet1(1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
        cout << "Краткий вид: " << wallet1 << endl;
        cout << "Подробный вид:\n" << wallet1.toString() << endl << endl;

        Wallet wallet2;
        cin >> wallet2;

        cout << "\nКошелек 2:" << endl;
        cout << "Краткий вид: " << wallet2 << endl;
        cout << "Подробный вид:\n" << wallet2.toString() << endl << endl;

        Wallet sum = wallet1 + wallet2;
        cout << "Сложение кошельков:\n" << sum.toString() << endl << endl;

        Wallet diff = wallet1 - wallet2;
        cout << "Вычитание кошельков:\n" << diff.toString() << endl << endl;

        try {
            double division = wallet1 / wallet2;
            cout << "Деление сумм кошельков: " << division << endl;
        } catch (const runtime_error& e) {
            cerr << "Ошибка при делении: " << e.what() << endl << endl;
        }

        if (wallet1 == wallet2) {
            cout << "Кошельки имеют равные суммы" << endl;
        } else {
            cout << "Кошельки имеют разные суммы" << endl;
        }

        if (wallet1 > wallet2) {
            cout << "Кошелек 1 содержит большую сумму" << endl;
        } else if (wallet1 < wallet2) {
            cout << "Кошелек 2 содержит большую сумму" << endl;
        } else {
            cout << "Суммы в кошельках равны" << endl;
        }

    } catch (const invalid_argument& e) {
        cerr << "Ошибка ввода: " << e.what() << endl;
        exit(1);
    } catch (const exception& e) {
        cerr << "Произошла ошибка: " << e.what() << endl;
        exit(1);
    }
}
void task3() {
    cout << "A(2, 3)" << endl;
    cout << "B(2, 3)" << endl;
    cout << "C(3)" << endl;
    cout << "E(1, 1, 3" << endl;
    cout << "D(3, 4, 5);" << endl;
    figure A(2, 3);
    cout << "Абстрактная фигура S(A) = " << A.area() << endl;
    rectangle B(2, 3);
    cout << "Прямоугольник S(B) = " << B.area() << endl;
    circle C(3);
    cout << "Круг S(C) = " << C.area() << endl;

    triangle E(1, 1, 3);
    triangle D(3, 4, 5);

    cout << "Треугольник S(E) = " << E.area() << endl;
    cout << "Треугольник S(D) = " << D.area() << endl;

    // Демонстрация полиморфизма через указатели
    figure *X, *Y, *Z;
    X = &B;
    Y = &C;
    Z = &D;

    cout << "Площадь прямоугольника S(X) = " << X->area() << endl;
    cout << "Площадь круга S(Y) = " << Y->area() << endl;
    cout << "Площадь треугольника S(Z) = " << Z->area() << endl;
}
void task4() {
    Pair p1(3, 4.5);
    Pair p2(3, 4.0);
    Pair p3(2, 5.0);

    cout << "p1: "; p1.print(); cout << endl;
    cout << "p2: "; p2.print(); cout << endl;
    cout << "p3: "; p3.print(); cout << endl;

    cout << "\nСравнение пар:" << endl;
    cout << "p1 > p2: " << (p1 > p2) << endl;
    cout << "p1 < p2: " << (p1 < p2) << endl;
    cout << "p1 == p2: " << (p1 == p2) << endl;
    cout << "p1 != p2: " << (p1 != p2) << endl;
    cout << "p3 >= p1: " << (p3 >= p1) << endl;
    cout << "p3 <= p1: " << (p3 <= p1) << endl;

    cout << endl;
    Fraction f1(2, 0.5);  // 2.5
    Fraction f2(2, 0.3);  // 2.3
    Fraction f3(3, 0.1);  // 3.1

    cout << "f1: "; f1.print(); cout << endl;
    cout << "f2: "; f2.print(); cout << endl;
    cout << "f3: "; f3.print(); cout << endl;

    cout << "\nСравнение дробей:" << endl;
    cout << "f1 > f2: " << (f1 > f2) << endl;
    cout << "f1 < f3: " << (f1 < f3) << endl;
    cout << "f2 == f3: " << (f2 == f3)<< endl;
    cout << "f2 != f3: " << (f2 != f3)<< endl;
    cout << "f1 >= f3: " << (f1 >= f3) << endl;
    cout << "f1 <= f2: " << (f1<= f2) << endl;
}
void task5() {
    testTriangle(3, 4, 5);    // Прямоугольный треугольник
    testTriangle(5, 5, 5);    // Равносторонний треугольник
    testTriangle(7, 8, 9);    // Произвольный треугольник
    testTriangle(1, 2, 3);    // Вырожденный треугольник
    testTriangle(0, 4, 5);    // Нулевая сторона
    testTriangle(-2, 3, 4);   // Отрицательная сторона
    testTriangle(1, 1, 10);   // Невозможный треугольник
}

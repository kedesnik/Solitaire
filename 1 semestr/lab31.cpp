#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
//7
double arth(double x, double epsilon) {
    double sum = 0.0;
    double term;
    int n = 0;
    do {
        term = 1.0 / ((2 * n + 1) * pow(x, 2 * n + 1));
        sum += term;
        n++;
    } while (fabs(term) >= epsilon); 
    return sum;
}

int main() {
    double x_start, x_end, dx, epsilon;

    cout << "Введите начальное значение x: ";
    cin >> x_start;
    cout << "Введите конечное значение x: ";
    cin >> x_end;
    cout << "Введите шаг dx: ";
    cin >> dx;
    cout << "Введите точность e: ";
    cin >> epsilon;

    // Заголовок таблицы
    cout << setw(10) << "x" 
              << setw(20) << "f(x)" 
              << setw(40) << "Количество членов" << endl;
    cout << string(60, '-') << endl;
    
    for (double x = x_start; x <= x_end; x += dx) {
        double result = arth(x, epsilon);
        int terms = 0;
        double term;
        do {
            term = 1.0 / ((2 * terms + 1) * pow(x, 2 * terms + 1));
            terms++;
        } while (fabs(term) >= epsilon);

        cout << setw(10) << x 
                  << setw(20) << result 
                  << setw(30) << terms << endl;
    }

    return 0;
}

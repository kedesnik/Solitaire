#include <iostream>
using namespace std;
float explore(float eps, float x);

int main() {
  setlocale(LC_ALL, "RUS");
  float x = 0;
  float eps = 0;
  cout << "Введите x: "; cin >> x;
  cout << "Введите eps: "; cin >> eps;
  cout << "Значение Y = " << explore(eps, x);
  return 0;
}

float explore(float eps, float x) {
  float yf = 1, ys = 0;
  while (true) {
    ys = 0.5 * (yf + x / yf);
    if (abs(ys - yf) <= eps)
      break;
    yf = ys;
  } return ys;
}
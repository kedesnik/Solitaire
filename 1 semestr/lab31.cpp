
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <chrono>
using namespace std;

void Task1();
void Task1_1(int n);

void Task2();
void Task2_1(int a, int b);

void Task3();
void Task3_1(int secretNumber);

void Task4();
int Task4_1(int a, int b);

void Task5();
float Task5_1(int n, float x, float eps);

void Task6();
void Task6_1(float x, float xk, float xd, float a, float b, float c);
float Task6_2(float x, float a, float b, float c);

void Task7();
double Task7_1(int n, float x);

void Task8();
int Task8_1(int n);
int Task8_2(int n);
unsigned int fibb(unsigned short n);
long long goodFib(int a, int k = 1, int m = 1);
void Task9();
int M(int n);
int Task9_1(int n);
void bin(int(n));
//у паши 17 вариант

int main()
{
	setlocale(LC_ALL, "");
	int n;
	cout<<"Какую задачу? ";cin>>n;
	switch (n) {
		
case 1:
	Task1();
	break;
case 2:
	Task2();
	break;
case 3:
	Task3();
	break;
case 4:
	Task4();
	break;
case 5:
	Task5();
	break;
case 6:
	Task6();
	break;
case 7:
	Task7();
	break;
case 8:
	Task8();
	break;
case 9:
	Task9();
	break;
}
	//Task5();
}

void Task1() {
	int n;
	cout << "Введите число n "; cin >> n;
	Task1_1(n);
}
void Task1_1(int n){
	double P = 0.0;
	for (int i = 1; i <= n; i++) {
		P += 1.0 / (i * (i + 1));
	}
	cout << "P = " << P;
}

void Task2() {
	int a,b;
	do {
		cout << "Введите первое число "; cin >> a;
		cout << "Введите второе число отличное от первого "; cin >> a;
	} while (max(a,b) - min(a,b) == 0);

	Task2_1(a,b);
}
void Task2_1(int a, int b){
    int n;
    do {
		cout << "Введите  число "; cin >> n;
	} while (n<min(a,b) || n>max(a,b));
	cout << "Ура Вы угадали(надо было вписать число из диапазона)";
}

void Task3() {
	srand(time(0));
	int secretNumber = rand() % 100 + 1;

	Task3_1(secretNumber);
}
void Task3_1(int secretNumber){
    int userGuess = 0, countt = 0;
    while (userGuess != secretNumber) {
		cout << "Введите ваше число: "; cin >> userGuess;
		countt++;
		if (userGuess > secretNumber)
			cout << "Перелет! Попробуйте ввести число меньше." << endl;
		else if (userGuess < secretNumber)
			cout << "Недолет! Попробуйте ввести число больше." << endl;
	}
	cout << "Поздравляю! Вы угадали число " << secretNumber << " за " << countt << " попыток!" << endl;
}

void Task4() {
	int a, b;
	cout << "Введите два числа" << endl;

    cout << "Введите первое число "; cin >> a;
    cout << "Введите второе число "; cin >> b;

	cout<<Task4_1(a,b);
}
int Task4_1(int a, int b){
    while (a != b) {
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}

void Task5() {
	float eps, x;
	//int n;
	int n=1;
	cout << "Введите число x "; cin >> x;
	cout << "Введите число eps "; cin >> eps;
	//cout << "Введите число "; cin >> n;
	
	float x1 = Task5_1(n, x, eps);
	float y = 1, a = 0;
	while (abs(y - a) >= eps) {
		a = y;
		y = (a + x1 / a) / 2;
	}
	cout << "y = " << y;
}

float Task5_1(int n, float x, float eps) {
	if (n == 1) return 1;
	else return 0.5 * (Task5_1(n - 1, x, eps) + x / Task5_1(n - 1, x, eps));
}

void Task6() {
	float xn, xk, xd;
	cout << "Введите Xнач Хкон dX: "; cin >> xn >> xk >> xd;
	float a, b, c;
	cout << "Введите a b c: "; cin >> a >> b >> c;
	
	int a1 = int(a), b1 = int(b), c1 = int(c);
	float x = xn;
	int ee = (((a1 & b1)^c1)!=0);
	while (x <= xk) {
		if (ee)
			cout << setw(10)<<x << setw(10) << Task6_2(x, a, b, c) << endl;
		else
			cout << setw(10) << x << setw(10) << int(Task6_2(x, a, b, c)) << endl;
		x += xd;
	}
}
float Task6_2(float x, float a, float b, float c) {
	if (x<1 && c != 0)
        return a*pow(x,2)+(b/c);
    else if (x>15 && c==0)
        return (x-a)/pow(x-c,2) ;
    return x*x+c*c;
}
//текст до числа
void Task7() {
	float x;
	int n;
	do { 
		cout << "Введите |х|>1  n: "; cin >> x >> n;
	} while (fabs(x)==0);
	double arth = Task7_1(n,x);
	cout << "Гиперболический тангенс будет равен " << arth;
}
double Task7_1(int n, float x) {
	double y = 0;
	for (int i = 0; i <= n; i++) {
		y += 1 / ((2 * n + 1) * pow(x,(2 * n + 1)));
	}
	return y;
}
// из лекции
void Task8() {
	int a;
	cout << "Введите число "; cin >> a;
	cout << Task8_1(a);
	
}

int Task8_1(int n) {
	if (n == 0)return 0;
	else if (n == 1)return 1;
	else return Task8_1(n - 1) + Task8_2(n - 2);
}
int Task8_2(int n) {
	int* a = new int[n+1];
	a[0] = 0;
	a[1] = 1;
	for(int i=2;i<=n;i++){
        a[i] = a[i-1] + a[i-2];
	}
	return a[n];
}



void Task9() {
	int num;
	cout << "Введите число "; cin >> num;
	if (num == 0) {
        cout << "Двоичное представление: 0" << endl;
    } else {
        cout << "Двоичное представление: ";
        bin(num);
        cout << endl;
}
	
}

void bin(int n) {
	if (n > 1) {
		bin(n/2);
	}
	cout<<n%2;
}
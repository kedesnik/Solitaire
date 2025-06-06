#include <ctime>
#include <iostream>
#include <cmath>

void DoArray(int* array, unsigned len);
void PrintArray(int array[], unsigned len);
void DoVArray(float* array2, unsigned len);
void PrintVArray(float array2[], unsigned len);
float ProChet(float array2[], unsigned len);
int Sum(int array[], unsigned len);
void Men(float array2[], unsigned len, double C, double eps);
float Poisk(float array[], unsigned len, float x);
void Sort(float array2[], unsigned len);
bool chet(float num);
void Sorting(float array2[], unsigned len, float C, float eps);
void QuickSort(int array[], unsigned len);
int BinPoisk(int array2[], unsigned len, int x);
// сдано
void Task1(int* array ,unsigned n);
//сдано
void Task2(float* array2, unsigned n);
//переделано
void Task3(float* array2, unsigned n);
//переделано
void Task4(int* array ,unsigned n);
//вроде переделано
void Task5(float* array2, unsigned n);
//переделать
void Task6(float* array2, unsigned n);
void Task7(float* array2, unsigned n);
//переделать
void Task8(float* array2, unsigned n);
void Task9(int* array ,unsigned n);
void Task10(int* array ,unsigned n);
float irandf(int a, int b);
using namespace std;


int main() {
    setlocale(LC_ALL, "");
    int p;
	cout<<"Какую задачу? ";cin>>p;
	
	srand(time(0));
    unsigned n;
    cin >> n;

    float* array2 = new float[n];
    int* array = new int[n];
    switch (p) {	
case 1:
	Task1(array,n);
	break;
case 2:
	Task2(array2,n);
	break;
case 3:
	Task3(array2,n);
	break;
case 4:
	Task4(array,n);
	break;
case 5:
	Task5(array2,n);
	break;
case 6:
	Task6(array2,n);
	break;
case 7:
	Task7(array2,n);
	break;
case 8:
	Task8(array2,n);
	break;
case 9:
	Task9(array,n);
	break;
case 10:
	Task10(array,n);
	break;

}
    
    
}
    
    //1
    void Task1(int* array, unsigned n){
    //int* array = new int[n];
    DoArray(array, n);
    PrintArray(array, n);
    delete[] array;
    }

    //2
    void Task2(float* array2, unsigned n){
    DoVArray(array2, n);
    PrintVArray(array2, n);
    delete[] array2;
    }
   
    //3
    void Task3(float* array2, unsigned n){
    DoVArray(array2, n);
    PrintVArray(array2, n);
    cout << ProChet(array2, n) << endl;
    delete[] array2;
    }


    //4
    void Task4(int* array, unsigned n){
    DoArray(array, n);
    PrintArray(array, n);
    int S = Sum(array, n);
    if (S == 0)
        cout << "нет суммы" << endl;
    else
        cout << S << endl;
    delete[] array;
    }

    //5
    void Task5(float* array2, unsigned n){
    double C, eps;
    cout << "Введите число C: ";
    cin >> C;
    cout << "Введите eps: ";
    cin >> eps;
    DoVArray(array2, n);
    PrintVArray(array2, n);
    Men(array2, n, C, eps);
    PrintVArray(array2, n);
    delete[] array2;
    }

    //6
    void Task6(float* array2, unsigned n){
    DoVArray(array2, n);
    PrintVArray(array2, n);
    float x, p;
    cout << "Введите X: ";
    cin >> x;
    p = Poisk(array2, n, x);
    if (p != -1)
        cout << "Номер: " << p << endl;
    else
        cout << "Нет элемента" << endl;
    delete[] array2;
    }

    //7
    void Task7(float* array2, unsigned n){
    DoVArray(array2, n);
    PrintVArray(array2, n);
    Sort(array2, n);
    PrintVArray(array2, n);
    delete[] array2;
    }

    //8
    void Task8(float* array2, unsigned n){
    float C, eps;
    cout << "Введите число C: ";
    cin >> C;
    cout << "Введите eps: ";
    cin >> eps;
    DoVArray(array2, n);
    PrintVArray(array2, n);
    Sorting(array2, n, C, eps);
    PrintVArray(array2, n);
    delete[] array2;
    }

    //9
    void Task9(int* array, unsigned n){
    DoArray(array, n);
    PrintArray(array, n);
    QuickSort(array, n);
    PrintArray(array, n);
    delete[] array;
    }

    //10
    void Task10(int* array, unsigned n){
    DoArray(array, n);
    QuickSort(array, n);
    PrintArray(array, n);
    int x,p;
    cout << "Введите X: ";
    cin >> x;
    p = BinPoisk(array, n, x);
    if (p != -1)
        cout << "Номер " << p << endl;
    else
        cout << "Нет элемента" << endl;
    }




void DoArray(int *array, unsigned len) {
    for (unsigned i = 0; i < len; i++)
        array[i] = rand() - RAND_MAX / 2;
}
void PrintArray(int array[], unsigned len) {
    for (unsigned i = 0; i < len; i++)
        cout << i << ". " << array[i] << endl;
}
void DoVArray(float *array2, unsigned len) {
    for (unsigned i = 0; i < len; i++)
        array2[i] = irandf(-100, 100);
}
void PrintVArray(float array2[], unsigned len) {
    for (unsigned i = 0; i < len; i++)
        cout << i << ". " << array2[i] << endl;
}
float ProChet(float array2[], unsigned len) {
    float P = 1;
    for (unsigned i = 0; i < len; i += 2)
        P += abs(array2[i]);
    return P;
}
int Sum(int array[], unsigned len) {
    int n1 = -1;
    
    for (unsigned i = 0; i < len; i++)
        if (array[i] < 0){
            
                n1 = i;
                break;
        }
            
    if (n1 == -1 ) {
        return 0;
    }
    int S = 0;
    for (unsigned i = n1 + 1;i < len;  i++)
        S += array[i];
    return S;
}

void Men(float array2[], unsigned len, double C, double eps) {
    for (unsigned i = 0; i < len; i++)
        if (array2[i] < C && abs(array2[i]) > eps)
            array2[i] = 1.0 / array2[i];// - ((float)rand() / (float)rand());
}

float Poisk(float array2[], unsigned len, float x) {
    for (unsigned i = 0; i < len; i++) {
        float eps = 0.1;
        if (fabs(array2[i] - x) <= eps)
            return i;
    }
    return -1;
}
void Sort(float array2[], unsigned len) {
    for (unsigned i = 0; i < len; i++) {
        int n1 = i;
        for (unsigned j = i + 1; j < len; j++) {
            if (array2[j] < array2[n1]) {
                n1 = j;
            }
        }
        if (n1 != i) {
            float buf = array2[i];
            array2[i] = array2[n1];
            array2[n1] = buf;
        }
    }
}
bool chet(float num) {
    return (int)num % 2 == 0;
}
//2 счётчик
void Sorting(float array2[], unsigned len, float C, float eps) {
    unsigned left = 0;
    for (unsigned right = 0; right < len; right++) {
        if (abs(array2[right] - C) <= eps) {
            swap(array2[left], array2[right]); 
            left++; 
        }
    }
}
void QuickSort(int array[], unsigned len) {
    int i = 0, j = len - 1;
    int buf, p;
    p = array[len >> 1];

    do {
        while (array[i] < p)
            i++;
        while (array[j] > p)
            j--;

        if (i <= j) {
            buf = array[i];
            array[i] = array[j];
            array[j] = buf;
            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0)
        QuickSort(array, j + 1);
    if (len > i)
        QuickSort(&array[i], len - i);
}
int BinPoisk(int array[], unsigned len, int x) {

    int n1 = 0, n2 = len, mid;
    while (n1 <= n2) {
        mid = (n1 + n2) / 2;
        if (array[mid] == x)
            return mid;
        if (array[mid] > x)
            n2 = mid - 1;
        if (array[mid] < x)
            n1 = mid + 1;
    }
    return -1;
}
float irandf(int a, int b) {
    return ((rand() % (b - a + 1) + a) + 0.0) / ((rand() % (b - a + 1) + a) + 0.01);
}
 
 #include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned int>(time(0)));
    int n, m;
    cout << "введите размер первого массива" << endl;
    cin >> n >> m;
    int **arr = new int *[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new int [m];
    }
 //#7
    int p;
    cout << "введите количество стобцов во втором массиве" << endl;
    cin >> p;
    int **arr_2 = new int *[m];
    for(int j = 0; j < m; j++) {
        arr_2[j] = new int [p];
    }
    int **result = new int *[n];
    for(int i = 0; i < n; i++) {
        result[i] = new int [p];
    }
    arr1(arr_2, m, p);
    cout << "первый массив: " << endl;
    print_arr(arr, n, m);
    cout << "второй массив: " << endl;
    print_arr(arr_2, m, p);
    matrix_x_matrix(arr, arr_2, result, n, m, p);
    cout << "результат умножения двух матриц: " << endl;
    print_arr(result, n, p);

    for(int j = 0; j < m; j++)
        delete[] arr_2[j];
    delete[] arr_2;
    return 0;
}

int irand(int a, int b) {
    return rand() % (b - a + 1) + a;
}
double irand_r(int a, int b) {
    return a + (static_cast<double>(rand()) / RAND_MAX) * (b - a);
}
void arr1(int **arr, const int n, const int m)
{
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            arr[i][j] = irand(min(-n, m), max(n, m));
        }
    }
}
void print_arr(int **arr, const int n, const int m)
{
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void matrix_x_matrix(int **arr, int **arr_2, int **result, const int n, const int m, const int p)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            result[i][j] = 0;
            for (int k = 0; k < m; k++) {
                result[i][j] += arr[i][k] * arr_2[k][j];
            }
        }
    }
}
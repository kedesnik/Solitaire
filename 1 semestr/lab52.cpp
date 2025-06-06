#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
int irand(int a, int b);
double irand_r(int a, int b);
void arr1(int **arr, const int n, const int m);
void arr2(double **arr_r, const int n, const int m);
void print_arr(int **arr, const int n, const int m);
void print_arr_r(double **arr_r, const int n, const int m);
int num_max(int **arr, const int n, const int m);
void odd(double **arr_r, double *res_4, const int m, const int n);
void sort_arr(double **arr_r, double *res_4, const int n, const int m);
void count_arr(double **arr_r, int *zero, int *minus, int *plus, const int n, const int m);
void task_6_print(double **arr_r, const int n, const int m, int *minus, int *plus, int *zero);
void arr_vector_col(int **arr, int *vector_col, int *res, const int n, const int m);
void print_arr_1(int *arr, const int m);
void matrix_x_matrix(int **arr, int **arr_2, int **result, const int n, const int m, const int p);
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
    //#1
    arr1(arr, n, m);
    //cout << "Целый массив: " << endl;
    print_arr(arr, n, m);
    //#2
    double **arr_r = new double*[n];
    for (int i = 0; i < n; i++) {
        arr_r[i] = new double[m];
    }
    arr2(arr_r, n, m);
    //cout << "Действительный массив: " << endl;
    print_arr_r(arr_r, n, m);
    //#3
    //cout << "количество вхождений максимального элемента массива " << n << "x" << m << endl;
    //cout << num_max(arr, n, m) << endl;
    //#4
    double *res_4 = new double[n];
    odd(arr_r, res_4, m, n);
    sort_arr(arr_r, res_4, n, m);
    //cout << "Отсортированный массив: " << endl;
    print_arr_r(arr_r, n, m);
    //#5
    int *zero = new int[m];
    int *plus = new int[m];
    int *minus = new int[m];
    //cout << "количество нулей, отрицательных и положительных элементов вещественного массива в каждом столбце" << endl;
    count_arr(arr_r, zero, minus, plus, n, m);
    task_6_print(arr_r, n, m, minus, plus, zero);

   
    
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
    //удаление массивов
    for(int i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;
    for (int i = 0; i < n; i++) {
        delete[] arr_r[i];
    }
    delete[] arr_r;
    delete[] res_4;
    delete[] zero;
    delete[] minus;
    delete[] plus;

    for(int j = 0; j < m; j++)
        delete[] arr_2[j];
    delete[] arr_2;
    for(int i = 0; i < n; i++)
        delete[] result[i];
    delete[] result;
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
void arr2(double **arr_r, const int n, const int m)
{
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            arr_r[i][j] = irand_r(min(-n, m), max(n, m));
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
void print_arr_r(double **arr_r, const int n, const int m)
{
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            //cout << arr_r[i][j] << " ";
        }
        cout << endl;
    }
}
int num_max(int **arr, const int n, const int m)
{
    int count_max = 0;
    int n_max = 0;
    int m_max = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (arr[i][j] > arr[n_max][m_max]) {
                n_max = i;
                m_max = j;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (arr[i][j] == arr[n_max][m_max]) {
                count_max += 1;
            }
        }
    }
    return count_max;
}
void odd(double **arr_r, double *res_4, const int m, const int n) {
    double res;
    for (int i = 0; i < n; i++) {
        res = 1.0;
        bool have_odd = false;
        for (int j = 0; j < m; j++) {
            double val = arr_r[i][j];
            int proverka = static_cast<int>(fabs(arr_r[i][j]));
            if (proverka % 2 != 0) {
                res *= val;
                have_odd = true;
            }
        }
        if (have_odd == false) {
            res = 0.0;
        }
        res_4[i] = res;
    }
}
void sort_arr(double **arr_r, double *res_4, const int n, const int m) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((res_4[i] == 0.0 && res_4[j] != 0.0) || (res_4[i] > res_4[j] && res_4[j] != 0.0)) {
                for (int k = 0; k < m; k++) {
                    double temp = arr_r[i][k];
                    arr_r[i][k] = arr_r[j][k];
                    arr_r[j][k] = temp;
                }
                double temp_res = res_4[i];
                res_4[i] = res_4[j];
                res_4[j] = temp_res;
            }
        }
    }
}
void count_arr(double **arr_r, int *zero, int *minus, int *plus, const int n, const int m)
{

    for (int j = 0; j < m; j++) {
        zero[j] = 0;
        minus[j] = 0;
        plus[j] = 0;
        for (int i = 0; i < n; i++) {
            if (arr_r[i][j] == 0) {
                zero[j]++;
            }
            else if (arr_r[i][j] > 0) {
                plus[j]++;
            }
            else {
                minus[j]++;
            }
        }
    }
}
void task_6_print(double **arr_r, const int n, const int m, int *minus, int *plus, int *zero)
{
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            //cout << arr_r[i][j] << " ";
        }
        //cout << endl;
    }
   // cout << endl;
    //cout << "нули" << endl;
    for (int j = 0; j < m; j++) {
        //cout << "    ";
        //cout << zero[j] << "    ";
    }
    //cout << endl;
    //cout << "отрицательные" << endl;
    for (int j = 0; j < m; j++) {
        //cout << "    ";
        //cout << minus[j] << "    ";
    }
    //cout << endl;
    //cout << "положительные" << endl;
    for (int j = 0; j < m; j++) {
        //cout << "    ";
        //cout << plus[j] << "    ";
    }
    //cout << endl;
}

void arr_vector_col(int **arr, int *vector_col, int *res, const int n, const int m)
{
    for (int i = 0; i < n; i++) {
        res[i] = 0;
        for (int j = 0; j < m; j++) {
            res[i] += arr[i][j] * vector_col[j];
        }
    }
}
void print_arr_1(int *arr, const int m)
{
    for(int i = 0; i < m; i++) {
        cout << arr[i] << endl;
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

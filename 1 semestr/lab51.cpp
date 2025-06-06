#include <ctime>
#include <iostream>
#include <cmath>

void DoArray(int** arr, unsigned len, unsigned lem);
void PrintArray(int** arr, unsigned len, unsigned lem);
void DoVArray(float** arr, unsigned len, unsigned lem);
void PrintVArray(float** arr, unsigned len, unsigned lem);
int CountMinus(float** arr, unsigned len, unsigned lem);
float ProChet(float** arr, unsigned len, unsigned lem);
void Sort(float** arr, unsigned len, unsigned lem);
void Analis(int** an, float** arr, unsigned len, unsigned lem);
void arr_vector_col(int **arr, int *vector_col, int *res, const int n, const int m);
void print_arr_1(int *arr, const int m);

void Task1(unsigned n, unsigned m);
void Task2(unsigned n, unsigned m);
void Task3(unsigned n, unsigned m);
void Task4(unsigned n, unsigned m);
void Task5(unsigned n, unsigned m);
void Task6(unsigned n, unsigned m);
int irand(int a, int b);
float irandf(int a, int b);

using namespace std;
int main() {
    setlocale(LC_ALL, "");
    int p;
	cout<<"Какую задачу? ";cin>>p;
    srand(time(0));
    unsigned n,m;
    cin >> n >> m;

    switch (p) {	
case 1:
	Task1(n, m);
	break;
case 2:
	Task2(n, m);
	break;
case 3:
	Task3(n, m);
	break;
case 4:
	Task4(n, m);
	break;
case 5:
	Task5(n, m);
	break;
case 6:
	Task6(n, m);
	break;


}
    
    
}

void Task1(unsigned n, unsigned m){
    //1+
    int** arr = new int* [n];
    for (int i = 0; i < n; i++)
        arr[i] = new int[m];
    DoArray(arr, n, m);
    PrintArray(arr, n, m);
    delete[] arr;
    
}

void Task2(unsigned n, unsigned m){
    //2+
    float **arr = new float* [n];
    for (unsigned i = 0; i < n; i++)
        arr[i] = new float[m];
    DoVArray(arr, n, m);
    PrintVArray(arr, n, m);
    delete[] arr;
    
}

void Task3(unsigned n, unsigned m){
    //3
    float** arr = new float* [n];
    for (unsigned i = 0; i < n; i++)
        arr[i] = new float[m];
    DoVArray(arr, n, m);
    PrintVArray(arr, n, m);
    int count = CountMinus(arr, n, m);
    cout << "Количество отрицательных элементов: " << count;
    delete[] arr;
}

void Task4(unsigned n, unsigned m){
    //4
    float** arr = new float* [n];
    for (unsigned i = 0; i < n; i++)
        arr[i] = new float[m];
    DoVArray(arr, n, m);
    PrintVArray(arr, n, m);
    Sort(arr, n, m);
    PrintVArray(arr, n, m);
    delete[] arr;
    
}

void Task5(unsigned n, unsigned m){
    //5
    float** arr = new float* [n];
    for (unsigned i = 0; i < n; i++)
        arr[i] = new float[m];
    int** an = new int* [n];
    for (unsigned i = 0; i < n; i++)
        an[i] = new int[m];
    DoVArray(arr, n, m);
    PrintVArray(arr, n, m);
    Analis(an, arr, n, m);
    PrintArray(an, 3, m);
    delete[] arr;
    delete[] an;  
}

void Task6(unsigned n, unsigned m){
    int **arr = new int *[n];
    for(int i = 0; i < n; i++) 
        arr[i] = new int [m];
    int *vector_col = new int[m];
    int *res = new int[n];
    cout << "введите элементы вектора" << endl;
    for (int j = 0; j < m; j++) {
        cin >> vector_col[j];
    }
    cout << "умножение на вектор" << endl;
    arr_vector_col(arr, vector_col, res, n, m);
    print_arr_1(res, m);

delete[] arr;
}
void DoArray(int** arr, unsigned len, unsigned lem) {
    for (unsigned i = 0; i < len; i++)
        for (unsigned j = 0; j < lem; j++)
        arr[i][j] = irand(-100, 100);
}
void PrintArray(int** arr, unsigned len, unsigned lem) {
    for (unsigned i = 0; i < len; i++) {
        for (unsigned j = 0; j < lem; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
void DoVArray(float** arr, unsigned len, unsigned lem) {
    for (unsigned i = 0; i < len; i++)
        for (unsigned j = 0; j < lem; j++)
            arr[i][j] = irandf(-100, 100);
}
void PrintVArray(float** arr, unsigned len, unsigned lem) {
    for (unsigned i = 0; i < len; i++) {
        for (unsigned j = 0; j < lem; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
int CountMinus(float** arr, unsigned len, unsigned lem) {
    int count = 0;
    for (unsigned i = 0; i < len; i++) {
        for (unsigned j = 0; j < lem; j++)
            if (arr[i][j] < 0)
                count++;
    } return count;
}
float ProChet(float** arr, unsigned len, unsigned i) {
    float P = 1;
    for (unsigned j = 0; j < len; j += 2)
        P *= arr[i][j];
    return P;
}
void Sort(float** arr, unsigned len, unsigned lem) {
    for (unsigned i = 0; i < len; i++) {
        float P = ProChet(arr, lem, i);
        unsigned n1 = i;
        for (unsigned j = i + 1; j < len; j++) {
            if (ProChet(arr, lem, j) < P) {
                P = ProChet(arr, lem, j);
                n1 = j;
            }
        }
        if (P != ProChet(arr, lem, i)) {
            float* buf = new float [lem];
            for (unsigned f = 0; f < lem; f++) {
                buf[f] = arr[i][f];
                arr[i][f] = arr[n1][f];
                arr[n1][f] = buf[f];
            }
        }
    }
}
void Analis(int** an, float** arr, unsigned len, unsigned lem) {
    for (unsigned j = 0; j < lem; j++) {
        for (unsigned i = 0; i < len; i++) {
            if (arr[i][j] == 0.0)
                an[0][j] += 1;
            if (arr[i][j] > 0.0)
                an[1][j] += 1;
            if (arr[i][j] < 0.0)
                an[2][j] += 1;
        }
    }
}

int irand(int a, int b) 
{ 
  return rand()%(b-a+1)+a; 
}
float irandf(int a, int b) {
    return ((rand() % (b - a + 1) + a) + 0.0) / ((rand() % (b - a + 1) + a) + 0.01);
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
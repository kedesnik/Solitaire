#include <ctime>
#include <iostream>
#include <cmath>
#include <time.h>
using namespace std;

void Task1(unsigned n);
void Task2(unsigned n);
void Task3(unsigned n);
void Task4(unsigned n);
void Task5(unsigned n);
void Task6(unsigned n);
void Task7(unsigned n);
void Task8(unsigned n);
void Task9(unsigned n);
void Task10(unsigned n);

void IntArray(int* array, unsigned length);
float* createFloatArray(unsigned length);
void printArrayInt(int array[], unsigned length);
void printArrayFloat(float array[], unsigned length);
int* createIntArrayFromInput(unsigned length);
float* createFloatArrayFromInput(unsigned length);
void floatSelectionSort(float array[], unsigned size);
bool isFloatEven(float number);
void intFastSort(int array[], unsigned size);
void helpIntFastSort(int array[], unsigned size, unsigned low, unsigned high);
unsigned partition(int array[], unsigned size, unsigned low, unsigned high);
int intBinarySearch(int array[], unsigned size, int key);
int helpIntBinarySearch(int array[], unsigned size, int key, unsigned first, unsigned last);

int main() {
  
    unsigned n;
    cout<< "Введите n ";
    cin  >> n;
    Task2(n);
}

void Task1(unsigned n) {
    int *array = new int[n];
    IntArray(array, n );
    printArrayInt(array, n);
    delete[] array;
}
void IntArray(int* array ,unsigned length) {
    for (unsigned i = 0; i < length; i++)
        array[i] = rand() - RAND_MAX/2;
    
}
/*
void Task2(unsigned n) {
    float *array = createFloatArray(n);
    printArrayFloat(array, n);
    delete[] array;
}

void Task3(unsigned n) {
    float *array = createFloatArrayFromInput(n);
    float M = 1;
    for (unsigned i = 0; i < n; i+=2)
        M *= array[i];
    cout << M; 
    delete[] array;
}

void Task4(unsigned n) {
    int* array = createIntArrayFromInput(n);

    int first = -1;
    int last = -1;
    for (int  i = 0; i < n; i++){
        if (array[i] < 0){
            if (first == -1){
                first = i;
            }
            else {
                last = i;
            }

        }
    }
    if (first == -1 || last == -1) {
        cout << "Найти сумму не удалось" << endl;
        return;
    }

    // cout << "Первый: " << first << endl << "Последний: " << last << endl;
    // printArrayInt(array, n);

    int S = 0;
    for (unsigned i = first+1; i < last; i++) 
        S += array[i];
    cout << S << endl;
    delete[] array;
}

void Task5(unsigned n) {
    float *array = createFloatArrayFromInput(n);
    for (unsigned i = 0; i < n; i++) 
        if (array[i] > 0) 
            array[i] = -rand() - ((float)rand()/(float)rand());
    printArrayFloat(array, n);
    delete[] array;
}

void Task6(unsigned n) {
    float *array = createFloatArrayFromInput(n);
    float findEl;
    cout << "Введите элемент, который нужно найти: ";
    cin >> findEl;

    for (unsigned i = 0; i < n; i++) 
        if (abs(array[i] - findEl) < __FLT_EPSILON__) {
            cout << "Номер элемента: " << i << endl;
            return;
        }
    cout << "Элемент не найден" << endl;
    delete[] array;
}

void Task7(unsigned n) {
    float *array = createFloatArrayFromInput(n);
    floatSelectionSort(array, n);
    printArrayFloat(array, n);
    delete[] array;
}

void Task8(unsigned n) {
    float *array = createFloatArrayFromInput(n);
    for (unsigned i = 0; i < n; i++) {
        unsigned index = i;
        if (isFloatEven(array[i])) continue;
        for (unsigned j = i+1; j < n; j++) {
            if (isFloatEven(array[j])) {
                float buf = array[i];
                array[i] = array[j];
                array[j] = buf;
            }
        }
    }
    printArrayFloat(array, n);
    delete[] array;
}

void Task9(unsigned n) {
    int *array = createIntArrayFromInput(n);
    intFastSort(array, n);
    printArrayInt(array, n);
    delete[] array;
}

void Task10(unsigned n) {
    int *array = createIntArrayFromInput(n);
    int key;
    cout << "Введите число, которое надо найти: ";
    cin >> key;
    intFastSort(array, n);
    int index = intBinarySearch(array, n, key);
    if (index != -1) {
        cout << "Индекс элемента: " << index << endl;
    } else {
        cout << "Элемент не найден" << endl;
    }
    delete[] array;
}




float* createFloatArray(unsigned length) {
    float *array = new float[length];
    for (unsigned i = 0; i < length; i++)
        array[i] = rand() - RAND_MAX/2 + ((float)rand() / (float)rand());
    return array;
}

void printArrayInt(int array[], unsigned length) {
    for (unsigned i = 0; i < length; i++)
        cout << "Элемент #" << i << " - " << array[i] << endl;
}

void printArrayFloat(float array[], unsigned length) {
    for (unsigned i = 0; i < length; i++)
        cout << "Элемент #" << i << " - " << array[i] << endl;
}

int* createIntArrayFromInput(unsigned length) {
    int *array = new int[length];

    for (unsigned i = 0; i < length; i++) {
        int el;
        cin >> el;
        array[i] = el;
    }
    return array;
}

float* createFloatArrayFromInput(unsigned length) {
    float *array = new float[length];

    for (unsigned i = 0; i < length; i++) {
        float el;
        cin >> el;
        array[i] = el;
    }
    return array;
}

void floatSelectionSort(float array[], unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        int min_index = i;
        for (unsigned j = i+1; j < size; j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            float buf = array[i];
            array[i] = array[min_index];
            array[min_index] = buf;
        }
    }
}

bool isFloatEven(float number) {
    return (int)number % 2 == 0;
}

void intFastSort(int array[], unsigned size) {
    helpIntFastSort(array, size, 0, size-1);
}

void helpIntFastSort(int array[], unsigned size, unsigned low, unsigned high) {
    if (low < high) {
        unsigned mid_index = partition(array, size, low, high);
        helpIntFastSort(array, size, low, mid_index);
        helpIntFastSort(array, size, mid_index+1, high);
    }
}

unsigned partition(int array[], unsigned size, unsigned low, unsigned high) {
        int pivot = array[(low + high)/2];
        unsigned i = low;
        unsigned j = high;
        while (1) {
            while (array[i] < pivot) i++;
            while (array[j] > pivot) j--;
            if (i >= j) return j;
            int buf = array[i];
            array[i] = array[j];
            array[j] = buf;
        }
}

int intBinarySearch(int array[], unsigned size, int key) {
    printArrayInt(array, size);
    return helpIntBinarySearch(array, size, key, 0, size-1);    
}

int helpIntBinarySearch(int array[], unsigned size, int key, unsigned first, unsigned last) {
    while (first <= last) {
        unsigned mid = (first + last)/2;
        int el = array[mid];
        if (key < el) last = mid-1;
        else if (key > el) first = mid+1;
        else return mid;
    }
    return -1;
}
*/

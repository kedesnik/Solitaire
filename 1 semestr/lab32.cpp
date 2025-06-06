#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <chrono>
using namespace std;

//8
//k- предыдущее значение фиб
//m - текущее значение фиб
long long goodFib(int n, long long k = 0, long long m = 1) {
   if (n == 0) return k; // F(0) = 0 
    if (n == 1) return m; // F(1) = 1 
   return goodFib(n - 1, m, k + m); // F(n) = F(n-1) + F(n-2) 
   
}
int main(){
    int n;
    cin>>n;
    long long result = goodFib(n);
    cout<<result;
}
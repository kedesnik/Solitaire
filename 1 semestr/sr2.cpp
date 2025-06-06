#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    int x = 0;

    // Проверяем количество несовпадающих символов
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - 1 - i]) {
            x++;
        }
    }

    // Условия для вывода "YES" или "NO"
    if (x == 1 || (x == 0 && n % 2 == 1)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

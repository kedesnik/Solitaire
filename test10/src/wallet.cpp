#include "wallet.h"
#include <stdexcept>
#include <sstream>
#include <cmath>

Wallet::Wallet() : p5000(0), p2000(0), p1000(0), p500(0), p200(0), p100(0),
                  p50(0), p10(0), p5(0), p2(0), p1(0), p05(0), p01(0), p005(0), p001(0) {}

Wallet::Wallet(int _5000, int _2000, int _1000, int _500, int _200, int _100,
              int _50, int _10, int _5, int _2, int _1,
              int _05, int _01, int _005, int _001) :
              p5000(_5000), p2000(_2000), p1000(_1000), p500(_500), p200(_200), p100(_100),
              p50(_50), p10(_10), p5(_5), p2(_2), p1(_1),
              p05(_05), p01(_01), p005(_005), p001(_001) {}

Wallet::Wallet(const Wallet& other) {
    p5000 = other.p5000;
    p2000 = other.p2000;
    p1000 = other.p1000;
    p500 = other.p500;
    p200 = other.p200;
    p100 = other.p100;
    p50 = other.p50;
    p10 = other.p10;
    p5 = other.p5;
    p2 = other.p2;
    p1 = other.p1;
    p05 = other.p05;
    p01 = other.p01;
    p005 = other.p005;
    p001 = other.p001;
}

double Wallet::total() const {
    return p5000 * 5000.0 + p2000 * 2000.0 + p1000 * 1000.0 +
           p500 * 500.0 + p200 * 200.0 + p100 * 100.0 +
           p50 * 50.0 + p10 * 10.0 + p5 * 5.0 + p2 * 2.0 + p1 * 1.0 +
           p05 * 0.5 + p01 * 0.1 + p005 * 0.05 + p001 * 0.01;
}

Wallet Wallet::operator+(const Wallet& other) const {
    return Wallet(
        p5000 + other.p5000, p2000 + other.p2000, p1000 + other.p1000,
        p500 + other.p500, p200 + other.p200, p100 + other.p100,
        p50 + other.p50, p10 + other.p10, p5 + other.p5, p2 + other.p2, p1 + other.p1,
        p05 + other.p05, p01 + other.p01, p005 + other.p005, p001 + other.p001
    );
}

Wallet Wallet::operator-(const Wallet& other) const {
    return Wallet(
        p5000 - other.p5000, p2000 - other.p2000, p1000 - other.p1000,
        p500 - other.p500, p200 - other.p200, p100 - other.p100,
        p50 - other.p50, p10 - other.p10, p5 - other.p5, p2 - other.p2, p1 - other.p1,
        p05 - other.p05, p01 - other.p01, p005 - other.p005, p001 - other.p001
    );
}

double Wallet::operator/(const Wallet& other) const {
    double thisTotal = total();
    double otherTotal = other.total();
    if (fabs(otherTotal) < EPS) {
        throw runtime_error("Деление на 0");
    }
    return thisTotal / otherTotal;
}

bool Wallet::operator==(const Wallet& other) const {
    return fabs(total() - other.total()) < EPS;
}

bool Wallet::operator!=(const Wallet& other) const {
    return !(*this == other);
}

bool Wallet::operator>(const Wallet& other) const {
    return total() > other.total();
}

bool Wallet::operator<(const Wallet& other) const {
    return total() < other.total();
}

string Wallet::toString() const {
    ostringstream oss;
    oss << fixed << setprecision(2);
    oss << "5000 руб.: " << p5000 << endl;
    oss << "2000 руб.: " << p2000 << endl;
    oss << "1000 руб.: " << p1000 << endl;
    oss << "500 руб.: " << p500 << endl;
    oss << "200 руб.: " << p200 << endl;
    oss << "100 руб.: " << p100 << endl;
    oss << "50 руб.: " << p50 << endl;
    oss << "10 руб.: " << p10 << endl;
    oss << "5 руб.: " << p5 << endl;
    oss << "2 руб.: " << p2 << endl;
    oss << "1 руб.: " << p1 << endl;
    oss << "50 коп.: " << p05 << endl;
    oss << "10 коп.: " << p01 << endl;
    oss << "5 коп.: " << p005 << endl;
    oss << "1 коп.: " << p001 << endl;
    oss << "Всего: " << total() << " руб.";
    return oss.str();
}

ostream& operator<<(ostream& os, const Wallet& wallet) {
    double sum = wallet.total();
    os << fixed << setprecision(2) << sum << " руб.";
    return os;
}

istream& operator>>(istream& is, Wallet& wallet) {
    cout << "Введите количество купюр/монет каждого номинала:" << endl;
    cout<<"5000 руб: ";
    is >> wallet.p5000;
    if (wallet.p5000 < 0) throw invalid_argument("Отрицательное количество купюр 5000 руб.");
    cout<<"2000 руб: ";
    is >> wallet.p2000;
    if (wallet.p2000 < 0) throw invalid_argument("Отрицательное количество купюр 2000 руб.");
    cout<<"1000 руб: ";
    is >> wallet.p1000;
    if (wallet.p1000 < 0) throw invalid_argument("Отрицательное количество купюр 1000 руб.");
    cout<<"500 руб: ";
    is >> wallet.p500;
    if (wallet.p500 < 0) throw invalid_argument("Отрицательное количество купюр 500 руб.");
    cout<<"200 руб: ";
    is >> wallet.p200;
    if (wallet.p200 < 0) throw invalid_argument("Отрицательное количество купюр 200 руб.");
    cout<<"100 руб: ";
    is >> wallet.p100;
    if (wallet.p100 < 0) throw invalid_argument("Отрицательное количество купюр 100 руб.");
    cout<<"500 руб: ";
    is >> wallet.p50;
    if (wallet.p50 < 0) throw invalid_argument("Отрицательное количество купюр 50 руб.");
    cout<<"10 руб: ";
    is >> wallet.p10;
    if (wallet.p10 < 0) throw invalid_argument("Отрицательное количество купюр 10 руб.");
    cout<<"5 руб: ";
    is >> wallet.p5;
    if (wallet.p5 < 0) throw invalid_argument("Отрицательное количество купюр 5 руб.");
    cout<<"2 руб: ";
    is >> wallet.p2;
    if (wallet.p2 < 0) throw invalid_argument("Отрицательное количество купюр 2 руб.");
    cout<<"1 руб: ";
    is >> wallet.p1;
    if (wallet.p1 < 0) throw invalid_argument("Отрицательное количество купюр 1 руб.");
    cout<<"50 коп: ";
    is >> wallet.p05;
    if (wallet.p05 < 0) throw invalid_argument("Отрицательное количество монет 50 коп.");
    cout<<"10 коп: ";
    is >> wallet.p01;
    if (wallet.p01 < 0) throw invalid_argument("Отрицательное количество монет 10 коп.");
    cout<<"5 коп: ";
    is >> wallet.p005;
    if (wallet.p005 < 0) throw invalid_argument("Отрицательное количество монет 5 коп.");
    cout<<"1 коп: ";
    is >> wallet.p001;
    if (wallet.p001 < 0) throw invalid_argument("Отрицательное количество монет 1 коп.");

    return is;
}

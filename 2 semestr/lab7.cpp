///********************************** 
///        Лабораторная работа No7 
///      Структуры и массивы структур 
/// Выполнил студент 151412 группы 
///         Ерпулев Егор Александрович 
///             Вариант No11 
///**********************************
#include <iostream>
#include <iomanip> 
#include <cmath>    

using namespace std;

struct Time {
    int hour;    
    int minute;

    void Read() {
        do {
            cout << " часы: ";
            cin >> hour;
            cout << " минуты: ";
            cin >> minute;
        } while (!Init());
    }

    bool Init() {
        if (hour < 0 || hour > 23 || minute < 0 || minute > 59) {
            
            return false;
        }
        return true;
    }
   
    void Display() const {
        cout << setfill('0') << setw(2) << hour << ":"
            << setw(2) << minute << endl;
    }
};


int TimeDifference(const Time& t1, const Time& t2) {
    int total1 = t1.hour * 60 + t1.minute;
    int total2 = t2.hour * 60 + t2.minute;
    return abs(total1 - total2); 
}

int main() {
    setlocale(LC_ALL, "");
    Time time1, time2;

    cout << "Первое время:\n";
    time1.Read();
    while (!time1.Init()) {
        cout << "Попробуйте снова:\n";
        time1.Read();
    }

    cout << "\nВторое время:\n";
    time2.Read();
    while (!time2.Init()) {
        cout << "Попробуйте снова:\n";
        time2.Read();
    }
    cout << "\nПервое время: ";
    time1.Display();
    cout << "Второе время: ";
    time2.Display();

    int diff = TimeDifference(time1, time2);
    cout << "\nРазница : " << diff ;

    return 0;
}



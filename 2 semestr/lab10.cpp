#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <string>
#include <windows.h>


#define EPS 0.000000001

using namespace std;

// Класс комплексных чисел (Задание 1)
class my_complex {
    double Re, Im;

public:
    my_complex() : Re(0), Im(0) {}
    my_complex(double a, double b = 0) : Re(a), Im(b) {}
    my_complex(const my_complex& X) : Re(X.Re), Im(X.Im) {}

    ~my_complex() {}

    void setRe(double x) { Re = x; }
    void setIm(double x) { Im = x; }
    double getRe() const { return Re; }
    double getIm() const { return Im; }

    friend void print_complex(const my_complex& A);
    friend my_complex operator+(const my_complex& A, const my_complex& B);
    friend my_complex operator-(const my_complex& A, const my_complex& B);
    friend my_complex operator*(const my_complex& A, const my_complex& B);
    friend my_complex operator/(const my_complex& A, const my_complex& B);
    friend bool operator==(const my_complex& A, const my_complex& B);
    friend bool operator!=(const my_complex& A, const my_complex& B);
    friend ostream& operator<<(ostream& out, const my_complex& X);

    my_complex& operator=(const my_complex& A) {
        if (this != &A) {
            Re = A.Re;
            Im = A.Im;
        }
        return *this;
    }

    double modulus() const {
        return sqrt(Re * Re + Im * Im);
    }

    string toTrigonometricForm() const {
        double r = modulus();
        double phi = atan2(Im, Re);
        ostringstream ss;
        ss << r << "(cos(" << phi << ") + i*sin(" << phi << "))";
        return ss.str();
    }

    string toString() const {
        ostringstream ss;
        if (abs(Im) < EPS) {
            ss << Re;
        }
        else if (Im > 0) {
            ss << Re << "+" << Im << "i";
        }
        else {
            ss << Re << Im << "i";
        }
        return ss.str();
    }
};

void print_complex(const my_complex& A) {
    cout << A.toString() << endl;
}

my_complex operator+(const my_complex& A, const my_complex& B) {
    return my_complex(A.Re + B.Re, A.Im + B.Im);
}

my_complex operator-(const my_complex& A, const my_complex& B) {
    return my_complex(A.Re - B.Re, A.Im - B.Im);
}

my_complex operator*(const my_complex& A, const my_complex& B) {
    return my_complex(A.Re * B.Re - A.Im * B.Im, A.Re * B.Im + A.Im * B.Re);
}

my_complex operator/(const my_complex& A, const my_complex& B) {
    double denominator = B.Re * B.Re + B.Im * B.Im;
    return my_complex(
        (A.Re * B.Re + A.Im * B.Im) / denominator,
        (A.Im * B.Re - A.Re * B.Im) / denominator
    );
}

bool operator==(const my_complex& A, const my_complex& B) {
    return abs(A.Re - B.Re) < EPS && abs(A.Im - B.Im) < EPS;
}

bool operator!=(const my_complex& A, const my_complex& B) {
    return !(A == B);
}

ostream& operator<<(ostream& out, const my_complex& X) {
    out << X.toString();
    return out;
}

// Класс RGB цвета (Задание 2)
class RGBColor {
private:
    unsigned char red;
    unsigned char green;
    unsigned char blue;

public:
    RGBColor() : red(0), green(0), blue(0) {}

    RGBColor(unsigned char r, unsigned char g, unsigned char b)
        : red(r), green(g), blue(b) {
    }

    RGBColor(const RGBColor& other)
        : red(other.red), green(other.green), blue(other.blue) {
    }

    ~RGBColor() {}

    RGBColor mix(const RGBColor& other) const {
        unsigned char mixedRed = (red + other.red) / 2;
        unsigned char mixedGreen = (green + other.green) / 2;
        unsigned char mixedBlue = (blue + other.blue) / 2;
        return RGBColor(mixedRed, mixedGreen, mixedBlue);
    }

    RGBColor invert() const {
        unsigned char invertedRed = 255 - red;
        unsigned char invertedGreen = 255 - green;
        unsigned char invertedBlue = 255 - blue;
        return RGBColor(invertedRed, invertedGreen, invertedBlue);
    }

    double getBrightness() const {
        return (static_cast<int>(red) + green + blue) / 3.0;
    }

    string toHEX() const {
        stringstream ss;
        ss << "#" << hex << setw(2) << setfill('0') << static_cast<int>(red)
            << setw(2) << static_cast<int>(green)
            << setw(2) << static_cast<int>(blue);
        return ss.str();
    }

    bool operator==(const RGBColor& other) const {
        return (red == other.red) && (green == other.green) && (blue == other.blue);
    }

    bool operator!=(const RGBColor& other) const {
        return !(*this == other);
    }

    friend ostream& operator<<(ostream& os, const RGBColor& color);
    friend istream& operator>>(istream& is, RGBColor& color);
};

ostream& operator<<(ostream& os, const RGBColor& color) {
    os << "RGB(" << static_cast<int>(color.red) << ", "
        << static_cast<int>(color.green) << ", "
        << static_cast<int>(color.blue) << ")";
    return os;
}

istream& operator>>(istream& is, RGBColor& color) {
    int r, g, b;
    cout << "Введите значение красного канала (0-255): ";
    is >> r;
    cout << "Введите значение зеленого канала (0-255): ";
    is >> g;
    cout << "Введите значение синего канала (0-255): ";
    is >> b;

    r = (r < 0) ? 0 : (r > 255) ? 255 : r;
    g = (g < 0) ? 0 : (g > 255) ? 255 : g;
    b = (b < 0) ? 0 : (b > 255) ? 255 : b;

    color.red = static_cast<unsigned char>(r);
    color.green = static_cast<unsigned char>(g);
    color.blue = static_cast<unsigned char>(b);

    return is;
}

// Базовый класс фигуры (Задание 3)
class figure {
protected:
    double x, y;
public:
    figure(double a = 0, double b = 0) { x = a; y = b; }
    virtual double area() { return 0; }
};

class rectangle : public figure {
public:
    rectangle(double a, double b) : figure(a, b) {};
    double area() { return x * y; }
};

class circle : public figure {
public:
    circle(double a) : figure(a) {};
    double area() { return 3.1416 * x * x; }
};

class triangle : public figure {
private:
    double z;

    bool isValidTriangle(double a, double b, double c) {
        return (a + b > c) && (a + c > b) && (b + c > a) &&
            (a > 0) && (b > 0) && (c > 0);
    }

public:
    triangle() : figure(0, 0), z(0) {}

    triangle(double a, double b, double c) : figure(a, b) {
        if (isValidTriangle(a, b, c)) {
            x = a;
            y = b;
            z = c;
        }
        else {
            x = y = z = 0;
            cout << "Ошибка: Невозможно создать треугольник с такими сторонами!" << endl;
        }
    }

    triangle(const triangle& t) : figure(t.x, t.y), z(t.z) {}

    ~triangle() {}

    double area() override {
        if (x == 0 || y == 0 || z == 0) return 0;
        double p = (x + y + z) / 2;
        return sqrt(p * (p - x) * (p - y) * (p - z));
    }

    triangle& operator=(const triangle& t) {
        if (this != &t) {
            x = t.x;
            y = t.y;
            z = t.z;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const triangle& t);
    friend istream& operator>>(istream& is, triangle& t);
};

ostream& operator<<(ostream& os, const triangle& t) {
    os << "Треугольник со сторонами: " << t.x << ", " << t.y << ", " << t.z;
    return os;
}

istream& operator>>(istream& is, triangle& t) {
    double a, b, c;
    cout << "Введите три стороны треугольника: ";
    is >> a >> b >> c;
    if (t.isValidTriangle(a, b, c)) {
        t.x = a;
        t.y = b;
        t.z = c;
    }
    else {
        cout << "Ошибка: Невозможно создать треугольник с такими сторонами!" << endl;
        t.x = t.y = t.z = 0;
    }
    return is;
}

// Класс квадрата с исключением (Задание 4)
class InvalidAreaException : public exception {
private:
    string message;
public:
    InvalidAreaException(const string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class Square {
private:
    double area;

public:
    Square() : area(1.0) {}

    Square(double a) {
        setArea(a);
    }

    Square(const Square& other) : area(other.area) {}

    ~Square() {
        cout << "Квадрат с площадью " << area << " уничтожен" << endl;
    }

    void setArea(double a) {
        if (a <= 0) {
            throw InvalidAreaException("Площадь квадрата должна быть положительной");
        }
        area = a;
    }

    double getArea() const {
        return area;
    }

    double getSideLength() const {
        return sqrt(area);
    }

    Square& operator=(const Square& other) {
        if (this != &other) {
            area = other.area;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Square& sq);
    friend istream& operator>>(istream& is, Square& sq);
};

ostream& operator<<(ostream& os, const Square& sq) {
    os << "Квадрат с площадью: " << sq.area << ", длина стороны: " << sq.getSideLength();
    return os;
}

istream& operator>>(istream& is, Square& sq) {
    double a;
    cout << "Введите площадь квадрата: ";
    is >> a;
    try {
        sq.setArea(a);
    }
    catch (const InvalidAreaException& e) {
        cerr << "Ошибка: " << e.what() << endl;
        is.setstate(ios::failbit);
    }
    return is;
}

// Функции для демонстрации каждого задания
void demoComplexNumbers() {
    double re, im;
    cout << "Демонстрация работы с комплексными числами\n";
    cout << "Введите действительную часть первого числа: ";
    cin >> re;
    cout << "Введите мнимую часть первого числа: ";
    cin >> im;
    my_complex A(re, im);

    cout << "Введите действительную часть второго числа: ";
    cin >> re;
    cout << "Введите мнимую часть второго числа: ";
    cin >> im;
    my_complex B(re, im);

    cout << "\nA = " << A << endl;
    cout << "B = " << B << endl;

    cout << "\nАрифметические операции:\n";
    cout << "A + B = " << A + B << endl;
    cout << "A - B = " << A - B << endl;
    cout << "A * B = " << A * B << endl;
    cout << "A / B = " << A / B << endl;

    cout << "\nСравнение:\n";
    cout << "A == B: " << (A == B ? "true" : "false") << endl;
    cout << "A != B: " << (A != B ? "true" : "false") << endl;

    cout << "\nДополнительные методы:\n";
    cout << "Модуль A: " << A.modulus() << endl;
    cout << "Тригонометрическая форма A: " << A.toTrigonometricForm() << endl;
}

void demoRGBColors() {
    cout << "\nДемонстрация работы с RGB цветами\n";

    RGBColor color1, color2;
    cout << "Введите первый цвет:\n";
    cin >> color1;
    cout << "Введите второй цвет:\n";
    cin >> color2;

    cout << "\nЦвет 1: " << color1 << endl;
    cout << "Цвет 2: " << color2 << endl;

    RGBColor mixed = color1.mix(color2);
    cout << "Смешанный цвет: " << mixed << endl;

    RGBColor inverted = color1.invert();
    cout << "Инвертированный цвет 1: " << inverted << endl;

    cout << "Яркость цвета 1: " << color1.getBrightness() << endl;
    cout << "HEX представление цвета 1: " << color1.toHEX() << endl;

    cout << "Цвета 1 и 2 " << (color1 == color2 ? "совпадают" : "разные") << endl;
}

void demoFigures() {
    cout << "\nДемонстрация работы с фигурами\n";

    double a, b, c;
    cout << "Введите длину и ширину прямоугольника: ";
    cin >> a >> b;
    rectangle rect(a, b);

    cout << "Введите радиус круга: ";
    cin >> a;
    circle circ(a);

    triangle tri;
    cin >> tri;

    cout << "\nПлощади фигур:\n";
    cout << "Прямоугольник: " << rect.area() << endl;
    cout << "Круг: " << circ.area() << endl;
    cout << "Треугольник: " << tri.area() << endl;
    cout << "Информация о треугольнике: " << tri << endl;
}

void demoSquares() {
    cout << "\nДемонстрация работы с квадратами\n";

    Square sq;
    cin >> sq;
    if (!cin.fail()) {
        cout << sq << endl;
    }

    cout << "\nТестирование исключений:\n";
    try {
        Square badSquare(-5);
    }
    catch (const InvalidAreaException& e) {
        cerr << "Поймано исключение: " << e.what() << endl;
    }
}

// Главное меню
int main() {
    SetConsoleOutputCP(1251); // установка UTF-8 для вывода
    SetConsoleCP(1251);
    int choice;
    do {
        cout << "\nМеню выбора заданий:\n";
        cout << "1. Комплексные числа\n";
        cout << "2. RGB цвета\n";
        cout << "3. Фигуры\n";
        cout << "4. Квадраты с исключениями\n";
        cout << "0. Выход\n";
        cout << "Выберите задание (0-4): ";
        cin >> choice;

        switch (choice) {
        case 1:
            demoComplexNumbers();
            break;
        case 2:
            demoRGBColors();
            break;
        case 3:
            demoFigures();
            break;
        case 4:
            demoSquares();
            break;
        case 0:
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}

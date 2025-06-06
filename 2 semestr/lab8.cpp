///********************************** 
///        Лабораторная работа No8 
///            Линейные списки 
/// Выполнил(а) студент(ка) 151412 группы 
///         Ерпулев Егор Александрович  
///********************************** 
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

// Структуру объявляем глобально
struct my_list {
    int inf; //полезная нагрузка
    my_list* next;//связь со следующим элементом
};

// Объявления функций, определения приведены ниже
void input_list(my_list*& first, int n);
void print_list(my_list* p);

void add_first(my_list*& first, int k);
bool add_after(my_list*& first, int k, int el);
bool add_before(my_list*& first, int k, int el);
void add_last(my_list*& first, int k);

bool del_i(my_list*& first, int k);
bool del_first(my_list*& first);
bool del_last(my_list*& first);
bool del_all(my_list*& first);

int count_elements(my_list* first);
my_list* search_for_node_ptr(my_list* first, int k);
void search(my_list* first, my_list*& ans, int k);
void create_a_copy(my_list* first, my_list*& ans);
void splitList(my_list* first, my_list*& chet, my_list*& nechet);
void selectionSorting(my_list*& first);
int irand(int a, int b);

int main() {
    srand((unsigned)time(0));
    //  setlocale(LC_ALL,"Russian");
    SetConsoleOutputCP(1251); // установка UTF-8 для вывода
    SetConsoleCP(1251);
    // Переменная для хранения начала списка. Обнулять строго обязательно!
    my_list* first = NULL;
    // Столько элементов добавим в список в начале работы. Больше эта переменная не потребуется.
    int n = 5;

    cout << "\t1 - Заполнение списка случайными числами\n\t"
        "2 - Вывод списка на экран\n\t"
        "4 - Вставка числа 7 в начало списка\n\t"
        "5 - Добавление 6 после элемента с номером 2(добавление в середину)\n\t"
        "6 - Вставка числа в конец списка\n\t"
        "7 - Добавление 7 перед элементом с номером 3(добавление в середину)\n\t"
        "8 - Удаление n-ого элемента\n\t"
        "9 - Удаление первого элемент\n\t"
        "10 - Удаление последнего элемента\n\t"
        "11 - Удаление списка с отчисткой памяти\n\t"
        "12 - Количество элементов в списке\n\t"
        "13 - Получение доступа к i-ому узлу для анализа\n\t"
        "14 - Поиск образца\n\t"
        "15 - Создание копии списка\n\t"
        "16 - Разбиение на два списка(с четными и нечетными элементами)\n\t"
        "17 - Устойчивая сортировка линейного списка\n\t"
        "0 - Завершение работы программы\n\t" << endl;
    int num = 1;
    while (num) {
        // печать меню


        cout << "Введите номер задания: ";
        cin >> num;
        switch (num) {
        case 0: break;
        case 1: {
            // Заполнение списка с клавиатуры
            input_list(first, n);
            break;
        }
        case 2: {
            // Вывод списка на экран
            cout << "Введенный с клавиатуры список" << endl;
            print_list(first);
        }
        case 3:
            break;
        case 4: {
            // Добавление 7 в начало списка и вывод
            add_first(first, 7);
            cout << "Добавленный элемент появился в начале списка" << endl;
            print_list(first);
            break;
        }
              
        case 5: {
            // Добавление 6 после элемента с номером 4
            bool answer = add_after(first, 2, 6);
            // Если попытка добавления завершилась неудачей, будет выведена строка об ошибке
            if (!answer) cout << "Error!" << endl;
            cout << "Список с добавленным в середину элементом (если не возникло ошибки)" << endl;
            print_list(first);
            break;
        }
        case 6: {
            // Добавление 7 в конец списка и вывод
            add_last(first, 7);
            cout << "Добавленный элемент появился в конце списка" << endl;
            print_list(first);
            break;
        }
        case 7: {
            // Добавление 7 перед элементом с номером 4
            bool answer = add_before(first, 3, 7);
            // Если попытка добавления завершилась неудачей, будет выведена строка об ошибке
            if (!answer) cout << "Error!" << endl;
            cout << "Список с добавленным перед Kтым (если не возникло ошибки)" << endl;
            print_list(first);
            break;
        }
        case 8: {
            // Удаление элемента с номером n
            cout << "Какой элемент вы желаете удалить? " << endl;
            cin >> n;
            bool answer = del_i(first, n);
            if (!answer) cout << "Error!" << endl;
            cout << "Список, из которого удалили i-ый элемент(если не возникло ошибки)" << endl;
            print_list(first);
            break;
        }
        case 9: {
            // Удаление первого элемента
            bool answer = del_first(first);
            if (!answer) cout << "Error!" << endl;
            cout << "Список, из которого удалили первый элемент" << endl;
            print_list(first);
            break;
        }
        case 10: {
            // Удаление последнего элемента
            bool answer = del_last(first);
            if (!answer) cout << "Error!" << endl;
            cout << "Список, из которого удалили первый элемент" << endl;
            print_list(first);
            break;
        }
        case 11: {
            // Удаление всего списка
            bool answer = del_all(first);
            if (!answer) cout << "Error!" << endl;
            cout << "Список успешно удален" << endl;
            print_list(first);
            break;
        }
        case 12: {
            //Подсчет количества элементов в списке
            cout << "Количество элементов в списке: " << count_elements(first) << endl;
            break;
        }
        case 13: {
            cout << "Введите индекс узла" << endl;
            int i;
            cin >> i;
            my_list* p = search_for_node_ptr(first, i);
            cout << "Адрес узла: " << p << endl << "Содержимое узла: " << p->inf << endl;
            break;
        }
        case 14: {
            // Результат поиска -- список номеров вхождений элемента в список
            my_list* res = 0;
            cout << "Ввведите искомое значение: ";
            int i;
            cin >> i;
            search(first, res, i);
            cout << "Номера элементов, равных искомому значению" << endl;
            print_list(res);
            break;
        }
        case 15: {
            //Создание копии
            my_list* res = nullptr;
            create_a_copy(first, res);
            cout << "Копия списка создана(другого и быть не может)" << endl;
            print_list(res);
            break;
        }
        case 16: {
            my_list* chet = nullptr;
            my_list* nechet = nullptr;
            splitList(first, chet, nechet);
            cout << "Список с четными элементами: ";
            print_list(chet);
            cout << "Список с нечетными элементами: ";
            print_list(nechet);
            break;
        }
        case 17: {
            selectionSorting(first);
            cout << "Отсортированный список, сто проц ниче не получится: ";

            print_list(first);
            break;
        }
        default: break;
    }
    if (num == 0) break;
  }
  return 0;
}

int irand(int a, int b) {
    return rand() % (b - a + 1) + a;
}

// Функция заполнения списка введенными с клавиатуры значениями.
// Получает в качестве парамеров сам список first и количество вводимых элементов.
// Обратите внимание, что список передается по ссылке, т.к. в него будут вноситься
// изменения. Количество элементов нужно только в этой задаче!
void input_list(my_list*& first, int n)
{
    first = new my_list;
    first->inf = irand(-10, 90);
    my_list* p = first;
    for (int i = 0; i < n - 1; i++) {
        p->next = new my_list;
        p = p->next;
        p->inf = irand(-10, 90);
    }
    p->next = 0;
}
//2
// Функция вывода списка на экран
void print_list(my_list* p)
{
    while (p) {
        cout << p->inf << " ";
        p = p->next;
    }
    cout << endl;
}
//4
// Функция добавления в начало
void add_first(my_list*& first, int k)
{
    my_list* q = new my_list;
    q->inf = k;
    q->next = first;
    first = q;
}
//6
//Функция добавление в конец
void add_last(my_list*& first, int k) {
    my_list* q = new my_list;
    q->inf = k;
    q->next = nullptr;
    my_list* p = first;
    if (!first) {
        first = q;
        return;
    }
    while (p->next) {
        p = p->next;
    }
    p->next = q;
}
//5
// Функция добавления элемента после k-го
// Возвращает true, если удалось добавить элемент, и false в противном случае
bool add_after(my_list*& first, int k, int el)//добавление после k-го элемента
{
    if (k < 0 || !first) return 0;
    my_list* p = first;
    int i = 0;
    for (i = 0; i < k && p->next; i++) p = p->next; //условие p->next нужно чтобы не выйти за границы списка
    if (i < k) return 0;
    my_list* w = new my_list;
    w->inf = el;
    w->next = p->next;
    p->next = w;
    return 1;
}
//7
// Функция добавления элемента перед k-ым
bool add_before(my_list*& first, int k, int el)//добавление после k-го элемента 
{
    if (k < 0 || !first) return 0;
    my_list* p = first;
    int i = 0;
    for (i = 0; i < (k - 1) && p->next; i++) p = p->next; //условие p->next нужно чтобы не выйти за границы списка q
    if (i + 1 < k) return 0;
    my_list* w = new my_list;
    w->inf = el;
    w->next = p->next;
    p->next = w;
    return 1;
}
//8
// Функция удаления элемента с номером k
bool del_i(my_list*& first, int k)
{
    if (k < 0) return 0;

    if (k == 0) {
        my_list* t = first;
        first = first->next;
        delete t;
        return 1;
    }

    my_list* p = first;
    int i = 0;
    for (i = 0; i < k - 1 && p->next; i++) p = p->next;

    if (!p->next) return false;
    my_list* w = p->next;
    p->next = w->next;
    delete w;
    return 1;
}
//9
bool del_first(my_list*& first)
{
    my_list* p = first;
    if (!first) return 0;
    first = first->next;
    delete p;
    return 1;
}
//10
bool del_last(my_list*& first) {
    my_list* p = first;
    if (!first) return 0;

    if (!p->next) {
        delete first;
        return 1;
    }
    while (p->next->next) {
        p = p->next;
    }
    delete p->next;
    p->next = nullptr;
    return 1;
}
//11
bool del_all(my_list*& first) {
    if (!first) return 0;
    while (first) {
        my_list* q = first;
        first = first->next;
        delete q;
    }
    return 1;
}
//12
int count_elements(my_list* first) {
    my_list* p = first;
    int i = 1;
    while (p->next) {
        p = p->next;
        i++;
    }
    return i;
}
//13
my_list* search_for_node_ptr(my_list* first, int k) {
    my_list* p = first;
    if (k < 0) return nullptr;
    for (int i = 0; i < k && p->next; i++) {
        p = p->next;
    }
    return p;
}

//14
// Функция линейного поиска элемента в списке. Находит номера всех вхождений
// элемента в список, и добавляет их в новый список. Если элемент не встретится
// в списке ни разу, результатом будет пустой список.
// Номера записаны в обратном порядке. Для удобства можно самостоятельно написать
// отдельную функцию, переворачивающую список.
// В функцию передаются три параметра: исходный список first, список для хранения
// найденных номером ans, искомый элемент k. Список ans передается по ссылке!
void search(my_list* first, my_list*& ans, int k)
{
    if (!first) return;
    my_list* p = first;
    int i = 0;
    while (p) {
        if (p->inf == k) add_first(ans, i); // Добавляем найденное в новый список
        i++;
        p = p->next;
    }
}
//15
void create_a_copy(my_list* first, my_list*& ans) {
    my_list* p = first;
    if (!first) {
        ans = nullptr;
    }
    ans = new my_list;
    ans -> inf = p -> inf;
    p = p->next;

    my_list* q = ans;
    //my_list *newfirst = newlist;
    while (p) {
        q->next = new my_list;
        q = q->next;
        q->inf = p->inf;
        p = p->next;
    }
    q->next = 0;
}
//16
void splitList(my_list* first, my_list*& chet, my_list*& nechet) {
    chet = nullptr;
    nechet = nullptr;
    my_list* chetTail = nullptr, * nechetTail = nullptr;

    while (first) {
        my_list* newNode = new my_list{ first->inf, nullptr };
        if (first->inf % 2 == 0) {
            if (!chet) {
                chet = newNode;
                chetTail = chet;
            }
            else {
                chetTail->next = newNode;
                chetTail = newNode;
            }
        }
        else {
            if (!nechet) {
                nechet = newNode;
                nechetTail = nechet;
            }
            else {
                nechetTail->next = newNode;
                nechetTail = newNode;
            }
        }

        first = first->next;
    }
}
//17
void selectionSorting(my_list*& first) {
    for (my_list* p = first; p && p->next; p = p->next) {
        my_list* nmin = p;
        for (my_list* q = p->next; q; q = q->next) {
            if (q->inf < nmin->inf)
                nmin = q;
            if (nmin != p)
                swap(p->inf, nmin->inf);
        }
    }
}


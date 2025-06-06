
#include <iostream>
using namespace std;

struct my_stack {
    int inf;
    my_stack* next;
};
// добавление элемента в стек
void add_stack(my_stack*& first, int k) {
    my_stack* p = new my_stack;
    p->inf = k;
    p->next = 0;
    if (first) {
        p->next = first;
    }
    first = p;
}
// извлечение элемента из стека
bool del_stack(my_stack*& first, int& k) {
    if (!first) return false;
    my_stack* p = first;
    first = first->next;
    k = p->inf;
    delete p;
    return true;
}
//реверсирование (переворачивание) стека
void reverse_stack(my_stack*& first) {
    if (!first) return;
    my_stack* p = 0;
    while (true) {
        int val;
        bool s = del_stack(first, val);
        if (!s) break;
        add_stack(p, val);
    }
    first = p;
}
// печать  стека  через  двойное  реверсирование
void print_stack(my_stack*& first) {
    reverse_stack(first);
    my_stack* p = 0;
    while (true) {
        int val;
        bool s = del_stack(first, val);
        if (!s) break;
        cout << val << ' ';
        add_stack(p, val);
    }
    first = p;
}

void Stack() {
    cout << "0 - Выход" << endl;
    cout << "1 - Добавить элемент" << endl;
    cout << "2 - Извлечь элемент" << endl;
    cout << "3 - Перевернуть стек" << endl;
    cout << "4 - Вывести стек" << endl;

    my_stack* stack = 0;

    int num = 1;
    int val;
    while (num) {
        cout << "\nВыбери: ";

        cin >> num;
        switch (num) {
        case 0:
            break;

        case 1:

            cin >> val;
            add_stack(stack, val);
            break;
        case 2: {
            int val;
            if (del_stack(stack, val))
                cout << "Извлечено: " << val << endl;
            else
                cout << "Стек пуст!" << endl;
            break;
        }
        case 3:
            reverse_stack(stack);
            cout << "Стек перевёрнут" << endl;
            break;
        case 4:
            print_stack(stack);
            break;
        default:
            cout << "Error!" << endl;
        }
    }

    int tmp;
    while (del_stack(stack, tmp));
}

struct deque {
    int inf;
    deque* next;
    deque* prev;
};

// добавление элемента в начало дека
void add_front(deque*& first, deque*& last, int k) {
    deque* p = new deque;
    p->inf = k;
    p->next = first;
    p->prev = 0;
    if (first) {
        first->prev = p;
    }
    first = p;
    if (!last) {
        last = p;
    }
}

// добавление элемента в конец дека
void add_back(deque*& first, deque*& last, int k) {
    deque* p = new deque;
    p->inf = k;
    p->prev = last;
    p->next = 0;
    if (last) {
        last->next = p;
    }
    last = p;
    if (!first) {
        first = p;
    }
}

// извлечение элемента из начала дека
bool del_front(deque*& first, deque*& last, int& k) {
    if (!first) return false;
    deque* p = first;
    k = p->inf;
    first = first->next;
    if (first) {
        first->prev = 0;
    }
    else {
        last = 0;
    }
    delete p;
    return true;
}

// извлечение элемента из конца дека
bool del_back(deque*& first, deque*& last, int& k) {
    if (!last) return false;
    deque* p = last;
    k = p->inf;
    last = last->prev;
    if (last) {
        last->next = 0;
    }
    else {
        first = 0;
    }
    delete p;
    return true;
}

// печать дека от начала к концу
void print_deque(deque* first) {
    deque* p = first;
    while (p) {
        cout << p->inf << ' ';
        p = p->next;
    }
    cout << endl;
}

void Deqeu() {
    cout << "0 - Выход" << endl;
    cout << "1 - Добавить элемент в начало" << endl;
    cout << "2 - Добавить элемент в конец" << endl;
    cout << "3 - Извлечь элемент из начала" << endl;
    cout << "4 - Извлечь элемент из конца" << endl;
    cout << "5 - Вывести дек" << endl;

    deque* first = 0;
    deque* last = 0;

    int num = 1;
    int val;
    while (num) {
        cout << "Выбери: ";
        cin >> num;
        switch (num) {
        case 0:
            break;
        case 1:
            cout << "Введи элемент: ";
            cin >> val;
            add_front(first, last, val);
            cout << endl;
            break;
        case 2:
            cout << "Введи элемент: ";
            cin >> val;
            add_back(first, last, val);
            cout << endl;
            break;
        case 3: {
            int val;
            if (del_front(first, last, val))
                cout << "Извлечено из начала: " << val << endl;
            else
                cout << "Дек пуст!" << endl;
            cout << endl;
            break;
        }
        case 4: {
            int val;
            if (del_back(first, last, val))
                cout << "Извлечено из конца: " << val << endl;
            else
                cout <<"Дек пуст!" << endl;
            cout << endl;
            break;
        }
        case 5:
            cout << "Элементы дека: ";
            print_deque(first);
            cout << endl;
            break;
        default:
            cout << "Error!" << endl;
        }
    }

    // Очистка памяти
    int tmp;
    while (del_front(first, last, tmp));

}



int main() {
    setlocale(LC_ALL, "");
    int n;
    cout << "стек дек ?(1,2)"; cin >> n;

    switch (n) {
    case 1:
        Stack();
        break;
    case 2:
        Deqeu();
        break;
    
    }

}

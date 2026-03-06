/* Даны указатели P1 и P2 на начало и конец непустой очереди. Извлекать из очереди 
элементы, пока значение начального элемента очереди не станет четным, и выводить значения
извлеченных элементов(если очередь не содержит элементов с четными значениями, то извлечь
все ее элементы).Вывести также новые адреса начала и конца очереди(для пустой очереди
дважды вывести nullptr).После извлечения элементов из очереди освобождать память, которую
они занимали.


Для каждой динамической структуры должен быть предусмотрен стандартный набор методов - добавления/удаления/вывода элементов. 
Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.



В заданиях данной подгруппы структура «очередь» (queue) моделируется цепочкой связанных
узлов-записей типа TNode. Поле Next последнего элемента цепочки равно nullptr. Началом
очереди («головой», head) считается первый элемент цепочки, концом («хвостом», tail) — ее
последний элемент. Для возможности быстрого добавления в конец очереди нового элемента
удобно хранить, помимо указателя на начало очереди, также и указатель на ее конец. В случае
пустой очереди указатели на ее начало и конец полагаются равными nullptr. Как и для стека,
значением элемента очереди считается значение его поля Data.*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool IsNumber(const  string& str) {
    if (str.empty()) return false;
    int start = (str[0] == '-' || str[0] == '+') ? 1 : 0;
    for (int i = start; i < str.length(); ++i) {
        if (!isdigit(str[i])) return false;
    }
    return start < str.length();
}
class Queue {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* P1; 
    Node* P2;  

public:
    Queue() : P1(nullptr), P2(nullptr) {}

    void push(int num) { // Добавление элемента в очередь
        Node* newNode = new Node;
        newNode->data = num;
        newNode->next = nullptr;
        if (!P2) { 
            P1 = P2 = newNode;
        }
        else {
            P2->next = newNode;
            P2 = newNode;
        }
        newNode->next = nullptr;
    }
    void show() { // Вывод элементов
        Node* temp = P1;
        if (!temp) {
            cout << "Очередь пустая" << endl;
            return;
        }
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool pop(int& num) {  // Извлечение элемента из очереди
        if (!P1) return false; // Очередь пуста

        Node* temp = P1;
        num = P1->data;
        P1 = P1->next;
        if (!P1) P2 = nullptr; // Если очередь стала пустой

        delete temp;
        return true;
    }

    Node* getP1() const {
        return P1;
    }
    void getP1data() const {
        int num1= P1->data;
        cout << num1;
    }

    void getP2data() const {
        int num1 = P2->data;
        cout << num1;
    }

    Node* getP2() const {
        return P2;
    }

    void EvenHead() { // Извлечение элементов, пока не встретится четное значение
        int num;
        while (!(P1 == nullptr) && (P1->data % 2 != 0)) { 
            pop(num);
            cout << num << " ";
        }
        cout << endl;
    }

    ~Queue() {
        int del;
        while (pop(del));
    }
};
int main() {
    setlocale(LC_ALL, "ru");
    Queue q;
    string in;
    string inum;
    int num;
    int n;
    cout << "Введите количество элементов в очереди: ";
    cin >> in;
    if (!IsNumber(in)) {
        cout << "Недопустимое значение.";
        return 1;
    }
    else {
        n = stoi(in);
    }
    cout << "Введите элементы очереди: ";
    for (int i = 1; i <= n; i++) {
        cin >> inum;
        if (!IsNumber(inum)) {
            cout << "Недопустимое значение.";
            return 1;
        }
        else {
            num = stoi(inum);
            q.push(num);
        }
    }
    cout << "Изначальная очередь: ";
    q.show();

    cout << "Извлеченные элементы: ";
    q.EvenHead();
    cout << "Измененная очередь: ";
    q.show();
    cout << "Значение первого элемента: ";
    q.getP1data();
    cout << endl;
    cout << "Новый адрес начала очереди (P1): " << q.getP1() << endl;
    cout << "Значение последнего элемента: ";
    q.getP2data();
    cout << endl;
    cout << "Новый адрес конца очереди (P2): " << q.getP2() << endl;

    return 0;
}
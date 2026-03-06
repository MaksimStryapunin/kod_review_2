/* Элементами контейнеров являются целые числа. Для
заполнения контейнера использовать итератор и конструктор соответствующего контейнера,
для вывода элементов использовать итератор (для вывода элементов в обратном порядке
использовать обратные итераторы, возвращаемые функциями-членами rbegin и rend)
Обязательно наличие дружественного интерфейса. Ввод данных организовать 
разными способами (с клавиатуры, рандом, из файла)

Даны дек D и список L. Каждый исходный контейнер содержит не менее 5
элементов. Вставить перед пятым с конца элементом списка последние 5 элементов дека в
обратном порядке. Использовать один вызов функции-члена insert.

*/


#include <ctime>
#include <deque>
#include <list>
#include <fstream>
#include <iostream>
using namespace std;
template <typename Container>
void Input(Container& N, int n)//Заполнение контейнеров
{
    int m, x;
    cout << "Выберете способ заполнения контейнера: " << endl;
    cout << "1)Ввод с клавиатуры." << endl;
    cout << "2)Ввод с помощью рандомайзера." << endl;
    cout << "3)Ввод данных из текстового файла." << endl;
    cin >> m;
    if (n < 5)
    {
        cout << "Ошибка. Недопустимый размер." << endl;
        return;
    }
    switch (m)
    {
    case 1:
    {
        for (int i = 0; i < n;i++)
        {
            cout << "Введите " << i + 1 << " элемент: ";
            cin >> x;
            N.insert(N.end(), x);
        }
        break;
    }
    case 2:
    {
        srand(time(0));
        for (int i = 0;i < n;i++)
            N.insert(N.end(), rand() % 101 - 50);
        break;
    }
    case 3:
    {
        ifstream file("a.txt", ios::in);// a.txt {9 3 -44-82 75 2 5 9 -43 74 927 94 -27 3 57 1 0 74 473 84}
        if (!file)
        {
            cout << "Ошибка. Файл не был открыт.";
            return;
        }
        for (int i = 0; i < n;i++)
        {
            file >> x;
            N.insert(N.end(), x);
        }
        file.close();
        break;
    }
    default:
    {
        cout << "Ошибка ввода." << endl;
        break;
    }
    }
}
template <typename Container>
void Print(const Container& N)//Вывод содержимого контейнеров
{
    for (auto it = N.begin(); it != N.end(); it++)
        cout << *it << " ";
    cout << endl;
}
void Insert(deque<int>& D, list<int>& L)//Вставка перед 5 с конца элемента списка последних 5 элементов дека в обратном порядке
{
    list<int>::iterator it = L.end();
    for (int i = 0; i < 5;i++)
        --it;
    for (int i = 4; i >= 0; i--) 
        it = L.insert(it, D[D.size() - 1 - i]);
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int n1, n2;
    deque <int> D;
    list <int> L;
    cout << "Введите размерность дека n1 (n1 >= 5): ";
    cin >> n1;
    Input(D, n1);
    cout << "Введите размерность списка n2 (n2 >= 5): ";
    cin >> n2;
    Input(L, n2);
    cout << "Изначальное содержимое контейнеров." << endl;
    cout << "Дек: ";
    Print(D);
    cout << "Список: ";
    Print(L);
    Insert(D, L);
    cout << "Изменённое содержание контейнеров." << endl;
    cout << "Дек: ";
    Print(D);
    cout << "Список: ";
    Print(L);
    return 0;
}
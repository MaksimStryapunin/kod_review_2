/*Дан односвязный линейный список и указатель на голову списка P1. Значения
элементов списка упорядочены по возрастанию. Необходимо создать копию исходного списка,
после чего во вновь созданном списке вставить в список значение M так, чтобы он остался
упорядоченным и вывести ссылку на первый элемент полученного списка P2


Для каждой динамической структуры должен быть предусмотрен стандартный набор методов - 
добавления/удаления/вывода элементов. 
Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.

*/
# include <windows.h>
# include <iostream>

using namespace std;

class Node
{
public:
	int x;
	Node* next;
};
typedef Node* PNode;

void add(int data, PNode& Head, PNode& LastNode)
{
	PNode Temp;
	if (Head == nullptr)
	{
		Head = new Node;
		LastNode = Head;
		Head->next = nullptr;
	}
	else
	{
		Temp = new Node;
		LastNode->next = Temp;
		LastNode = Temp;
		LastNode->next = nullptr;
	}
	LastNode->x = data;
}

PNode find(int data, PNode& Head)
{
	PNode Temp = Head;
	PNode prev = Head;
	while (Temp != nullptr && Temp->x < data)
	{
		prev = Temp;
		Temp = Temp->next;
	}
	return prev;
}

void newadd(int data, PNode p,PNode &Head )
{
	PNode newNode =  new Node;
	newNode->next = nullptr;
	newNode->x = data;
	if (Head == nullptr || Head->x >= data)
	{
		newNode->next = Head;
		Head = newNode;
	}
	else
	{
		PNode Prev = find(data, Head);
		if (Prev != nullptr)
		{
			newNode->next = Prev->next;
			Prev->next = newNode;
		}
	}
}

void show(PNode& Head)
{
	PNode Mynode = Head;
	//PNode Temp = nullptr;
	int count = 0;
	cout << "Все полученные числа: ";

	while (Mynode != nullptr)
	{
		cout << Mynode->x << " ";
		Mynode = Mynode->next;
	}
	cout << endl;
	
}

void show2(PNode& Head)
{
	PNode Mynode = Head;
	//PNode Temp = nullptr;
	int count = 0;
	cout << "Все полученные числа: ";

	while (Mynode != nullptr)
	{
		cout << Mynode->x << " ";
		Mynode = Mynode->next;
		
	}
	if (Mynode == nullptr)
	{
		cout << "Пусто!";
	}
	cout << endl;
	
}

PNode Find(PNode Head, int data)
{
	PNode q = Head;
	while (q && q->x != data)
		q = q->next;
	return q;
}


void DeleteNode(PNode& Head, PNode OldNode)
{
	PNode q = Head;
	if (Head == OldNode)
		Head = OldNode->next;				 // удаляем первый элемент.
	else
	{
		while (q->next != OldNode)			// ищем элемент, если оне не первый.
			q = q->next;
		q->next = OldNode->next;
	}
	delete OldNode; 
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	PNode p1 = nullptr;
	PNode p2 = nullptr;
	PNode p3 = nullptr;
	PNode p4 = nullptr;
	int n, m;
	cout << "Добро пожаловать!" << endl;
	cout << "Перед нами последняя задача: " << endl;
	cout << "Дан односвязный линейный список. Значения элементов списка упорядочены по возрастанию." << endl;
	cout << "Необходимо создать копию исходного списка, после чего во вновь созданном списке вставить" << endl;
	cout << "значение M так, чтобы он остался упорядоченным и вывести ссылку на первый элемент полученного списка P2." << endl << endl;
	cout << "----------------------------------------------------------------------" << endl << endl;
	cout << "Вам необхожимо будет ввести количество элементов в списке," << endl;
	cout << "а позже ввести значения элементов СТРОГО В ПОРЯДКЕ ВОЗРАСТАНИЯ " << endl;
	cout << "и ввести число которое вы хотите вставить." << endl;
	cout << "ПРИМЕР ПОРЯДКА ВОЗРАСТАНИЯ 1 2 3 4 5 6" << endl;
	cout << "---------------------------------------------------------------------" << endl << endl;
	cout << "Введите число n - количество элементов в списке: ";
	cin >> n;
	cout << endl << "Введите " << n << " чисел в порядке возрастания (!!!!): ";
	for (int i = 0; i < n; i++)
	{
		int j;
		cin >> j;
		add(j, p1, p2);
		add(j, p3, p4);
	}

	cout << endl << "Введите целое значение числа m, которое необходимо будет вставить: ";
	cin >> m;
	show(p1);
	cout << endl;
	PNode P = find(m, p3);
	newadd(m, P, p3);
	show(p3);
	int choice;
	cout << endl << "Хотите удалить какой-нибудь элемент?" << endl;
	cout << "Если да, то напишите 1" << endl;
	cout << "Если нет, то напишите 2" << endl;
	cout << "Ваш выбор: ";
	cin >> choice;
	cout << endl;
	switch (choice)
	{
		case 1:
		{
			cout << "Введите число - количество элементов которое вы хотите удалить: ";
			int num;
			cin >> num;
			for (int i = 0; i < num; i++)
			{
				cout << "Введите значение элемента, который вы хотите удалить: ";
				int x;
				cin >> x;
				PNode p = Find(p3, x);
				cout << endl;
				cout << "Удаление...." << endl;
				DeleteNode(p3, p);
			}
			show2(p3);
		}break;

		case 2:
			{
				{
					cout << "Спасибо за терпение!!!" << endl;
					cout << "До свидания!!!" << endl;
				}
			}
		default:
		{
			cout << "Введено неверное число"; break;
		}
	}
	return 0;
}
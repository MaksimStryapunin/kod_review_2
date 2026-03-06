/*Дан односвязный линейный список и указатель на голову списка P1. Необходимо
вставить значение M после каждого второго элемента списка, и вывести ссылку на последний
элемент полученного списка P2.

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

void show(PNode& Head)
{
	PNode Mynode = Head;
	cout << "Все числа из списка: ";

	while (Mynode != nullptr)
	{
		cout << Mynode->x << " ";
		Mynode = Mynode->next;
	}

}

void addafter(int data, PNode& Head)
{
	PNode Temp = Head;
	PNode MyNode;
	int count = 1;
	while (Temp != nullptr)
	{
		count++;
		if (count == 4)
		{
			MyNode = new Node;
			MyNode->x = data;
			MyNode->next = Temp->next;
			Temp->next = MyNode;
			count = 0;
		}
		Temp = Temp->next;
	}
}

void showafter(PNode& Head)
{
	PNode Mynode = Head;
	cout << endl;
	cout << "Все числа из измененного списка: ";
	while (Mynode != nullptr)
	{
		cout << Mynode->x << " ";
		Mynode = Mynode->next;
		
	}
	cout << endl;
}

PNode showlast(PNode& Head)
{
	PNode Mynode2 = Head;
	while (Mynode2 != nullptr && Mynode2->next != nullptr)
	{
		Mynode2 = Mynode2->next;
	}
	return Mynode2;
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
		Head = OldNode->next;  // удаляем первый элемент 
	else
	{
		while (q->next != OldNode) // ищем элемент 
			q = q->next;
		q->next = OldNode->next;
	}
	delete OldNode; // освобождаем память 
}



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	PNode H1 = NULL;
	PNode LastNode = NULL;
	cout << "Добро пожаловать!" << endl;
	cout << "Перед нами задача: " << endl;
	cout << "Дан односвязный линейный список" << endl;
	cout << "Необходимо вставить значение M после каждого третьего элемента списка," << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "Вам необходимо ввести два значения: " << endl;
	cout << "1. n(n>=3) - количество элементов в списке" << endl;
	cout << "2. m - число, которое мы будем вставлять. " << endl;
	cout << "Затем через пробел ввести элементы списка, количество которых будет совпадать с тем, что вы ввели ранее," << endl;
	cout << "После мы выведем полученный результат на экран и ссылку на последний элемент. " << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "Введите число(БОЛЬШЕ 3) - количество элементов в массиве: ";
	int n, x, m;;
	cin >> n;
	cout << "Введите " << n << " элементов списка ";
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		add(x, H1, LastNode);
	}
	cout << endl;
	cout << "Введите значение m для вставки после каждого третьего элемента: ";
	cin >> m;
	cout << endl;
	show(H1);
	cout << endl;
	addafter(m, H1);
	showafter(H1);
	cout << endl;
	PNode last = showlast(H1);
	cout << "Ссылка на последний элемент: " << last << " " << last->x;

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
			PNode p = Find(H1, x);
			cout << endl;
			cout << "Удаление...." << endl;
			DeleteNode(H1, p);
		}
		show(H1);
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

/*Дано число D и указатель P1 на вершину непустого стека. 
Добавить элемент со значением D в стек и вывести адрес P2 новой вершины стека.

Для каждой динамической структуры должен быть предусмотрен стандартный набор методов - 
добавления/удаления/вывода элементов. 
Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.

В заданиях подгруппы структура «стек» (stack) моделируется цепочкой связанных
узлов-записей типа TNode. Поле Next последнего элемента цепочки равно nullptr. Вершиной
стека (top) считается первый элемент цепочки. Для доступа к стеку используется указатель на
его вершину (для пустого стека данный указатель полагается равным nullptr). Значением
элемента стека считается значение его поля Data*/

#include <iostream>
//FIXME: (запрещено испольбзовать пространство имён std)
//using namespace std;

class Node {
public:
    int data;       
    Node* next;     

    
    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top; 

public:
    Stack() : top(nullptr) {}
    //FIXME: (нет деструктора)
    ~Stack() : top(nullptr) { clearStack(); }
    void push(int value) {//  для добавления элемента в стек
        Node* newNode = new Node(value); // Создаем новый узел
        newNode->next = top;             // Новый узел указывает на текущую вершину
        top = newNode;                   // Обновляем вершину стека
        std::cout << "Элемент " << value << " добавлен в стек." << std::endl;
    }
    void pop() { // Метод для удаления элемента из стека
        if (top == nullptr) {            
            std::cout << "Стек пуст! Невозможно удалить элемент." << std::endl;
            return;
        }
        Node* temp = top;                
        top = top->next;                 
        std::cout << "Элемент " << temp->data << " удален из стека." << std::endl;
        delete temp;                 
    }
    //FIXME (нет комментариев для функции)
    void print() {
        if (top == nullptr) {           
            std::cout << "Стек пуст!" << std::endl;
            return;
        }
        Node* current = top;            
        std::cout << "Элементы стека: ";
        while (current != nullptr) {     
            std::cout << current->data << " "; 
            current = current->next;    
        }
        std::cout << std::endl;                  
    }
    //FIXME (нет комментариев для функции)
    Node* getTop() {//вывести элемент top
        return top;
    }
    //FIXME (нет комментариев для функции)
    void clearStack() {//очистить стек
        while (top != nullptr) {       
            Node* temp = top;            
            top = top->next;             
            delete temp;                 // Удаляем узел
        }
        std::cout << "Стек очищен." << std::endl;
    }
    friend void addElementAndPrintAddress(Stack& stack, int D);
};

//FIXME (нет комментариев для функции)
void addElementAndPrintAddress(Stack& stack, int D) {//добавить элемент и вывести адрес
    stack.push(D);
    std::cout << "Адрес новой вершины стека: " << stack.getTop() << std::endl;
}

int main() {
    Stack stack;
    int choice, value;

    while (true) {
        std::cout << "\nМеню:\n";
        std::cout << "1. Добавить элемент в стек\n";
        std::cout << "2. Удалить элемент из стека\n";
        std::cout << "3. Вывести элементы стека\n";
        std::cout << "4. Очистить стек\n";
        std::cout << "5. Выйти\n";
        std::cout << "Введите ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Введите число для добавления в стек: ";
            std::cin >> value;
            addElementAndPrintAddress(stack, value);
            break;
        case 2:
            stack.pop();
            break;
        case 3:
            stack.print();
            break;
        case 4:
            stack.clearStack();
            break;
        case 5:
            std::cout << "Выход из программы." << std::endl;
            return 0;
        default:
            std::cout << "Неверный выбор! Пожалуйста, попробуйте снова." << std::endl;
        }
    }

    return 0;
}

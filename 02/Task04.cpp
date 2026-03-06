/* Дан двусвязный линейный список и указатель на первый элемент этого 
списка. Создать текстовый файл, в который вывести содержимое списка в обратном 
порядке. По ходу вывода списка удалять элементы в нем. Числа выводить в одну строку, 
разделяя ровно одним пробелом, в конце строки пробел на ставить.


Все динамические структуры данных реализовывать через классы. Не использовать STL.  
Для каждой динамической структуры должен быть предусмотрен стандартный
набор методов - добавления/удаления/вывода элементов. Во всех задачах обязательно наличие 
дружественного интерфейса. Ввод данных с клавиатуры. */




#include <iostream>
#include <fstream>
#include <string>
#include <locale>
using namespace std;

// Структура узла двусвязного списка
struct Uzel {
    int Dannye;         // Данные узла
    Uzel* Predydushiy;  // Указатель на предыдущий узел
    Uzel* Sleduyushiy;  // Указатель на следующий узел
};

// Класс для работы с двусвязным списком
class Spisok {
private:
    Uzel* Perviy; // Указатель на первый узел

public:
    // Инициализация списка
    void Inicializacia() {
        Perviy = nullptr;
    }

    // Добавление элемента в конец списка
    void DobavitElement(int Znachenie) {
        Uzel* Novyj = new Uzel;
        Novyj->Dannye = Znachenie;
        Novyj->Predydushiy = nullptr;
        Novyj->Sleduyushiy = nullptr;

        if (Perviy == nullptr) {
            Perviy = Novyj;
        }
        else {
            Uzel* Tekushiy = Perviy;
            while (Tekushiy->Sleduyushiy != nullptr) {
                Tekushiy = Tekushiy->Sleduyushiy;
            }
            Tekushiy->Sleduyushiy = Novyj;
            Novyj->Predydushiy = Tekushiy;
        }
    }

    // Удаление указанного узла
    void UdalitElement(Uzel* UzelDlyaUdaleniya) {
        if (UzelDlyaUdaleniya == nullptr) return;

        Uzel* Pred = UzelDlyaUdaleniya->Predydushiy;
        Uzel* Sled = UzelDlyaUdaleniya->Sleduyushiy;

        if (Pred != nullptr) {
            Pred->Sleduyushiy = Sled;
        }
        else {
            Perviy = Sled;
        }

        if (Sled != nullptr) {
            Sled->Predydushiy = Pred;
        }

        delete UzelDlyaUdaleniya;
    }

    // Вывод списка на экран
    void Pechat() const {
        Uzel* Tekushiy = Perviy;
        cout << "Список: ";
        while (Tekushiy != nullptr) {
            cout << Tekushiy->Dannye << " ";
            Tekushiy = Tekushiy->Sleduyushiy;
        }
        cout << endl;
    }

    // Запись в файл в обратном порядке и удаление элементов
    void ZapisatVFailIOchistit(const string& ImyaFaila) {
        ofstream file(ImyaFaila);
        if (!file.is_open()) {
            cout << "Ошибка открытия файла!" << endl;
            return;
        }

        bool PerviyElement = true;
        Uzel* Tekushiy = Perviy;

        // Находим последний элемент
        while (Tekushiy != nullptr && Tekushiy->Sleduyushiy != nullptr) {
            Tekushiy = Tekushiy->Sleduyushiy;
        }

        // Записываем и удаляем элементы с конца
        while (Tekushiy != nullptr) {
            if (PerviyElement) {
                file << Tekushiy->Dannye;
                PerviyElement = false;
            }
            else {
                file << " " << Tekushiy->Dannye;
            }

            Uzel* Predydushiy = Tekushiy->Predydushiy;
            UdalitElement(Tekushiy);
            Tekushiy = Predydushiy;
        }

        file.close();
        cout << "Данные записаны в файл и список очищен." << endl;
    }

    // Очистка всего списка
    void Ochistka() {
        Uzel* Tekushiy = Perviy;
        while (Tekushiy != nullptr) {
            Uzel* Sleduyushiy = Tekushiy->Sleduyushiy;
            delete Tekushiy;
            Tekushiy = Sleduyushiy;
        }
        Perviy = nullptr;
    }
};

// Функция для ввода числа с проверкой
int VvodChisla() {
    string Vvod;
    while (true) {
        cout << "Введите число (или '-1' для завершения): ";
        cin >> Vvod;

        if (Vvod == "-1") {
            return -1;
        }

        bool Korrektno = true;
        int Znak = 1;
        size_t Start = 0;

        if (Vvod.empty()) {
            Korrektno = false;
        }
        else if (Vvod[0] == '-') {
            Znak = -1;
            Start = 1;
            if (Vvod.size() == 1) Korrektno = false;
        }

        for (size_t i = Start; i < Vvod.size(); ++i) {
            if (!isdigit(Vvod[i])) Korrektno = false;
        }

        if (Korrektno) {
            int Chislo = 0;
            for (size_t i = Start; i < Vvod.size(); ++i) {
                Chislo = Chislo * 10 + (Vvod[i] - '0');
            }
            return Chislo * Znak;
        }
        else {
            cout << "Некорректный ввод! Используйте цифры и знак '-' в начале." << endl;
        }
    }
}

// Новая функция для вывода содержимого файла
void VivodSoderzhimogoFaila(const string& ImyaFaila) {
    ifstream file(ImyaFaila);
    if (!file.is_open()) {
        cout << "Ошибка при открытии файла для чтения!" << endl;
        return;
    }

    cout << "\n=== Содержимое файла ===" << endl;
    string Stroka;
    while (getline(file, Stroka)) {
        cout << Stroka << endl;
    }
    file.close();
}

int main() {
    setlocale(LC_ALL, "Russian");

    Spisok MoiSpisok;
    MoiSpisok.Inicializacia();

    cout << "=== Ввод чисел в список ===" << endl;
    while (true) {
        int Chislo = VvodChisla();
        if (Chislo == -1) break;
        MoiSpisok.DobavitElement(Chislo);
    }

    MoiSpisok.Pechat();

    cout << "\n=== Запись в файл ===" << endl;
    string ImyaFaila;
    cout << "Введите имя файла: ";
    cin >> ImyaFaila;

    MoiSpisok.ZapisatVFailIOchistit(ImyaFaila);
    VivodSoderzhimogoFaila(ImyaFaila); // Вызов новой функции
    MoiSpisok.Ochistka();

    return 0;
}
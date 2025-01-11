#include <iostream>
using namespace std;

// Структура узла двунаправленного списка
struct Node {
    int data;       // Данные узла
    Node* next;     // Указатель на следующий узел
    Node* prev;     // Указатель на предыдущий узел

    // Конструктор для удобства
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Класс для двунаправленного списка
class DoublyLinkedList {
private:
    Node* head;  // Указатель на первый элемент списка
    Node* tail;  // Указатель на последний элемент списка

public:
    // Конструктор (инициализация пустого списка)
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Проверка на пустоту
    bool isEmpty() const {
        return head == nullptr;
    }

    // Добавление элемента после заданного узла
    void addAfter(Node* prevNode, int value) {
        if (prevNode == nullptr) {
            cout << "Ошибка: указатель на предыдущий узел равен nullptr." << endl;
            return;
        }
        Node* newNode = new Node(value);
        newNode->next = prevNode->next;
        newNode->prev = prevNode;
        if (prevNode->next != nullptr) {
            prevNode->next->prev = newNode; // Если существует следующий элемент, перенаправляем его на новый
        }
        prevNode->next = newNode;

        // Если новый узел добавляется в конец списка
        if (prevNode == tail) {
            tail = newNode;
        }
    }

    // Добавление элемента перед заданным узлом
    void addBefore(Node* nextNode, int value) {
        if (nextNode == nullptr) {
            cout << "Ошибка: указатель на следующий узел равен nullptr." << endl;
            return;
        }
        Node* newNode = new Node(value);
        newNode->prev = nextNode->prev;
        newNode->next = nextNode;
        if (nextNode->prev != nullptr) {
            nextNode->prev->next = newNode; // Если существует предыдущий элемент, перенаправляем его на новый
        }
        nextNode->prev = newNode;

        // Если новый узел добавляется в начало списка
        if (nextNode == head) {
            head = newNode;
        }
    }

    // Удаление элемента после заданного узла
    void removeAfter(Node* prevNode) {
        if (prevNode == nullptr || prevNode->next == nullptr) {
            cout << "Ошибка: нет элемента для удаления после заданного узла." << endl;
            return;
        }
        Node* temp = prevNode->next;
        prevNode->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = prevNode; // Если существует следующий элемент, перенаправляем его
        }
        if (temp == tail) {
            tail = prevNode; // Если удаляем последний элемент, обновляем tail
        }
        delete temp;
    }

    // Удаление элемента перед заданным узлом
    void removeBefore(Node* nextNode) {
        if (nextNode == nullptr || nextNode->prev == nullptr) {
            cout << "Ошибка: нет элемента для удаления перед заданным узлом." << endl;
            return;
        }
        Node* temp = nextNode->prev;
        nextNode->prev = temp->prev;
        if (temp->prev != nullptr) {
            temp->prev->next = nextNode; // Если существует предыдущий элемент, перенаправляем его
        }
        if (temp == head) {
            head = nextNode; // Если удаляем первый элемент, обновляем head
        }
        delete temp;
    }

    // Печать списка в прямом направлении
    void printForward() const {
        if (isEmpty()) {
            cout << "Список пуст." << endl;
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Печать списка в обратном направлении
    void printBackward() const {
        if (isEmpty()) {
            cout << "Список пуст." << endl;
            return;
        }
        Node* current = tail;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    // Уничтожение списка
    void destroy() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    // Деструктор
    ~DoublyLinkedList() {
        destroy();
    }

    // Получить указатель на первый элемент (для работы с другими операциями)
    Node* getHead() const {
        return head;
    }

    // Получить указатель на последний элемент (для работы с другими операциями)
    Node* getTail() const {
        return tail;
    }
};



int main() {
    // Создаем объект двусвязного списка
    DoublyLinkedList list;

    // Добавляем элементы в список
    list.addAfter(nullptr, 10);  // Список: 10
    list.addAfter(list.getHead(), 20);  // Список: 10 20
    list.addAfter(list.getHead(), 30);  // Список: 10 30 20
    list.addBefore(list.getTail(), 40);  // Список: 10 30 40 20

    // Печатаем список в прямом порядке
    cout << "Список в прямом порядке: ";
    list.printForward();  // Ожидаемый вывод: 10 30 40 20

    // Печатаем список в обратном порядке
    cout << "Список в обратном порядке: ";
    list.printBackward();  // Ожидаемый вывод: 20 40 30 10

    // Удаляем элемент после заданного узла (например, после первого элемента)
    list.removeAfter(list.getHead());  // Удаляем 30
    cout << "Список после удаления элемента после первого: ";
    list.printForward();  // Ожидаемый вывод: 10 40 20

    // Удаляем элемент перед заданным узлом (например, перед последним элементом)
    list.removeBefore(list.getTail());  // Удаляем 40
    cout << "Список после удаления элемента перед последним: ";
    list.printForward();  // Ожидаемый вывод: 10 20

    // Уничтожаем список и освобождаем память
    list.destroy();
    cout << "Список после уничтожения: ";
    list.printForward();  // Ожидаемый вывод: Список пуст.

    return 0;
}

#include <iostream>
using namespace std;

// Структура узла двунаправленного кольцевого списка
struct Node {
    int data;       // Данные узла
    Node* next;     // Указатель на следующий узел
    Node* prev;     // Указатель на предыдущий узел

    // Конструктор для удобства
    Node(int val) : data(val), next(this), prev(this) {} // Инициализация кольца
};

// Класс для двунаправленного кольцевого списка с заглавным звеном
class DoublyCircularList {
private:
    Node* head;  // Указатель на заглавное звено

public:
    // Конструктор (инициализация списка с заглавным звеном)
    DoublyCircularList() {
        head = new Node(0); // Заглавное звено, не содержит данных
    }

    // Проверка на пустоту
    bool isEmpty() const {
        return head->next == head; // Если следующий узел указывает на сам заглавный
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
        prevNode->next->prev = newNode; // Перенаправляем указатель следующего элемента
        prevNode->next = newNode; // Перенаправляем указатель текущего узла
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
        nextNode->prev->next = newNode; // Перенаправляем указатель предыдущего элемента
        nextNode->prev = newNode; // Перенаправляем указатель текущего узла
    }

    // Удаление элемента после заданного узла
    void removeAfter(Node* prevNode) {
        if (prevNode == nullptr || prevNode->next == head) {
            cout << "Ошибка: нет элемента для удаления после заданного узла." << endl;
            return;
        }
        Node* temp = prevNode->next;
        prevNode->next = temp->next;
        temp->next->prev = prevNode; // Перенаправляем указатель следующего узла
        delete temp;
    }

    // Удаление элемента перед заданным узлом
    void removeBefore(Node* nextNode) {
        if (nextNode == nullptr || nextNode->prev == head) {
            cout << "Ошибка: нет элемента для удаления перед заданным узлом." << endl;
            return;
        }
        Node* temp = nextNode->prev;
        nextNode->prev = temp->prev;
        temp->prev->next = nextNode; // Перенаправляем указатель предыдущего узла
        delete temp;
    }

    // Удаление текущего элемента
    void removeCurrent(Node* currentNode) {
        if (currentNode == nullptr || currentNode == head) {
            cout << "Ошибка: нельзя удалить заглавное звено или пустой элемент." << endl;
            return;
        }
        currentNode->prev->next = currentNode->next;
        currentNode->next->prev = currentNode->prev;
        delete currentNode;
    }

    // Печать списка в прямом направлении
    void printForward() const {
        if (isEmpty()) {
            cout << "Список пуст." << endl;
            return;
        }
        Node* current = head->next;
        while (current != head) {
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
        Node* current = head->prev;
        while (current != head) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    // Уничтожение списка
    void destroy() {
        while (head->next != head) {
            removeAfter(head); // Удаляем все элементы после заглавного звена
        }
        delete head; // Удаляем само заглавное звено
    }

    // Деструктор
    ~DoublyCircularList() {
        destroy();
    }

    // Получить указатель на первый элемент списка (не на заглавное звено)
    Node* getHead() const {
        return head->next;
    }
};

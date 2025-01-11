#include <iostream>
using namespace std;

// Структура для хранения узла списка
struct Node {
    int data;
    Node* next;

    // Конструктор для удобства инициализации
    Node(int val) : data(val), next(nullptr) {}
};

// Класс для работы с однонаправленным списком с заглавным звеном
class LinkedListWithHeader {
private:
    Node* head;  // Указатель на первый элемент списка (заглавное звено)

    // Рекурсивная печать узлов
    void printRecursive(Node* node) const {
        if (node == nullptr) return;  // Базовый случай: достигли конца списка
        cout << node->data << " ";    // Печать текущего узла
        printRecursive(node->next);   // Рекурсивный вызов для следующего узла
    }

    int sumRecursive(Node* node) const {
        if (node == nullptr) return 0; // Базовый случай: конец списка
        return node->data + sumRecursive(node->next); // Суммируем текущий элемент и вызываем рекурсию для следующего
    }

public:
    // Конструктор (инициализация пустого списка)
    LinkedListWithHeader() : head(nullptr) {}

    // Проверка на пустоту
    bool isEmpty() const {
        return head == nullptr;
    }

    // Добавление элемента в список после заданного элемента
    void addAfter(Node* prevNode, int value) {
        if (prevNode == nullptr) {
            cout << "Предыдущий элемент не может быть нулевым." << endl;
            return;
        }
        Node* newNode = new Node(value);
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }

    // Удаление элемента из списка после заданного элемента
    void removeAfter(Node* prevNode) {
        if (prevNode == nullptr || prevNode->next == nullptr) {
            cout << "Нет элемента для удаления после заданного узла." << endl;
            return;
        }
        Node* temp = prevNode->next;
        prevNode->next = temp->next;
        delete temp;
    }

    // Создание упорядоченного списка
    void createOrdered(int arr[], int size) {
        for (int i = 0; i < size; i++) {
            addOrdered(arr[i]);
        }
    }

    // Добавление элемента в упорядоченный список
    void addOrdered(int value) {
        Node* newNode = new Node(value);
        Node* current = head;

        // Если список пустой или новый элемент должен быть первым
        if (current == nullptr || current->data >= value) {
            newNode->next = head;
            head = newNode;
            return;
        }

        // Ищем подходящее место для нового элемента
        while (current->next != nullptr && current->next->data < value) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    // Печать списка
    void printList() const {
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

    // Рекурсивная печать списка
    void printListRecursive() const {
        cout << "Список (рекурсивно): ";
        printRecursive(head);  // Запуск рекурсии с головы списка
        cout << endl;
    }

    int getSumRecursive() const {
        return sumRecursive(head); // Запускаем рекурсию с головы списка
    }

    // Уничтожение списка
    void destroy() {
        Node* current = head->next;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
    }

    // Получение первого узла (для использования в других операциях)
    Node* getHead() const {
        return head;
    }
};
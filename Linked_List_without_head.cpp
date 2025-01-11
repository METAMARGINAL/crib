#include <iostream>
using namespace std;

// Структура узла списка
struct Node {
    int data;   // Данные узла
    Node* next; // Указатель на следующий узел

    // Конструктор для удобства
    Node(int val) : data(val), next(nullptr) {}
};

// Класс для работы с однонаправленным списком без заглавного звена
class LinkedList {
private:
    Node* head; // Указатель на первый элемент списка

    // Вспомогательная функция для рекурсивной печати списка
    void printRecursively(Node* node) const {
        if (node == nullptr) {
            return; // Базовый случай: достигли конца списка
        }
        cout << node->data << " "; // Вывод текущего элемента
        printRecursively(node->next); // Рекурсивный вызов для следующего узла
    }

    // Вспомогательная функция для рекурсивной суммы элементов списка
    int sumRecursively(Node* node) const {
        if (node == nullptr) {
            return 0; // Базовый случай: достигли конца списка
        }
        return node->data + sumRecursively(node->next); // Текущий элемент + сумма оставшихся элементов
    }

public:
    // Конструктор (инициализация пустого списка)
    LinkedList() : head(nullptr) {}

    // Проверка на пустоту
    bool isEmpty() const {
        return head == nullptr;
    }

    // Добавление элемента в начало списка
    void addToHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void addAfter(Node* prevNode, int value) {
        if (prevNode == nullptr) {
            cout << "Ошибка: указатель на предыдущий узел равен nullptr." << endl;
            return;
        }
        Node* newNode = new Node(value);
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }

    // Добавление элемента в конец списка
    void addToTail(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Добавление элемента в упорядоченный список
    void addOrdered(int value) {
        Node* newNode = new Node(value);

        // Если список пуст или элемент должен быть первым
        if (isEmpty() || head->data >= value) {
            newNode->next = head;
            head = newNode;
            return;
        }

        // Ищем место для вставки
        Node* current = head;
        while (current->next != nullptr && current->next->data < value) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    // Создание списка в прямом порядке
    void createInOrder(int arr[], int size) {
        for (int i = 0; i < size; i++) {
            addToTail(arr[i]); // Добавляем элементы в конец
        }
    }

    // Создание списка в обратном порядке
    void createInReverseOrder(int arr[], int size) {
        for (int i = 0; i < size; i++) {
            addToHead(arr[i]); // Добавляем элементы в начало
        }
    }

    // Создание упорядоченного списка
    void createOrdered(int arr[], int size) {
        for (int i = 0; i < size; i++) {
            addOrdered(arr[i]); // Вставляем элементы в упорядоченном порядке
        }
    }

    // Рекурсивная печать списка
    void printListRecursively() const {
        if (isEmpty()) {
            cout << "Список пуст." << endl;
            return;
        }
        printRecursively(head); // Вызываем вспомогательную функцию
        cout << endl;
    }

    // Рекурсивная функция суммы элементов списка
    int sumListRecursively() const {
        return sumRecursively(head); // Вызываем вспомогательную функцию
    }

    void removeFirst() {
        if (isEmpty()) {
            cout << "Ошибка: список пуст, нет элемента для удаления." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp; // Освобождаем память, на которую указывал head
    }

    void removeAfter(Node* prevNode) {
        if (prevNode == nullptr || prevNode->next == nullptr) {
            cout << "Ошибка: нет элемента для удаления после заданного узла." << endl;
            return;
        }
        Node* temp = prevNode->next;
        prevNode->next = temp->next;
        delete temp;
    }

    // Уничтожение списка
    void destroy() {
        while (!isEmpty()) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Печать списка (обычная, не рекурсивная)
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

    // Деструктор
    ~LinkedList() {
        destroy();
    }

    Node* getHead() const {
        return head;
    }
};


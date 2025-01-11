#include <iostream>
class Stack {
private:
    int* arr;      // Массив для хранения элементов стека
    int capacity;  // Вместимость стека
    int topIndex;  // Индекс верхнего элемента стека

public:
    Stack(int size = 10) { // Конструктор с дефолтным размером 10
        capacity = size;
        arr = new int[capacity];
        topIndex = -1; // Стек пуст
    }

    ~Stack() { // Деструктор
        delete[] arr;
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    bool isFull() {
        return topIndex == capacity - 1;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty!" << std::endl;
            return -1; // Возвращаем ошибочный код, если стек пуст
        }
        return arr[topIndex];
    }

    void push(int elem) {
        if (isFull()) {
            std::cout << "Stack is full!" << std::endl;
            return;
        }
        arr[++topIndex] = elem;
    }

    void pop() {
        if (!isEmpty()) {
            --topIndex;
        }
        else {
            std::cout << "Stack is empty!" << std::endl;
        }
    }

    void clear() {
        // Очистка стека и освобождение памяти
        delete[] arr;  // Освобождаем текущий массив
        arr = nullptr;  // Обнуляем указатель
        capacity = 0;   // Сбрасываем вместимость
        topIndex = -1;  // Сбрасываем индекс верхнего элемента

        // Выделяем новый массив для стека
        arr = new int[10]; // Можно выбрать дефолтный размер, например 10
        capacity = 10;
    }

    void print() {
        if (!isEmpty()) {
            for (int i = topIndex; i >= 0; --i) {
                std::cout << arr[i] << std::endl;
            }
        }
        else {
            std::cout << "Stack is empty!" << std::endl;
        }
    }
};

#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;          // Массив для хранения элементов очереди
    int front;         // Индекс первого элемента очереди
    int rear;          // Индекс последнего элемента очереди
    int capacity;      // Вместимость очереди
    int size;          // Текущий размер очереди

public:
    Queue(int cap) {   // Конструктор с размером очереди
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~Queue() {         // Деструктор
        delete[] arr;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int elem) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        rear = (rear + 1) % capacity; // Циклически увеличиваем rear
        arr[rear] = elem;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        front = (front + 1) % capacity; // Циклически увеличиваем front
        size--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1; // Возвращаем ошибочный код, если очередь пуста
        }
        return arr[front];
    }

    void print() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        int idx = front;
        for (int i = 0; i < size; i++) {
            cout << arr[idx] << " ";
            idx = (idx + 1) % capacity; // Циклически двигаемся по индексу
        }
        cout << endl;
    }

    void clear() {
        front = 0;
        rear = -1;
        size = 0;
    }
};
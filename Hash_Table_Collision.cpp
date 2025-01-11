#include <iostream>

class HashTable {
private:
    int* table;
    int size;

public:
    // Конструктор хеш-таблицы
    HashTable(int size) : size(size) {
        table = new int[size];
        for (int i = 0; i < size; i++) {
            table[i] = -1; // -1 означает пустую ячейку
        }
    }

    // Деструктор
    ~HashTable() {
        delete[] table;
    }

    // Хеш-функция
    int hash(int key) {
        return key % size;
    }

    // Метод для разрешения коллизий с использованием линейного пробирования
    void insert_linear(int key) {
        int index = hash(key);
        while (table[index] != -1) {  // Ищем свободную ячейку
            index = (index + 1) % size;  // Линейное пробирование
        }
        table[index] = key;
    }

    // Метод для разрешения коллизий с использованием квадратичного пробирования
    void insert_quadratic(int key) {
        int index = hash(key);
        int i = 0;
        while (table[(index + i * i) % size] != -1) {  // Ищем свободную ячейку
            i++;
        }
        table[(index + i * i) % size] = key;
    }

    // Метод для разрешения коллизий с использованием двойного хэширования
    void insert_double_hashing(int key) {
        int index = hash(key);
        int step = 1 + (key % (size - 1));  // Вторая хеш-функция
        int i = 0;
        while (table[(index + i * step) % size] != -1) {  // Ищем свободную ячейку
            i++;
        }
        table[(index + i * step) % size] = key;
    }

    // Метод для разрешения коллизий с использованием внешних цепочек (связанных списков)
    void insert_chaining(int key) {
        int index = hash(key);
        while (table[index] != -1) {  // Ищем свободную ячейку
            index = (index + 1) % size;  // Линейное пробирование
        }
        table[index] = key;
    }

    // Поиск элемента в хеш-таблице
    bool search(int key) {
        int index = hash(key);
        while (table[index] != -1) {
            if (table[index] == key) {
                return true;
            }
            index = (index + 1) % size;  // Линейное пробирование
        }
        return false;
    }

    // Вывод всех элементов таблицы
    void print() {
        for (int i = 0; i < size; i++) {
            if (table[i] != -1) {
                std::cout << "Index " << i << ": " << table[i] << std::endl;
            }
        }
    }
};

//int main() {
//    int size = 10;
//    HashTable ht(size);
//
//    std::cout << "Inserting using linear probing:" << std::endl;
//    ht.insert_linear(5);
//    ht.insert_linear(15);
//    ht.insert_linear(25);
//    ht.insert_linear(35);
//    ht.print();
//
//    std::cout << "Searching for 15: " << ht.search(15) << std::endl;
//    std::cout << "Searching for 100: " << ht.search(100) << std::endl;
//
//    HashTable ht2(size);
//
//    std::cout << "\nInserting using quadratic probing:" << std::endl;
//    ht2.insert_quadratic(5);
//    ht2.insert_quadratic(15);
//    ht2.insert_quadratic(25);
//    ht2.insert_quadratic(35);
//    ht2.print();
//
//    HashTable ht3(size);
//
//    std::cout << "\nInserting using double hashing:" << std::endl;
//    ht3.insert_double_hashing(5);
//    ht3.insert_double_hashing(15);
//    ht3.insert_double_hashing(25);
//    ht3.insert_double_hashing(35);
//    ht3.print();
//
//    return 0;
//}
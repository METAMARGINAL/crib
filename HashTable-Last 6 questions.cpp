#include <iostream>
#include <string>
//first class and first main is 48-50 questions
//second class and second main is 51-53 questions
using namespace std;

const int TABLE_SIZE = 10; // Второй вариант
const int EMPTY = -1;
const int DELETED = -2;



struct Node {
	string key;
	int val;
	Node* next;

	Node(const string& k, int v) : key(k), val(v), next(nullptr) {}
};

class HashTable {
	Node* table[TABLE_SIZE];

	int hashFunction(const std::string& key) {
		int hash = 0;
		for (char ch : key) {
			hash = (hash + static_cast<int>(ch)) % TABLE_SIZE;
		}
		return hash;
	}

public:
	HashTable() {
		for (int i = 0; i < TABLE_SIZE; i++)
		{
			table[i] = nullptr;
		}
	}
	int search(const string& key) {
		int index = hashFunction(key);
		Node* current = table[index];
		while (current) {
			if (current->key == key) {
				return current->val;
			}
			current = current->next;
		}
		cout << "ПИЗДЕЦ" << endl;
	}

	void insert(const string& key, int value) {
		int index = hashFunction(key);
		Node* newNode = new Node(key, value);

		if (!table[index])
		{
			table[index] = newNode;
		}
		else {
			Node* current = table[index];
			while (current) {
				if (current->key == key) {
					current->val = value;
					delete newNode;
					return;
				}
				current = current->next;
			}
			newNode->next = table[index];
			table[index] = newNode;
		}
	}

	void remove(const string& key) {
		int index = hashFunction(key);
		Node* current = table[index];
		Node* prev = nullptr;

		while (current) {
			if (current->key == key) {
				if (prev) {
					prev->next = current->next;
				}
				else {
					table[index] = current->next;
				}
				delete current;
				return;
			}
			prev = current;
			current = current->next;
		}
		cout << "ВСЕ " << endl;
	}

	void print() {
		for (int i = 0; i < TABLE_SIZE; ++i) {
			std::cout << "Index " << i << ": ";
			Node* current = table[i];
			while (current) {
				std::cout << "[" << current->key << ": " << current->val << "] -> ";
				current = current->next;
			}
			std::cout << "nullptr" << std::endl;
		}
	}

	~HashTable() {
		for (int i = 0; i < TABLE_SIZE; ++i) {
			Node* current = table[i];
			while (current) {
				Node* toDelete = current;
				current = current->next;
				delete toDelete;
			}
		}
	}
};


class HashTable {
	int table[TABLE_SIZE];

	int hashFunction(int key) const {
		return key % TABLE_SIZE;
	}
public:
	HashTable() {
		for (int i = 0; i < TABLE_SIZE; i++)
		{
			table[i] = EMPTY;
		}
	}

	bool search(int key) {
		int hash = hashFunction(key);
		for (int i = 0; i < TABLE_SIZE; i++) {
			int probe = (i + hash) % TABLE_SIZE;//линейное пробирование
			if (table[probe] == EMPTY)
			{
				return false;
			}
			if (table[probe] == key)
			{
				return true;
			}
			return false;
		}
	}

	bool insert(int key) {
		int hash = hashFunction(key);
		for (int i = 0; i < TABLE_SIZE; i++) {
			int probe = (i + hash) % TABLE_SIZE;
			if (table[probe] == EMPTY || table[probe] == DELETED)
			{
				table[probe] = key;
				return true;
			}
		}
		cout << "ПЕРЕБОР" << endl;
		return false;
	}

	bool remove(int key) {
		int hash = hashFunction(key);
		for (int i = 0; i < TABLE_SIZE; i++) {
			int probe = (i + hash) % TABLE_SIZE;
			if (table[probe] == EMPTY)
			{
				return false;
			}
			if (table[probe] == key) {
				table[probe] = DELETED;
				return true;
			}
		}
		return false;
	}

	void PrintTable() {
		for (int i = 0; i < TABLE_SIZE; i++) {
			if (table[i] == EMPTY)
			{
				cout << "[" << i << "] EMPTY" << endl;
			}
			else if (table[i] == DELETED) {
				cout << "[" << i << "] DELETED" << endl;
			}
			else {
				cout << "[" << i << "] " << table[i] << endl;
			}
		}
	}
};

//int main() {
//    HashTable ht;
//
//    ht.insert("apple", 10);
//    ht.insert("banana", 20);
//    ht.insert("cherry", 30);
//    ht.insert("date", 40);
//
//    ht.print();
//
//    try {
//        std::cout << "Value for 'apple': " << ht.search("apple") << std::endl;
//        ht.remove("apple");
//        std::cout << "After removing 'apple':" << std::endl;
//        ht.print();
//    }
//    catch (const std::runtime_error& e) {
//        std::cout << e.what() << std::endl;
//    }
//
//    return 0;
//}

//int main()
//{
//	HashTable ht;
//
//	// Тестирование вставки
//	ht.insert(10);
//	ht.insert(20);
//	ht.insert(30);
//	ht.insert(110); // Коллизия для хэша 10 % TABLE_SIZE
//	ht.PrintTable();
//
//	// Тестирование поиска
//	cout << "Поиск 10: " << (ht.search(10) ? "Найден" : "Не найден") << endl;
//	cout << "Поиск 40: " << (ht.search(40) ? "Найден" : "Не найден") << endl;
//
//	// Тестирование удаления
//	cout << "Удаление 10: " << (ht.remove(10) ? "Успех" : "Не найден") << endl;
//	cout << "Поиск 10 после удаления: " << (ht.search(10) ? "Найден" : "Не найден") << endl;
//
//	// Вывод таблицы
//	ht.PrintTable();
//
//	return 0;
//}



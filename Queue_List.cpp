#include <iostream>
using namespace std;

class Queue {
	struct Node
	{
		int data;
		Node* next;
	};
	Node* head, * tail;
public:
	Queue() : head(nullptr), tail(nullptr) {}
	bool isEmpty() {
		return head == nullptr;
	}
	void enque(int elem) {

		Node* p = new Node;
		p->data = elem;
		p->next = nullptr;
		if (isEmpty()) {
			head = tail = p;
		}
		else {

			tail->next = p;
			tail = p;
		}
	}
	void deque() {
		if (isEmpty())
			return;
		Node* p = head;
		head = head->next;
		p->next = nullptr;
		delete p;
		p = nullptr;
	}
	int peek() {

		return head->data;
	}

	void print() {
		if (!isEmpty()) {
			Node* temp = head;
			while (temp) {
				std::cout << temp->data << std::endl;
				temp = temp->next;
			}
		}

	}

	void clear() {
		while (!isEmpty()) {
			deque();  // Извлекаем элементы из очереди и удаляем их
		}
	}

};
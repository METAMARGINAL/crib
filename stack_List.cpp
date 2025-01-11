#include <iostream>
using namespace std;

class Stack {
	struct Node
	{
		int data;
		Node* next;
	};
	Node* top;
public:
	Stack() : top(nullptr) {}

	bool isEmpty() {
		return top == nullptr;
	}
	int peek() {
		return top->data;
	}
	void push(int elem) {
		Node* p = new Node;
		p->data = elem;
		p->next = top;
		top = p;
	}
	void pop() {
		if (!isEmpty()) {
			Node* p = top;
			top = top->next;
			p->next = nullptr;
			delete p;
			p = nullptr;
		}
	}

	void print() {
		if (!isEmpty()) {
			Node* temp = top;
			while (temp) {
				std::cout << temp->data << std::endl;
				temp = temp->next;
			}
		}
	}

	void deleteStack() {
		while (!isEmpty()) {
			pop();
		}
	}
	
	bool isValid(string s) {
		Stack st; // Создаем собственный стек для хранения символов
		for (char c : s) { // Проходим по каждому символу строки
			if (c == '(' || c == '{' || c == '[') { // Если символ — открывающая скобка
				st.push(c); // Добавляем его в стек
			}
			else { // Если символ — закрывающая скобка
				if (st.isEmpty() || // Если стек пуст
					(c == ')' && st.peek() != '(') || // Закрывающая скобка не соответствует открывающей
					(c == '}' && st.peek() != '{') ||
					(c == ']' && st.peek() != '[')) {
					return false; // Строка невалидна, возвращаем false
				}
				st.pop(); // Иначе, убираем соответствующую открывающую скобку
			}
		}
		return st.isEmpty(); // Если стек пуст, все скобки закрыты правильно
	}

};

class InfixToPostfix {
public:
	// Метод для получения приоритета оператора
	int precedence(char op) {
		if (op == '+' || op == '-') return 1;
		if (op == '*' || op == '/') return 2;
		return 0; // для скобок
	}

	// Метод для выполнения преобразования
	std::string toPostfix(const std::string& infix) {
		Stack operators;  // Стек для операторов
		std::string postfix;  // Результат в постфиксной записи

		for (char c : infix) {
			if (isalnum(c)) {  // Если символ — операнд (переменная или число)
				postfix += c;  // Добавляем его в результат
			}
			else if (c == '(') {
				operators.push(c);  // Если символ — открывающая скобка, помещаем ее в стек
			}
			else if (c == ')') {
				// Пока на вершине стека не открывающая скобка, извлекаем операторы
				while (!operators.isEmpty() && operators.peek() != '(') {
					postfix += operators.peek();
					operators.pop();
				}
				operators.pop();  // Убираем открывающую скобку из стека
			}
			else if (isOperator(c)) {
				// Пока стек не пуст, и приоритет текущего оператора <= приоритету
				// оператора на вершине стека, извлекаем из стека операторы
				while (!operators.isEmpty() && precedence(operators.peek()) >= precedence(c)) {
					postfix += operators.peek();
					operators.pop();
				}
				operators.push(c);  // Добавляем текущий оператор в стек
			}
		}

		// Извлекаем оставшиеся операторы из стека
		while (!operators.isEmpty()) {
			postfix += operators.peek();
			operators.pop();
		}

		return postfix;  // Возвращаем результат
	}

private:
	bool isOperator(char c) {
		return (c == '+' || c == '-' || c == '*' || c == '/');
	}
};
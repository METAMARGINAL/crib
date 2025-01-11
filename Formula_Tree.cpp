#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// Структура узла дерева-формулы
struct FormulaNode {
    string value;          // Оператор или операнд
    FormulaNode* left;     // Левый потомок
    FormulaNode* right;    // Правый потомок

    FormulaNode(string v) : value(v), left(nullptr), right(nullptr) {}
};

class FormulaTree {
private:
    FormulaNode* root;

    // Вспомогательный метод для уничтожения дерева
    void destroyTree(FormulaNode* node) {
        if (node) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

    // Вспомогательный метод для чтения дерева в строку (инфиксная запись)
    void toString(FormulaNode* node, ostringstream& out) {
        if (!node) return;

        if (node->left || node->right) out << "("; // Добавляем скобку для операторов
        toString(node->left, out);
        out << node->value;
        toString(node->right, out);
        if (node->left || node->right) out << ")"; // Закрываем скобку
    }

    // Вспомогательный метод для вычисления значения дерева
    double evaluate(FormulaNode* node) {
        if (!node->left && !node->right) {
            return stod(node->value); // Если это число, преобразуем в double
        }

        double leftVal = evaluate(node->left);
        double rightVal = evaluate(node->right);

        if (node->value == "+") return leftVal + rightVal;
        if (node->value == "-") return leftVal - rightVal;
        if (node->value == "*") return leftVal * rightVal;
        if (node->value == "/") return leftVal / rightVal;

        throw runtime_error("Unknown operator: " + node->value);
    }

public:
    // Конструктор
    FormulaTree() : root(nullptr) {}

    // Деструктор
    ~FormulaTree() {
        destroyTree(root);
    }

    // Построение дерева из префиксной записи (пример: "+ 3 * 4 5")
    FormulaNode* buildFromPrefix(istringstream& input) {
        string token;
        if (!(input >> token)) return nullptr;

        FormulaNode* node = new FormulaNode(token);
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            node->left = buildFromPrefix(input);
            node->right = buildFromPrefix(input);
        }
        return node;
    }

    void buildTree(const string& prefixExpression) {
        istringstream input(prefixExpression);
        root = buildFromPrefix(input);
    }

    // Чтение дерева в строку (инфиксная запись)
    string toString() {
        ostringstream out;
        toString(root, out);
        return out.str();
    }

    // Вычисление значения дерева
    double evaluate() {
        if (!root) throw runtime_error("Tree is empty");
        return evaluate(root);
    }
};
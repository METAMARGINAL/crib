#include <iostream>
#include <queue>  // Для обхода в ширину
#include <stack>  // Для итеративного обхода в глубину
using namespace std;

// Структура узла бинарного дерева
struct Node {
    int data;       // Данные узла
    Node* left;     // Указатель на левое поддерево
    Node* right;    // Указатель на правое поддерево

    // Конструктор для инициализации узла
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Класс бинарного дерева
class BinaryTree {
private:
    Node* root; // Указатель на корень дерева

    // Рекурсивная функция для удаления дерева
    void destroy(Node* node) {
        if (node == nullptr) return;
        destroy(node->left);  // Рекурсивно удаляем левое поддерево
        destroy(node->right); // Рекурсивно удаляем правое поддерево
        delete node;  // Удаляем текущий узел
    }

    // Рекурсивная функция обхода дерева в прямом порядке (pre-order)
    void printPreOrder(Node* node) const {
        if (node == nullptr) return;
        cout << node->data << " ";  // Печатаем корень
        printPreOrder(node->left);  // Обходим левое поддерево
        printPreOrder(node->right); // Обходим правое поддерево
    }

    // Рекурсивная функция обхода дерева в симметричном порядке (in-order)
    void printInOrder(Node* node) const {
        if (node == nullptr) return;
        printInOrder(node->left);  // Обходим левое поддерево
        cout << node->data << " "; // Печатаем корень
        printInOrder(node->right); // Обходим правое поддерево
    }

    // Рекурсивная функция обхода дерева в обратном порядке (post-order)
    void printPostOrder(Node* node) const {
        if (node == nullptr) return;
        printPostOrder(node->left);  // Обходим левое поддерево
        printPostOrder(node->right); // Обходим правое поддерево
        cout << node->data << " ";  // Печатаем корень
    }

public:
    // Конструктор (создает пустое дерево)
    BinaryTree() : root(nullptr) {}

    // Деструктор (удаляет дерево)
    ~BinaryTree() {
        destroy(root);  // Удаляем дерево
    }

    // Создание бинарного дерева, содержащего один узел с заданным значением
    void createSingleNodeTree(int value) {
        root = new Node(value);
    }

    // Создание бинарного дерева по заданному корню и двум поддеревьям
    void createTree(Node* leftSubtree, int rootValue, Node* rightSubtree) {
        root = new Node(rootValue);
        root->left = leftSubtree;
        root->right = rightSubtree;
    }

    // Проверка на пустоту
    bool isEmpty() const {
        return root == nullptr;
    }

    // Изменение данных в корне бинарного дерева
    void setRootData(int value) {
        if (root == nullptr) {
            cout << "Ошибка: дерево пусто!" << endl;
            return;
        }
        root->data = value;
    }

    // Присоединение левого дочернего узла к корню
    void attachLeftChild(Node* leftChild) {
        if (root == nullptr) {
            cout << "Ошибка: дерево пусто!" << endl;
            return;
        }
        root->left = leftChild;
    }

    // Присоединение правого дочернего узла к корню
    void attachRightChild(Node* rightChild) {
        if (root == nullptr) {
            cout << "Ошибка: дерево пусто!" << endl;
            return;
        }
        root->right = rightChild;
    }

    // Присоединение левого поддерева к корню
    void attachLeftSubtree(Node* leftSubtree) {
        if (root == nullptr) {
            cout << "Ошибка: дерево пусто!" << endl;
            return;
        }
        root->left = leftSubtree;
    }

    // Присоединение правого поддерева к корню
    void attachRightSubtree(Node* rightSubtree) {
        if (root == nullptr) {
            cout << "Ошибка: дерево пусто!" << endl;
            return;
        }
        root->right = rightSubtree;
    }

    // Отсоединение левого поддерева от корня
    void detachLeftSubtree() {
        if (root == nullptr || root->left == nullptr) {
            cout << "Ошибка: нет левого поддерева для отсоединения!" << endl;
            return;
        }
        root->left = nullptr;
    }

    // Отсоединение правого поддерева от корня
    void detachRightSubtree() {
        if (root == nullptr || root->right == nullptr) {
            cout << "Ошибка: нет правого поддерева для отсоединения!" << endl;
            return;
        }
        root->right = nullptr;
    }

    // Вернуть копию левого поддерева
    Node* getLeftSubtree() const {
        return root ? root->left : nullptr;
    }

    // Вернуть копию правого поддерева
    Node* getRightSubtree() const {
        return root ? root->right : nullptr;
    }

    // Обход дерева в прямом порядке (pre-order)
    void printPreOrder() const {
        printPreOrder(root);
        cout << endl;
    }

    // Обход дерева в симметричном порядке (in-order)
    void printInOrder() const {
        printInOrder(root);
        cout << endl;
    }

    // Обход дерева в обратном порядке (post-order)
    void printPostOrder() const {
        printPostOrder(root);
        cout << endl;
    }

    // 16. Обход дерева в ширину
    void breadthFirstTraversal() {
        if (root == nullptr) {
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
    }

    // 17. Итеративный обход дерева в глубину
    void iterativeDepthFirstTraversal() {
        if (root == nullptr) {
            return;
        }

        stack<Node*> s;
        s.push(root);

        while (!s.empty()) {
            Node* current = s.top();
            s.pop();

            cout << current->data << " ";

            // Обратите внимание: сначала добавляем правого потомка, а затем левого,
            // чтобы левый обрабатывался раньше при извлечении из стека.
            if (current->right != nullptr) {
                s.push(current->right);
            }
            if (current->left != nullptr) {
                s.push(current->left);
            }
        }
    }
};

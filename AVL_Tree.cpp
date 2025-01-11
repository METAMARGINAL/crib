#include <iostream>
#include <algorithm>
using namespace std;

// Узел AVL-дерева
struct Node {
    int key;
    int height;
    Node* left;
    Node* right;

    Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
private:
    Node* root;

    // Получить высоту узла
    int height(Node* node) {
        return node ? node->height : 0;
    }

    // Вычислить баланс-фактор узла
    int getBalance(Node* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    // Правый поворот
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Поворот
        x->right = y;
        y->left = T2;

        // Обновление высот
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    // Левый поворот
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Поворот
        y->left = x;
        x->right = T2;

        // Обновление высот
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    // Балансировка узла
    Node* balance(Node* node) {
        int balanceFactor = getBalance(node);

        // Левый перекос
        if (balanceFactor > 1) {
            if (getBalance(node->left) < 0) {
                node->left = leftRotate(node->left); // Лево-правый поворот
            }
            return rightRotate(node); // Правый поворот
        }

        // Правый перекос
        if (balanceFactor < -1) {
            if (getBalance(node->right) > 0) {
                node->right = rightRotate(node->right); // Право-левый поворот
            }
            return leftRotate(node); // Левый поворот
        }

        return node; // Балансировка не требуется
    }

    // Вставка узла
    Node* insert(Node* node, int key) {
        if (!node) return new Node(key);

        if (key < node->key) {
            node->left = insert(node->left, key);
        }
        else if (key > node->key) {
            node->right = insert(node->right, key);
        }
        else {
            return node; // Дубликаты не допускаются
        }

        // Обновление высоты текущего узла
        node->height = max(height(node->left), height(node->right)) + 1;

        // Балансировка узла
        return balance(node);
    }

    // Найти узел с минимальным ключом
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left) {
            current = current->left;
        }
        return current;
    }

    // Удаление узла
    Node* remove(Node* node, int key) {
        if (!node) return node;

        if (key < node->key) {
            node->left = remove(node->left, key);
        }
        else if (key > node->key) {
            node->right = remove(node->right, key);
        }
        else {
            // Узел с одним или без потомков
            if (!node->left || !node->right) {
                Node* temp = node->left ? node->left : node->right;
                if (!temp) {
                    temp = node;
                    node = nullptr;
                }
                else {
                    *node = *temp;
                }
                delete temp;
            }
            else {
                // Узел с двумя потомками
                Node* temp = minValueNode(node->right);
                node->key = temp->key;
                node->right = remove(node->right, temp->key);
            }
        }

        if (!node) return node;

        // Обновление высоты текущего узла
        node->height = max(height(node->left), height(node->right)) + 1;

        // Балансировка узла
        return balance(node);
    }

    // Симметричный обход дерева
    void inOrderTraversal(Node* node) {
        if (!node) return;
        inOrderTraversal(node->left);
        cout << node->key << " ";
        inOrderTraversal(node->right);
    }

public:
    // Конструктор
    AVLTree() : root(nullptr) {}

    // Вставка ключа
    void insert(int key) {
        root = insert(root, key);
    }

    // Удаление ключа
    void remove(int key) {
        root = remove(root, key);
    }

    // Симметричный обход дерева
    void inOrderTraversal() {
        inOrderTraversal(root);
        cout << endl;
    }
};
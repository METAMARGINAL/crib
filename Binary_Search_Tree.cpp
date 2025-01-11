#include <iostream>
using namespace std;

// Структура узла бинарного дерева поиска
struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

// Класс для работы с бинарным деревом поиска
class BinarySearchTree {
private:
    Node* root;

    // Вспомогательный метод для уничтожения дерева
    void destroyTree(Node* node) {
        if (node) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

    // Вспомогательный метод для вставки элемента
    Node* insert(Node* node, int key) {
        if (!node) return new Node(key);
        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        return node;
    }

    // Вспомогательный метод для удаления элемента
    Node* deleteNode(Node* node, int key) {
        if (!node) return node;

        if (key < node->key) {
            node->left = deleteNode(node->left, key);
        }
        else if (key > node->key) {
            node->right = deleteNode(node->right, key);
        }
        else {
            // Узел найден
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Узел имеет двух потомков
            Node* temp = findMin(node->right);
            node->key = temp->key;
            node->right = deleteNode(node->right, temp->key);
        }
        return node;
    }

    // Вспомогательный метод для поиска минимального элемента
    Node* findMin(Node* node) {
        while (node && node->left)
            node = node->left;
        return node;
    }

    // Вспомогательный метод для обхода дерева (прямой, симметричный, обратный)
    void traversePreOrder(Node* node) {
        if (node) {
            cout << node->key << " ";
            traversePreOrder(node->left);
            traversePreOrder(node->right);
        }
    }

    void traverseInOrder(Node* node) {
        if (node) {
            traverseInOrder(node->left);
            cout << node->key << " ";
            traverseInOrder(node->right);
        }
    }

    void traversePostOrder(Node* node) {
        if (node) {
            traversePostOrder(node->left);
            traversePostOrder(node->right);
            cout << node->key << " ";
        }
    }

    // Вспомогательный метод для поиска (рекурсивный)
    Node* searchRecursive(Node* node, int key) {
        if (!node || node->key == key)
            return node;

        if (key < node->key)
            return searchRecursive(node->left, key);
        else
            return searchRecursive(node->right, key);
    }

    // Вспомогательный метод для поиска (итеративный)
    Node* searchIterative(Node* node, int key) {
        while (node && node->key != key) {
            if (key < node->key)
                node = node->left;
            else
                node = node->right;
        }
        return node;
    }

public:
    // Конструктор
    BinarySearchTree() : root(nullptr) {}

    // Деструктор
    ~BinarySearchTree() {
        destroyTree(root);
    }

    // Проверка, пусто ли дерево
    bool isEmpty() {
        return root == nullptr;
    }

    // Вставка нового элемента
    void insert(int key) {
        root = insert(root, key);
    }

    // Удаление элемента
    void remove(int key) {
        root = deleteNode(root, key);
    }

    // Обход дерева
    void traversePreOrder() {
        traversePreOrder(root);
        cout << endl;
    }

    void traverseInOrder() {
        traverseInOrder(root);
        cout << endl;
    }

    void traversePostOrder() {
        traversePostOrder(root);
        cout << endl;
    }

    // Поиск элемента (рекурсивный)
    bool searchRecursive(int key) {
        return searchRecursive(root, key) != nullptr;
    }

    // Поиск элемента (итеративный)
    bool searchIterative(int key) {
        return searchIterative(root, key) != nullptr;
    }
};




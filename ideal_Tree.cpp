#include <iostream>
#include <algorithm>
using namespace std;

// Узел бинарного дерева
struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

// Класс для работы с деревом
class BalancedBinaryTree {
private:
    Node* root;

    // Рекурсивное построение идеально сбалансированного дерева
    Node* buildBalancedTree(int* sortedArray, int start, int end) {
        if (start > end) return nullptr;

        // Выбираем средний элемент как корень
        int mid = (start + end) / 2;
        Node* node = new Node(sortedArray[mid]);

        // Рекурсивно строим левое и правое поддеревья
        node->left = buildBalancedTree(sortedArray, start, mid - 1);
        node->right = buildBalancedTree(sortedArray, mid + 1, end);

        return node;
    }

    // Обход в симметричном порядке для вывода
    void inOrderTraversal(Node* node) {
        if (node) {
            inOrderTraversal(node->left);
            cout << node->key << " ";
            inOrderTraversal(node->right);
        }
    }

public:
    BalancedBinaryTree() : root(nullptr) {}

    // Построение идеально сбалансированного дерева
    void buildTree(int* keys, int size) {
        // Сортируем массив ключей
        sort(keys, keys + size);
        root = buildBalancedTree(keys, 0, size - 1);
    }

    // Симметричный обход дерева
    void traverseInOrder() {
        inOrderTraversal(root);
        cout << endl;
    }
};

// Пример использования
int main() {
    BalancedBinaryTree tree;

    // Исходные ключи
    int keys[] = { 50, 30, 70, 20, 40, 60, 80 };
    int size = sizeof(keys) / sizeof(keys[0]);

    // Построение идеально сбалансированного дерева
    tree.buildTree(keys, size);

    // Симметричный обход дерева
    cout << "Симметричный обход идеально сбалансированного дерева: ";
    tree.traverseInOrder(); // Ожидается: 20 30 40 50 60 70 80

    return 0;
}


//#include "Linked_List_without_head.cpp"
//#include "linked_list_with_head.cpp"
#include <iostream>
#include"DoubleLinkedCucleList.cpp"
using namespace std;

//int main() {
//    LinkedList list;  // Создаем объект списка
//    int choice;
//    int value;
//    Node* nodePointer = nullptr;
//
//    do {
//        // Выводим меню с выбором действий
//        cout << "\nМеню: \n";
//        cout << "1. Добавить элемент в начало списка\n";
//        cout << "2. Добавить элемент в конец списка\n";
//        cout << "3. Добавить элемент после заданного узла\n";
//        cout << "4. Удалить первый элемент списка\n";
//        cout << "5. Удалить элемент после заданного узла\n";
//        cout << "6. Печать списка\n";
//        cout << "7. Рекурсивная печать списка\n";
//        cout << "8. Рекурсивная сумма элементов списка\n";
//        cout << "9. Уничтожить список\n";
//        cout << "0. Выйти\n";
//        cout << "Введите номер действия: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1:
//            cout << "Введите значение для добавления в начало списка: ";
//            cin >> value;
//            list.addToHead(value);
//            break;
//
//        case 2:
//            cout << "Введите значение для добавления в конец списка: ";
//            cin >> value;
//            list.addToTail(value);
//            break;
//
//        case 3:
//            if (list.isEmpty()) {
//                cout << "Список пуст, невозможно добавить элемент после заданного узла.\n";
//                break;
//            }
//            cout << "Введите значение для добавления после заданного узла: ";
//            cin >> value;
//            cout << "Введите значение текущего узла (после которого добавить новый): ";
//            cin >> value;
//            nodePointer = list.getHead();
//            while (nodePointer != nullptr && nodePointer->data != value) {
//                nodePointer = nodePointer->next;
//            }
//            if (nodePointer != nullptr) {
//                list.addAfter(nodePointer, value);
//            }
//            else {
//                cout << "Узел не найден.\n";
//            }
//            break;
//
//        case 4:
//            list.removeFirst();
//            break;
//
//        case 5:
//            if (list.isEmpty()) {
//                cout << "Список пуст, невозможно удалить элемент после заданного узла.\n";
//                break;
//            }
//            cout << "Введите значение текущего узла (после которого удалить элемент): ";
//            cin >> value;
//            nodePointer = list.getHead();
//            while (nodePointer != nullptr && nodePointer->data != value) {
//                nodePointer = nodePointer->next;
//            }
//            if (nodePointer != nullptr) {
//                list.removeAfter(nodePointer);
//            }
//            else {
//                cout << "Узел не найден.\n";
//            }
//            break;
//
//        case 6:
//            list.printList();
//            break;
//
//        case 7:
//            list.printListRecursively();
//            break;
//
//        case 8:
//            cout << "Сумма элементов списка: " << list.sumListRecursively() << endl;
//            break;
//
//        case 9:
//            list.destroy();
//            cout << "Список уничтожен.\n";
//            break;
//
//        case 0:
//            cout << "Выход...\n";
//            break;
//
//        default:
//            cout << "Неверный выбор, попробуйте снова.\n";
//        }
//    } while (choice != 0);  // Меню повторяется, пока пользователь не выберет выход
//
//    return 0;
//}

//int main() {
//    LinkedListWithHeader list;
//
//    // Добавляем элементы в упорядоченный список
//    list.addOrdered(10);
//    list.addOrdered(20);
//    list.addOrdered(30);
//
//    // Печать списка
//    cout << "Список: ";
//    list.printList(); // Вывод: 10 20 30
//
//    // Сумма элементов с заглавным звеном
//    cout << "Сумма элементов (рекурсивно, с заглавным звеном): " << list.getSumRecursive() << endl;
//
//    // Уничтожение списка
//    list.destroy();
//    return 0;
//}

//int main() {
//    // Создаем двунаправленный кольцевой список
//    DoublyCircularList list;
//
//    // Проверяем, что список пуст
//    if (list.isEmpty()) {
//        cout << "Список инициализирован и пуст." << endl;
//    }
//
//    // Добавление элементов
//    cout << "Добавление первого элемента: 10" << endl;
//    list.addAfter(list.getHead()->prev, 10); // Добавляем элемент после заглавного звена
//
//    cout << "Добавление второго элемента: 20 (после 10)" << endl;
//    list.addAfter(list.getHead(), 20); // Добавляем после первого элемента
//
//    cout << "Добавление третьего элемента: 5 (перед 10)" << endl;
//    list.addBefore(list.getHead(), 5); // Добавляем перед первым элементом
//
//    // Печать списка в прямом и обратном направлениях
//    cout << "Список в прямом порядке: ";
//    list.printForward();
//
//    cout << "Список в обратном порядке: ";
//    list.printBackward();
//
//    // Удаление элемента после заглавного звена
//    cout << "Удаление элемента после заглавного звена (первый элемент):" << endl;
//    list.removeAfter(list.getHead()->prev);
//
//    // Удаление элемента перед заглавным звеном
//    cout << "Удаление элемента перед заглавным звеном (последний элемент):" << endl;
//    list.removeBefore(list.getHead());
//
//    // Печать списка после удаления
//    cout << "Список после удаления в прямом порядке: ";
//    list.printForward();
//
//    // Удаление текущего элемента
//    cout << "Удаление оставшегося элемента (10):" << endl;
//    list.removeCurrent(list.getHead());
//
//    // Проверка, что список пуст
//    if (list.isEmpty()) {
//        cout << "Список пуст после удаления всех элементов." << endl;
//    }
//
//    // Уничтожение списка
//    cout << "Уничтожение списка..." << endl;
//    list.destroy();
//
//    return 0;
//}

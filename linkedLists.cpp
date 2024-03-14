#include <iostream>
#include <string>

// Структура для представления узла в связанном списке
struct Node {
    std::string data; // данные хранимые в узле
    Node* next; // указатель на следующий узел
};

// a. Функция для создания пустого связанного списка
void createEmptyLinkedList(Node*& head) {
    head = nullptr;
}

// b. Функция для добавления нового узла со значением в начало связанного списка
void addToBeginning(Node*& head, std::string value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// c. Функция для добавления нового узла со значением в конец связанного списка
void addToEnd(Node*& head, std::string value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    
    if (head == nullptr) {
        head = newNode;
        return;
    }
    
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// d. Функция для проверки наличия и удаления первого узла из связанного списка
void deleteFirstNode(Node*& head) {
    if (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// e. Функция для проверки наличия и удаления всех узлов со значением value из связанного списка
void deleteNodesWithValue(Node*& head, std::string value) {
    Node* current = head;
    Node* prev = nullptr;
    
    while (current != nullptr) {
        if (current->data == value) {
            if (prev == nullptr) {
                head = current->next;
                delete current;
                current = head;
            } else {
                prev->next = current->next;
                delete current;
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }
}

// Тесты
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    // Инициализация указателя на начало списка
    Node* head = nullptr;

    //Установка русской локали
   // std::locale russian_locale("ru_RU.utf8");
   // std::locale::global(russian_locale);

    // a. Создание пустого связанного списка
    createEmptyLinkedList(head);

    // b. Добавление нового узла со значением в начало связанного списка
    addToBeginning(head, "3");
    addToBeginning(head, "2");
    addToBeginning(head, "1");
    std::cout << "List after adding to the beginning: ";
    printLinkedList(head);

    // c. Добавление нового узла со значением в конец связанного списка
    addToEnd(head, "4");
    addToEnd(head, "5");
    addToEnd(head, "6");
    std::cout << "List after adding to the end: ";
    printLinkedList(head);

    // d. Проверка наличия и удаление первого узла из связанного списка
    deleteFirstNode(head);
    std::cout << "List after removing the first node: ";
    printLinkedList(head);

    // e. Проверка наличия и удаление всех узлов со значением value из связанного списка
    deleteNodesWithValue(head, "3");
    std::cout << "List after removing all nodes with value 3: ";
    printLinkedList(head);

    return 0;
}












































/*
#include <iostream>
#include <locale>

//std::locale russian_locale("ru_RU.utf8");

// Структура для представления узла в связанном списке
struct Node {
    string data; // данные хранимые в узле
    Node* next; // указатель на следующий узел
};

// a. Функция для создания пустого связанного списка
void createEmptyLinkedList(Node*& head) {
    head = nullptr;
}

// b. Функция для добавления нового узла со значением в начало связанного списка
void addToBeginning(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// c. Функция для добавления нового узла со значением в конец связанного списка
void addToEnd(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    
    if (head == nullptr) {
        head = newNode;
        return;
    }
    
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// d. Функция для проверки наличия и удаления первого узла из связанного списка
void deleteFirstNode(Node*& head) {
    if (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// e. Функция для проверки наличия и удаления всех узлов со значением value из связанного списка
void deleteNodesWithValue(Node*& head, int value) {
    Node* current = head;
    Node* prev = nullptr;
    
    while (current != nullptr) {
        if (current->data == value) {
            if (prev == nullptr) {
                head = current->next;
                delete current;
                current = head;
            } else {
                prev->next = current->next;
                delete current;
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }
}

// Тесты
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    // Инициализация указателя на начало списка
    Node* head = nullptr;

    //Установка русской локали
   // std::locale russian_locale("ru_RU.utf8");
   // std::locale::global(russian_locale);

    // a. Создание пустого связанного списка
    createEmptyLinkedList(head);

    // b. Добавление нового узла со значением в начало связанного списка
    addToBeginning(head, 3);
    addToBeginning(head, 2);
    addToBeginning(head, 1);
    //std::cout << "Список после добавления в начало: ";
    std::cout<<"List after adding to the beginning: ";
    printLinkedList(head);

    // c. Добавление нового узла со значением в конец связанного списка
    addToEnd(head, 4);
    addToEnd(head, 5);
    addToEnd(head, 6);
    //std::cout << "Список после добавления в конец: ";
    std::cout << "List after adding to the end: ";
    printLinkedList(head);

    // d. Проверка наличия и удаление первого узла из связанного списка
    deleteFirstNode(head);
    //std::cout << "Список после удаления первого узла: ";
    std::cout << "List after removing the first node: ";
    printLinkedList(head);

    // e. Проверка наличия и удаление всех узлов со значением value из связанного списка
    deleteNodesWithValue(head, 3);
    //std::cout << "Список после удаления всех узлов со значением 3: ";
    std::cout << "List after removing all nodes with value 3: ";
    printLinkedList(head);

    return 0;
}
*/
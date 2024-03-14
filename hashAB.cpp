#include <iostream>
#include <string>

using namespace std;

// Структура для представления узла в связном списке
template<typename K, typename V>
struct Node {
    K key;
    V value;
    Node* next;
    
    // Конструктор
    Node(K k, V v) : key(k), value(v), next(nullptr) {}
};

// Класс для хэш-таблицы
template<typename K, typename V, int size>
class HashTable {
private:
    Node<K, V>* table[size]; // Массив указателей на начало связных списков

    // Хэш-функция для получения индекса в таблице
    int hashFunction(const K& key) {
        // Простейший пример хэш-функции: сумма ASCII-кодов символов в ключе
        int hashValue = 0;
        for (char c : key) {
            hashValue += c;
        }
        return hashValue % size;
    }

public:
    // Конструктор, инициализирующий хэш-таблицу
    HashTable() {
        for (int i = 0; i < size; ++i) {
            table[i] = nullptr;
        }
    }

    // Метод для добавления элемента в хэш-таблицу
    void insert(const K& key, const V& value) {
        int index = hashFunction(key);
        Node<K, V>* newNode = new Node<K, V>(key, value);
        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            Node<K, V>* current = table[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Метод для поиска значения по ключу
    bool search(const K& key, V& value) {
        int index = hashFunction(key);
        Node<K, V>* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                value = current->value;
                return true;
            }
            current = current->next;
        }
        return false; // Ключ не найден
    }

    // Метод для удаления элемента из хэш-таблицы
    void remove(const K& key) {
        int index = hashFunction(key);
        Node<K, V>* current = table[index];
        if (current == nullptr) {
            return; // Нет элементов в списке для данного индекса
        }
        if (current->key == key) {
            table[index] = current->next;
            delete current;
            return;
        }
        while (current->next != nullptr && current->next->key != key) {
            current = current->next;
        }
        if (current->next == nullptr) {
            return; // Ключ не найден
        }
        Node<K, V>* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
};

int main() {
    const int tableSize = 10;
    HashTable<string, int, tableSize> hashTable;

    // Добавляем элементы в хэш-таблицу
    hashTable.insert("apple", 5);
    hashTable.insert("banana", 10);
    hashTable.insert("orange", 15);
    hashTable.insert("apple", 20); // Обновляем значение для ключа "apple"

    // Поиск значений по ключам
    int value;
    if (hashTable.search("banana", value)) {
        cout << "Value for key 'banana': " << value << endl;
    } else {
        cout << "Key 'banana' not found." << endl;
    }

    if (hashTable.search("grape", value)) {
        cout << "Value for key 'grape': " << value << endl;
    } else {
        cout << "Key 'grape' not found." << endl;
    }

    // Удаляем элемент из хэш-таблицы
    hashTable.remove("banana");

    return 0;
}

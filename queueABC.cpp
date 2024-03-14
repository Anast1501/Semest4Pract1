#include <iostream>
#include <string>
using namespace std;

//Структура для представления узла в очереди
struct Node {
    string data;
    Node* next;

    //Конструктор
    Node (string value) : data(value), next(nullptr) {}
};

//Класс для реализации очереди
class Queue {
    private:
    Node* front; //указатель на начало очереди
    Node* rear;  //указатель на конец очереди
    
    public:
    //Конструктор
    Queue() : front(nullptr), rear(nullptr) {}

    //Деструктор для освобождения памяти
    ~Queue() { 
        while (front != nullptr) {
            Node*  temp = front;
            front = front->next;
            delete temp;
        }
    }

    //Метод для проверки, пуста ли очередь
    bool isEmpty() {
        return  front == nullptr;
    }

    //Метод для добавления элемента в конец очереди
    void enqueue(string value) {
        Node* newNode = new Node(value);
        if(rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        }

         // Метод для удаления элемента из начала очереди и возвращения его значения
        string dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return "error"; // Возвращаем -1 в случае пустой очереди
        }
        
        string value = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        
        // Если очередь стала пустой, обнуляем указатель на конец
        if (front == nullptr) {
            rear = nullptr;
        }
        
        return value;
    }
};

int main() {
    Queue q;

    // Пример использования очереди для моделирования обработки заявок
    cout << "Processing requests:\n";
    for (int i = 1; i <= 5; ++i) {
        q.enqueue(to_string(i));
        cout << "Added request " << i << " to the queue.\n";
    }
    
    cout << "Processing requests in the order they arrived:\n";
    while (!q.isEmpty()) {
        cout << "Processing request " << q.dequeue() << ".\n";
    }

    return 0;
}

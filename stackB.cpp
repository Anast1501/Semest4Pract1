#include <iostream>
#include <stack>
#include <string>

// Структура для представления вызова функции
struct FunctionCall {
    std::string functionName;
    int returnValue;
    // Здесь можно добавить дополнительные поля, такие как локальные переменные и т.д.

    FunctionCall(const std::string& name) : functionName(name), returnValue(0) {}
};

class CallStack {
private:
    std::stack<FunctionCall> callStack;

public:
    // Добавление вызова функции в стек
    void push(const std::string& functionName) {
        callStack.push(FunctionCall(functionName));
    }

    // Удаление вызова функции из стека
    void pop() {
        if (!callStack.empty()) {
            callStack.pop();
        }
    }

    // Получение текущего вызова функции из вершины стека
    FunctionCall& top() {
        return callStack.top();
    }

    // Проверка, пуст ли стек вызовов
    bool empty() const {
        return callStack.empty();
    }
};

int main() {
    CallStack callStack;

    // Вызов функции main и добавление его в стек
    callStack.push("main");

    // Вызов функции foo и добавление его в стек
    callStack.push("foo");

    // Имитация выполнения foo с возвратом значения 42
    callStack.top().returnValue = 42;

    // Возврат из функции foo и удаление ее из стека
    //callStack.pop();

    // Возврат из функции main и удаление ее из стека
    callStack.pop();

    // Проверка, пуст ли стек вызовов
    if (callStack.empty()) {
        std::cout << "Call stack is empty." << std::endl;
    } else {
        std::cout << "Call stack is not empty." << std::endl;
    }

    return 0;
}

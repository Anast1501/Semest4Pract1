//Реализуйте обратную польскую запись: стек можно использовать для
//преобразования математического выражения из инфиксной нотации в
//постфиксную (обратную польскую) запись, а затем для вычисления результата.

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>

// Функция для определения приоритета операторов
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0; // Для скобок
}

// Функция для преобразования инфиксного выражения в обратную польскую запись
std::string infixToPostfix(const std::string& infix) {
    std::stack<char> operators; //ПЕРЕПИСАТЬ СТРУКТУРУ СТЕКА
    std::stringstream postfix;
    for (char c : infix) {
         if (std::isspace(c))
             continue; // Пропускаем пробелы
        if (std::isdigit(c)) {
            postfix << c << ' '; // Числа сразу добавляем в выходную строку
        } else if (c == '(') { 
               operators.push(c); // Открывающаяся скобка добавляется в стек
        } else if (c == ')') {
            // Выводим операторы из стека в выходную строку до тех пор, пока не встретим открывающую скобку
            while (!operators.empty() && operators.top() != '(') {
                postfix << operators.top() << ' ';
                operators.pop();
            }
            operators.pop(); // Удаляем открывающую скобку из стека
        } else {
            // Операторы
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                postfix << operators.top() << ' ';
                operators.pop();
            }
            operators.push(c);
        }
    }
    // Выводим оставшиеся операторы из стека в выходную строку
    while (!operators.empty()) {
        postfix << operators.top() << ' ';
        operators.pop();
    }
    return postfix.str();
}

// Функция для вычисления выражения в обратной польской записи
int evaluatePostfix(const std::string& postfix) {
    std::stack<int> operands;
    std::stringstream ss(postfix);
    std::string token;
    while (ss >> token) {
        if (std::isdigit(token[0])) {
            operands.push(std::stoi(token)); // Числа добавляем в стек
        } else {
            // Операторы
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();
            switch (token[0]) {
                case '+':
                    operands.push(operand1 + operand2);
                    break;
                case '-':
                    operands.push(operand1 - operand2);
                    break;
                case '*':
                    operands.push(operand1 * operand2);
                    break;
                case '/':
                    operands.push(operand1 / operand2);
                    break;
                default:
                    throw std::runtime_error("Unknown operator");
            }
        }
    }
    return operands.top(); // Результат находится на вершине стека
}


int main() {
    std::string infix = "5 + ((1 + 2) * 4) - 3";
    std::string postfix = infixToPostfix(infix);
    std::cout << "Infix expression: " << infix << std::endl;
    std::cout << "Postfix expression: " << postfix << std::endl;
    int result = evaluatePostfix(postfix);
    std::cout << "Result: " << result << std::endl;
    return 0;
}





































/*
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

// a. Обратная польская запись
int evaluateReversePolishNotation(const std::string& expression) {
    std::stack<int> operands;
    std::unordered_map<char, int> precedence{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

    for (char c : expression) {
        if (isdigit(c)) {
            operands.push(c - '0');
        } else {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();
            if (c == '+')
                operands.push(operand1 + operand2);
            else if (c == '-')
                operands.push(operand1 - operand2);
            else if (c == '*')
                operands.push(operand1 * operand2);
            else if (c == '/')
                operands.push(operand1 / operand2);
        }
    }

    return operands.top();
}

// b. Управление вызовами функций
void functionCallsDemo() {
    std::stack<int> callStack;
    int currentFunction = 0;
    int localVariables = 10;

    // Вызов первой функции
    callStack.push(currentFunction);
    std::cout << "Вызов функции " << currentFunction << ", локальные переменные: " << localVariables << std::endl;

    // Возврат из функции
    callStack.pop();
    std::cout << "Возврат из функции " << currentFunction << std::endl;

    // Вызов второй функции
    currentFunction = 1;
    callStack.push(currentFunction);
    std::cout << "Вызов функции " << currentFunction << ", локальные переменные: " << localVariables << std::endl;
}

// c. Обработка и отмена операций
void undoRedoDemo() {
    std::stack<std::string> operations;
    std::string document = "Initial document";

    // Добавление операций
    operations.push(document);
    document += " - Operation 1";

    operations.push(document);
    document += " - Operation 2";

    // Отмена операции
    if (!operations.empty()) {
        operations.pop();
        document = operations.top();
    }

    std::cout << "Document after undo: " << document << std::endl;

    // Повтор операции
    if (!operations.empty()) {
        document += " - Operation 3";
        operations.push(document);
    }

    std::cout << "Document after redo: " << operations.top() << std::endl;
}

// d. Обход деревьев и графов (DFS)
void depthFirstSearch() {
    // Реализация DFS алгоритма
}

// e. Проверка сбалансированности скобок
bool checkBalancedBrackets(const std::string& expression) {
    std::stack<char> brackets;

    for (char c : expression) {
        if (c == '(' || c == '[' || c == '{') {
            brackets.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (brackets.empty())
                return false;
            char top = brackets.top();
            brackets.pop();
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{'))
                return false;
        }
    }

    return brackets.empty();
}

int main() {
    // Примеры работы каждой функции

    // a. Обратная польская запись
    std::string expression = "32+5*";
    std::cout << "Результат выражения " << expression << " равен " << evaluateReversePolishNotation(expression) << std::endl;

    // b. Управление вызовами функций
    functionCallsDemo();

    // c. Обработка и отмена операций
    undoRedoDemo();

    // d. Обход деревьев и графов (DFS)
    depthFirstSearch();

    // e. Проверка сбалансированности скобок
    std::string bracketExpression = "{[()]}";
    std::cout << "Выражение " << bracketExpression << " сбалансировано: " << std::boolalpha << checkBalancedBrackets(bracketExpression) << std::endl;

    return 0;
}

*/

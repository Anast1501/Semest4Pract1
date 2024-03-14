#include <iostream>
#include <string>

using namespace std;

// Функция для повторения строки указанное количество раз
std::string repeatString(std::string str, int times) {
    std::string result;
    for(int i = 0; i < times; i++) {
        result += str;
    }
    return result;
}

int main() {
    // Пример использования функции repeatString с разными типами аргументов
    std::string repeatedString1 = repeatString("internal event ", 4); // Повтор 3 раза
    std::string repeatedString2 = repeatString("external event ", 5); // Повтор 5 раз
    // Результат повторения строки
    cout << "Result of repeating a string 1: " << repeatedString1 << endl;
    cout << "Result of repeating a string 2: " << repeatedString2 << endl;

    return 0;
}

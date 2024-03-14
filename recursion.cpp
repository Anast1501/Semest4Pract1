#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

// Функция для генерации всех возможных перестановок
void generatePermutations(vector<string>& elements, int start, int end) {
    if (start == end) {
        // Базовый случай: мы достигли конца массива, выводим текущую перестановку
        for (const string& element : elements) {
            cout << element << " ";
        }
        cout << endl;
    } else {
        // Рекурсивный случай: генерируем все перестановки с уменьшением размера задачи
        for (int i = start; i <= end; i++) {
            swap(elements[start], elements[i]); // Поменять текущий элемент с элементом на позиции start
            generatePermutations(elements, start + 1, end); // Вызвать рекурсивно для остальной части массива
            swap(elements[start], elements[i]); // Вернуть исходное состояние массива
        }
    }
}

int main() {
    vector<string> events = {"1", "2", "3"};
   // std::cout << "Все возможные перестановки:\n";
    generatePermutations(events, 0, events.size() - 1);

    return 0;
}

#include <iostream>
#include <stack> //ПЕРЕПИСАТЬ СТЕК

using namespace std;

// Структура для представления графа
struct Graph
{
    int V;           // Количество вершин
    int **adjMatrix; // Матрица смежности
    bool *visited;   // Массив для отслеживания посещенных вершин

    // Конструктор
    Graph(int vertices) : V(vertices)
    {
        // Инициализируем матрицу смежности
        adjMatrix = new int *[V];
        for (int i = 0; i < V; ++i)
        {
            adjMatrix[i] = new int[V];
            for (int j = 0; j < V; ++j)
            {
                adjMatrix[i][j] = 0; // Изначально все ребра отсутствуют
            }
        }

        // Инициализируем массив посещенных вершин
        visited = new bool[V];
        for (int i = 0; i < V; ++i)
        {
            visited[i] = false;
        }
    }

    // Метод для добавления ребра в граф
    void addEdge(int u, int v)
    {
        adjMatrix[u][v] = 1;
        // Для ненаправленного графа добавьте обратное ребро
        // adjMatrix[v][u] = 1;
    }

    // Метод для обхода графа в глубину (DFS)
    void DFS(int start)
    {
        // Создаем стек для выполнения DFS
        stack<int> stk;

        // Помещаем стартовую вершину в стек и отмечаем ее как посещенную
        stk.push(start);
       visited[start] = true;
       //stk.pop();
        // Продолжаем обход в глубину, пока стек не пуст
        while (true)
        { 
            
            // Извлекаем вершину из стека
            int current = stk.top();
          stk.pop();
           
            cout << current << " "; // Выводим текущую вершину

            // Обходим соседние вершины текущей вершины
            for (int i = 0; i < V; ++i)
            {
                if (adjMatrix[current][i] && !visited[i])
                {
                    stk.push(i);
                    visited[i] = true;
                }
            }
            
            if (stk.empty()) break;
        }
    }
};

int main()
{
    // Создаем граф с 5 вершинами
    Graph graph(5);
    // Добавляем ребра в граф
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    // Обходим граф в глубину, начиная с вершины 0
    cout << "Depth-First Search (DFS) traversal starting from vertex : ";
    graph.DFS(0);
    cout << endl;

    return 0;
}

/*
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

// Структура для представления графа
struct Graph {
    int V; // Количество вершин
    vector<vector<int>> adjList; // Список смежности

    // Конструктор
    Graph(int vertices) : V(vertices), adjList(vertices) {}

    // Метод для добавления ребра в граф
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        // Для ненаправленного графа добавьте обратное ребро
        // adjList[v].push_back(u);
    }

    // Метод для обхода графа в глубину (DFS)
    void DFS(int start) {
        // Создаем стек для выполнения DFS
        stack<int> stk;
        // Создаем множество для отслеживания посещенных вершин
        unordered_set<int> visited;

        // Помещаем стартовую вершину в стек и отмечаем ее как посещенную
        stk.push(start);
        visited.insert(start);

        // Продолжаем обход в глубину, пока стек не пуст
        while (!stk.empty()) {
            // Извлекаем вершину из стека
            int current = stk.top();
            stk.pop();
            cout << current << " "; // Выводим текущую вершину

            // Обходим соседние вершины текущей вершины
            for (int neighbor : adjList[current]) {
                // Если соседняя вершина не посещена, добавляем ее в стек и отмечаем как посещенную
                if (visited.find(neighbor) == visited.end()) {
                    stk.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
    }
};

int main() {
    // Создаем граф с 5 вершинами
    Graph graph(5);
    // Добавляем ребра в граф
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    // Обходим граф в глубину, начиная с вершины 0
    cout << "Depth-First Search (DFS) traversal starting from vertex 0: ";
    graph.DFS(0);
    cout << endl;

    return 0;
}
*/
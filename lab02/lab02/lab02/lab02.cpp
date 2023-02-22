#include <iostream>
#include <stack>
#include <queue> 

#include <list> 
#include <cstdlib>
#include <chrono>


using namespace std;
using namespace std::chrono;
int main()
{
    int list1[22][2] =
    { {1,2},{2,1},{1,5},{5,1},{2,7},{7,2},{2,8},{8,2},{7,8},{8,7},{8,3},{3,8},{5,6},{6,5},{6,4},{4,6},{6,9},{9,6},{4,9},{9,4},{9,10},{10,9} };

    list <int> top_1 = { 2, 5 };
    list <int> top_2 = { 1, 7, 8 };
    list <int> top_3 = { 8 };
    list <int> top_4 = { 6, 9 };
    list <int> top_5 = { 1, 6 };
    list <int> top_6 = { 4, 5, 9 };
    list <int> top_7 = { 2, 8 };
    list <int> top_8 = { 2, 3, 7 };
    list <int> top_9 = { 4, 6, 10 };
    list <int> top_10 = { 9 };


    setlocale(LC_ALL, "rus");
    stack<int> Stack;
    queue<int> Queue;

    int mas[10][10] = { { 0, 1, 0, 0, 1, 0, 0, 0, 0, 0 },
    { 1, 0, 0, 0, 0, 0, 1, 1, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
    { 0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
    { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
    { 0, 0, 0, 1, 1, 0, 0, 0, 1, 0 },
    { 0, 1, 0, 0, 0, 0, 0, 1, 0, 0 },
    { 0, 1, 1, 0, 0, 0, 1, 0, 0, 0 },
    { 0, 0, 0, 1, 0, 1, 0, 0, 0, 1 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, };

    int used[10];
    for (int i = 0; i < 10; i++)
        used[i] = 0; 
    auto start = high_resolution_clock::now();
    Queue.push(0); // тут поместили первую вершину

        while (!Queue.empty())
        {
            int node = Queue.front(); // извлекаем вершину
            Queue.pop();
            used[node] = 2; // отмечаем ее как посещенную
            for (int j = 0; j < 10; j++)
            { // проверяем её связи в матрице
                if (mas[node][j] == 1 && used[j] == 0)
                {
                    Queue.push(j); // добавляем ее в очередь
                    used[j] = 1; // отмечаем вершину как обнаруженную
                }
            }
            cout<< "Мы посетили эту вершину " << node + 1 << endl;
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<"Время работы поиска в ширину: " << duration.count()<< " микросекунды" << endl;
    cout << "DFS:" << endl;
    for (int i = 0; i < 10; i++) 
        used[i] = 0;
    auto start2 = high_resolution_clock::now();
    Stack.push(0); 
    while (!Stack.empty())
    { 
        int node = Stack.top(); 
        Stack.pop();
        if (used[node] == 2) continue;
        used[node] = 2; 
        for (int j = 9; j >= 0; j--)
        { 
            if (mas[node][j] == 1 && used[j] != 2)
            { 
                Stack.push(j);
                used[j] = 1; 
            }
        }
        cout<< "Мы посетили эту вершину " << node + 1 << endl; 
    }
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout << "Время работы поиска в глубину: " << duration.count() << " микросекунды" << endl;
    cout << "Все показанные способы поиска работают с одной сложностью O(|v^2| = 100)" << endl;
    cin.get();
    return 0;
}
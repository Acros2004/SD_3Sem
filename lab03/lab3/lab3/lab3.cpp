#include <iostream>
using namespace std;

const int V = 9;

int* Algo(int** GR, int V, int st) {
    int* distance, count, index, i, u;
    bool* flag;
    distance = new int[V];//массив для записи дистанции
    flag = new bool[V];//массив для поджигания вершин
    for (i = 0; i < V; i++) { distance[i] = INT_MAX; flag[i] = false; }//записываем что все дистанции изначально inf и вершины не обнаружены
    distance[st] = 0;//для стартовой вершины
    for (count = 0; count < V; count++) {
        int min = INT_MAX;
        for (i = 0; i < V; i++)
            if (!flag[i] && distance[i] <= min) { min = distance[i]; index = i; }//если вершина не была обнаружена и дистанция меньше минимальной,то мы записываем её номер и дистанцию
        u = index;//сохраняем вершину и помечаем
        flag[u] = true;
        for (i = 0; i < V; i++)
            if (!flag[i] && GR[u][i] && distance[u] != INT_MAX &&
                distance[u] + GR[u][i] < distance[i])
                distance[i] = distance[u] + GR[u][i];//вылаживаем путь(стоимость до какой-либо вершины)
    }
    return distance;
}

void main() {
    setlocale(LC_ALL, "Rus");
    int start, ** matrix;//инициализация стартовой вершины и двумерного массива(в будующем это будет массив смежности)
    matrix = new int* [V];//создаём массив 9х9
    for (int i = 0; i < V; i++) matrix[i] = new int[V]; //инициализировали матрицу смежности 

    int DATA[] = {
     0,7,0,10,0,0,0,0,0,
     7,0,27,0,9,0,0,0,0,
     0,27,0,0,0,0,0,0,15,
     10,0,0,0,8,0,31,0,0,
     0,9,0,8,0,11,0,0,0,
     0,0,0,0,11,0,0,17,15,
     0,0,0,31,0,0,0,32,0,
     0,0,0,0,0,17,32,0,21,
     0,0,15,0,0,15,0,17,0
    };

    int i, j, k = 0;
    for (i = 0; i < V; i++)//заполняем матрицу данными из DATA
        for (j = 0; j < V; j++) matrix[i][j] = DATA[k++];
    cout << "Введите стартовую вершину ";
    cin >> start; //начальная вершина
    start--;//т к у нас нумерация с 0

    int* distance = Algo(matrix, V, start);

    int m = start + 1;
    cout << "Вес пути до разных вершин:\n";
    for (i = 0; i < V; i++)
        if (distance[i] != INT_MAX)
            cout << m << " в " << i + 1 << " составляет " << distance[i] << endl;
        else cout << m << " в " << i + 1 << "невозможно добраться" << endl;

    exit;
}
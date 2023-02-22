#include<conio.h>
#include<iostream>

using namespace std;

bool Prov(int, int, int[]);
const int inf = 23123;
const int V = 8;

bool Prov(int u, int v, int numbers[])
{
	if (u == v)
		return false;
	if (numbers[u] == 0 && numbers[v] == 0)
		return false;
	else if (numbers[u] == 1 && numbers[v] == 1)
		return false;
	return true;
}
void AlgoPrima(int mass[][V]) {
	int a = -1, b = -1, min, n = V, ne = 0, visited[10] = { 0 }, mincost = 0;
	visited[0] = 1;
	cout << "\n";
	min = 999;
	while (ne < n - 1)
	{
		int min = 999, a = -1, b = -1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (mass[i][j] < min)
					if (Prov(i, j, visited))
					{
						min = mass[i][j];
						a = i;
						b = j;
					}
			visited[a] = visited[b] = 1;
			mincost += min;
			cout << "\n " << ne++ << "  " << a << "->" << b << "стоимость перехода: " << min;
	}

	cout << "\n Минимальная стоимость  " << mincost;


}

bool Prov2(int u, int v, int numbers[]) {
	if (u == v)
		return false;
	if (numbers[u] == 0 && numbers[v] == 0) {
		return true;
	}
	else if (numbers[u] == 1 && numbers[v] == 1)
		return false;
	return true;
}
void Prov3(int i,int j,int group[]) {
	while (group[i] != i)
		i = group[i];
	int a = i;
	while (group[j] != j)
		j = group[j];
	int b = j;
	group[a] = b;
}
int Prov4(int i, int group[]) {
	while (group[i] != i)
		i = group[i];
	return i;
}

void AlgoKruskal(int mass[][V]) {
	int a = -1, b = -1, min, n = V, ne = 0,f = 0, visited[10] = { 0 }, mincost = 0;
	cout << "\n";
	min = 999;
	int group[V];
	for (int i = 0; i < n; i++) {
		group[i] = i;
	}

	while (ne < n - 1)
	{
		int min = 999, a = -1, b = -1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (Prov2(i, j, visited) && mass[i][j] < min) {
					min = mass[i][j];
					a = i;
					b = j;
				}
			if ((visited[a] == 0 && visited[b] == 0)&& ne != 0) {
				ne++;
			}
			Prov3(a, b, group);
			visited[a] = visited[b] = 1;
			mincost += min;
			cout << "\n " << ne++ << "  " << ++a << "->" << ++b << "стоимость перехода: " << min;
	}
	min = 999;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if ((Prov4(i,group) != Prov4(j,group)) && (mass[i][j] < min)) {
				min = mass[i][j];
				a = i;
				b = j;
			}
	mincost += min;
	cout << "\n " << ne++ << "  " << ++a << "->" << ++b << "стоимость перехода: " << min;
	cout << "\n Минимальная стоимость  " << mincost;

}

void main()
{
	setlocale(LC_ALL, "ru");

	int mass[8][8] = {
		{inf,2,inf,8,2,inf,inf,inf},
		{2,inf,3,10,5,inf,inf,inf},
		{inf,3,inf,inf,12,inf,inf,7},
		{8,2,inf,inf,14,3,1,inf},
		{2,5,12,14,inf,11,4,8},
		{inf,inf,inf,3,11,inf,6,inf},
		{inf,inf,inf,1,4,6,inf,9},
		{inf,inf,7,inf,8,inf,9,inf}
	};
	AlgoPrima(mass);
	cout << "\n";
	AlgoKruskal(mass);
	
}
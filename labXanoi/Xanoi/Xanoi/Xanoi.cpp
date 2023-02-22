#include <iostream>
using namespace std;

void Hanoi(int col, int point1, int point2)
{
    int tmp;

    if ((point1 == 1 && point2 == 2) || (point1 == 2 && point2 == 1)) tmp = 3;//есть и другой способ проверки,по формуле : tmp = 6-i-k
    else
        if ((point1 == 1 && point2 == 3) || (point1 == 3 && point2 == 1)) tmp = 2;
        else
            if ((point1 == 2 && point2 == 3) || (point1 == 3 && point2 == 2)) tmp = 1;

    // рекурсивный случай
    if (col > 1)
    {
        Hanoi(col - 1, point1, tmp);
        cout << point1 << " to " << point2 << std::endl;
        Hanoi(col - 1, tmp, point2);
    }
    // базовый случай
    else
        std::cout << point1 << " to " << point2 << std::endl;
}

int main()
{
    setlocale(LC_ALL, "ru");
    int quantity, first, second;

    cout << "Сколько у нас колец?" << endl;
    cin >> quantity;
    cout << "Введите начальное положение башни" << endl;
    cin >> first;
    cout << "Введите конечное положение башни" << endl;
    cin >> second;

    Hanoi(quantity, first, second);

    system("pause");
}
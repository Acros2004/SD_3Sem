#include <list>
#include <iostream>
#include <vector>
using namespace std;

const int inf = 22222;

int main()
{
    int array[6][6] = {
        {0,28,21,59,12,27},
        {7,0,24,inf,21,9},
        {9,32,0,12,11,inf},
        {8,inf,5,0,16,inf},
        {14,13,15,10,0,22},
        {15,18,inf,inf,6,0}
    };
    int array2[6][6] = {
        {-1,1,2,3,4,5},
        {0,-1,2,3,4,5},
        {0,1,-1,3,4,5},
        {0,1,2,-1,4,5},
        {0,1,2,3,-1,5},
        {0,1,2,3,4,-1}
    };
    
    int lenght = 6;
    for (int k = 0; k < 6; k++) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                int d = array[i][k] + array[k][j];
                if (array[i][j] > d) {
                    array[i][j] = d;
                    array2[i][j] = k;
                }
            }
        }
    }

    for (int i = 0; i < lenght; i++) {
        for (int j = 0; j < lenght; j++)
            std::cout << " " << array[i][j];
        std::cout << std::endl;
    }
    for (int i = 0; i < lenght; i++) {
        for (int j = 0; j < lenght; j++)
            std::cout << " " << array2[i][j];
        std::cout << std::endl;
    }

    int start = 0;
    int finish = 3;
    while (start != finish) {
        start = array2[start][finish];
        int a = start;
        cout << " " << ++a;
    }
    cout<<" > "<<++start;
    //getPath(array2,start,finish);

   /* list <int> path;
    path.push_front(start);
    while (start != finish) {
        start = array2[start][finish];
        path.push_back(start);
    }
    copy(path.begin(), path.end(), ostream_iterator<int>(cout, " "));
    */
   
}


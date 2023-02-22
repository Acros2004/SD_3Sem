#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>

using namespace std;

#define V 5
// размер популяции
#define SIZE 10

struct unique_gene {
    int price;
    string genome;
};
string getMutatedGen(string gene) {
    for (;;)
    {
        int tempNumber = 1 + rand() % (V - 1);
        int tempNumber2 = 1 + rand() % (V - 1);
        if (tempNumber2 != tempNumber) {
            char temp = gene[tempNumber];
            gene[tempNumber] = gene[tempNumber2];
            gene[tempNumber2] = temp;
            break;
        }
    }
    return gene;
}
bool best(struct unique_gene t1,struct unique_gene t2) {
    return t1.price < t2.price;
}
bool repeat(string s, char ch)
{
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ch)
            return true;
    }
    return false;
}

string create_genome()
{
    string gnome = "0";
    while (true) {
        if (gnome.size() == V) {
            break;
        }
        int temp = 1 + rand() % (V-1);
        if (!repeat(gnome, (char)(temp + 48)))
            gnome += (char)(temp + 48);
    }
    return gnome;
}
int doSeveraly(int a)
{
    return (90 * a) / 100;
}


int main()
{
    setlocale(LC_ALL, "ru");
    

    //стартовая популяция
    int gen = 1;
    // Количество взаимодействий генов
    int gen_thres = 100;

    vector<struct unique_gene> population;
    struct unique_gene temp;

    auto getPrice  = [](string a) 
    {
        int cities[V][V] = { { 0, 2, INT_MAX, 12, 5 },
                    { 2, 0, 4, 8, INT_MAX },
                    { INT_MAX, 4, 0, 3, 3 },
                    { 12, 8, 3, 0, 10 },
                    { 5, INT_MAX, 3, 10, 0 } };
       /* int cities[V][V] = { { 0, 5, INT_MAX, 13, INT_MAX,INT_MAX,INT_MAX,INT_MAX },
                    { 25, 0, 40, INT_MAX, INT_MAX, INT_MAX,INT_MAX,INT_MAX },
                    { INT_MAX, 15, 0, INT_MAX, INT_MAX,9,INT_MAX,INT_MAX },
                    { 14, INT_MAX, INT_MAX, 0, 3,20,INT_MAX,INT_MAX },
                    { INT_MAX, INT_MAX, INT_MAX, 2, 0,INT_MAX,2,3 } ,
                    { INT_MAX, INT_MAX, 5, 10, INT_MAX,0,15,INT_MAX },
                    { INT_MAX, INT_MAX, INT_MAX, INT_MAX, 1, 9, 0, 2 },
                    { INT_MAX, INT_MAX, INT_MAX, INT_MAX, 5, INT_MAX, 3, 0 } };*/
        int f = 0;
        for (int i = 0; i < a.size() - 1; i++) {
            if (cities[a[i] - 48][a[i + 1] - 48] == INT_MAX)
                return INT_MAX;
            f += cities[a[i] - 48][a[i + 1] - 48];
        }
        return f;
    };
    for(int i = 0; i < SIZE;i++)
    {
        temp.genome = create_genome();
        temp.price = getPrice(temp.genome);
        population.push_back(temp);
    } 

    int tempSize = INT_MAX;
    int bestGen = 0;
    cout << "Номер популяции: " << 0 << endl;
    for (int i = 0; i < SIZE; i++) 
    {
        cout << i << " Уникальный ген :" << population[i].genome << " цена пути: " << population[i].price << endl;
        if (population[i].price < tempSize)
        {
            tempSize = population[i].price;
            bestGen = i;
        }    
    }
    cout << "Наименьшая цена составила у гена " << bestGen << "\nЕго геном: " << population[bestGen].genome << "\nЦена пути: " << population[bestGen].price << endl;
    cout << "=====================================" << endl;
    
    int selection = 20000;

    while (selection > 0 && gen <= gen_thres)
    {
        sort(population.begin(), population.end(), best);
        vector<struct unique_gene> new_population;

        for (int i = 0; i < SIZE; i++) 
        {
            struct unique_gene must_mutated = population[i];

            for (;;) {
                string newGen = getMutatedGen(must_mutated.genome);
                struct unique_gene mutated;
                mutated.genome = newGen;
                mutated.price = getPrice(mutated.genome);

                if (mutated.price <= must_mutated.price)
                {
                    new_population.push_back(mutated);
                    break;
                }
                else
                {
                    float prob = pow(2.7,
                        -1 * ((float)(mutated.price
                            - must_mutated.price)
                            / selection));
                    if (prob > 0.5) {
                        new_population.push_back(mutated);
                        break;
                    }
                }
            }
        }
        selection = doSeveraly(selection);
        population = new_population;
        tempSize = INT_MAX;
        bestGen = 0;
        cout << "Номер популяции: " << gen << endl;
        for (int i = 0; i < SIZE; i++)
        {
            cout << i << " Уникальный ген :" << population[i].genome << " цена пути: " << population[i].price << endl;
            if (population[i].price < tempSize)
            {
                tempSize = population[i].price;
                bestGen = i;
            }
        }
        cout << "Наименьшая цена составила у гена " << bestGen << "\nЕго геном: " << population[bestGen].genome << "\nЦена пути: " << population[bestGen].price << endl;
        cout << "=====================================" << endl;
        gen++;
    }
    
    
    
}
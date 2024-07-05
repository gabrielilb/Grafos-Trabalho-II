#include "Aresta.h"
#include "Digrafo.h"
#include <exception>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int c, v;

    cin >> c >> v;

    int c1, c2, p;
    int r, x, m;
    Digrafo voos(c);

    for (int i = 0; i < v; i++)
    {
        cin >> c1 >> c2 >> p;
        voos.insere_aresta(Aresta(c2, c1, p));
    }

    cin >> r;

    for (int j = 0; j < r; j++)
    {
        cin >> x >> m;

        vector<int> pai, peso;
        voos.peso_min(x, pai, peso);

        for (int k = 0; k < peso.size(); k++)
        {
            if (k == x)
            {
                continue;
            }

            if (peso[k] <= m)
            {
                cout << k << ": " << peso[k] << ", ";
                int p = k;
                while (pai[p] != -1)

                {
                    cout << p << " ";
                    p = pai[p];
                }
                cout << p << "\n";
            }
            else
            {
                cout << k << ": " << "economicamente inviavel ate " << x << endl;
            }
        }
    }

    return 0;
}
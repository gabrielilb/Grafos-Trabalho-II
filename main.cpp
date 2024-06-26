#include "Aresta.h"
#include "Digrafo.h"
#include <exception>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int c, v; // cidades e voos

    cin >> c >> v; // entrada das cidades e dos voos

    int c1, c2, p; // c1 é x, c2 é y e p (de peso) é o z
    int r, x, m;   // quantas cidades serão reavaliadas, relativa a cidade x e seu peso máximo m
    Digrafo voos(c);

    for (int i = 0; i < v; i++) // entrada das malhas de voos e custo
    {
        cin >> c1 >> c2 >> p;
        voos.insere_aresta(Aresta(c2, c1, p));
    }

    cin >> r; // entrada da quantidade de cidades que serão reavaliadas

    for (int j = 0; j < r; j++) // loop das cidades reavaliadas
    {
        cin >> x >> m;

        vector<int> pai, peso;
        voos.peso_min(x, pai, peso); // criação do peso min para o digrafo voos

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

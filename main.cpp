/*
 * Tarefa 04 - Grafeira Linhas Aereas
 *
 * GEN254 - Grafos - 2024/1
 *
 * Nome:      XXXX
 * Matricula: XXXX
 */

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
        voos.insere_aresta(Aresta(c1, c2, p));
    }

    cin >> r; // entrada da quantidade de cidades que serão reavaliadas

    for (int j = 0; j < r; j++) // loop das cidades reavaliadas
    {
        cin >> x >> m;
        for (int k = 0; k < voos.num_vertices(); k++) // loop para verificar os pesos a partir do x para todos os outros vértices, k seria o u do enunciado do trab
        {
            if (k != x) // somente faço a busca para o vértice que não for ele mesmo
            {
                std::vector<int> caminho = voos.peso_min(k, x); // criação do vetor com o caminho de peso mínimo
                cout << k << ": ";

                if (caminho[0] > m)
                {
                    cout << "economicamente inviavel ate " << x << "\n";
                }
                else
                {
                    cout << caminho[0] << ",";
                    for (int l = caminho.size() - 1; l > 0; l--)
                    {
                        cout << " " << caminho[l];
                    }
                    cout << "\n";
                }
            }
        }
        cout << "\n";
    }

    return 0;
}

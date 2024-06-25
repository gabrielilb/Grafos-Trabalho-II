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
    cin >> c >> v;
    int c1, c2, p; // c1 é x, c2 é y e p (de peso) é o z
    Digrafo voos(c);

    for (int i = 0; i <= v; i++)
    {
        cin >> c1 >> c2 >> p;
    }

    return 0;
}

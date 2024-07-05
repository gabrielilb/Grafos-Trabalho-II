#include "Digrafo.h"
#include "Filapri_min.h"
#include <exception>
#include <algorithm>
#include <string>
#include <iostream>
#include <climits>
#include <list>
#include <vector>

using namespace std;

Digrafo::Digrafo(int num_vertices)
{
    num_vertices_ = num_vertices;
    num_arestas_ = 0;

    listas_adj_.resize(num_vertices);
}

void Digrafo::insere_aresta(Aresta e)
{
    std::vector<int> vertice_peso;
    vertice_peso.push_back(e.v2);
    vertice_peso.push_back(e.peso);
    listas_adj_[e.v1].push_back(vertice_peso);

    num_arestas_++;
}

void Digrafo::peso_min(int inicio, std::vector<int> &pais, std::vector<int> &pesos)
{

    Filapri_min<int> fila_peso_min(num_vertices_);
    pais.resize(num_vertices_, -1);
    pesos.resize(num_vertices_, INT_MAX);
    pesos[inicio] = 0;

    for (int i = 0; i < num_vertices_; i++)
    {
        fila_peso_min.insere(i, pesos[i]);
    }

    while (!fila_peso_min.vazia())
    {

        pair<int, int> removido = fila_peso_min.remove();
        if (removido.second != INT_MAX)
        {
            for (auto j : listas_adj_[removido.first])
            {

                if (pesos[j[0]] > pesos[removido.first] + j[1])
                {
                    pesos[j[0]] = pesos[removido.first] + j[1];
                    pais[j[0]] = removido.first;
                    fila_peso_min.diminui_prio(j[0], pesos[j[0]]);
                }
            }
        }
    }
}
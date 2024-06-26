#include "Digrafo.h"
#include "Filapri_min.h"
#include <exception>
#include <stdexcept>
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

    listas_adj_.resize(num_vertices); // a lista já vai possuir o número de vértices
}

int Digrafo::num_vertices()
{
    return num_vertices_;
}

int Digrafo::num_arestas()
{
    return num_arestas_;
}

void Digrafo::insere_aresta(Aresta e)
{
    std::vector<int> vertice_peso;
    vertice_peso.push_back(e.v2);
    vertice_peso.push_back(e.peso);
    listas_adj_[e.v1].push_back(vertice_peso); // incluindo na posição v1 o vetor contendo vértice v2 e seu peso

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

    while (!fila_peso_min.vazia()) // enquanto há elementos na fila de prioridade, o loop deve ser mantido
    {
        pair<int, int> removido = fila_peso_min.remove(); // preciso usar pair pois professor usou este tipo, vai remover o de menor valor
        if (removido.second != INT_MAX)
        {
            for (auto j : listas_adj_[removido.first]) // verificar todos os vizinhos do vértice
            {
                if (pesos[j[0]] > pesos[removido.first] + j[1]) // j é vetor, sendo necessário selecionar o primeiro índice e comparar com o first do par. Aqui, está sendo comparado o peso da aresta com a soma dos pesos do caminho
                {                                               // Se o peso da aresta for maior que o caminho encontrado, significa que esse caminho possui menor peso, sendo selecionado
                    pesos[j[0]] = pesos[removido.first] + j[1];
                    pais[j[0]] = removido.first;                   // ajustado o vértice pai
                    fila_peso_min.diminui_prio(j[0], pesos[j[0]]); // ajustada a fila de prioridade
                }
            }
        }
    }
}
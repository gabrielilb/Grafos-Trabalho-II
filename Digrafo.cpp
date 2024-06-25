/*
 * Tarefa 04 - Grafeira Linhas Aereas
 *
 * GEN254 - Grafos - 2024/1
 *
 * Nome:      XXXX
 * Matricula: XXXX
 */

#include "Digrafo.h"
#include "Filapri_min.h"
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

Digrafo::Digrafo(int num_vertices)
{
    if (num_vertices <= 0)
    {
        throw(invalid_argument("Erro no construtor Grafo(int): o numero de "
                               "vertices " +
                               to_string(num_vertices) + " nao eh invalido!"));
    }

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
    // preciso fazer a verificação se a aresta já existe
    if (e.v1 == e.v2)
    {
        return; // os vertices sao iguais
    }

    for (auto i : listas_adj_[e.v1])
    {
        if (i[0] == e.v2)
        {
            return; // Já existe aresta
        }
    }
    // do contrário só inserir
    std::vector<int> vertice_peso(e.v2, e.peso);
    listas_adj_[e.v1].insert(listas_adj_[e.v1].end(), vertice_peso); // incluindo na posição v1 o vetor contendo vértice v2 e seu peso

    num_arestas_++;
}

std::vector<int> Digrafo::peso_min(int inicio, int fim)
{
    Filapri_min<int> fila_peso_min(num_vertices_);
    vector<int> pais(num_vertices_);
    vector<int> pesos(num_vertices_);

    // ajustar a fila de pesos mínimos com o número de vértices
    for (int i = 0; i < num_vertices_; i++)
    {
        int a; // variável para verificar qual valor será incluso na fila
        if (i == inicio)
        {
            a = 0;
        }
        else
        {
            a = 9999;
        }
        fila_peso_min.insere(i, a);
        pais[i] = -1;
        pesos[i] = a;
    }

    while (fila_peso_min.tem_indice(fim)) // enquanto há elementos na fila de prioridade, o loop deve ser mantido
    {
        if (!fila_peso_min.vazia())
        {
            pair<int, int> removido = fila_peso_min.remove(); // preciso usar pair pois professor usou este tipo, vai remover o de menor valor
            if (removido.first != 9999)
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
        else
        {
            break;
        }
    }

    std::vector<int> vetor;
    vetor.insert(vetor.end(), pesos[fim]); // incluo no vetor de retorno o peso do caminho do vértice inicial até o destino final
    int k = fim;                           // salvo em k o índice do vértice final
    while (k != -1)                        // vou "andar" na árvore do fim ao início para buscar o caminho que será realizado
    {
        vetor.insert(vetor.end(), k); // incluo no vetor de retorno o índice desse vértice
        k = pais[k];                  // atualizo o índice do vértico para o pai do atual
    }

    return vetor;
}
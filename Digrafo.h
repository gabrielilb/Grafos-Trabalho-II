/*
 * Tarefa 04 - Grafeira Linhas Aereas
 *
 * GEN254 - Grafos - 2024/1
 *
 * Nome:      XXXX
 * Matricula: XXXX
 */

#ifndef DIGRAFO_H

#define DIGRAFO_H

#include "Aresta.h"
#include <vector>
#include <list>

class Digrafo
{

public:
    Digrafo(int num_vertices);

    int num_vertices();
    int num_arestas();

    void insere_aresta(Aresta e);
    std::vector<int> peso_min(int inicio, int fim);

private:
    int num_vertices_;
    int num_arestas_;
    std::vector<std::list<std::vector<int>>> listas_adj_; // ajustado para que seja um vetor (v1) com lista de vetores (v2 e peso)
};

#endif /* DIGRAFO_H */
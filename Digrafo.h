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
    void peso_min(int inicio, std::vector<int> &pais, std::vector<int> &pesos);

private:
    int num_vertices_;
    int num_arestas_;
    std::vector<std::list<std::vector<int>>> listas_adj_; // ajustado para que seja um vetor (v1) com lista de vetores (v2 e peso)
};

#endif /* DIGRAFO_H */

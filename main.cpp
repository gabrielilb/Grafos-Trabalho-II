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
        voos.insere_aresta(Aresta(c2, c1, p)); // devido a busca da árvore ser das folhas para a raiz, ajustar a inserção das arestas
    }

    cin >> r; // entrada da quantidade de cidades que serão reavaliadas

    for (int j = 0; j < r; j++) // loop das cidades reavaliadas
    {
        cin >> x >> m; // entrada da cidade que será verificada e seu peso máximo

        vector<int> pai, peso;
<<<<<<< HEAD
        voos.peso_min(x, pai, peso); // criação do peso min para o digrafo voos
=======
        voos.peso_min(x, pai, peso); // criação do peso mínimo para o digrafo voos;
>>>>>>> a05bcce37d3977e9244dc403a44f18fb0e5357be

        for (int k = 0; k < peso.size(); k++) // loop para verificação do caminho
        {
            if (k == x) // se o vértice for igual ao x, continuar o loop
            {
                continue;
            }
            if (peso[k] <= m) // se o peso for menor ou igual ao pedido pelo usuário
            {
                cout << k << ": " << peso[k] << ", ";
                int p = k;           // vou salvar o índice em p para utilizar no próximo loop sem perder a informação do k
                while (pai[p] != -1) // vou "andar" no vetor pai até localizar a raiz
                {
                    cout << p << " "; // printar o índice p
                    p = pai[p];       // atualizar o índice de p para o conteúdo
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

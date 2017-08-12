#include "ff.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    int vertice, aresta, franquia, cliente; //declaração dos itens a serem lidos na primeira linha.
    scanf("%d %d %d %d", &vertice, &aresta, &franquia, &cliente);

    int **grafo; //criação do grafo em memória dinâmica.
    grafo = (int**)calloc(vertice+2, sizeof(int*));

    int i = 0;

    for (i = 0; i < vertice+2; i++){
        grafo[i] = (int*)calloc(vertice+2, sizeof(int)); //alocação de uma coluna completa para o grafo. sendo assim, no final, teremos também as linhas alocadas.
//o tamanho é vértive+2 pois já crio a super-origem e super-destino no grafo, que serão os dois ultimos elementos.
    }

    for (i = 0; i < aresta; i++){
        int v1, v2, peso;
        scanf ("%d %d %d", &v1, &v2, &peso); //leitura e atribuição de valores diretamente no grafo.
        grafo[v1][v2] = peso;
    }

    for (i = 0; i < franquia; i++){
        int indice_vertice;
        scanf("%d", &indice_vertice); //identificando um vertice que será uma franquia

        grafo[vertice][indice_vertice] = 99999999; //ligando a superorigem a ele
    }

    for (i = 0; i < cliente; i++){
        int indice_aresta;
        scanf("%d", &indice_aresta); //identificando um vertice que será um cliente

        grafo[indice_aresta][vertice+1] = 99999999; //ligando ele ao superdestino
    }

    int resposta;

    resposta = fordFulkerson(vertice, grafo); //chamada do algoritmo de ford fulkerson.
    printf("%d\n", resposta);

    for (i = 0; i < vertice+2; i++){
        free(grafo[i]); //liberando a memoria alocada de cada elemento do grafo
    }

    free(grafo); //liberando a memoria alocada do grafo em si

    return 0;

}

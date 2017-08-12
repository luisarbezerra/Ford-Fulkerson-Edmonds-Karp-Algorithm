#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int buscaLargura(int vertice, int *caminho, int **grafo, int **fluxo){
    int superOrigem = vertice+1; //determino que a superorigem e superdestino são o penultimo e ultimo elementos
    int superDestino = vertice+2;
    fila *f = criaFila(); //uso a função de criar fila que me retorna uma fila do tipo fila.

    int *visitado; // 0 é não-visitado, 1 é visitado, porém não todos os vizinhos, 2 é visitado todos os vizinhos. Segue a lógica das cores apresentada na sala.
    visitado = (int*)calloc((vertice+2), sizeof(int)); //aloco espaço para o vetor visitado (que guarda vertices visitados)

    int i,j;

    for (i = 0; i < vertice+2; i++){
        visitado[i] = 0; // colocando todos como não-visitados, ou seja, 0.
    }

    enfileirar(superOrigem-1, f, visitado); //enfileiro o vértice origem na fila, no caso a superorigem,e ele torna visitado (1) no vetor visitado.
    caminho[superOrigem-1] = -1;

    while (f->primeiro != NULL){ //enquanto ainda existir elemento na fila, ainda tem lugar pra visitar

        i = desenfileirar(f, visitado); //desenfileira e ainda torna o visitado (2), ou seja, não há mais vértices a serem analisados.

        for (j = 0; j < vertice+2; j++){

            if (visitado[j] == 0 && (grafo[i][j] - fluxo[i][j] > 0)){ //enquanto o vertice ainda não for visitado e se existe um caminho ali, ou seja, a conta > 0

                enfileirar(j, f, visitado); //enfileira ele para analisá-lo.
                caminho[j] = i; //cheguei no j a partir de i
            }
        }
    }

    int check = visitado[superDestino-1]; //recebe o valor visitado, variando de 0,1 e 2.

    free(visitado);
    free(f);
    return (check == 2); //retorna 2 se achar um caminho até superdestino, ou seja, chegou no superdestino.
}

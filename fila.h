#ifndef _FILA
#define _FILA

typedef struct nodo {
    struct nodo *prox;
    struct nodo *ant;
    int vertice;
}nodo;

typedef struct fila {
    struct nodo *primeiro;
    struct nodo *ultimo;
}fila;

fila *criaFila();

int desenfileirar(fila *f, int *visitado);

void enfileirar(int vertice, fila *f, int *visitado);

#endif // _FILA


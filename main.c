#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_TAM 6

//estrutura da fila

typedef struct {
    char pratos[MAX_TAM][20];
    int frente, fundo, quantidade;
} FilaPratos;

//estrutura da pilha

typedef struct {
    char pratos[MAX_TAM][20];
    int topo;
} PilhaPratos;

//agora vou criar as funções de enfileirar e empilhar

void inicializarFila(FilaPratos *fila) {
    fila->frente = 0;
    fila->fundo = -1;
    fila->quantidade = 0;
}
void enfileirarPrato(FilaPratos *fila, char *prato) {
    if (fila->quantidade == MAX_TAM) {
        printf("Já deu Rosa, não tem mais espaço.. Não é possível enfileirar mais pratos.\n");
        return;
    }
    fila->fundo = (fila->fundo + 1) % MAX_TAM;
    strcpy(fila->pratos[fila->fundo], prato);
    fila->quantidade++;
}
//desfileirando 

char* desenfileirarPrato(FilaPratos *fila) {
    if (fila->quantidade == 0) {
        printf("Erro: A fila de pratos está vazia. Não é possível desenfileirar mais pratos.\n");
        return NULL;
    }
    char *prato = fila->pratos[fila->frente];
    fila->frente = (fila->frente + 1) % MAX_TAM;
    fila->quantidade--;
    return prato;
}


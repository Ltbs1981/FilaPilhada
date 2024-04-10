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


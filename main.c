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
void inicializarPilha(PilhaPratos *pilha) {
    pilha->topo = -1;
}

void empilharPrato(PilhaPratos *pilha, char *prato) {
    if (pilha->topo == MAX_TAM - 1) {
        printf("Já deu mano, não cabe mais pratos, vamos enxaguar..\n");
        return;
    }
    pilha->topo++;
    strcpy(pilha->pratos[pilha->topo], prato);
}

void desempilharPrato(PilhaPratos *pilha) {
    if (pilha->topo == -1) { 
        printf("Erro: Pilha vazia. Não é possível remover mais pratos.\n");
        return;
    }
    printf("Prato enxaguado: %s\n", pilha->pratos[pilha->topo]);
    pilha->topo--; 
}

int main() {
    FilaPratos fila;
    PilhaPratos pilha;

    inicializarFila(&fila);
    inicializarPilha(&pilha);

    printf("Rosa, o que acha de lavar alguns pratos?\n");
    printf("Vamos começar a lavar os pratos...\n\n");

    for (int i = 0; i < MAX_TAM; i++) {
        char corPrato[20];
        printf("Informe a cor do prato %d: ", i + 1);
        scanf("%s", corPrato);

        enfileirarPrato(&fila, corPrato);

        printf("Prato %d (%s) enfileirado.\n\n", i + 1, corPrato);
    }

    printf("Todos os pratos enfileirados. Agora vamos empilhá-los...\n\n");

    while (fila.quantidade > 0) {
        char *prato = desenfileirarPrato(&fila);
        empilharPrato(&pilha, prato);
        printf("Prato %s empilhado.\n\n", prato);
    }

    printf("Todos os pratos empilhados. Agora vamos enxaguá-los...\n\n");

    while (pilha.topo >= 0) {
        desempilharPrato(&pilha);
    }

    printf("Cara, você arrasou. Louça zerada!\n");

    return 0;
}



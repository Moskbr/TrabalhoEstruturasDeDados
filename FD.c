#include <stdio.h>
#include <stdlib.h>
#include "FD.h"


// Cria a fila dinamica
Fila *criaFila(){
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

// Verifica se a fila esta vazia
int fila_Vazia(Fila *f){
    if(f->inicio == NULL)
        return 1;
    return 0;
}

// Insere na fila
void fpush(Fila *f, Cliente x){
    nodo *novo = (nodo*)malloc(sizeof(nodo));
    novo->dados = x;
    if(f->fim != NULL)
        f->fim->prox = novo;
    f->fim = novo;
    novo->prox = NULL;
    if(f->inicio == NULL)
        f->inicio = novo;
}

// Remove da fila
Cliente fpop(Fila *f){
    Cliente x;
    x = f->inicio->dados;
    nodo *prox = f->inicio->prox;
    free(f->inicio);
    f->inicio = prox;
    if(f->inicio == NULL)
        f->fim = NULL;
    return x;
}

// Retorna o tamanho da fila
int fila_Tamanho(Fila *f){
    nodo *aux = f->inicio;
    int tam = 0;

    while(aux != NULL){
        aux = aux->prox;
        tam++;
    }
    return tam;
}

// Para fins de depuracao
void imprime_fila(Fila *f){
    nodo *aux = f->inicio;
    printf("Fila: ");
    while(aux != NULL){
        printf("%s:%i ", aux->dados.Nome, aux->dados.qtd_ingressos);
        aux = aux->prox;
    }
}

// Libera nodos da lista ligada
void libera_nodos(nodo *lista) {
    if (lista == NULL) return;
    libera_nodos(lista->prox);
    free(lista);
}

// Libera fila dinamica
void libera_fila(Fila *f){
    libera_nodos(f->inicio);
}


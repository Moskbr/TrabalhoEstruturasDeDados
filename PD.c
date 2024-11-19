#include <stdio.h>
#include <stdlib.h>
#include "PD.h"

// Cria pilha vazia
Pilha *criaPilha(){
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

// Verifica se a pilha esta vazia
int vazia(Pilha *p){
    if(p->topo == NULL)
        return 1;
    return 0;
}

// Insere na pilha
void push(Pilha *p, int x){
    nodo *novo = (nodo*)malloc(sizeof(nodo));
    novo->dados = x;
    novo->prox = p->topo; // Novo se torna a cabeca da lista (topo da pilha)
    p->topo = novo;// p->topo aponta para a nova cabeca
}

// Remove da pilha
int pop(Pilha *p){
    int x = p->topo->dados; // Extrai o topo da pilha;
    nodo *prox = p->topo->prox;// Salva o proximo elemento
    free(p->topo);// Remove o nodo
    p->topo = prox;
    return x;
}

// Retorna o tamanho da pilha
int tamanho(Pilha *p){
    nodo *aux = p->topo;
    int tam = 0;

    while(aux != NULL){
        aux = aux->prox; // Varre a pilha
        tam++; // Incrementa +1 a cada elemento visitado
    }
    return tam;
}

// Para fins de depuracao
void imprime(Pilha *p){
    nodo *aux = p->topo;
    printf("Pilha: ");
    while(aux != NULL){
        printf("%i ", aux->dados);
        aux = aux->prox;
    }
}

// Libera uma lista ligada
void libera(nodo *lista) {
    if (lista == NULL) return;
    libera(lista->prox);
    free(lista);
}

// Libera a pilha dinamica
void libera_pilha(Pilha *p){
    libera(p->topo);
}

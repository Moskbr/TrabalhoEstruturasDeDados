#include <stdio.h>
#include <stdlib.h>
#include "PE.h"

// Cria a pilha
Pilha *criaPilha(){
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = -1; // -1 indica pilha vazia
    return p;
}

// Verifica se a pilha esta vazia
int vazia(Pilha *p){
    if(p->topo == -1) return 1;
    return 0;
}

// Insere elementos na pilha
void push(Pilha *p, int x){
    p->topo++;
    p->v[p->topo] = x;
}

// Remove elementos da pilha
int pop(Pilha *p){
    int x = p->v[p->topo];
    p->topo--;
    return x;
}

// Para depuracao
void imprime(Pilha *p){
    int i = p->topo;
    printf("Pilha: ");
    if(i == -1){
        printf("vazia.\n");
        return;
    }
    for(;i>=0;i--)
        printf("%i ", p->v[i]);
    printf("\n");
}

// Retorna o tamanho da pilha
int tamanho(Pilha *p){
    return p->topo+1;
}

// Limpa a pilha
void libera_pilha(Pilha *p){
    p->topo = -1;
    return;
}

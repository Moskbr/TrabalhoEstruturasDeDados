#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FE.h"

// Cria a fila estatica
Fila *criaFila(){
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->inicio = 0;
    f->fim = 0;
    return f;
}

// Verifica se a fila esta vazia
int fila_Vazia(Fila *f){
    if(f->inicio == f->fim)
        return 1;
    return 0;
}

// Insere na fila
void fpush(Fila *f, Cliente x){
    f->v[f->fim] = x;
    f->fim++;
}

// Remove da fila
Cliente fpop(Fila *f){
    Cliente x;
    x = f->v[f->inicio];
    f->inicio++;
    return x;
}

// Retorna o tamanho da fila
int fila_Tamanho(Fila *f){
    int ini, count=0;
    for(ini = f->inicio; ini < f->fim; ini++)
        count++;
    return count;
}

// Para fins de depuracao
void imprime_fila(Fila *f){
    int i = f->inicio;
    for(;i != f->fim; i++){
        printf(" %s:", f->v[i].Nome);
        printf("%d, ", f->v[i].qtd_ingressos);
    }
    printf("\n");
}

// Limpa a fila
void libera_fila(Fila* f){
    f->inicio = 0;
    f->fim = 0;
    return;
}

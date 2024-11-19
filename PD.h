#ifndef NODE_H // no caso em que as pilhas e as filas sao dinamicas,
#define NODE_H // nao pode haver multiplas declaracoes de Nodo

typedef struct Nodo{
    int dados;
    struct Nodo *prox;
}nodo;

#endif
#ifndef PD_H
#define PD_H

typedef struct pilha{
    nodo *topo;
}Pilha;

Pilha *criaPilha();
int vazia(Pilha *p);
void push(Pilha *p, int x);
int pop(Pilha *p);
int tamanho(Pilha *p);
void imprime(Pilha *p);
void libera(nodo *lista);
void libera_pilha(Pilha *p);

#endif
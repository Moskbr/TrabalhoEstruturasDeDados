#ifndef PE_H
#define PE_H

#define PMAX 2000

typedef struct{ //Pilha ESTATICA
    int topo;
    int v[PMAX];
}Pilha;

Pilha *criaPilha();
int vazia(Pilha *p);
void push(Pilha *p, int x);
int pop(Pilha *p);
void imprime(Pilha *p);
int tamanho(Pilha *p);
void libera_pilha(Pilha *p);

#endif
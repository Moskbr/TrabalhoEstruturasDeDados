#ifndef CLIENTE_H
#define CLIENTE_H
typedef struct Cliente{
    char Nome[20];// Nome da pessoa P
    int qtd_ingressos;// quantidade N de ingressos que ela quer
}Cliente;
#endif
#ifndef NODE_H // no caso em que as pilhas e as filas sao dinamicas,
#define NODE_H // nao pode haver multiplas declaracoes de Nodo

typedef struct Nodo{
    Cliente dados;// tipo Cliente
    struct Nodo *prox;
}nodo;

#endif
#ifndef FD_H
#define FD_H

#define FMAX 20

typedef struct{
    nodo *inicio;
    nodo *fim;
}Fila;

Fila *criaFila();
int fila_Vazia(Fila *f);
void fpush(Fila *f, Cliente x);
Cliente fpop(Fila *f);
int fila_Tamanho(Fila *f);
void imprime_fila(Fila *f);
void libera_nodos(nodo *lista);
void libera_fila(Fila *f);

#endif
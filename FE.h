#ifndef FE_H
#define FE_H

typedef struct Cliente{
    char Nome[20];// Nome da pessoa P
    int qtd_ingressos;// quantidade N de ingressos que ela quer
}Cliente;

#define FMAX 20

typedef struct{
    Cliente v[FMAX + 1];// vetor de Clientes
    int inicio;
    int fim;
}Fila;

Fila *criaFila();
int fila_Vazia(Fila *f);
void fpush(Fila *f, Cliente x);
Cliente fpop(Fila *f);
int fila_Tamanho(Fila *f);
void imprime_fila(Fila *f);
void libera_fila(Fila* f);

#endif
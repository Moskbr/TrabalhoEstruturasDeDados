#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* -- Pilhas -- */
#include "PE.h"
//#include "PD.h"

/* -- Filas -- */
#include "FE.h"
//#include "FD.h"


// funcao para criar estrutura auxiliar Cliente, contendo nome do cliente [Nome]
// e a quantidade de ingressos que ele quer [qtd_ingressos].
// A struct esta declarada nos headers da fila estatica e dinamica.
Cliente* criaCliente(char n[20], int qtd){
    Cliente* c = (Cliente*)malloc(sizeof(Cliente));
    strcpy(c->Nome, n);
    c->qtd_ingressos = qtd;
    return c;
}



int main()
{
    int N, G, A, B, T, I, F;// variaveis do enunciado
    int tam_f0, tam_f1, i, k;// variaveis auxiliares
    char nome[20];
    char comando[10];

    // criando as pilhas
    Pilha* guiche0 = criaPilha();
    Pilha* guiche1 = criaPilha();

    // criando as filas
    Fila* fila0 = criaFila();
    Fila* fila1 = criaFila();

    // cria ponteiro para objeto Cliente
    Cliente* c = NULL;

    F = -1;
    T = 0;// contador de ingressos vendidos
    scanf("%10s", comando);// scanf limitado a 10 caracteres
    while(strcmp(comando, "fim"))
    {
        if(!strcmp(comando, "chega")){// caso: chega P N
            scanf("%20s", nome);
            scanf("%d", &N);

            c = criaCliente(nome, N);
            tam_f0 = fila_Tamanho(fila0);// obtem tamanho da fila0
            tam_f1 = fila_Tamanho(fila1);// obtem tamanho da fila1

            // Se ambas as filas nao estiverem cheias
            if(tam_f0 < FMAX && tam_f1 < FMAX){
                if(tam_f0 > tam_f1){
                    fpush(fila1, *c);
                    F = 1;
                }
                else{// se tam_f0 for menor ou igual a tam_f1
                    fpush(fila0, *c);
                    F = 0;
                }
                printf("%s entrou na fila %d.\n", nome, F);
            }
            else{
                if(tam_f0 >= FMAX && tam_f1 < FMAX){// se fila0 esta cheia mas fila1 nao
                    fpush(fila1, *c);
                    F = 1;
                    printf("%s entrou na fila %d.\n", nome, F);
                }
                else if(tam_f0 < FMAX && tam_f1 >= FMAX){// se fila1 esta cheia mas fila0 nao
                    fpush(fila0, *c);
                    F = 0;
                    printf("%s entrou na fila %d\n", nome, F);
                }
                else{
                    // ambas as filas estao cheias
                    printf("%s desistiu, filas cheias\n", nome);
                }
            }
        }
        else if(!strcmp(comando, "vende")){// caso: vende G
            scanf("%d", &G);
            if(G == 0){// caso G = 0
                if(fila_Vazia(fila0)){
                    printf("Fila 0 vazia!\n");
                }
                else{
                    *c = fpop(fila0);
                    if(vazia(guiche0)){
                        printf("Guiche %d sem ingressos! %s triste.\n", G, c->Nome);
                    }
                    else{
                        for(i=0; i<c->qtd_ingressos && tamanho(guiche0) > 0; i++){
                            I = pop(guiche0);
                            printf("%s comprou ingresso #%d.\n", c->Nome, I);
                            T++;
                        }
                    }
                }
            }
            else if(G == 1){// se G = 1, mesmo funcionamento
                if(fila_Vazia(fila1)){
                    printf("Fila 1 vazia!\n");
                }
                else{
                    *c = fpop(fila1);
                    if(vazia(guiche1)){
                        printf("Guiche %d sem ingressos! %s triste.\n", G, c->Nome);
                    }
                    else{
                        for(i=0; i<c->qtd_ingressos && tamanho(guiche1) > 0; i++){
                            I = pop(guiche1);
                            printf("%s comprou ingresso #%d.\n", c->Nome, I);
                            T++;
                        }
                    }
                }
            }
        }
        else if(!strcmp(comando, "carrega")){// caso: carrega G A B
            scanf("%d", &G);
            scanf("%d", &A);
            scanf("%d", &B);
            
            for(k=A;k<=B;k++){
                if(G == 0){
                    push(guiche0, k);
                }
                else if(G == 1){
                    push(guiche1, k);
                }
            }
            printf("%d ingresso(s) carregado(s) no guiche %d.\n", (B-A+1), G);
        }
        else
            printf("Comando invalido\n");// caso comando nao reconhecido
        
        scanf("%10s", comando);
    }

    // liberando memoria alocada
    libera_fila(fila0);
    libera_fila(fila1);
    libera_pilha(guiche0);
    libera_pilha(guiche1);
    free(c);

    printf("Ingressos vendidos: %d\n", T);
    return 0;
}
# TrabalhoEstruturasDeDados
Trabalho da matéria de Estruturas de Dados que exercita conceitos de File e Pilha dinâmicas e estáticas.

#### Contexto:
Gerenciamento de filas e guichês para compra de ingressos. As filas (de pessoas) são tratadas com a estrutura de dados Fila, e os guichês como Pilha de ingressos disponíveis.

#### Entrada e Saída:
- comando "chega <nome_A> < G >" adiciona a pessoa 'nome_A' à fila do guichê 'G'.
- comando "vende < G >" vende um ingresso à fila do guichê 'G'.
- comando "carrega < G > <NUM_1> <NUM_2>" carrega na pilha de ingressos do guichê 'G', ingressos de número NUM_1 até NUM_2.

A saída de cada comando mostra se foi bem sucedido,, ou não, devido à algum erro ou condição não tratada (como fila vazia, guichê vazio, etc).

#### Implementação:
Como requisito do trabalho, os *includes* do arquivo `main.c` podem ser alterados de forma a ser utilizado estruturas estáticas (baseadas em vetores) ou dinâmicas (baseadas em listas ligadas), sem alterar as chamadas de funções do `main.c`. Recomenda-se antes, compilar todos os arquivos com o `Makefile` e alterá-lo também.

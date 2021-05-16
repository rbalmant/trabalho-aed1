#ifndef __LISTA_ENCADEADA_H
#define __LISTA_ENCADEADA_H

// Simples
typedef struct lista_encadeada_t
{
    int i;

    struct lista_encadeada_t *prox;
} lista_encadeada_t;

/* // Duplamente encadeada
typedef struct lista_encadeada_2_t
{
    int i;

    struct lista_encadeada_2_t *anterior;
    struct lista_encadeada_2_t *prox;
} lista_encadeada_2_t;*/


// Funções - lista simplesmente encadeada
lista_encadeada_t *lista_encadeada_inicializa(int i);

int lista_encadeada_inserir(lista_encadeada_t **cabeca, int i);
int lista_encadeada_remover(lista_encadeada_t **cabeca, int i);

lista_encadeada_t *lista_encadeada_busca(lista_encadeada_t *cabeca, int i);

void lista_encadeada_imprime(lista_encadeada_t *cabeca);

int lista_encadeada_destroi(lista_encadeada_t *cabeca);





// Funções - lista simplesmente encadeada circular



// Funções - lista duplamente encadeada




#endif
#include <stdlib.h>
#include <stdio.h>
#include "lista_encadeada.h"


// Função para inicializar um novo elemento da lista encadeada! (ou seja, inicializamos um elemento qualquer, que pode inclusive ser o primeiro)
lista_encadeada_t *lista_encadeada_inicializa(int i)
{
    // Alocação de memória para o novo elemento lista
    lista_encadeada_t *l = malloc(sizeof(lista_encadeada_t));
    if (l == NULL)
    {
        fprintf(stderr, "erro malloc\n"); // falta ou falha de memória
        return NULL;
    }

    l->i = i;
    l->prox = NULL;

    return l; // IMPORTANTE: Retornamos o endereço do elemento criado!
}

// Função para inserior um novo elemento na lista encadeada dada (elemento cabeça)
// ATENÇÃO: essa função chama a função acima, então na prática apenas a função abaixo deve ser utilizada. (uma função inicia a memória e o elemento (acima), e outra de fato insere na lista encadeada)
int lista_encadeada_inserir(lista_encadeada_t **cabeca, int i)
{
    // Temos que ter certeza que o elemento cabeça foi inicializado!
    if (*cabeca != NULL)
    {
        lista_encadeada_t *novo_elemento = lista_encadeada_inicializa(i);
        if (novo_elemento != NULL)
        {
            novo_elemento->prox = *cabeca;
            novo_elemento->i = i;
            *cabeca = novo_elemento;

            return 0;
        }

        return -1;
    }
    else
    {
        *cabeca = lista_encadeada_inicializa(i); // Estamos inserindo o primeiro elemento
        if (*cabeca == NULL) return -1;

        return 0;
    }

    return -1;
}

// Função para buscar um elmento na lista encadeada
lista_encadeada_t *lista_encadeada_busca(lista_encadeada_t *cabeca, int i)
{
    // O elemento cabeça deve ser não nulo, do contrário não há o que procurar 
    if (cabeca != NULL)
    {

        // Nosso elemento ponteiro cursor para varrer a lista (não queremos alterar cabeça)
        lista_encadeada_t *c = cabeca;

        // Varremos a lista encadeada até acharmos o elemento, ou nosso cursor for NULL
        while (c != NULL)
        {
            if (c->i == i) return c;

            c = c->prox;
        }
    }

    return NULL;
}

// Função para remover um elemento da lista encadeada
int lista_encadeada_remover(lista_encadeada_t **cabeca, int i)
{
    // Se o elemento cabeca for nulo, não há o que ser removido
    if (*cabeca != NULL)
    {
        // Precisamos primeiro encontrar o elemento, como na busca, vamos utilizar um ponteiro cursor
        lista_encadeada_t *c = *cabeca;

        // Como na busca, varremos até encontrar o vetor (ou o ponteiro cursor for NULL), mas devemos tratar o caso especial que o elemento a ser removido é o primeiro (cabeça)!


        // Caso a chave do elemento cabeça não for igual a chave procurada, varremos como na busca. 
        if (c->i != i)
        {
            while (c != NULL)
            {
                if ((c->prox)->i == i) break;

                c = c->prox;
            }

            // anterior = c
            // encontrado (a ser removido) = *(c->prox)
            // próximo = (c->prox)->prox
            lista_encadeada_t *tmp = c->prox;

            c->prox = tmp->prox;
            free(tmp);

            return 0;
        }
        // Caso a chave do primeiro elemento (cabeça) seja igual a chave procurada, precisamos substituir cabeça.
        else
        {
            // Devemos remover o primeiro elemento
            lista_encadeada_t *tmp = c;
            *cabeca = tmp->prox;
            free(tmp);

            return 0;
        }


    }

    return -1;
}

// Uma função auxiliar para imprimir todas as chaves de uma lista encadeada.
// Tem funcionamento bastante parecido com a busca, exceto que não estamos fazendo nenhuma comparação.
void lista_encadeada_imprime(lista_encadeada_t *cabeca)
{
    if (cabeca != NULL)
    {
        lista_encadeada_t *c = cabeca;

        while (c != NULL)
        {
            fprintf(stdout, "%d\n", c->i);

            c = c->prox;
        }
    }
}

// Precisamos também de uma função para liberar a memória.
// Como na busca, varremos a lista toda, excluindo elemento a elemento.
int lista_encadeada_destroi(lista_encadeada_t *cabeca)
{
    if (cabeca != NULL)
    {
        lista_encadeada_t *tmp;
        while (cabeca != NULL)
        {
            tmp = cabeca;
            cabeca = tmp->prox;
            //printf("freein' %d\n", tmp->i);
            free(tmp);
        }
        return 0;
    }

    return -1;
}
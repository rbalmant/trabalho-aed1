#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

pilha_seq_t *pilha_seq_inicializa(int cap)
{
    if (cap <= 0) return NULL;

    pilha_seq_t *p = malloc(sizeof(pilha_seq_t));
    if (p == NULL)
    {
        fprintf(stderr, "Erro malloc\n");
        return NULL;
    }

    p->n = malloc(sizeof(int) * cap);
    if (p->n == NULL)
    {
        fprintf(stderr, "Erro malloc\n");
        free(p);
        return NULL;
    }

    p->cap = cap;
    p->topo = -1;

    return p;
}

int pilha_seq_vazia(pilha_seq_t *p)
{
    if (p == NULL) return -1;

    return p->topo == -1;
}

int pilha_seq_cheia(pilha_seq_t *p)
{
    if (p == NULL) return -1;

    return p->topo == p->cap;
}

// Inserção
int pilha_seq_insere(pilha_seq_t *p, int i)
{
    if (p == NULL || pilha_seq_cheia(p)) return -1;

    *(p->n + ++(p->topo)) = i;

    return 0;
}

// Remoção O(1) (constante) (note que não vamos fazer os elementos voltarem uma posição, nesse caso perderíamos muita performance na remoção)
int pilha_seq_remove(pilha_seq_t *p)
{
    if (p == NULL || pilha_seq_vazia(p)) return -1;

    int i = *(p->n);

    (p->topo)--;

    return i;
}

void pilha_seq_imprime(pilha_seq_t *p)
{
    if (p == NULL || pilha_seq_vazia(p)) return;

    int i=0;
    while (i <= p->topo)
    {
        fprintf(stdout, "%d\n", *(p->n + i));
    }
}

void pilha_seq_destroi(pilha_seq_t *p)
{
    if (p != NULL)
    {
        free(p->n);
        free(p);
    }
}

void pilha_seq_aumenta_cap(pilha_seq_t *p, int cap)
{
    if (p != NULL && cap > p->cap)
    {
        int *v2;
        v2 = realloc(p->n, sizeof(int) * cap);
        if (v2 == NULL)
        {
            fprintf(stdout, "Erro de memória.\n");
            return;
        }


        p->n = v2;
        p->cap = cap;

        // Note que o topo não se altera, não estamos mexendo nas chaves, apenas na capacidade.
    }
}
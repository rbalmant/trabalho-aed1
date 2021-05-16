#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

vetor_t *vetor_inicializa(int cap)
{
    if (cap <= 0) return NULL;

    vetor_t *v = malloc(sizeof(vetor_t));
    if (v == NULL)
    {
        fprintf(stderr, "erro malloc\n");
        return NULL;
    }

    v->n = malloc(sizeof(int) * cap);
    if (v->n == NULL)
    {
        fprintf(stderr, "erro malloc\n");
        free(v);
        return NULL;
    }

    v->tam = 0;
    v->cap = cap;

    return v;
}

vetor_t *vetor_inicializa_a_partir_de_vetor(int *v, int cap, int tam)
{
    if (v != NULL)
    {
        vetor_t *r = malloc(sizeof(vetor_t));
        if (r == NULL)
        {
            fprintf(stderr, "erro malloc\n");
            return NULL;
        }

        r->n = v;
        r->cap = cap;
        r->tam = tam;

        return r;
    }

    return NULL;
}

int vetor_vazio(vetor_t *v)
{
    if (v == NULL) return -1;

    return v->tam == 0;
}

int vetor_cheio(vetor_t *v)
{
    if (v == NULL) return -1;

    return v->tam == v->cap;
}

int vetor_busca(vetor_t *v, int i)
{
    if (v == NULL || vetor_vazio(v)) return -1;

    int k = 0;
    while (k <= v->tam)
    {
        if (*(v->n + k) == i) return k;
    }

    return -1;
}

int vetor_insere(vetor_t *v, int i)
{
    if (v == NULL || vetor_cheio(v)) return -1;

    *(v->n + (v->tam)) = i;
    v->tam++;

    return 0;
}

int vetor_insere_pos(vetor_t *v, int i, int pos)
{
    if (v == NULL || vetor_cheio(v) || pos > v->cap) return -1;

    int k = v->tam + 1;
    while (k > pos)
    {
        *(v->n + k) = *(v->n + k - 1);
        k--;
    }

    *(v->n + pos) = i;

    return 0;
}

int vetor_remove(vetor_t *v, int i)
{
    if (v == NULL || vetor_vazio(v)) return -1;

    int pos = vetor_busca(v, i);
    if (pos >= 0)
    {
        vetor_remove_pos(v, pos);
        return 0;
    }
    else
    {
        // Nada a fazer, elemento não encontrado!
        return -1;
    }
}

int vetor_remove_pos(vetor_t *v, int pos)
{
    if (v == NULL || vetor_vazio(v) || pos > v->tam) return -1;

    while (pos < v->tam)
    {
        *(v->n + pos) = *(v->n + pos + 1);
        pos++;
    }

    return 0;
}

void vetor_imprime(vetor_t *v)
{
    if (v == NULL) return;

    int i=0;
    while (i <= v->tam)
    {
        fprintf(stdout, "%d\n", *(v->n + i++));
    }
}

void vetor_aumenta_cap(vetor_t *v, int cap)
{
    if (v != NULL && cap > v->cap)
    {
        int *v2;
        v2 = realloc(v->n, sizeof(int) * cap);
        if (v2 == NULL)
        {
            fprintf(stdout, "Erro de memória.\n");
            return;
        }

        v->n = v2;
        v->cap = cap;

        // Note que o tamanho não muda nesse caso.
    }
}

void vetor_destroi(vetor_t *v)
{
    if (v != NULL)
    {
        free(v->n);
        free(v);
    }
}

// Uma função auxiliar para "limpar" um vetor (deixar ele todo aleatório novamente)
// Note que estamos colocando tam elementos, e todos os elementos estão módulo tam, ou seja, inteiros aleatórios de 1 até tam (pois estamos somando 1, assim excluindo valores 0)
void vetor_aleatorio(int *v, int tam)
{
    if (v != NULL)
    {
        for (int j=0; j<tam; j++)
        {
            *(v + j) = (int) (rand() % tam + 1); // Inteiros de 1 até iter_tam_max (inclusive)
        }
    }
}

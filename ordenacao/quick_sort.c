#include "quick_sort.h"
#include <stdlib.h>
#include <stdio.h>

void quick_sort(int *v, int cap, int p, int r)
{
    if (v != NULL && p < r && r <= cap)
    {
        quick_sort_real(v, p, r);
    }
}

void quick_sort_real(int *v, int i, int f)
{

    if (i >= f) return; // Quando isso acontece, as chamadas na stack call são retornadas na ordem reversa, até que a primeira chamada retorne para a função main (ou outra função).

    // i < f (listas de tamanho de pelo menos 2 elementos)
    int k; // k vai ser nosso ponto de quebra da lista (ou sublista)
    
    // Particionamos a lista (ou uma sublista em chamadas recursivas).
    k = quick_sort_particiona(v, i, f);

    // Ordenamos a primeira parte.
    quick_sort_real(v, i, k - 1);

    // Ordenamos a segunda parte.
    quick_sort_real(v, k + 1, f);
}

int quick_sort_particiona(int *v, int esq, int dir)
{
    // Como pivô estamos escolhendo o vetor mais a esqueda da sublista (TODO: Testar com pivô aleatório e comparar tempos)
    int x, pivot = esq;
    
    x = *(v + pivot);
    

    while (esq < dir)
    {
        while (*(v + esq) <= x) esq++; // Elementos a esquerda de x, e menores que x (pivô), já estão ordenados, então podemos pular eles tranquilamente.
        while (*(v + dir) > x) dir--; // Elementos a direita de x, e maiores que x (pivô), já estão ordenados, então podemos pular eles tranquilamente.

        // Note que nesse momento temos a garantia de duas coisas.
        // *(v + dir) <= x, e *(v + esq) > x, dessa forma esses elementos podem ser trocados para serem ordenados.

        if (esq < dir) // Condição para a troca.
        {
            quick_sort_troca((v + esq), (v + dir));
        }
    }
    quick_sort_troca((v + dir), (v + pivot));
    return dir;

}

// Função para troca dois elementos de posição. (note que apenas trocamos os valores)
void quick_sort_troca(int *a, int *b)
{
    if (a != NULL && b != NULL)
    {
        int tmp = *b;
        *b = *a;
        *a = tmp;
    }
}
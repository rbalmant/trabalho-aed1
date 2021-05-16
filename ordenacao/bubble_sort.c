#include <stdlib.h>
#include <stdio.h>
#include "bubble_sort.h"


void bubble_sort_troca(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Bubblesort versão recursiva.
void bubble_sort(int *v, int tam)
{
    if (v != NULL && tam >= 1) // condição de parada (retorno na call stack): tam < 1
    {
        int i = 0;
        while (i < tam)
        {
            if (*(v + i) > *(v + i + 1)) // Comparação do método da bolha.
            {
                bubble_sort_troca((v + i), (v + i + 1)); // Se o elemento seguinte for menor, trocamos.
            }

            i++;
        }
        bubble_sort(v, tam-1);
    }
}

// Bubblesort versão iterativa (ligeiramente melhor que a versão acima, em termos de tempo computacional)
void bubble_sort2(int *v, int tam)
{
    int i,j;

    // Compara listas com tamanhos variados, de i inicio até j (final), sendo que o j se move, então as listas vão ficando menores.
    for (i=tam-1; i>0; i--)
    {
        for (j=0; j<i; j++)
        {
            if (*(v + j) > *(v + j + 1)) // Comparação do método bolha.
            {
                bubble_sort_troca((v + j), (v + j + 1));
            }
        }
    }
}

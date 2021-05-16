/*
    Seropédica, 2 de maio de 2021.

    Trabalho final da disciplina de Algoritmos e Estruturas de Dados I (2020.1), da Universidade Federal Rural do Rio de Janeiro.
    Professor: Rafael Bernardo

    Aluno: Raphael Balmant

    Para os resultados obtidos, utilizei:

    Processador: Intel(R) Core(TM) i7-8550U CPU @ 1.80GHz
    Sistema operacional: Arch Linux  (Linux 5.11.16-arch1-1)
    Compilador: gcc version 10.2.0 (GCC)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "../bubble_sort.h"

#define V_TAM_INICIAL 10
#define V_TAM_ITER     4


int main(int argc, char *argv[])
{
    int *v = NULL; // vetor a ser prenchido e ordenado

    int iter_i=0;
    int i;
    unsigned long long max; // inteiro sem sinal de 64bits, ou seja, pode guardar o maior valor em módulo disponível na máquina.

    FILE *f_tempos;
    time_t tempo_i;
    time_t tempo_f;
    float tempo_intervalo;

    srand(time(NULL));

    f_tempos = fopen("../../tempos/bubblesort.txt", "w+");
    if (f_tempos == NULL)
    {
        fprintf(stderr, "erro fopen\n");
        return -1;
    }

    fprintf(f_tempos, "AVALIAÇÃO DO MÉTODO BOLHA (BUBBLESORT)\n\n");
    fprintf(f_tempos, "ITERAÇÃO |  TAMANHO  |       TEMPO\n");

    while (iter_i < V_TAM_ITER)
    {

        if (v != NULL)
        {
            free(v);
            v = NULL;
        }

        max = V_TAM_INICIAL * (int) pow(10, iter_i);
        v = malloc(sizeof(int) * max);
        if (v == NULL)
        {
            fprintf(stderr, "erro malloc\n");
            fclose(f_tempos);
            return -1;
        }

        i=0;
        while (i < max)
        {
            *(v + i) = (rand() % max) + 1;
            i++;
        }

        tempo_i = clock();
        bubble_sort2(v, max);
        tempo_f = clock();

        tempo_intervalo = ((float)(tempo_f - tempo_i) / CLOCKS_PER_SEC);

        fprintf(f_tempos, "    %d    |  %llu", iter_i+1, max);
        for(int j=0; j < V_TAM_ITER - iter_i; j++)
        {
            fprintf(f_tempos, " ");
        }
        
        fprintf(f_tempos, "|   %11.20lfs\n", tempo_intervalo);

        iter_i++;
    }


    fclose(f_tempos);
    free(v);
    return 0;
}
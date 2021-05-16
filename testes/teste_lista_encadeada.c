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
#include "../vetor.h" // apenas para auxiliar com valores.
#include "../lista_encadeada.h"

#define V_TAM_INICIAL 10
#define V_TAM_ITER    5

int main(int argc, char *argv[])
{
    int *v = NULL; // vetor auxiliar.
    lista_encadeada_t *lista = NULL; // elemento cabeça.


    int iter_i=0;
    unsigned long long max; // inteiro sem sinal de 64bits, ou seja, pode guardar o maior valor em módulo disponível na máquina.

    FILE *f_tempos; // Arquivo a ser escrito com os tempos.

    time_t tempo_i;
    time_t tempo_f;

    float tempo_insercao;
    float tempo_remocao;

    srand(time(NULL)); // Seed para o rand()

    f_tempos = fopen("../tempos/lista_encadeada.txt", "w+");
    if (f_tempos == NULL)
    {
        fprintf(stderr, "erro fopen\n");
        return -1;
    }

    fprintf(f_tempos, "AVALIAÇÃO DA INSERÇÃO E REMOÇÃO EM UMA LISTA ENCADEADA (SIMPLES)\n\n");
    fprintf(f_tempos, "%s %s %s %s\n", "ITERAÇÃO", "TAMANHO", "INSERÇAO", "REMOÇÃO");

    max = V_TAM_INICIAL * (int) pow(10, V_TAM_ITER-1);
    v = malloc(sizeof(int) * max);
    if (v == NULL)
    {
        fprintf(stderr, "erro malloc\n");
        fclose(f_tempos);
        return -1;
    }



    while (iter_i < V_TAM_ITER)
    {
        max = V_TAM_INICIAL * (int) pow(10, iter_i);
        vetor_aleatorio(v, max); // preenchemos o vetor auxiliar com o tamanho de elementos da iteração atual.


        // Vamos avaliar primeiro a inserção. Para isso vamos completar a lista encadeada com todos os elementos do vetor auxiliar.
        tempo_i = clock();
        for (int j=0; j<max; j++) lista_encadeada_inserir(&lista, *(v + j));
        tempo_f = clock();

        // Inserção finalizada, podemos computar o intervalo de tempo.
        tempo_insercao = ((float)(tempo_f - tempo_i) / CLOCKS_PER_SEC);

        // Vamos agora para remoção.
        // Para a remoção vamos remover um elemento aleatório da lista encadeada.
        int rng = rand() % max; // Índice aleatório do elemento de v a ser retirado da lista encadeada.

        tempo_i = clock();
        lista_encadeada_remover(&lista, *(v + rng));
        tempo_f = clock();

        // Remoção concluída. Vamos computar o intervalo de tempo que demorou.
        tempo_remocao = ((float)(tempo_f - tempo_i) / CLOCKS_PER_SEC);

        fprintf(f_tempos, "%d %llu", iter_i+1, max);

        for (int j=0; j<V_TAM_ITER-iter_i; j++)
        {
            fprintf(f_tempos, " ");
        }

        fprintf(f_tempos, "%.20lfs %.20lfs\n", tempo_insercao, tempo_remocao);

        iter_i++;
    }


    fclose(f_tempos);
    free(v);
    lista_encadeada_destroi(lista);
    return 0;
}
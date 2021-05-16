#ifndef __VETOR_H_
#define __VETOR_H_

typedef struct
{
    int *n;

    int tam;
    int cap;
} vetor_t;

// Inicializa um vetor com capacidade inicial cap
vetor_t *vetor_inicializa(int cap);

// Inicia um vetor e copia tam elementos de v para o novo vetor.
vetor_t *vetor_inicializa_a_partir_de_vetor(int *v, int cap, int tam);

// Verifica se o vetor está vazio (retorno nulo -> vetor NÃO está vazio, retorno posivito -> vetor vazio, retorno negativo -> erro)
int vetor_vazio(vetor_t *v);

// Verifica se o vetor está cheio (retorno nulo -> vetor NÃO está cheio, retorno positivo -> vetor cheio, retorno negativo -> error)
int vetor_cheio(vetor_t *v);

// Insere uma chave i no vetor v.
int vetor_insere(vetor_t *v, int i);

// Insere uma chave i na posição pos do vetor v.
int vetor_insere_pos(vetor_t *v, int i, int pos);

// Busca pela chave i no vetor v.
int vetor_busca(vetor_t *v, int i);

// Tenta remover uma chave i do vetor v.
int vetor_remove(vetor_t *v, int i);

// Remove o elemento de posição pos do vetor v.
int vetor_remove_pos(vetor_t *v, int pos);

// Imprime todos os elementos de v.
void vetor_imprime(vetor_t *v);

// Libera memória do vetor v.
void vetor_destroi(vetor_t *v);

// Aumenta a capacidade do vetor v para cap. (IMPORTANTE: v tem que ter sido inicializado com malloc, pois estamos utilizando realloc!)
void vetor_aumenta_cap(vetor_t *v, int cap);

// FUNÇÃO AUXILIAR: Pegar um vetor genérico de tamanho tam e insere inteiros aleatórios em todas as suas posições.
void vetor_aleatorio(int *v, int tam);

#endif
#ifndef __PILHA_H
#define __PILHA_H

// Pilha utlizando memória sequencial.
// IMPORTANTE: topo = -1 quer dizer pilha vazia!

typedef struct
{
    int *n;

    int topo;
    int cap;
} pilha_seq_t;


// Inicializamos a estrutura de pilha com uma capacidade determinada.
pilha_seq_t *pilha_seq_inicializa(int cap);

// Função para verificar se uma pilha qualquer está vazia.
int pilha_seq_vazia(pilha_seq_t *p);

// Função para verificar se uma pilha qualquer está cheia. (topo atingiu cap)
int pilha_seq_cheia(pilha_seq_t *p);

// Inserção de um elemento na pilha
int pilha_seq_insere(pilha_seq_t *p, int i);

// Remoção
int pilha_seq_remove(pilha_seq_t *p);

void pilha_seq_imprime(pilha_seq_t *p);

void pilha_seq_destroi(pilha_seq_t *p);

void pilha_seq_aumenta_cap(pilha_seq_t *p, int cap);

#endif
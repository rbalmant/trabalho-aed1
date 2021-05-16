#ifndef __FILA_H
#define __FILA_H

typedef struct
{
    int *n;

    int inicio;
    int fim;
    int cap;
} fila_seq_t;

#define ELEM_MAX 4096 // Máximo de elementos padrão em uma fila sequencial. 

// Inicializa a fila sequencial com um tamanho determinado.
fila_seq_t *fila_seq_inicializa(int cap);

// Queue -> enfileira um elemento (inserir)
int fila_seq_enfileira(fila_seq_t *fila, int i);

// Dequeue -> desenfileira um elemento (remover)
int fila_seq_desenfileira(fila_seq_t *fila);

// Busca por um elemento qualquer
int fila_seq_busca(fila_seq_t *fila, int i);

// Libera memória da fila sequencial.
void fila_seq_destroi(fila_seq_t *fila);

// Aumenta capacidade de armazenamento.
void fila_seq_aumenta_cap(fila_seq_t *f, int cap);


typedef struct fila_enc_nodo_t
{
    int i;

    struct fila_enc_nodo_t *prox;
} fila_enc_nodo_t; // Cada elemento da nossa fila é um elemento desse tipo abstrato.

typedef struct
{
    fila_enc_nodo_t *comeco; // Primeiro elemento adicionado.
    fila_enc_nodo_t *final; // Último elemento adicionado.
} fila_enc_t;

int fila_enc_enfileira(fila_enc_t **fila, int i); // Note que estamos exigindo uma variável ponteiro para ponteiro fila do tipo fila_enc_t (que contém tanto ponteiro pro começo quanto pro fim)

int fila_enc_desenfileira(fila_enc_t **fila); // Mesmo raciocínio que a função acima.

// Busca por um elemento na fila encadeada.
fila_enc_nodo_t *fila_enc_busca(fila_enc_t **fila, int i);

int fila_enc_destroi(fila_enc_t *fila);


#endif
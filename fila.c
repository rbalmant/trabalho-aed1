#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

// FILA COMO VETOR!

fila_seq_t *fila_seq_inicializa(int cap)
{
    if (cap <= 0) return NULL;

    fila_seq_t *f = malloc(sizeof(fila_seq_t));
    if (f == NULL)
    {
        fprintf(stderr, "Erro malloc\n");
        return NULL;
    }

    f->n = malloc(sizeof(int) * cap);
    if (f->n == NULL)
    {
        fprintf(stderr, "Erro malloc\n");
        free(f);
        return NULL;
    }

    f->inicio = -1;
    f->fim = -1;
    f->cap = cap;

    return f;
}


// Função para enfileirar um elemento em uma fila (como vetor).
// Note que, nesse caso, eu vou inserir os elementos no final, e só posso inserir se houver capacidade no meu vetor.
int fila_seq_enfileira(fila_seq_t *fila, int i)
{
    if (fila != NULL)
    {
        // Temos uma fila não vazia.
        // Primeira coisa que devemos verificar é se temos capacidade no vetor da fila para armazenar mais uma chave.

        if (fila->fim == fila->cap)
        {
            fprintf(stdout, "Fila já está na capacidade máxima de armazenamento!\n");
            return -2;
        }

        // Podemos adicionar um elemento. (note que (*fila)-> fim é nesse momento no máximo (*fila->cap - 1), por construção)

        *(fila->n + fila->fim + 1) = i;
        (fila->fim)++;

        return 0;
    }

    fprintf(stdout, "fila vazia.\n");
    return -1;
}

int fila_seq_desenfileira(fila_seq_t *fila)
{
    if (fila == NULL) return -1;

    // Fila sequencial não vazia.

    int i = *(fila->n + fila->inicio + 1);
    fila->inicio++;
    
    // Poderia mover todos os elementos para esquerda no vetor, porém, teria que varrer o vetor inteiro, e então perderia o benefício da complexidade constante.

    return i;
}

// Como não sei se a fila está ordenada ou não, tenho que fazer uma busca linear. (varrer todos os elementos)
int fila_seq_busca(fila_seq_t *fila, int i)
{
    if (fila == NULL) return -1;

    for (int j=fila->inicio+1; j <= fila->fim+1; j++)
    {
        if (*(fila->n + j) == i) return j;
    }

    return -2;
}

void fila_seq_destroi(fila_seq_t *fila)
{
    if (fila != NULL)
    {
        free(fila->n);
        free(fila);
    }
}

void fila_seq_aumenta_cap(fila_seq_t *f, int cap)
{
    if (f != NULL && cap > f->cap)
    {
        int *v2;
        v2 = realloc(f->n, sizeof(int) * cap);
        if (v2 == NULL)
        {
            fprintf(stdout, "Erro de memória.\n");
            return;
        }

        f->n = v2;
        f->cap = cap;

        // Note que o inicio e fim não se alteram, não estamos mexendo nas chaves, apenas na capacidade.
    }
}

// FILA COMO LISTA SIMPLESMENTE ENCADEADA

// Função para inserior elemento, ou seja, enfileirar. (queue) (tempo constante)
int fila_enc_enfileira(fila_enc_t **fila, int i)
{
    if (*fila == NULL)
    {
        // Primeiro elemento a ser enfileirado!

        fila_enc_t *nova_fila = malloc(sizeof(fila_enc_t)); // alocação de memória
        if (nova_fila == NULL)
        {
            fprintf(stderr, "erro malloc\n"); // falha ou falta de memória
            return -1;
        }

        fila_enc_nodo_t *elem = malloc(sizeof(fila_enc_nodo_t));
        if (elem == NULL)
        {
            fprintf(stderr, "erro malloc\n"); // falha ou falta de memória
            return -1;
        }


        elem->i = i;
        elem->prox = NULL;

        // Primeiro elemento é tanto o começo quanto o final da fila. Note que o comeco da fila só é alterado quando fazemos dequeue, portanto
        // quando tempos uma lista não vazia (caso do else abaixo), não precisamos nos importar com o começo, apenas com o final (último elemento adicionado)
        nova_fila->final = elem;
        nova_fila->comeco = elem;

        *fila = nova_fila; // O ponteiro para ponteiro da lista vai receber o endereço da nova fila (que é um ponteiro). Ponteiro pra ponteiro = ponteiro pra ponteiro OK.
        return 0;
    }
    else
    {
        // Já existe pelo menos um elemento na fila!
        fila_enc_nodo_t *elem = malloc(sizeof(fila_enc_nodo_t));
        if (elem == NULL)
        {
            fprintf(stderr, "erro malloc\n"); // falha ou falta de memória
            return -1;
        }


        elem->i = i;
        elem->prox = NULL;
        (*fila)->final->prox = elem;
        (*fila)->final = elem;

        
        return 0;
    }
}

// Função para remover um elemento (ou seja, desenfileira) (dequeue) (tempo constante)
int fila_enc_desenfileira(fila_enc_t **fila)
{
    if (*fila == NULL)
    {
        // Fila vazia -> nada a fazer.
        return -1;
    }
    else
    {
        // Fila não-vazia.
        // Fila é FIFO, então devemos encontrar o primeiro elemento adicionado, para desenfileirar esse elemento.
        // Portanto, como fila->comeco guarda o endereço do primeiro elemento, devemos remover esse.


        // Elemento a ser removido = primeiro adicionado.
        fila_enc_nodo_t *tmp = (*fila)->comeco;

        // Chave do elemento a ser removido.
        int ret = tmp->i;

        // O começo agora é o segundo elemento adicionado.
        (*fila)->comeco = tmp->prox;

        // Libera memória.
        free(tmp);
        
        // Retorna a chave.
        return ret;
    }
}

// No caso da busca, infelizmente, não tem jeito, vou ter que fazer busca elemento por elemento... :-(
fila_enc_nodo_t *fila_enc_busca(fila_enc_t **fila, int i)
{
    if (*fila == NULL) return NULL;

    // Fila não vazia => Temos começo e final.

    fila_enc_nodo_t *c = (*fila)->comeco;
    while (c != NULL && c->i != i) c = c->prox; // Para quando c é NULL (chegamos ao final), ou quando c->i == i, ou seja elemento encontrado!

    return c; // Retorna NULL em caso de elemento não encontrado.
}

// Libera memória, elemento por elemento.
int fila_enc_destroi(fila_enc_t *fila)
{
    if (fila != NULL)
    {
        fila_enc_nodo_t *cabeca = fila->comeco;
        fila_enc_nodo_t *tmp;
        while (cabeca != NULL)
        {
            tmp = cabeca;
            cabeca = tmp->prox;
            printf("desenfileirei: %d\n", tmp->i);
            free(tmp);
        }

        free(fila);
        return 0;
    }

    return -1;
}
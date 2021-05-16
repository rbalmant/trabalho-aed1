#ifndef __QUICK_SORT_H
#define __QUICK_SORT_H


void quick_sort(int *v, int cap, int p, int r);
void quick_sort_real(int *v, int p, int r);
int quick_sort_particiona(int *v, int p, int r);
int quick_sort_particiona_pivo_aleatorio(int *v, int p, int r);
void quick_sort_troca(int *a, int *b);


#endif
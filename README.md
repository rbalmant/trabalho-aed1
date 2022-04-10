# Código do trabalho final da disciplina Algoritmos e Estruturas de Dados I (2020.1) da Universidade Federal Rural do Rio de Janeiro.

O trabalho consistiu em medir o tempo de execução de alguns algoritmos com entradas variando em tamanho (alguns algoritmos poderiam ser de escolha do aluno). No meu caso foi implementado:

- Bubblesort (método da bolha) (ordenação) (O(n^2) no pior caso)
- Quicksort (ordenação) (O(n * log(n) no caso médio)
- Inserção e remoção nas seguintes estruturas de dados:
    - Lista sequencial (vetor)
    - Lista encadeada (simples)
    - Pilha (implementada como vetor)
    - Fila (implementada como vetor)

A inserção foi feita em todas as estruturas de dados utilizando um vetor auxiliar contendo inteiros aleatórios módulo o tamanho máximo do vetor mais um para cada iteração (assim, em cada iteração os valores possíveis variam de 1 até o próprio tamanho do vetor auxiliar). E então, foram utilizadas as funções de cada estrutura de dados para inserir ou remover elementos.
\
\
Nos testes, foram inseridos todos os elementos do vetor auxiliar na estrutura de dados, e na remoção ou foi escolhido um elemento do vetor auxiliar aleatório (nos casos de lista sequencial e lista encadeada), ou usada a função própria de remoção da pilha e fila (pop e dequeue, respectivamente).

\
\
Os seguintes resultados foram obtidos:



## Tempos do método da bolha (bubblesort iterativo)

Iteração|Tamanho|Tempo
--- | --- | ---
|1|10|0.00000099999999747524s|
|2|100|0.00001200000042445026s|
|3|1000|0.00067400000989437103s|
|4|10000|0.10800100117921829224s|
|5|100000|12.72261905670166015625s|
|6|1000000|1557.59326171875000000000s|

## Tempos do quicksort

Iteração |  Tamanho  |       Tempo
--- | --- | ---
|    1    |  10         |   0.00000300000010611257s|
|    2    |  100        |   0.00001100000008591451s|
|    3    |  1000       |   0.00013899999612476677s|
|    4    |  10000      |   0.00172900001052767038s|
|    5    |  100000     |   0.00906699988991022110s|
|    6    |  1000000    |   0.08104100078344345093s|
|    7    |  10000000   |   0.86078101396560668945s|
|    8    |  100000000  |   12.72713470458984375000s|
|    9    |  1000000000 |   127.04190826416015625000s|

## Tempos da lista sequencial (vetor)

Iteração | Tamanho | Inserção | Remoção
--- | --- | --- | ---
|1 |10    |     0.00000399999998990097s |0.00000199999999495049s|
|2 |100  |      0.00001899999915622175s| 0.00000000000000000000s|
|3 |1000    |   0.00000499999987368938s| 0.00000099999999747524s|
|4| 10000    |  0.00003700000161188655s |0.00000700000009601354s|
|5 |100000   |  0.00039599998854100704s |0.00002099999983329326s|
|6 |1000000   | 0.00374100008048117161s |0.00026500000967644155s|
|7 |10000000  | 0.02382599934935569763s |0.00101699994411319494s|
|8 |100000000 | 0.21774899959564208984s |0.03629399836063385010s|
|9|1000000000|4.63209676742553710938s|0.09591200202703475952s|

## Tempos da lista encadeada (simples)

Iteração | Tamanho | Inserção | Remoção
--- | --- | --- | ---
|1| 10       | 0.00000600000021222513s |0.00000399999998990097s|
|2| 100       |0.00001499999962106813s |0.00000199999999495049s|
|3| 1000    |  0.00009799999679671600s |0.00001599999995960388s|
|4| 10000   |  0.00111399998422712088s |0.00001899999915622175s|
|5| 100000   | 0.01020099967718124390s |0.00034400000004097819s|
|6| 1000000  | 0.02717499993741512299s |0.00253599998541176319s|
|7| 10000000 | 0.20690900087356567383s |0.00978299975395202637s|
|8| 100000000 |3.18067407608032226562s |0.02382900007069110870s|

## Tempos da pilha

Iteração | Tamanho | Inserção | Remoção
--- | --- | --- | ---
|1|10        | 0.00000399999998990097s |0.00000199999999495049s|
|2| 100       | 0.00000399999998990097s |0.00000199999999495049s|
|3| 1000       |0.00001200000042445026s |0.00000099999999747524s|
|4| 10000    |  0.00016500000492669642s |0.00000199999999495049s|
|5| 100000   |  0.00039599998854100704s |0.00000099999999747524s|
|6| 1000000  |  0.00375899998471140862s |0.00000099999999747524s|
|7| 10000000  | 0.02341200038790702820s |0.00000099999999747524s|
|8| 100000000 | 0.22801899909973144531s |0.00000099999999747524s|
|9| 1000000000 |4.28397321701049804688s |0.00000199999999495049s|

## Tempos da fila

Iteração | Tamanho | Inserção | Remoção
--- | --- | --- | ---
|1| 10         |0.00000099999999747524s| 0.00000000000000000000s|
|2| 100        |0.00000099999999747524s| 0.00000000000000000000s|
|3| 1000       |0.00000199999999495049s| 0.00000000000000000000s|
|4| 10000      |0.00002700000004551839s| 0.00000000000000000000s|
|5| 100000     |0.00027200000477023423s| 0.00000099999999747524s|
|6| 1000000    |0.00301799993030726910s| 0.00000099999999747524s|
|7| 10000000   |0.02360299974679946899s| 0.00000000000000000000s|
|8| 100000000  |0.48629298806190490723s| 0.00000099999999747524s|
|9| 1000000000 |4.20023202896118164062s| 0.00000099999999747524s|

\
\
Todos os resultados foram obtidos com a mesma máquina, mesmo sistema operacional, e mesmo compilador:

- Processador: Intel(R) Core(TM) i7-8550U CPU @ 1.80GHz
- Sistema operacional: Arch Linux  (Linux 5.11.16-arch1-1)
- Compilador: gcc version 10.2.0 (GCC)




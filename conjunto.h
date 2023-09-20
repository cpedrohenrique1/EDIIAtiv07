#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <time.h>
#include <iostream>
#include <QString>

class Conjunto
{
private:
    int *vetor;
    int *vetor_selection_sort;
    int *vetor_insertion_sort;
    long long tamanho_vetor;
    long long nmr_execucoes;
public:
    Conjunto(long long tamanho_array);
    ~Conjunto();
    long long getTamanhoVetor() const;
    int *getVetor() const;
    int* getVetorSelectionSort() const;
    int* getVetorInsertionSort() const;
    long long getNmrExecucoes() const;
    void selectionSort();
    void insertionSort();
};

#endif // CONJUNTO_H

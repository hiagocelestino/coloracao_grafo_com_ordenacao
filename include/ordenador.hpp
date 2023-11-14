#ifndef ORDENADOR_H
#define ORDENADOR_H

#include "lista.hpp"

class Ordenador{
    public:
        Ordenador();
        void bubbleSort(Lista *vertices, int tamanho);
        void selectionSort(Lista *vertices, int tamanho);
        void insertionSort(Lista *vertices, int tamanho);
        void mergeSort(Lista *vertices, int inicio, int fim);
        void heapSort(Lista *vertices, int tamanho);
        void quickSort(Lista *vertices, int inicio, int fim);
        void countingsort(Lista *vertices, int tamanho);
    private:
        void _swap(Lista *lista, int pos1, int pos2);
        void _heapify(Lista *vertices, int tamanho, int i);
        int _particao(Lista *vertices, int baixo, int alto);
        void _merge(Lista *vertice, int esq, int meio, int dir);
};

#endif
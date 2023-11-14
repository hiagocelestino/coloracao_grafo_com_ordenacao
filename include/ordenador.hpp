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
        void merge(Lista *vertice, int esq, int meio, int dir);
        void heapSort(Lista *vertices, int tamanho);
        void heapify(Lista *vertices, int tamanho, int i);
        void quickSort(Lista *vertices, int inicio, int fim);
        int particao(Lista *vertices, int baixo, int alto);
        void mantemPosicoes(Lista *vertices, int tamanho);
        // void _constroi(Lista *vertices, int tamanho);
        // void  _refaz(int esq, int dir, Lista *vertices);
        void sort();
        // void quickSort();
        // void mergeSort();
        // void heapSort();
    private:
        // int _merge(int *valuesL, int *valuesR, int nl, int nr);
        // void _ordena(int esq, int dir, Item *itens);
        // void _particao(int esq, int dir, int *i, int *j, Item *itens);
        // Item _retiraMax(Item *itens, int sizeItens);
        // void _constroi(Item *itens, int sizeItens);
        // void  _refaz(int esq, int dir, Item *itens);
};

#endif
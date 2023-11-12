#ifndef LISTA_HPP
#define LISTA_HPP

#include <iostream>
#include "celula.hpp"

class Lista {
    public:
        Lista();
        Lista(int numero_vertice);
        int getTamanho();
        Celula *getInicio();
        Celula *getFim();
        Lista *getProxLista();
        void adicionaItem(Celula *novo);
        void setProximaLista(Lista *proxima_lista);
        int getCor();
        void setCor(int c);
        void imprimir();

    private:
        unsigned int tamanho;
        int cor;
        Celula *inicio;
        Celula *fim;
};

#endif
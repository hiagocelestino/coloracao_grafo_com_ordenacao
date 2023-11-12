#ifndef LISTA_ADJASCENCIA_HPP
#define LISTA_ADJASCENCIA_HPP

#include <iostream>
#include "lista.hpp"


class ListaAdjacencia {
    public:
        ListaAdjacencia(int tamanho);
        ~ListaAdjacencia();

        
    private:
        Lista* inicio;
        Lista* fim;
        Lista* proxima_lista;
        int tamanho;
};

#endif
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include "lista.hpp"
#include "celula.hpp"


class Grafo{
    public:
        Grafo(int num_vertices);
        ~Grafo();

        Lista *getVertices();
        void setVertices(Lista *novos_vertices);
        void setAresta(int v, int w);
        int getQuantidadeVertices();
        void imprimeVizinhos(int v);
        void colorirVertice(int v, int c);
        int verificaColoracaoGulosa();
        void imprimeVertices();
    private:
        Lista *vertices;
        int num_vertices;
};

#endif
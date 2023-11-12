#ifndef GRAPH_HPP
#define GRAPH_HPP

/*  Você pode inserir os includes necessários para que sua classe funcione.
 * Nenhuma outra alteração neste arquivo é permitida
 */
#include <iostream>
#include "lista.hpp"
#include "celula.hpp"


class Grafo{
    public:
        Grafo(int num_vertices);
        ~Grafo();

        void InsereAresta(int v, int w);

        int QuantidadeVertices();
        int QuantidadeArestas();

        int GrauMinimo();
        int GrauMaximo();

        void ImprimeVizinhos(int v);
        void colorirVertice(int v, int c);
        int verificaColoracaoGulosa();
    private:
        Lista *vertices;
        int num_vertices;
};

#endif
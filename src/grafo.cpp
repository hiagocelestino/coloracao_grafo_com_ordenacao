#include "grafo.hpp"

Grafo::Grafo(int numero_vertices) {
    vertices = new Lista[numero_vertices];
    num_vertices = numero_vertices;

    for(int i = 0; i < numero_vertices; i++) {
        Lista lista_conexoes = Lista(i);
        vertices[i] = lista_conexoes;
    }
};

Grafo::~Grafo() {
    delete vertices;
};

void Grafo::InsereAresta(int v, int w) {
    Celula *valor = new Celula();
    valor->setConteudo(w);
    vertices[v].adicionaItem(valor);
};

int Grafo::QuantidadeVertices() {
    return num_vertices;
};

int Grafo::QuantidadeArestas() {
    return 0;
};

int Grafo::GrauMinimo() {
    return 0;
};

int Grafo::GrauMaximo() {
    return 0;
};

void Grafo::ImprimeVizinhos(int v) {
    std::cout << "Vértice: " << v << std::endl;
    vertices[v].imprimir();
};

void Grafo::colorirVertice(int vertice, int cor) {
    vertices[vertice].setCor(cor);
};

int Grafo::verificaColoracaoGulosa() {
    int coloracao_gulosa = 1;

    for( int i = 0; i < num_vertices; i++ ) {
        int cor_vertice = vertices[i].getCor();
        int cores_necessarias[cor_vertice] = {0};

        Celula *vizinho = vertices[i].getInicio();
        while ( vizinho != nullptr ) {
            int cor_vizinho = vertices[vizinho->getConteudo()].getCor();
            if (cor_vizinho > cor_vertice) {
                coloracao_gulosa = 0;
                break;
            }
            cores_necessarias[cor_vizinho] = 1;
            vizinho->getProximo();
        }

        for ( int j = 0; j < cor_vertice; j++ ) {
            if (cores_necessarias[j] == 0) {
                coloracao_gulosa = 0;
                break;
            }
        }

        if (coloracao_gulosa == 0) {
            break;
        }
    }

    return coloracao_gulosa;
}
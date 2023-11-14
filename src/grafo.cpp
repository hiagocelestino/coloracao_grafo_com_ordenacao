#include "grafo.hpp"

using namespace std;
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

Lista* Grafo::getVertices() {
    return vertices;
};

void Grafo::setVertices(Lista *novos_vertices) {
    vertices = novos_vertices;
}

void Grafo::setAresta(int v, int w) {
    Celula *valor = new Celula();
    valor->setConteudo(w);
    vertices[v].adicionaItem(valor);
};

int Grafo::getQuantidadeVertices() {
    return num_vertices;
};

void Grafo::imprimeVizinhos(int v) {
    cout << "Vértice: " << v << endl;
    vertices[v].imprimir();
};

void Grafo::imprimeVertices() {
    for(int i = 0; i < num_vertices; i++) {
        cout << vertices[i].getLabel() << " ";
    }
    cout << endl;
};

void Grafo::colorirVertice(int vertice, int cor) {
    vertices[vertice].setCor(cor);
};

int Grafo::verificaColoracaoGulosa() {
    int coloracao_gulosa = 1;

    for( int i = 0; i < num_vertices; i++ ) {
        int cor_vertice = vertices[i].getCor();
        if (cor_vertice <= 1) continue;
        int cores_necessarias[cor_vertice - 1] = {0};

        Celula *vizinho = vertices[i].getInicio();
        while ( vizinho != nullptr ) {
            int label_vizinho = vizinho->getConteudo();
            int cor_vizinho = vertices[label_vizinho].getCor();

            if (cor_vizinho < cor_vertice) {
                cores_necessarias[cor_vizinho - 1] = 1;
            }
            vizinho = vizinho->getProximo();
        }

        for ( int j = 0; j < cor_vertice - 1; j++ ) {
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
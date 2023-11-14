#include <iostream>
#include <string>

#include "grafo.hpp"
#include "ordenador.hpp"

using namespace std;
int main() {
    char ordenacao;
    int num_vertices;

    cin >> ordenacao;
    cin >> num_vertices;
    
    string valores;
    Grafo *grafo = new Grafo(num_vertices);

    for(int i = 0; i < num_vertices; i++) {
        int num_vizinhos;
        int vertice;
        cin >> num_vizinhos;
        for (int j = 0; j < num_vizinhos; j++) {
            cin >> vertice;
            grafo->setAresta(i, vertice);
        }
    }

    for(int i = 0; i < num_vertices; i++) {
        int cor;
        cin >> cor;
        grafo->colorirVertice(i, cor);
    }

    int coloracao_gulosa = grafo->verificaColoracaoGulosa();

    if ( coloracao_gulosa == 0 ) {
        cout << coloracao_gulosa << endl;
        return 0;
    }

    Ordenador ordenador = Ordenador();

    switch(ordenacao) {
        case 'b':
            ordenador.bubbleSort(grafo->getVertices(), grafo->getQuantidadeVertices());
            break;
        case 's':
            ordenador.selectionSort(grafo->getVertices(), grafo->getQuantidadeVertices());
            break;
        case 'i':
            ordenador.insertionSort(grafo->getVertices(), grafo->getQuantidadeVertices());
            break;
        case 'q':
            ordenador.quickSort(grafo->getVertices(), 0, grafo->getQuantidadeVertices() - 1);
            break;
        case 'm':
            ordenador.mergeSort(grafo->getVertices(), 0, grafo->getQuantidadeVertices() - 1);
            break;
        case 'p':
            ordenador.heapSort(grafo->getVertices(), grafo->getQuantidadeVertices());
            break;
        case 'y':
            ordenador.sort();
            break;
        default:
            throw ("Entrada Inválida.");
    }
    
    cout << 1 << " ";
    grafo->imprimeVertices();
    return 0;
}
#include <iostream>
#include <string>

#include "grafo.hpp"
#include "ordenador.hpp"

using namespace std;
int main(int argc, char *argv[]) {
    
    // if (argc < 3) {
    //     cout << "Faltam parâmetros." << endl;
    //     return 1; 
    // }
    // string parametro = argv[1];
    // string expressao = argv[2];
    // string valores = argv[3];

    // – b: Método da bolha ou bubble sort.
    // – s: Método da seleção ou selection sort.
    // – i: Método da inserção ou insertion sort.
    // – q: quicksort.
    // – m: mergesort.
    // – p: heapsort.
    // – y: Seu próprio método de ordenação.

    char ordenacao;
    int num_vertices;

    cin >> ordenacao;
    cin >> num_vertices;
    
    string valores;
    Grafo grafo = Grafo(num_vertices);

    for(int i = 0; i < num_vertices; i++) {
        int num_vizinhos;
        int vertice;
        cin >> num_vizinhos;
        for (int j = 0; j < num_vizinhos; j++) {
            cin >> vertice;
            grafo.InsereAresta(i, vertice);
        }
    }

    for(int i = 0; i < num_vertices; i++) {
        int cor;
        cin >> cor;
        grafo.colorirVertice(i, cor);
    }

    int coloracao_gulosa = grafo.verificaColoracaoGulosa();

    if ( coloracao_gulosa == 0 ) {
        cout << coloracao_gulosa << endl;
        return 0;
    }

    Ordenador ordenador = Ordenador();

    switch(ordenacao) {
        case 'b':
            ordenador.bubbleSort();
            break;
        case 's':
            ordenador.selectionSort();
            break;
        case 'i':
            ordenador.insertionSort();
            break;
        case 'q':
            ordenador.insertionSort();
            break;
        case 'm':
            ordenador.insertionSort();
            break;
        case 'p':
            ordenador.insertionSort();
            break;
        case 'y':
            ordenador.insertionSort();
            break;
        default:
            throw ("Entrada Inválida.");
    }
    
    
    return 0;
}
#include "ordenador.hpp"

void _swap(Lista *lista, int pos1, int pos2) {

    if (lista[pos1].getCor() == lista[pos2].getCor()){
        if (lista[pos1].getLabel() < lista[pos2].getLabel()) {
            return;
        }
    }

    Lista aux = Lista();
    aux = lista[pos1];
    lista[pos1] = lista[pos2];
    lista[pos2] = aux;

}

Ordenador::Ordenador() {};

void Ordenador::bubbleSort(Lista *vertices, int tamanho) {
    int realizouTroca;
    
    for ( int i = 0; i < tamanho - 1; i++ ) {
        realizouTroca = 0;
        for( int j = 0; j < tamanho - i - 1; j++ ) {
            if ( vertices[j].getCor() > vertices[ j + 1 ].getCor() ) {
                _swap(vertices, j, j + 1);
                realizouTroca = 1;
            }
        }
        if (!realizouTroca) break;
    }
};

void Ordenador::selectionSort(Lista *vertices, int tamanho) {
    int i, j, min;
    for( i = 0; i < tamanho -1; i++ ) {
        min = i;
        for (j = i + 1; j < tamanho; j++) {
            if ( vertices[j].getCor() < vertices[min].getCor() || 
            ( vertices[j].getCor() == vertices[min].getCor() && vertices[j].getLabel() < vertices[min].getLabel() )
            ) {
                min = j;
            }
        }
        
        Lista aux = vertices[min];
        for ( int k = min; k > i; k--) {
            vertices[k] = vertices[k - 1];
        }
        vertices[i] = aux;
    }
};

void Ordenador::insertionSort(Lista *vertices, int tamanho) {
    int i = 0, j = 0;
    Lista aux;
    for(i = 1; i < tamanho; i++) {
        aux = vertices[i];
        j = i - 1;

        while( aux.getCor() < vertices[j].getCor() && j >= 0) {
            vertices[j + 1] = vertices[j];
            j--;
        }
        vertices[j + 1] = aux;
    }
};

void Ordenador::mergeSort(Lista *vertices, int inicio, int fim) {
    if ( inicio < fim ) {
        int meio = inicio + (fim - inicio) / 2;
        mergeSort(vertices, inicio, meio);
        mergeSort(vertices, meio + 1, fim);
        merge(vertices, inicio, meio, fim);
    }
}

void Ordenador::merge(Lista *vertices, int esq, int meio, int dir) {
    int tam_esq = meio - esq + 1;
    int tam_dir = dir - meio;

    Lista *esquerdaArray = new Lista[tam_esq];
    Lista *direitaArray= new Lista[tam_dir];

    for (int i = 0; i < tam_esq; i++) {
        esquerdaArray[i] = vertices[esq + i];
    }
    for (int j = 0; j < tam_dir; j++) {
        direitaArray[j] = vertices[meio + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = esq;

    while (i < tam_esq && j < tam_dir) {
        if (esquerdaArray[i].getCor() <= direitaArray[j].getCor()) {
            vertices[k] = esquerdaArray[i];
            i++;
        } else {
            vertices[k] = direitaArray[j];
            j++;
        }
        k++;
    }

    while (i < tam_esq) {
        vertices[k] = esquerdaArray[i];
        i++;
        k++;
    }

    while (j < tam_dir) {
        vertices[k] = direitaArray[j];
        j++;
        k++;
    }

    delete[] esquerdaArray;
    delete[] direitaArray;
}


void Ordenador::heapSort(Lista *vertices, int tamanho) { 
    for (int i = tamanho / 2 - 1; i >= 0; i--)
        heapify(vertices, tamanho, i);
 
    for (int i = tamanho - 1; i > 0; i--) {
        _swap(vertices, 0, i);
        heapify(vertices, i, 0);
    }
};

void Ordenador::heapify(Lista *vertices, int tamanho, int i) {
    int maior = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < tamanho && vertices[left].getCor() > vertices[maior].getCor()){
        maior = left;
    }

    if(right < tamanho && vertices[right].getCor() > vertices[maior].getCor()){
        maior = right;
    }

    if (maior != i) {
        _swap(vertices, i, maior);
        heapify(vertices, tamanho, maior);
    }

}

void Ordenador::quickSort(Lista *vertices, int inicio, int fim) {
    if (inicio >= fim) return;

    int pivot = particao(vertices, inicio, fim);

    quickSort(vertices, inicio, pivot - 1);
    quickSort(vertices, pivot + 1, fim);
}

int Ordenador::particao(Lista *vertices, int inicio, int fim) {
    int i = inicio;

    for ( int j = inicio; j < fim; j++) {
        if (vertices[j].getCor() <= vertices[fim].getCor() ) {
            _swap(vertices, i++, j);
        }
    }
    _swap(vertices, i, fim);

    return i;
};

void Ordenador::mantemPosicoes(Lista *vertices, int tamanho) {
    for ( int i = 0; i < tamanho - 1; i++) {
        if (vertices[i].getLabel() > vertices[i+1].getLabel()) {
            if (vertices[i].getCor() == vertices[i+1].getCor()) {
                _swap(vertices, i, i + 1);
            }
        }
    }
};

void Ordenador::sort() {

};
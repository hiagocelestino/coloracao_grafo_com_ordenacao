#include "ordenador.hpp"

Ordenador::Ordenador() {};

void Ordenador::_swap(Lista *lista, int pos1, int pos2) {
    if (pos1 == pos2) {
        return;
    }

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
        _merge(vertices, inicio, meio, fim);
    }
}

void Ordenador::_merge(Lista *vertices, int esq, int meio, int dir) {
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
        _heapify(vertices, tamanho, i);
 
    for (int i = tamanho - 1; i > 0; i--) {
        _swap(vertices, 0, i);
        _heapify(vertices, i, 0);
    }
};

void Ordenador::_heapify(Lista *vertices, int tamanho, int indice) {
    int menor = indice;
    int esq = 2 * indice + 1;
    int dir = 2 * indice + 2;

    if(esq < tamanho) {
        if (vertices[esq].getCor() > vertices[menor].getCor()
            || (vertices[esq].getCor() == vertices[menor].getCor()
                && vertices[esq].getLabel() > vertices[menor].getLabel())
        ) {
            menor = esq;
        }
    }

    if (dir < tamanho) {
        if (vertices[dir].getCor() > vertices[menor].getCor()
        || (vertices[dir].getCor() == vertices[menor].getCor()
                && vertices[dir].getLabel() > vertices[menor].getLabel())
        ) {
            menor = dir;
        }
    }

    if (menor != indice) {
        _swap(vertices, menor, indice);
        _heapify(vertices, tamanho, menor);
    }
}

void Ordenador::quickSort(Lista *vertices, int inicio, int fim) {
    if (inicio >= fim) return;

    int pivot = _particao(vertices, inicio, fim);

    quickSort(vertices, inicio, pivot - 1);
    quickSort(vertices, pivot + 1, fim);
}

int Ordenador::_particao(Lista *vertices, int inicio, int fim) {
    int i = inicio;

    for ( int j = inicio; j < fim; j++) {
        if (vertices[j].getCor() < vertices[fim].getCor()
            || (vertices[j].getCor() == vertices[fim].getCor() 
                && vertices[j].getLabel() <= vertices[fim].getLabel())
        ) {
            _swap(vertices, i++, j);
        }
    }
    _swap(vertices, i, fim);

    return i;
};

void Ordenador::countingsort(Lista *vertices, int tamanho) {
    if (tamanho <= 1) {
        return;
    }

    int max_cor = vertices[0].getCor();
    for (int i = 1; i < tamanho; i++) {
        if (vertices[i].getCor() > max_cor) {
            max_cor = vertices[i].getCor();
        }
    }

    int contadores[max_cor + 1] = {0};

    for (int i = 0; i < tamanho; i++) {
        contadores[vertices[i].getCor()]++;
    }

    for (int i = 1; i <= max_cor; i++) {
        contadores[i] += contadores[i - 1];
    }

    Lista *temp = new Lista[tamanho];

    for (int i = tamanho - 1; i >= 0; i--) {
        int cor = vertices[i].getCor();
        temp[contadores[cor] - 1] = vertices[i];
        contadores[cor]--;
    }

    for (int i = 0; i < tamanho; i++) {
        vertices[i] = temp[i];
    }

    delete[] temp;
}

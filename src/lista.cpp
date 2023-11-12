#include "lista.hpp"

Lista::Lista() {

};

Lista::Lista(int numero_vertice) {
    tamanho = 0;
    inicio = nullptr;
    fim = nullptr;
};

int Lista::getTamanho() {
    return tamanho;
};

Celula* Lista::getInicio() {
    return inicio;
};

Celula* Lista::getFim() {
    return fim;
};

void Lista::adicionaItem(Celula *novo) {
    if(inicio == nullptr) {
        inicio = novo;
    } else {
        fim->setProximo(novo);
    }

    fim = novo;
    tamanho++;
};

int Lista::getCor() {
    return cor;
};

void Lista::setCor(int c) {
    cor = c;
};

void Lista::imprimir() {
    // Celula *valor = inicio;
    // while(valor != nullptr) {
    //     std::cout << valor->getConteudo() << std::endl;
    //     valor = valor->getProximo();
    // }

    std::cout << "Coloração: " << cor << std::endl;
}
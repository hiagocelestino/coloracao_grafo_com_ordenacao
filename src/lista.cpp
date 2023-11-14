#include "lista.hpp"

Lista::Lista() {

};

Lista::~Lista() {
    delete inicio;
    delete fim;
}

Lista::Lista(int labelVertice) {
    tamanho = 0;
    inicio = nullptr;
    fim = nullptr;
    label = labelVertice;
};

unsigned int Lista::getLabel() {
    return label;
}

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
    std::cout << "VIZINHO" << std::endl;
    Celula *valor = inicio;
    while(valor != nullptr) {
        std::cout << valor->getConteudo() << " ";
        valor = valor->getProximo();
    }
    std::cout << std::endl;

}
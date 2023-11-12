#include "celula.hpp"

Celula::Celula() {
    prox = nullptr;
};

Celula::~Celula() {

};

int Celula::getConteudo() {
    return conteudo;
};

void Celula::setConteudo(int valor) {
    conteudo = valor;
};

Celula* Celula::getProximo() {
    return prox;
};

void Celula::setProximo(Celula *proximo) {
    prox = proximo;
};
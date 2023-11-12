#ifndef CELULA_HPP
#define CELULA_HPP

#include <iostream>

class Celula {
    public:
        Celula();
        ~Celula();

        int getConteudo();
        void setConteudo(int valor);
        Celula *getProximo();
        void setProximo(Celula *proximo);
        int verificaColoracaoGulos();
    private:
        int conteudo;
        Celula *prox;
};

#endif
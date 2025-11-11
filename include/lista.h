#ifndef LISTA_ENCADEADA_H_INCLUDED
#define LISTA_ENCADEADA_H_INCLUDED

typedef enum{true = 1, false = 0}boolean;

typedef struct lista* Lista;

Lista criar_lista();

Lista insere(Lista, int);

Lista remover(Lista);

#endif // LISTA_ENCADEADA_H_INCLUDED


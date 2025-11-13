#ifndef LISTA_ENCADEADA_H_INCLUDED
#define LISTA_ENCADEADA_H_INCLUDED

#define TRANSL_VALOR 0.5f

typedef enum{true = 1, false = 0}bool;

typedef struct{
    int codigo;
    float valor_translacao;
}Reg;

typedef struct lista* Lista;

Lista criar_lista();

void liberar_lista(Lista);

Lista insere(Lista, Reg);

Lista remover(Lista);

#endif // LISTA_ENCADEADA_H_INCLUDED


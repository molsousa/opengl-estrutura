#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include "../include/lista.h"

struct lista{
    Reg info;
    struct lista* prox;
};

Lista criar_lista()
{
    return NULL;
}

void liberar_lista(Lista l)
{
    if(l == NULL)
        return;

    liberar_lista(l->prox);
    free(l);
}

Lista insere(Lista l, Reg info)
{
    if(l == NULL){
        Lista aux = malloc(sizeof(struct lista));

        glTranslatef(info.valor_translacao, 0, 0);

        aux->info = info;
        aux->prox = NULL;

        return aux;
    }

    l->prox = insere(l->prox, info);

    return l;
}

Lista remover(Lista l)
{
    Lista aux = l->prox;

    free(l);

    return aux;
}

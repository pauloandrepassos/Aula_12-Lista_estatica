#include "lista.h"
#include "stdio.h"
#include "stdlib.h"
#define MAX 5

struct lista{
    int qtd;
    struct numero dados[MAX];
};

Lista* cria_lista() {
    Lista *l;
    l = (Lista*) malloc(sizeof(struct lista));
    if(l == NULL){
        printf("MEMORIA INSUFICIENTE!");
        exit(1);
    }
    if(l != NULL)
        l->qtd = 0;
    return l;
}

void libera_lista(Lista* l) {
    free(l);
}

int tamanho_lista(Lista *l){
    if(l == NULL)
        return -1;
    else
        return l->qtd;
}

int lista_cheia(Lista *l) {
    if(l == NULL)
        return -1;
    return (l->qtd == MAX);
}

int lista_vazia(Lista *l) {
    if(l == NULL)
        return -1;
    return (l->qtd == 0);
}

int inserir_inicio(Lista *l, struct numero valor){
    if(l == NULL)
        return  0;
    if(lista_cheia(l)){
        printf("Lista Cheia!\n");
        return 0;
    }
    int i;
    for(i = l->qtd - 1; i >= 0; i--)
        l->dados[i + 1] = l->dados[i];
    l->dados[0] = valor;
    l->qtd++;
    return 1;
}

int inserir_meio(Lista *l, struct numero valor){
    /*if(l == NULL)
        return  0;
    if(lista_cheia(l))
        return 0;*/
}

int inserir_final(Lista *l, struct numero valor){
    if(l == NULL)
        return 0;
    if(lista_cheia(l)){
        printf("Lista Cheia!\n");
        return 0;
    }
    l->dados[l->qtd] = valor;
    l->qtd++;
    return 1;
}

int inserir_ordenado(Lista *l, struct numero valor){
    if(l == NULL)
        return 0;
    if(lista_cheia(l)) {
        printf("Lista Cheia!\n");
        return 0;
    }
    int i, j = 0;
    while(j < l->qtd && l->dados[j].num < valor.num)
        j++;
    for(i = l->qtd - 1; i >= j; i--)
        l->dados[i + 1] = l->dados[i];
    l->dados[j] = valor;
    l->qtd++;
}

int remover(Lista *l, int valor){
    if(l == NULL)
        return 0;
    if(lista_vazia(l)) {
        printf("Lista vazia!\n");
        return 0;
    }
    int i, j = 0;
    while(j < l->qtd && l->dados[j].num != valor)
        j++;
    if(j == l->qtd) {
        printf("Numero nao encontrado!\n");
        return 0;
    }
    for (i = j; i < l->qtd - 1; i++) {
        l->dados[i] = l->dados[i + 1];
    }
    l->qtd--;
    return 1;
}
int remover_inicio(Lista *l){
    if(l == NULL)
        return 0;
    if(lista_vazia(l)) {
        printf("Lista vazia!\n");
        return 0;
    }
    int i = 0;
    for (i = 0; i < l->qtd - 1; i++)
        l->dados[i] = l->dados[i + 1];
    l->qtd--;
    return 1;
}
int remover_fim(Lista *l){
    if(l == NULL)
        return 0;
    if(lista_vazia(l)) {
        printf("Lista vazia!\n");
        return 0;
    }
    l->qtd--;
    return 1;
}

int imprime(Lista *l) {
    if(lista_vazia(l)) {
        printf("Lista vazia!\n");
        return 0;
    }
    int i;
    for(i = 0; i < l->qtd; i ++){
        printf("%d ", l->dados[i].num);
    }
    printf("\n");
    return 1;
}


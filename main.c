#include "stdio.h"
#include "lista.h"
int imprimir_opcoes() {
    printf("\n"
           "1 - Imprimir lista\n"
           "2 - Inserir numero no inicio da lista\n"
           "3 - Inserir numero no final da lista (append)\n"
           "4 - Inserir numero em posicao x (insert)\n"
           "5 - Remover numero (remove)\n"
           "6 - Remover primeiro numero da lista\n"
           "7 - Remover ultimo numero da lista\n"
           "8 - Remover todos os numeros (clear)\n"
           "0 - Encerrar programa\n"
           "\nDigite:");
    return 1;
}

int main() {
    Lista *l;
    l = cria_lista();
    struct numero valor;
    int opcao = 1;
    while(opcao != 0) {
        imprimir_opcoes();
        scanf(" %d", &opcao);
        if(opcao == 1) {
            imprime(l);
        }
        else if (opcao == 2) {
            if (lista_cheia(l)) {
                printf("Lista cheia!\n");
            }
            else {
                printf("Digite o numero que deseja adicionar:");
                scanf(" %d", &valor);
                inserir_inicio(l, valor);
            }
        }
        else if (opcao == 3) {
            if(lista_cheia(l)) {
                printf("Lista cheia!\n");
            }
            else {
                printf("Digite o numero que deseja adicionar:");
                scanf(" %d", &valor);
                append(l, valor);
            }
        }
        else if (opcao == 4) {
            if (lista_cheia(l)) {
                printf("Lista cheia!\n");
            }
            else {
                printf("Digite o numero que deseja adicionar:");
                scanf(" %d", &valor);
                int pos;
                printf("Posicao:");
                scanf(" %d", &pos);
                insert(l, valor, pos);
            }
        }
        else if (opcao == 5) {
            if(lista_vazia(l)) {
                printf("Lista vazia!\n");
            }
            else {
                printf("Digite o numero que deseja remover:");
                scanf(" %d", &valor.num);
                remover(l, valor.num);
            }
        }
        else if (opcao == 6) {
            remover_inicio(l);
        }
        else if (opcao == 7) {
            remover_fim(l);
        }
        else if (opcao == 8) {
            clear(l);
        }

    }

    return  1;

}
/*
int main() {
    Lista *l;
    l = cria_lista();
    struct numero valor;

    valor.num = 10;
    append(l, valor);

    valor.num = 12;
    append(l, valor);

    valor.num = 15;
    append(l, valor);

    valor.num = 8;
    insert(l, valor, 1);

    clear(l);

    imprime(l);
    return 1;
}*/
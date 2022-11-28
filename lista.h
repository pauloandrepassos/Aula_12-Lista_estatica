struct numero{
    int num;
};
typedef struct lista Lista;

Lista* cria_lista();
void libera_lista(Lista* l);

int tamanho_lista(Lista* l);
int lista_cheia(Lista *l);
int lista_vazia(Lista *l);

int inserir_inicio(Lista *l, struct numero valor);
int inserir_meio(Lista *l, struct numero valor);
int inserir_final(Lista *l, struct numero valor);
int inserir_ordenado(Lista *l, struct numero valor);

int remover(Lista *l, int valor);
int remover_inicio(Lista *l);
int remover_fim(Lista *l);

int imprime(Lista *l);


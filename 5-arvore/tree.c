#include <stdio.h>
#include <stdlib.h>

typedef struct arvoreBinaria {
    int elem;
    struct arvoreBinaria *dir, *esq;
} arvoreBinaria;

arvoreBinaria* insere(arvoreBinaria *a, int vetor[], int inicio, int fim);
arvoreBinaria* remover(arvoreBinaria *a, int el);
void preOrdem(arvoreBinaria *a);
void emOrdem(arvoreBinaria *a);
void posOrdem(arvoreBinaria *a);

int main() {
    arvoreBinaria *raiz = NULL;
    int vetor[10] = {50, 30, 70, 20, 40, 60, 80, 10, 35, 75};
    raiz = insere(raiz, vetor, 0, 9);

    int x;
    char op;
    do {
        fflush(stdin);
        printf("\n1 - Excluir\n2 - Pre-Ordem\n3 - Em-Ordem\n4 - Pos-Ordem\n5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf(" %c", &op);

        switch (op) {
            case '1':
                if (raiz != NULL) {
                    printf("\nDigite um valor para remover: ");
                    scanf("%d", &x);
                    raiz = remover(raiz, x);
                } else {
                    printf("\nArvore vazia.\n");
                }
                break;
            case '2':
                preOrdem(raiz);
                break;
            case '3':
                emOrdem(raiz);
                break;
            case '4':
                posOrdem(raiz);
                break;
            case '5':
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }

    } while (op != '5');

    return 0;
}

arvoreBinaria* insere(arvoreBinaria *a, int vetor[], int inicio, int fim) {
    if (inicio > fim) return a;

    int meio = (inicio + fim) / 2; // Escolhe o elemento do meio para balancear a árvore
    a = (arvoreBinaria*) malloc(sizeof(arvoreBinaria));
    a->elem = vetor[meio];
    a->esq = insere(a->esq, vetor, inicio, meio - 1);
    a->dir = insere(a->dir, vetor, meio + 1, fim);

    return a;
}

arvoreBinaria* remover(arvoreBinaria *a, int el) {
    if (a == NULL) {
        printf("Elemento nao encontrado.\n");
        return NULL;
    }

    arvoreBinaria *p, *p2;
    if (a->elem == el) {
        if (a->esq == NULL && a->dir == NULL) { // É uma folha
            free(a);
            return NULL;
        } else if (a->esq == NULL) { // Tem apenas filho à direita
            p = a->dir;
            free(a);
            return p;
        } else if (a->dir == NULL) { // Tem apenas filho à esquerda
            p = a->esq;
            free(a);
            return p;
        } else { // Tem dois filhos
            p2 = a->dir;
            p = a->dir;
            while (p->esq != NULL) p = p->esq;
            p->esq = a->esq;
            free(a);
            return p2;
        }
    }

    if (a->elem < el) {
        a->dir = remover(a->dir, el);
    } else {
        a->esq = remover(a->esq, el);
    }

    return a;
}

void preOrdem(arvoreBinaria *a) {
    if (a != NULL) {
        printf("%d ", a->elem);
        preOrdem(a->esq);
        preOrdem(a->dir);
    }
}

void emOrdem(arvoreBinaria *a) {
    if (a != NULL) {
        emOrdem(a->esq);
        printf("%d ", a->elem);
        emOrdem(a->dir);
    }
}

void posOrdem(arvoreBinaria *a) {
    if (a != NULL) {
        posOrdem(a->esq);
        posOrdem(a->dir);
        printf("%d ", a->elem);
    }
}

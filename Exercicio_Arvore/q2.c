#include <stdio.h>
#include <stdlib.h>

// Árvore Binária de Busca

// CRIACAO DO NO
typedef struct no { // estrutura no
    struct no *left; // esquerda(valores menores) 
    struct no *right; // direita(valores maiores)
    int info;
}No;

// FUNCAO PARA INSERIR VALORES
No* inserir(int data) {
    No*aux = (No*) malloc(sizeof(No)); // aloca memoria para o No
    aux->info = data; // campo valor recebe o numero que quero inserir
    aux->left = aux->right = NULL; // se recebe acima entao atribui NULL para esquerda e direita
    return aux; // retorna ponteiro para o No
}

No* insert(No *raiz, int info) {
    if (raiz == NULL) { // se a raiz for null então entra na condicao
        raiz = inserir(info);
    }else if (info < raiz->info){ // se nao, insere a esquerda
        raiz->left = insert(raiz->left, info);
    }else if (info > raiz->info){ // se nao, insere a direita
        raiz->right = insert(raiz->right, info);
    }
    return raiz; // retorna a raiz
}

char ans[1000000];
int curPos = 0;

void prefixa(No *raiz) {
    if (raiz != NULL) {
        curPos += sprintf(ans + curPos, " %d", raiz->info);
        prefixa(raiz->left);
        prefixa(raiz->right);
    }
}

void infixa(No *raiz) {
    if (raiz != NULL) {
        infixa(raiz->left);
        curPos += sprintf(ans + curPos, " %d", raiz->info);
        infixa(raiz->right);
    }
}

void posfixa(No *raiz) {
    if (raiz != NULL) {
        posfixa(raiz->left);
        posfixa(raiz->right);
        curPos += sprintf(ans + curPos, " %d", raiz->info);
    }
}
// FUNCAO PRINCIPAL
int main() {
    int C, N, v, i, c;
    No *raiz = NULL;
    scanf("%d", &C);
    for (c = 1; c <= C; c++) {
        raiz = NULL;
        curPos = 0;
        scanf("%d", &N);
        for (i = 0; i < N; i++) {
            scanf("%d", &v);
            raiz = insert(raiz, v);
        }
        //printf("\n");
        printf("Case %d:\n", c);
        printf("Pre.:");
        prefixa(raiz);
        printf("%s\n", ans);
        curPos = 0;
        printf("In..:");
        infixa(raiz);
        printf("%s\n", ans);
        curPos = 0;
        printf("Post:");
        posfixa(raiz);
        printf("%s\n\n", ans);
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Percurso em Árvore por Nível

typedef struct no {
    struct no *left;
    struct no *right;
    int info;
}No;

No* Criar_No(int value) {
    No *aux = (No*)malloc(sizeof(No));
    aux->info = value;
    aux->left = NULL;
    aux->right = NULL;
    return aux;
}

No* insert(No *arv, int value) {
    if (arv == NULL) {
        return Criar_No(value);
    }
    if (value < arv->info) {
        arv->left = insert(arv->left, value);
    } else if (value > arv->info) {
        arv->right = insert(arv->right, value);
    }
    return arv;
}

void nivel(No *arv, int level) {
    if (arv == NULL) {
        return;
    }
    if (level == 1) {
        printf("%d ", arv->info);
    } else if (level > 1) {
        nivel(arv->left, level-1);
        nivel(arv->right, level-1);
    }
}

int height(No *arv) {
    if (arv == NULL) {
        return 0;
    }
    int left_height = height(arv->left);
    int right_height = height(arv->right);
    if (left_height > right_height) {
        return left_height + 1;
    }
    return right_height + 1;
}

void ordemNivel(No *arv) {
    int h = height(arv);
    if (h > 500) {
        return;
    }
    for (int i = 1; i <= h; i++) {
        nivel(arv, i);
    }
}

void destruir(No *arv) {
    if (arv == NULL) {
        return;
    }
    destruir(arv->left);
    destruir(arv->right);
    free(arv);
}

No* isercaoUnica(No *arv, int value) {
    if (arv == NULL) {
        return Criar_No(value);
    }
    if (value < arv->info) {
        arv->left = isercaoUnica(arv->left, value);
    } else if (value > arv->info) {
        arv->right = isercaoUnica(arv->right, value);
    }
    return arv;
}

No* fazerArv(int *values, int n) {
    No *arv = NULL;
    for (int i = 0; i < n; i++) {
        arv = isercaoUnica(arv, values[i]);
    }
    return arv;
}

int main() {
    int C;

    scanf("%d", &C);
    
    if(C<=1000){
        for(int i=1; i<=C; i++){
            int N;
            scanf("%d", &N);
            if(N >=1 && N <=500){
                int values[N];
                for (int j = 0; j < N; j++) {
                    int value;
                    scanf("%d", &value);
                    if(value>=0){
                        values[j] = value;
                    }
                }
                No *arv = fazerArv(values, N);
                printf("Case %d:\n", i);
                ordemNivel(arv);
                if (i < C) printf("\n\n");
                destruir(arv);
            }
        }         
    }
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Prefixa, Infixa e Posfixa*/

#define MAXSIZE 1000 //definindo tamanho dos vetores de infixo, prefixo e a minha saisa

typedef struct no{
    char valor;
    struct no* esquerda;
    struct no* direita;
}No;

No *NovoNo(char valor){ // criando novo no
	No *raiz = (No*)malloc(sizeof(No));
    raiz->valor = valor;
    raiz->esquerda = raiz->direita = NULL;
    //printf("%s", raiz);
	return raiz;
}

No *CriarArvore(char *prefixo, char *infixo, int n){

    char valorraiz = prefixo[0];
    int raizinicial, i;

	if(n == 0) return NULL;

    for(i=0; i<n; i++){
        if(infixo[i] == valorraiz){
            raizinicial=i;
            break;
        }
    }
    No *raiz = NovoNo(valorraiz);
    raiz->esquerda = CriarArvore(prefixo+1, infixo, raizinicial);
    raiz->direita = CriarArvore(prefixo+raizinicial+1, infixo+raizinicial+1, n-raizinicial-1);
	//printf("%s\n", raiz);
    return raiz;
}

void posfixo(No *raiz, char *saida, int *inicio){

    if(raiz != NULL){	
		posfixo(raiz->esquerda, saida, inicio);
		posfixo(raiz->direita, saida, inicio);
		
		saida[*inicio] = raiz->valor;
        //printf("%s", saida);
		(*inicio)++;
        printf("%c", raiz->valor);
    }
}

int main(){
    int casos, i, j;

    scanf("%d", &casos);
    
	if(casos>2000) return 0;
    for(i=1; i<=casos; i++){
        char prefixo[MAXSIZE], infixo[MAXSIZE], saida[MAXSIZE];
        int inicio=0, n;
        
        scanf("%d %s %s", &n, prefixo, infixo);
		No *raiz = CriarArvore(prefixo, infixo, n);
		posfixo(raiz, saida, &inicio);
        printf("\n", saida);
    }
    return 0;
}
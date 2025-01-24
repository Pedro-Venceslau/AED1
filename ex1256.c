#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->proximo = NULL;
    return novoNo;
}

void inserir(No** cabeca, int valor) {
    No* novoNo = criarNo(valor);
    if (*cabeca == NULL) {
        *cabeca = novoNo;
    } else {
        No* atual = *cabeca;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoNo;
    }
}

void imprimirTabelaHash(No** tabelaHash, int m) {
    for (int i = 0; i < m; i++) {
        printf("%d ->", i);
        No* atual = tabelaHash[i];
        while (atual != NULL) {
            printf(" %d ->", atual->valor);
            atual = atual->proximo;
        }
        printf(" \\\n");
    }
}

void liberarTabelaHash(No** tabelaHash, int m) {
    for (int i = 0; i < m; i++) {
        No* atual = tabelaHash[i];
        while (atual != NULL) {
            No* temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }
}

int main() {
    int t;
    scanf("%d", &t); 

    while (t--) {
        int m, c;
        scanf("%d %d", &m, &c); 

      No* tabelaHash[m];
        for (int i = 0; i < m; i++) {
            tabelaHash[i] = NULL;
        }

        for (int i = 0; i < c; i++) {
            int chave;
            scanf("%d", &chave);
            int indice = chave % m;
            inserir(&tabelaHash[indice], chave);
        }

        imprimirTabelaHash(tabelaHash, m);

        if (t > 0) {
            printf("\n");
        }

        liberarTabelaHash(tabelaHash, m);
    }

    return 0;
}

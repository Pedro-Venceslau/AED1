#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int busca_binaria(int *arr, int tamanho, int alvo) {
    int esquerda = 0, direita = tamanho - 1, meio, resultado = -1;
    while (esquerda <= direita) {
        meio = (esquerda + direita) / 2;
        if (arr[meio] == alvo) {
            resultado = meio;
            direita = meio - 1; 
        } else if (arr[meio] < alvo) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    return resultado;
}

int main() {
    int N, Q, caso = 1;
    while (scanf("%d %d", &N, &Q) && (N != 0 || Q != 0)) {
        int marmores[N], consultas[Q];
        
        for (int i = 0; i < N; i++) {
            scanf("%d", &marmores[i]);
        }
        
        qsort(marmores, N, sizeof(int), comparar);
        
        for (int i = 0; i < Q; i++) {
            scanf("%d", &consultas[i]);
        }
        
        printf("CASE# %d:\n", caso++);
        
        for (int i = 0; i < Q; i++) {
            int posicao = busca_binaria(marmores, N, consultas[i]);
            if (posicao != -1) {
                printf("%d found at %d\n", consultas[i], posicao + 1);
            } else {
                printf("%d not found\n", consultas[i]);
            }
        }
    }
    return 0;
}

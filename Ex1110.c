#include <stdio.h>
#include <stdlib.h>


typedef struct No {
    int valor;
    struct No* prox;
} No;

typedef struct Fila {
    No* frente;
    No* tras;
} Fila;

Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->frente = NULL;
    fila->tras = NULL;
    return fila;
}

int estaVazia(Fila* fila) {
    return fila->frente == NULL;
}

void enfileirar(Fila* fila, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->prox = NULL;
    if (estaVazia(fila)) {
        fila->frente = novoNo;
        fila->tras = novoNo;
    } else {
        fila->tras->prox = novoNo;
        fila->tras = novoNo;
    }
}

int desenfileirar(Fila* fila) {
    if (estaVazia(fila)) {
        return -1; 
    }
    No* temp = fila->frente;
    int valor = temp->valor;
    fila->frente = fila->frente->prox;
    if (fila->frente == NULL) {
        fila->tras = NULL;
    }
    free(temp);
    return valor;
}

void liberarFila(Fila* fila) {
    while (!estaVazia(fila)) {
        desenfileirar(fila);
    }
    free(fila);
}

int main() {
    int n;

    while (1) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }

        Fila* fila = criarFila();
        for (int i = 1; i <= n; i++) {
            enfileirar(fila, i);
        }

        printf("Cartas descartadas: ");
        int primeiro = 1;
        while (fila->frente != fila->tras) {
            if (!primeiro) {
                printf(", ");
            }
            printf("%d", desenfileirar(fila));
            primeiro = 0;

            enfileirar(fila, desenfileirar(fila));
        }

        printf("\nCarta restante: %d\n", desenfileirar(fila));

        liberarFila(fila);
    }

    return 0;
}

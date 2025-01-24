#include <stdio.h>
#include <stdlib.h>


typedef struct No {
    int valor;
    struct No* prox;
} No;

// Estrutura da fila
typedef struct Fila {
    No* frente;
    No* tras;
} Fila;

// Inicializa a fila
Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->frente = NULL;
    fila->tras = NULL;
    return fila;
}

// Verifica se a fila está vazia
int estaVazia(Fila* fila) {
    return fila->frente == NULL;
}

// Manda para o fim da fila
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

// Remove do topo
int desenfileirar(Fila* fila) {
    if (estaVazia(fila)) {
        return -1; // Indica que a fila está vazia
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

// Libera a memória da fila
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

        // Cria a fila e enfileira as cartas
        Fila* fila = criarFila();
        for (int i = 1; i <= n; i++) {
            enfileirar(fila, i);
        }

        // Processa as cartas
        printf("Cartas descartadas: ");
        int primeiro = 1;
        while (fila->frente != fila->tras) {
            // Remove a carta do topo
            if (!primeiro) {
                printf(", ");
            }
            printf("%d", desenfileirar(fila));
            primeiro = 0;

            // Move a próxima carta para a base
            enfileirar(fila, desenfileirar(fila));
        }

        // Imprime a carta restante
        printf("\nCarta restante: %d\n", desenfileirar(fila));

        // Libera a memória da fila
        liberarFila(fila);
    }

    return 0;
}

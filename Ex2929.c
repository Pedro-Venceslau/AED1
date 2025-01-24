#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000000 // Limite máximo de operações

typedef struct {
    long long valor;
    long long minimo; 
} Presente;

typedef struct {
    Presente pilha[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int vazia(Pilha *p) {
    return p->topo == -1;
}

void push(Pilha *p, long long valor) {
    if (p->topo < MAX - 1) {
        p->topo++;
        p->pilha[p->topo].valor = valor;
        if (p->topo == 0) {
            p->pilha[p->topo].minimo = valor;
        } else {
            // Atualiza o menor valor
            p->pilha[p->topo].minimo = (valor < p->pilha[p->topo - 1].minimo) ? valor : p->pilha[p->topo - 1].minimo;
        }
    }
}

void pop(Pilha *p) {
    if (!vazia(p)) {
        p->topo--;
    }
}

long long min(Pilha *p) {
    if (!vazia(p)) {
        return p->pilha[p->topo].minimo;
    }
    return -1;
}

int main() {
    int n;
    char operacao[10];
    long long valor;

    Pilha pilha;
    inicializar(&pilha);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", operacao);

        if (strcmp(operacao, "PUSH") == 0) {
            scanf("%lld", &valor);
            push(&pilha, valor);
        } else if (strcmp(operacao, "POP") == 0) {
            if (vazia(&pilha)) {
                printf("EMPTY\n");
            } else {
                pop(&pilha);
            }
        } else if (strcmp(operacao, "MIN") == 0) {
            if (vazia(&pilha)) {
                printf("EMPTY\n");
            } else {
                printf("%lld\n", min(&pilha));
            }
        }
    }

    return 0;
}

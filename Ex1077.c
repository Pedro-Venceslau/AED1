#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 300 
typedef struct {
    char itens[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *pilha) {
    pilha->topo = -1;
}

int vazia(Pilha *pilha) {
    return pilha->topo == -1;
}

void empilhar(Pilha *pilha, char elemento) {
    if (pilha->topo < MAX - 1) {
        pilha->itens[++(pilha->topo)] = elemento;
    }
}

char desempilhar(Pilha *pilha) {
    if (!vazia(pilha)) {
        return pilha->itens[(pilha->topo)--];
    }
    return '\0';
}

char topo(Pilha *pilha) {
    if (!vazia(pilha)) {
        return pilha->itens[pilha->topo];
    }
    return '\0';
}

int precedencia(char operador) {
    switch (operador) {
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}

int operador(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

void infixa_para_posfixa(char *infixa, char *posfixa) {
    Pilha pilha;
    inicializar(&pilha);
    int i, j = 0;
    char c;

    for (i = 0; infixa[i] != '\0'; i++) {
        c = infixa[i];

        if (isalnum(c)) { 
            posfixa[j++] = c;
        } else if (c == '(') { 
            empilhar(&pilha, c);
        } else if (c == ')') { 
            while (!vazia(&pilha) && topo(&pilha) != '(') {
                posfixa[j++] = desempilhar(&pilha);
            }
            desempilhar(&pilha); 
        } else if (operador(c)) { 
            while (!vazia(&pilha) && precedencia(topo(&pilha)) >= precedencia(c)) {
                posfixa[j++] = desempilhar(&pilha);
            }
            empilhar(&pilha, c);
        }
    }

    while (!vazia(&pilha)) {
        posfixa[j++] = desempilhar(&pilha);
    }

    posfixa[j] = '\0'; 
}

int main() {
    int n, i;
    char infixa[MAX], posfixa[MAX];

    scanf("%d\n", &n);

    for (i = 0; i < n; i++) {
        fgets(infixa, sizeof(infixa), stdin);
        infixa[strcspn(infixa, "\n")] = '\0'; 
        infixa_para_posfixa(infixa, posfixa);
        printf("%s\n", posfixa);
    }

    return 0;
}

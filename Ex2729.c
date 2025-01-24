#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comparar(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

void processar_lista(char *linha) {
    char *itens[1000]; 
    int contador = 0;

    char *token = strtok(linha, " ");
    while (token != NULL) {
        itens[contador++] = token;
        token = strtok(NULL, " ");
    }
    qsort(itens, contador, sizeof(char *), comparar);

    printf("%s", itens[0]);
    for (int i = 1; i < contador; i++) {
        if (strcmp(itens[i], itens[i - 1]) != 0) {
            printf(" %s", itens[i]);
        }
    }
    printf("\n");
}

int main() {
    int n;
    char linha[1001];

    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        fgets(linha, sizeof(linha), stdin);
        linha[strcspn(linha, "\n")] = '\0'; 
        processar_lista(linha); 
    }

    return 0;
}

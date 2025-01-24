#include <stdio.h>
#include <string.h>

int contar_diamantes(char *linha) {
    int diamantes = 0;
    int i, j;
    int tamanho = strlen(linha);

    for (i = 0; i < tamanho; i++) {
        if (linha[i] == '<') {
            for (j = i + 1; j < tamanho; j++) {
                if (linha[j] == '>') {
                    diamantes++;
                    linha[j] = '.';
                    break;
                }
            }
        }
    }

    return diamantes;
}

int main() {
    int n, i;
    char linha[1001]; // Até 1000 caracteres por caso de teste

    scanf("%d", &n); // Lê o número de casos de teste

    for (i = 0; i < n; i++) {
        scanf("%s", linha); // Lê cada linha de entrada
        printf("%d\n", contar_diamantes(linha)); // Imprime o número de diamantes
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int n, m, i, j;

    scanf("%d", &n);

    while (n--) {
        scanf("%d", &m);

        int notas[m], ordenadas[m];
        int nao_trocados = 0;

        for (i = 0; i < m; i++) {
            scanf("%d", &notas[i]);
            ordenadas[i] = notas[i];
        }

        qsort(ordenadas, m, sizeof(int), comparar);

        for (i = 0; i < m; i++) {
            if (notas[i] == ordenadas[i]) {
                nao_trocados++;
            }
        }

        printf("%d\n", nao_trocados);
    }

    return 0;
}

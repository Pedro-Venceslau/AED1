#include <stdio.h>
#include <string.h>

#define MAX 1000 // Definir tamanho máximo para a lista de amigos

int main() {
    char listaAtual[MAX], novaLista[MAX], amigoIndicado[51];
    char resultado[MAX] = ""; 

    fgets(listaAtual, MAX, stdin);
    fgets(novaLista, MAX, stdin);
    fgets(amigoIndicado, 51, stdin);

  listaAtual[strcspn(listaAtual, "\n")] = '\0';
    novaLista[strcspn(novaLista, "\n")] = '\0';
    amigoIndicado[strcspn(amigoIndicado, "\n")] = '\0';

    if (strcmp(amigoIndicado, "nao") == 0) {
        snprintf(resultado, MAX, "%s %s", listaAtual, novaLista);
    } else {
        char *pos = strstr(listaAtual, amigoIndicado);
        if (pos != NULL) {
            int offset = pos - listaAtual; 
            strncpy(resultado, listaAtual, offset);
            resultado[offset] = '\0'; 

          snprintf(resultado + offset, MAX - offset, "%s %s", novaLista, listaAtual + offset);
        } else {
            snprintf(resultado, MAX, "%s %s", listaAtual, novaLista);
        }
    }

    printf("%s\n", resultado);

    return 0;
}

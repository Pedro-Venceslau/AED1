#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 50
#define MAX_LENGTH 51

typedef struct {
    char str[MAX_LENGTH];
    int indice_original;
} InformacaoString;

int comparar(const void *a, const void *b) {
    InformacaoString *str1 = (InformacaoString *)a;
    InformacaoString *str2 = (InformacaoString *)b;
    int tamanho1 = strlen(str1->str);
    int tamanho2 = strlen(str2->str);
    
    if (tamanho1 != tamanho2) {
        return tamanho1 - tamanho2; 
    }
    return str1->indice_original - str2->indice_original; 
}

int main() {
    int N;
    scanf("%d", &N);
    getchar(); 
    
    while (N--) {
        InformacaoString strings[MAX_STRINGS];
        int contador = 0;
        
        char linha[MAX_STRINGS * (MAX_LENGTH + 1)];
        fgets(linha, sizeof(linha), stdin);
        
        char *token = strtok(linha, " \n");
        while (token != NULL) {
            strcpy(strings[contador].str, token);
            strings[contador].indice_original = contador;
            contador++;
            token = strtok(NULL, " \n");
        }
        
        qsort(strings, contador, sizeof(InformacaoString), comparar);
        
        for (int i = 0; i < contador; i++) {
            if (i > 0) printf(" ");
            printf("%s", strings[i].str);
        }
        printf("\n");
    }
    
    return 0;
}

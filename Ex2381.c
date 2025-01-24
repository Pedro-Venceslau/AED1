#include <stdio.h>
#include <string.h>

void BubbleSort(char vet[][21], int n){
    char temp[21];
    for(int i=0; i<n-1; i++){ 
        for(int j=0; j< n -i -1; j++){ 
            if (strcmp(vet[j], vet[j+1]) > 0){
                strcpy(temp, vet[j]);
                strcpy(vet[j], vet[j+1]);
                strcpy(vet[j+1], temp);
            }
        }
    }
}

int main(){
    int qtd, sorteio;

    scanf("%d %d", &qtd, &sorteio);
    
    char alunos[qtd][21]; 

    for(int i = 0; i < qtd; i++){
        scanf("%s", alunos[i]);
    }
    
    BubbleSort(alunos, qtd);
    
    printf("%s\n", alunos[sorteio - 1]);

    return 0;
}

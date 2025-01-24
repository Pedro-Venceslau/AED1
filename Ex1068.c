#include <stdio.h>
#include <string.h>

typedef struct no{
    char dado;
    struct no *seg;
} No;

No *topo = NULL; 

void PUSH (char caract){ 
    No *novo = malloc(sizeof(No));
    novo->dado = caract;
    novo->seg = topo;
    topo = novo;
}

void POP(){
    if(topo == NULL){
        return;
    }
    No *temp = topo;
    topo = topo->seg;
    free(temp);
}
void Verific_Parentese(char expr[]){
  
    int tam = strlen(expr);

    for(int i=0; i<tam; i++){
        if(expr[i] == '('){ 
            PUSH(expr[i]);
        } else if (expr[i] == ')') {  
            if (topo == NULL) {
                printf("incorrect\n");
                return;
            }
            POP(); 
        }
    }

    if (topo == NULL) {
        printf("correct\n");
    } else {
        printf("incorrect\n");
    }

}

int main(){
    int qtd_exp;
    char expr[1000];
    scanf("%d", &qtd_exp);
    getchar(); 

    for(int i=1; i<=qtd_exp; i++){
        fgets(expr, 1000, stdin);
        Verific_Parentese(expr);
    }

    return 0;
}

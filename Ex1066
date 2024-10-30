#include <stdio.h>
 
int main() {
    int num, cont_imp=0, cont_par=0, cont_pos=0, cont_neg=0;
    
    for(int i=1; i<=5; i++){
        scanf("%d", &num);
        if(num > 0)
            cont_pos++;
        if(num < 0)
            cont_neg++;
        if(num % 2 == 0)
            cont_par++;
        if(num % 2 != 0)
            cont_imp++;
    }
    
    printf("%d valor(es) par(es)\n", cont_par);
    printf("%d valor(es) impar(es)\n", cont_imp);
    printf("%d valor(es) positivo(s)\n", cont_pos);
    printf("%d valor(es) negativo(s)\n", cont_neg);

    return 0;
}

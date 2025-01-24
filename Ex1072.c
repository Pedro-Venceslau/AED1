#include <stdio.h>
 
int main() {
    int qtd, num, in=0, out=0;
    
    scanf("%d", &qtd);
    
    for(int i=1; i<=qtd; i++){
        scanf("%d", &num);
        if((num >= 10) && (num <= 20)){
            in++;
        }else{
            out++;
        }
    }
    
    printf("%d in\n", in);
    printf("%d out\n", out);

    return 0;
}

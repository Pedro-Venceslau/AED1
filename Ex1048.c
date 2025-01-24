#include <stdio.h>
 
int main() {
    float sal, perc, novo_sal;
    
    scanf("%f", &sal);
    
    if((sal >= 0) && (sal <= 400.00)){
        perc = 1.15;
        novo_sal = sal * perc;
        printf("Novo salario: %.2f\n", novo_sal);
        printf("Reajuste ganho: %.2f\n", novo_sal-sal);
        printf("Em percentual: 15 %\n");
    }else if((sal >= 400.01) && (sal <= 800.00)){
        perc = 1.12;
        novo_sal = sal * perc;
        printf("Novo salario: %.2f\n", novo_sal);
        printf("Reajuste ganho: %.2f\n", novo_sal-sal);
        printf("Em percentual: 12 %\n");
    }else if((sal >= 800.01) && (sal <= 1200.00)){
        perc = 1.1;
        novo_sal = sal * perc;
        printf("Novo salario: %.2f\n", novo_sal);
        printf("Reajuste ganho: %.2f\n", novo_sal-sal);
        printf("Em percentual: 10 %\n");
    }else if((sal >= 1200.01) && (sal <= 2000.00)){
        perc = 1.07;
        novo_sal = sal * perc;
        printf("Novo salario: %.2f\n", novo_sal);
        printf("Reajuste ganho: %.2f\n", novo_sal-sal);
        printf("Em percentual: 7 %\n");
    }else if(sal >= 2000){
        perc = 1.04;
        novo_sal = sal * perc;
        printf("Novo salario: %.2f\n", novo_sal);
        printf("Reajuste ganho: %.2f\n", novo_sal-sal);
        printf("Em percentual: 4 %\n");
    }
    return 0;
}

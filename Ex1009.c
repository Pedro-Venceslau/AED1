#include <stdio.h>
 
int main() {
    char nome[10];
    double sal, mon, com, tot;
    
    scanf("%s", &nome);
    scanf("%lf%lf", &sal, &mon);
    
    com = (0.15 * mon);
    tot = (com + sal);
    printf("TOTAL = R$ %.2lf\n", tot);
    return 0;
}

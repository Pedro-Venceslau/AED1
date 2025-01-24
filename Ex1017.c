#include <stdio.h>
 
int main() {
int V, T;
float DISTANCIA, LITROS;

scanf("%d", &V);
scanf("%d", &T);

DISTANCIA= V*T;
LITROS= DISTANCIA/12;

printf("%.3f\n", LITROS);
    return 0;
}

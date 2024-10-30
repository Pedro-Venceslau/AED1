#include <stdio.h>

int main() {
    float valor;
    int parte_inteira, parte_centavos;
    int notas100, notas50, notas20, notas10, notas5, notas2;
    int moedas1, moedas50, moedas25, moedas10, moedas5, moedas01;
    
    scanf("%f", &valor);
    
    parte_inteira = (int)valor;
    parte_centavos = (valor - parte_inteira) * 100 + 0.5;  // Ajuste para arredondamento correto
    
    // Cálculo das notas
    notas100 = parte_inteira / 100;
    parte_inteira %= 100;
    notas50 = parte_inteira / 50;
    parte_inteira %= 50;
    notas20 = parte_inteira / 20;
    parte_inteira %= 20;
    notas10 = parte_inteira / 10;
    parte_inteira %= 10;
    notas5 = parte_inteira / 5;
    parte_inteira %= 5;
    notas2 = parte_inteira / 2;
    parte_inteira %= 2;

    // Cálculo das moedas
    moedas1 = parte_inteira;
    moedas50 = parte_centavos / 50;
    parte_centavos %= 50;
    moedas25 = parte_centavos / 25;
    parte_centavos %= 25;
    moedas10 = parte_centavos / 10;
    parte_centavos %= 10;
    moedas5 = parte_centavos / 5;
    moedas01 = parte_centavos % 5;

    printf("NOTAS:\n");
    printf("%d nota(s) de R$ 100.00\n", notas100);
    printf("%d nota(s) de R$ 50.00\n", notas50);
    printf("%d nota(s) de R$ 20.00\n", notas20);
    printf("%d nota(s) de R$ 10.00\n", notas10);
    printf("%d nota(s) de R$ 5.00\n", notas5);
    printf("%d nota(s) de R$ 2.00\n", notas2);
    printf("MOEDAS:\n");
    printf("%d moeda(s) de R$ 1.00\n", moedas1);
    printf("%d moeda(s) de R$ 0.50\n", moedas50);
    printf("%d moeda(s) de R$ 0.25\n", moedas25);
    printf("%d moeda(s) de R$ 0.10\n", moedas10);
    printf("%d moeda(s) de R$ 0.05\n", moedas5);
    printf("%d moeda(s) de R$ 0.01\n", moedas01);

    return 0;
}
